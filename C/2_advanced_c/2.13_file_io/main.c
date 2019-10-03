/* How to file input/output works. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char author[40];
    char title[30];
    short year;
    struct book *next;
} book_t;

void pause(const char *message)
{
    printf("%s\nPress enter to continue...\n", message);
    while(getchar() != '\n');
    puts("");
}

void safe_fgets(char *buffer, const int max_size)
{
    fgets(buffer, max_size, stdin);
    size_t newline_span = strcspn(buffer, "\n");
    while (buffer[newline_span] != '\n') {
        printf("Too many characters (max = %d). Please try again : ", max_size-2);
        while (getchar() != '\n');
        fgets(buffer, max_size, stdin);
        newline_span = strcspn(buffer, "\n");
    }
    buffer[newline_span] = '\0';
}

char safe_getchar()
{
    char buffer[3];  // allow 1 character
    safe_fgets(buffer, sizeof(buffer));
    return buffer[0];
}

int enter_num(char *buffer, const int max_size)
{
    safe_fgets(buffer, max_size);
    char *endptr;
    int num = strtol(buffer, &endptr, 10);
    while (strlen(endptr) != 0 || endptr == buffer) {
        printf("Not a number. Please try again: ");
        safe_fgets(buffer, sizeof(buffer));
        num = strtol(buffer, &endptr, 10);
    }
    return num;
}

int enter_index(const int max_idx)
{
    printf("Please enter an index: ");
    char buffer[11];  // allow up to 9 digits for the index
    int idx = enter_num(buffer, sizeof(buffer));
    while (idx < 1 || idx > max_idx) {
        printf("Index out of range (0 < i < %d). Please try again: ", max_idx+1);
        idx = enter_num(buffer, sizeof(buffer));
    }
    puts("");
    return idx;
}

book_t enter_book()
{
    book_t book;
    printf("Please enter an author: ");
    safe_fgets(book.author, sizeof(book.author));
    printf("Please enter an title: ");
    safe_fgets(book.title, sizeof(book.title));
    printf("Please enter a year: ");
    char buffer[6];  // allow up to 4 digits for the year
    book.year = enter_num(buffer, sizeof(buffer));
    puts("");
    return book;
}

book_t generate_book(const char *restrict author, const char *restrict title, const short year)
{
    book_t book;
    strcpy(book.author, author);
    strcpy(book.title, title);
    book.year = year;
    return book;
}

void print_book(const int idx, const book_t book)
{
    printf("%d. %s - %s (%d)\n", idx, book.author, book.title, book.year);
}

int index_of_last_book(book_t *head)
{
    int idx = 1;
    while (head->next != NULL) {
        idx++;
        head = head->next;
    }
    return idx;
}

book_t *move_to_index(book_t *slot, const int idx)
{
    book_t *current = slot;
    for (int curr_idx=1; curr_idx < idx; curr_idx++)
        current = current->next;
    return current;
}

book_t *push(book_t *slot, const book_t book)
{
    book_t *temp = malloc(sizeof(*temp));
    if (temp == NULL) {
        puts("Out of memory error.");
        exit(EXIT_FAILURE);
    }
    strcpy(temp->author, book.author);
    strcpy(temp->title, book.title);
    temp->year = book.year;
    temp->next = slot;
    return temp;
}

book_t *pop(book_t *slot)
{
    book_t *temp = slot;
    slot = slot->next;
    free(temp);
    return slot;
}

book_t *add(book_t *head)
{
    puts("\nPlease enter the new book's characteristics.\n");
    book_t book = enter_book();
    if (head != NULL) {
        puts("Now, please enter the index of the book in the database.\n");
        int max_idx = index_of_last_book(head) + 1;
        int idx = enter_index(max_idx);
        if (idx != 1) {
            book_t *current = move_to_index(head, idx-1);
            current->next = push(current->next, book);
        }
    } else {
        head = push(head, book);
    }
    pause("The book was successfully added.");
    return head;
}

void list(book_t *head)
{
    if (head != NULL) {
        puts("\nBooks currently in the database:\n");
        int idx = 1;
        while (head != NULL) {
            print_book(idx, *head);
            idx++;
            head = head->next;
        }
        pause("");
    } else {
        pause("\nSorry, there is no book to list.");
    }
}

book_t *delete(book_t *head)
{
    if (head != NULL) {
        puts("\nPlease enter the index of the book to delete.\n");
        int max_idx = index_of_last_book(head);
        int idx = enter_index(max_idx);
        if (idx != 1) {
            book_t *current = move_to_index(head, idx-1);
            current->next = pop(current->next);
            return head;
        }
        head = pop(head);
        pause("The book was successfully deleted.");
    } else {
        pause("\nSorry, there is no book to delete.");
    }
    return head;
}

book_t *sort(book_t *head)
{
    if (head != NULL) {
        for (int i=1; i < index_of_last_book(head); i++) {
            for (int j=i; j > 0; j--) {
                if (j != 1) {
                    book_t *current = move_to_index(head, j-1);
                    if (strcmp(current->next->author, current->next->next->author) > 0) {
                        current->next->next->next = push(current->next->next->next, *(current->next));
                        current->next = pop(current->next);
                    }
                } else {
                    if (strcmp(head->author, head->next->author) > 0) {
                        head->next->next = push(head->next->next, *head);
                        head = pop(head);
                    }
                }
            }
        }
        pause("\nThe books were successfully sorted by author.");
    } else {
        pause("\nSorry, there is no book to sort.");
    }
    return head;
}

book_t *clear(book_t *head)
{
    while (head != NULL)
        head = pop(head);
    pause("\nSuccessfully cleared database.");
    return head;
}

void save_file(book_t *head)
{
    printf("\nPlease enter a filename to write: ");
    char filename[32];  // allow up to 30 characters
    safe_fgets(filename, sizeof(filename));
    FILE *fp = fopen(filename, "w");
    while (head != NULL) {
        book_t buffer;
        strcpy(buffer.author, head->author);
        strcpy(buffer.title, head->title);
        buffer.author[sizeof(buffer.author)-1] = '\n';
        buffer.title[sizeof(buffer.title)-1] = '\n';
        fwrite(buffer.author, sizeof(buffer.author), 1, fp);
        fwrite(buffer.title, sizeof(buffer.title), 1, fp);
        fprintf(fp, "%d\n", head->year);
        head = head->next;
    }
    fclose(fp);
    pause("\nSuccessfully saved database.");
}

book_t *load_file(book_t *head)
{
    printf("\nPlease enter a filename to read: ");
    char filename[32];  // allow up to 30 characters
    safe_fgets(filename, sizeof(filename));
    FILE *fp = fopen(filename, "r");
    if (fp != NULL) {
        book_t book;
        while (fread(book.author, sizeof(book.author), 1, fp) != 0) {
            fread(book.title, sizeof(book.title), 1, fp);
            book.author[sizeof(book.author)-1] = '\0';
            book.title[sizeof(book.title)-1] = '\0';
            fscanf(fp, "%hd ", &(book.year));
            if (head != NULL) {
                int idx = index_of_last_book(head);
                book_t *current = move_to_index(head, idx);
                current->next = push(current->next, book);
            } else {
                head = push(head, book);
            }
        }
        pause("\nSuccessfully added books to database.");
    } else {
        pause("\nFile not found.");
    }
    fclose(fp);
    return head;
}

void list_file()
{
    printf("\nPlease enter a filename to read: ");
    char filename[32];  // allow up to 30 characters
    safe_fgets(filename, sizeof(filename));
    printf("\nBooks in %s:\n\n", filename);
    FILE *fp = fopen(filename, "r");
    if (fp != NULL) {
        book_t book;
        int idx = 1;
        int is_empty = 1;
        while (fread(book.author, sizeof(book.author), 1, fp) != 0) {
            fread(book.title, sizeof(book.title), 1, fp);
            book.author[sizeof(book.author)-1] = '\0';
            book.title[sizeof(book.title)-1] = '\0';
            fscanf(fp, "%hd ", &(book.year));
            print_book(idx, book);
            idx++;
            is_empty = 0;
        }
        if (is_empty)
            pause("Sorry, there is no book to list.");
        else
            pause("");
    } else {
        pause("\nFile not found.");
    }
    fclose(fp);
}

int main()
{
    book_t *head = NULL;
    head = push(head, generate_book("Ivan Cukic", "Functional Programming in C++", 2018));
    head = push(head, generate_book("Daniel Kahneman", "Thinking, Fast and Slow", 2012));
    head = push(head, generate_book("Nick Bostrom", "Superintelligence", 2008));
    head = push(head, generate_book("Nassim Nicholas Taleb", "The Black Swan", 2008));
    head = push(head, generate_book("Brian Kernighan, Dennis Ritchie", "The C Programming Language", 1978));
    while (1) {
        puts("Main menu.\n");
        puts("  1. Add a book.");
        puts("  2. List all books.");
        puts("  3. Remove a book.");
        puts("  4. Sort books by author.");
        puts("  5. Clear database.\n");
        puts("  6. Save books to file.");
        puts("  7. Add books from file.");
        puts("  8. Display books from file.\n");
        puts("  Q. Quit program.\n");
        printf("Please enter your selection: ");
        switch (safe_getchar()) {
        case '1': head = add(head); break;
        case '2': list(head); break;
        case '3': head = delete(head); break;
        case '4': head = sort(head); break;
        case '5': head = clear(head); break;
        case '6': save_file(head); break;
        case '7': head = load_file(head); break;
        case '8': list_file(head); break;
        case 'q':
        case 'Q': pause(""); return 0;
        default: puts("\nPlease type a number between 1 and 8, or Q to quit.\n"); break;
        }
    }
}
