/* How to use structures. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHELF_LEN 100       // 100 = max 99 books + 1 empty slot
#define INDEX_MAX_SIZE 10   // 10 = max 8 digits + \n + \0
#define YEAR_MAX_SIZE 6     // 6 = max 4 digits + \n + \0

typedef struct {
    char author[40];
    char title[30];
    short year;
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
    char *endptr;
    safe_fgets(buffer, max_size);
    int n = strtol(buffer, &endptr, 10);
    while (strlen(endptr) != 0 || endptr == buffer) {
        printf("Not a number. Please try again: ");
        safe_fgets(buffer, sizeof(buffer));
        n = strtol(buffer, &endptr, 10);
    }
    return n;
}

int enter_index(const int len)
{
    char buffer[INDEX_MAX_SIZE];
    printf("Please enter an index: ");
    int i = enter_num(buffer, sizeof(buffer));
    while (i < 1 || i > len - 2) {
        printf("Invalid index (1 <= i <= %d). Please try again: ", len - 2);
        i = enter_num(buffer, sizeof(buffer));
    }
    return i - 1;
}

void enter_book(book_t *ptr_book)
{
    char buffer[YEAR_MAX_SIZE];
    printf("Please enter an author: ");
    safe_fgets(ptr_book->author, sizeof(ptr_book->author));
    printf("Please enter an title: ");
    safe_fgets(ptr_book->title, sizeof(ptr_book->title));
    printf("Please enter a year: ");
    ptr_book->year = enter_num(buffer, sizeof(buffer));
}

int is_empty(const book_t *ptr_book)
{
    return ptr_book->author[0] == '\0' && ptr_book->title[0] == '\0' && ptr_book->year == 0;
}

void copy_book(book_t *restrict ptr_dest, const book_t *restrict ptr_source)
{
    strcpy(ptr_dest->author, ptr_source->author);
    strcpy(ptr_dest->title, ptr_source->title);
    ptr_dest->year = ptr_source->year;
}

void print_book(const book_t *ptr_book, const int idx)
{
    printf("%d. %s - %s (%d)\n", idx, ptr_book->author, ptr_book->title, ptr_book->year);
}

void insert_book(book_t *ptr_first_book, const int len)
{
    if (!is_empty(ptr_first_book + len - 2)) {
        puts("\nSorry, there is no space left. Please remove a book first.\n");
    } else {
        book_t new_book;
        puts("\nFirst, enter the new book's characteristics.\n");
        enter_book(&new_book);
        puts("\nNow, enter the index of the book in the shelf.\n");
        book_t *ptr_new_book = ptr_first_book + enter_index(len);
        book_t *ptr_book = ptr_new_book;
        if (!is_empty(ptr_book)) {
            while (!is_empty(++ptr_book));
            book_t *ptr_next_book = ptr_book + 1;
            while (ptr_book != ptr_new_book)
                copy_book(--ptr_next_book, --ptr_book);
        } else {
            while (is_empty(--ptr_new_book));
            ptr_new_book++;
        }
        *ptr_new_book = new_book;
        puts("");
    }
}

void remove_book(book_t *ptr_first_book, const int len)
{
    puts("\nChoose the index of the book to delete.\n");
    book_t *ptr_book = ptr_first_book + enter_index(len);
    book_t *ptr_next_book = ptr_book + 1;
    while (!is_empty(ptr_book))
        copy_book(ptr_book++, ptr_next_book++);
    puts("");
}

void list_books(book_t *ptr_first_book, const int len)
{
    puts("\nBooks currently on the shelf:\n");
    book_t *ptr_book = ptr_first_book;
    int idx = 1;
    while (!is_empty(ptr_book))
        print_book(ptr_book++, idx++);
    puts("");
}

int main()
{
    book_t shelf[SHELF_LEN] = {
        { "Brian Kernighan, Dennis Ritchie", "The C Programming Language", 1978 },
        { "Nassim Nicholas Taleb", "The Black Swan", 2008 },
        { "Nick Bostrom", "Superintelligence", 2008 },
        { "Daniel Kahneman", "Thinking, Fast and Slow", 2012 },
        { "Ivan Cukic", "Functional Programming in C++", 2018 },
    };
    size_t len = sizeof(shelf) / sizeof(*shelf);
    while (1) {
        puts("Main menu. Choose between:");
        puts("  1. Add a book.");
        puts("  2. Remove a book.");
        puts("  3. List all books.");
        puts("  Q. Quit program.");
        printf("Please enter your selection: ");
        switch (safe_getchar()) {
        case '1': insert_book(shelf, len); break;
        case '2': remove_book(shelf, len); break;
        case '3': list_books(shelf, len); break;
        case 'q':
        case 'Q': return 0;
        default: puts("\nPlease type either 1, 2, 3, or Q.\n"); break;
        }
    }
}
