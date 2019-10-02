/* How to use linked lists. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char author[40];
    char title[30];
    short year;
    struct book *next;
} book_t;

void flush_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void safe_fgets(char *buffer, const int max_size)
{
    fgets(buffer, max_size, stdin);
    size_t idx_newline = strcspn(buffer, "\n");
    while (buffer[idx_newline] != '\n') {
        printf("Too many characters (max = %d). Please try again : ", max_size - 2);
        flush_stdin();
        fgets(buffer, max_size, stdin);   
        idx_newline = strcspn(buffer, "\n");
    }
    buffer[idx_newline] = '\0';
}

char safe_getchar()
{
    char buffer[3];
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

int index_of_last_book(book_t *head)
{
    book_t *current = head;
    int idx = 1;
    while ((current = current->next) != NULL)
        idx++;
    return idx;
}

int enter_index(book_t *head)
{
    char buffer[10];
    printf("Please enter an index: ");
    int max_idx=index_of_last_book(head), idx;
    while ((idx = enter_num(buffer, sizeof(buffer))) < 1 || idx > max_idx)
        printf("Index out of range (0 < i < %d). Please try again: ", max_idx+1);
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
    char buffer[6];
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

void print_book(int idx, book_t *book)
{
    printf("%d. %s - %s (%d)\n", idx, book->author, book->title, book->year);
}

book_t *current_at_index(book_t *head, const int idx)
{
    book_t *current = head;
    for (int curr_idx=1; curr_idx < idx; curr_idx++)
        current = current->next;
    return current;
}

book_t *push(book_t *head, book_t book)
{
    book_t *temp = malloc(sizeof(*temp));
    strcpy(temp->author, book.author);
    strcpy(temp->title, book.title);
    temp->year = book.year;
    temp->next = head;
    return temp;
}

book_t *pop(book_t *head)
{
    book_t *temp = head;
    head = head->next;
    free(temp);
    return head;
}

book_t *add(book_t *head)
{
    puts("\nPlease enter the new book's characteristics.\n");
    book_t book = enter_book();
    if (head != NULL) {
        puts("Now, please enter the index of the book in the shelf.\n");
        int idx = enter_index(head);
        if (idx != 1) {
            book_t *current = current_at_index(head, idx-1);
            current->next = push(current->next, book);
            return head;
        }
    }
    return push(head, book);
}

book_t *delete(book_t *head)
{
    if (head != NULL) {
        puts("\nPlease enter the index of the book to delete.\n");
        int idx = enter_index(head);
        if (idx != 1) {
            book_t *current = current_at_index(head, idx-1);
            current->next = pop(current->next);
            return head;
        }
        return pop(head);
    }
    puts("\nSorry, there is no book to delete. Please add a book first.\n");
    return head;
}

void list(book_t *head)
{
    if (head != NULL) {
        puts("\nBooks currently on the shelf:\n");
        book_t *current = head;
        int idx = 1;
        do {
            print_book(idx++, current);
            current = current->next;
        } while (current != NULL);
        puts("");
    } else {
        puts("\nSorry, there is no book to list. Please add a book first.\n");
    }
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
        puts("Main menu. Choose between:");
        puts("  1. Add a book.");
        puts("  2. Remove a book.");
        puts("  3. List all books.");
        puts("  Q. Quit program.");
        printf("Please enter your selection: ");
        switch (safe_getchar()) {
        case '1': head = add(head); break;
        case '2': head = delete(head); break;
        case '3': list(head); break;
        case 'q':
        case 'Q': return 0;
        default: puts("\nPlease type either 1, 2, 3, or Q.\n"); break;
        }
    }
}
