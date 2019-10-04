/* How file input/output works. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDEX_LEN 9
#define YEAR_LEN 4
#define PATH_LEN 30

typedef struct book {
    char author[40];
    char title[30];
    short year;
    struct book *next;
} book_t;

void enter_string(char *buffer, const int max_size)
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

char enter_character()
{
    char buffer[3];
    enter_string(buffer, sizeof(buffer));
    return buffer[0];
}

int enter_number(char *buffer, const int max_size)
{
    enter_string(buffer, max_size);
    char *endptr;
    int number = strtol(buffer, &endptr, 10);
    while (strlen(endptr) != 0 || endptr == buffer) {
        printf("Not a number. Please try again: ");
        enter_string(buffer, sizeof(buffer));
        number = strtol(buffer, &endptr, 10);
    }
    return number;
}

int enter_index(const int idx_max)
{
    printf("\nPlease enter an index: ");
    char buffer[INDEX_LEN+2];
    int idx = enter_number(buffer, sizeof(buffer));
    while (idx < 1 || idx > idx_max) {
        printf("Index out of range (1 <= i <= %d). Please try again: ", idx_max);
        idx = enter_number(buffer, sizeof(buffer));
    }
    return idx;
}

book_t enter_book()
{
    book_t book;
    printf("\nPlease enter an author: ");
    enter_string(book.author, sizeof(book.author));
    printf("Please enter an title: ");
    enter_string(book.title, sizeof(book.title));
    printf("Please enter a year: ");
    char buffer[YEAR_LEN+2];
    book.year = enter_number(buffer, sizeof(buffer));
    return book;
}

void print_book(const int idx, const book_t book)
{
    printf("\n%d. %s - %s (%d)", idx, book.author, book.title, book.year);
}

int is_last(book_t *slot)
{
    return slot->next == NULL;
}

int get_steps_to_last(book_t *slot)
{
    int steps = 0;
    while ((slot = slot->next) != NULL)
        steps++;
    return steps;
}

book_t *walk_steps(book_t *current, const int steps)
{
    for (int i=0; i < steps; i++)
        current = current->next;
    return current;
}

book_t *get_last(book_t *current)
{
    while (!is_last(current))
        current = current->next;
    return current;
}

book_t *push(book_t *slot, const book_t book)
{
    book_t *new = malloc(sizeof(*new));
    if (new == NULL)
        exit(EXIT_FAILURE);
    strcpy(new->author, book.author);
    strcpy(new->title, book.title);
    new->year = book.year;
    new->next = slot->next;
    slot->next = new;
    return slot;
}

book_t *pop(book_t *slot)
{
    book_t *temp = slot->next;
    slot->next = slot->next->next;
    free(temp);
    return slot;
}

book_t *init()
{
    book_t *head = malloc(sizeof(*head));
    if (head == NULL)
        exit(EXIT_FAILURE);
    head->next = NULL;
    return head;
}

book_t *add(book_t *head)
{
    puts("\nPlease enter the new book's characteristics.");
    book_t book = enter_book();
    puts("\nNow, please enter the index of the book in the database.");
    int idx_max = get_steps_to_last(head) + 1;
    int steps = enter_index(idx_max) - 1;
    book_t *slot = walk_steps(head, steps);
    slot = push(slot, book);
    puts("\nThe book was successfully added.");
    return head;
}

book_t *delete(book_t *head)
{
    if (!is_last(head)) {
        puts("\nPlease enter the index of the book to delete.");
        int idx_max = get_steps_to_last(head);
        int steps = enter_index(idx_max) - 1;
        book_t *slot = walk_steps(head, steps);
        slot = pop(slot);
        puts("\nThe book was successfully deleted.");
    } else {
        puts("\nThere is no book in the database.");
    }
    return head;
}

book_t *clear(book_t *head)
{
    while (!is_last(head = pop(head)));
    puts("\nSuccessfully cleared database.");
    return head;    
}

void display(book_t *head)
{
    if (!is_last(head)) {
        puts("\nBooks currently in the database:");
        int idx = 0;
        while (!is_last(head)) {
            idx++;
            head = head->next;
            print_book(idx, *head);
        }
        puts("\n");
    } else {
        puts("\nThere is no book in the database.");
    }
}

// book_t *sort_two_books(book_t *slot) {
//     if (strcmp(slot->author, slot->next->author) > 0) {
//         slot->next->next = push(slot->next->next, *slot);
//         slot = pop(slot);
//     }
//     return slot;
// }

// book_t *sort(book_t *head)
// {
//     if (head != NULL && head->next != NULL) {
//         int max_idx = index_of_last_book(head);
//         for (int i=1; i < max_idx; i++) {
//             for (int j=i; j > 0; j--) {
//                 if (j != 1) {
//                     book_t *current = move_to_index(head, j-1);
//                     current->next = sort_two_->nextbooks(current->next);
//                 } else {
//                     head = sort_two_books(head);
//                 }
//             }
//         }
//         puts("\nThe books were successfully sorted by author.");
//     } else {
//         puts("\nThere are not enough books to do a sorting.");
//     }
//     return head;
// }

book_t *sort_two_books(book_t *current) {
    if (strcmp(current->next->author, current->next->next->author) > 0) {
        current->next->next = push(current->next->next, *current);
        current = pop(current);
    }
    return current;
}

book_t *sort(book_t *head)
{
    if (!is_last(head)) {
        book_t *upper = get_last(head);
        while (upper != head) {
            book_t *current = head;
            while (!is_last(current)) {
                current = sort_two_books(current);
                puts("");
            }
        upper = current;
        }
        puts("\nThe books were successfully sorted by author.");
    } else {
        puts("\nThere is no book in the database.");
    }
    return head;
}

void save_file(book_t *head)
{
    printf("\nPlease enter a filename to write: ");
    char buffer[PATH_LEN+2];
    enter_string(buffer, sizeof(buffer));
    FILE *fp = fopen(buffer, "w");
    while (!is_last(head)) {
        head = head->next;
        fprintf(fp, "%s\n%s\n%d\n", head->author, head->title, head->year);
    }
    fclose(fp);
    printf("\nSuccessfully saved database to \"%s\".\n", buffer);
}

book_t *load_file(book_t *head)
{
    printf("\nPlease enter a filename to read: ");
    char buffer[PATH_LEN+2];
    enter_string(buffer, sizeof(buffer));
    FILE *fp = fopen(buffer, "r");
    if (fp != NULL) {
        book_t book;
        while (fgets(book.author, sizeof(book.author), fp) != NULL) {
            fgets(book.title, sizeof(book.title), fp);
            fscanf(fp, "%hd ", &(book.year));
            book.author[strlen(book.author)-1] = '\0';
            book.title[strlen(book.title)-1] = '\0';
            book_t *tail = get_last(head);
            tail = push(tail, book);
        }
        printf("\nSuccessfully loaded books from \"%s\".\n", buffer);
    } else {
        puts("\nFile not found.");
    }
    fclose(fp);
    return head;
}

book_t *display_file(book_t *head)
{
    printf("\nPlease enter a filename to read: ");
    char buffer[PATH_LEN+2];
    enter_string(buffer, sizeof(buffer));
    FILE *fp = fopen(buffer, "r");
    if (fp != NULL) {
        printf("\nBooks in \"%s\":\n", buffer);
        book_t book;
        int is_empty = 1;
        int idx = 1;
        while (fgets(book.author, sizeof(book.author), fp) != NULL) {
            fgets(book.title, sizeof(book.title), fp);
            fscanf(fp, "%hd ", &(book.year));
            book.author[strlen(book.author)-1] = '\0';
            book.title[strlen(book.title)-1] = '\0';
            print_book(idx, book);
            is_empty = 0;
            idx++;
        }
        if (is_empty)
            puts("\nThe file is empty.");
        else
            puts("\n");        
    } else {
        puts("\nFile not found.");
    }
    fclose(fp);
    return head;
}

int main()
{
    book_t *head = init();
    head = push(head, (book_t) { "Ivan Cukic", "Functional Programming in C++", 2018 });
    head = push(head, (book_t) { "Daniel Kahneman", "Thinking, Fast and Slow", 2012 });
    head = push(head, (book_t) { "Nick Bostrom", "Superintelligence", 2008 });
    head = push(head, (book_t) { "Nassim Nicholas Taleb", "The Black Swan", 2008 });
    head = push(head, (book_t) { "Brian Kernighan, Dennis Ritchie", "The C Programming Language", 1978 });
    while (1) {
        puts("Main menu.\n");
        puts("  1. Add a book.");
        puts("  2. Display the books.");
        puts("  3. Remove a book.");
        puts("  4. Sort books by author.");
        puts("  5. Clear database.\n");
        puts("  6. Save books to file.");
        puts("  7. Load books from file.");
        puts("  8. Display books from file.\n");
        puts("  Q. Quit program.\n");
        printf("Please enter your selection: ");
        switch (enter_character()) {
        case '1': head = add(head); break;
        case '2': display(head); break;
        case '3': head = delete(head); break;
        case '4': head = sort(head); break;
        case '5': head = clear(head); break;
        case '6': save_file(head); break;
        case '7': head = load_file(head); break;
        case '8': display_file(head); break;
        case 'q':
        case 'Q': puts("\nGood bye!"); return 0;
        default: puts("\nPlease enter a number between 1 and 8, or Q to quit."); break;
        }
        puts("Press enter to continue...");
        while(getchar() != '\n');
    }
}
