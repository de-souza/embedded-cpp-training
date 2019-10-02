/* How to use linked lists. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDEX_MAX_SIZE 10   // 10 = max 8 digits + \n + \0
#define YEAR_MAX_SIZE 6     // 6 = max 4 digits + \n + \0

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

int enter_index(const int max_idx)
{
    char buffer[INDEX_MAX_SIZE];
    printf("Please enter an index: ");
    int i = enter_num(buffer, sizeof(buffer));
    while (i < 1 || i > max_idx) {
        printf("Invalid index (1 <= i <= %d). Please try again: ", max_idx);
        i = enter_num(buffer, sizeof(buffer));
    }
    return i;
}

book_t *enter_book()
{
    book_t *book = malloc(sizeof(book_t));
    char buffer[YEAR_MAX_SIZE];
    puts("\nPlease enter the new book's characteristics.\n");
    printf("Please enter an author: ");
    safe_fgets(book->author, sizeof(book->author));
    printf("Please enter an title: ");
    safe_fgets(book->title, sizeof(book->title));
    printf("Please enter a year: ");
    book->year = (short) enter_num(buffer, sizeof(buffer));
    puts("");
    return book;
}

book_t *create_book(const char *restrict author, const char *restrict title, const short year)
{
    book_t *book = malloc(sizeof(book_t));
    strcpy(book->author, author);
    strcpy(book->title, title);
    book->year = year;
    return book;
}

book_t *add_book(book_t *head, book_t *book)
{
    if (head == NULL)
        return book;
    book_t *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = book;
    return head;
}

book_t *remove_book(book_t *head)
{
    if (head == NULL) {
        puts("\nSorry, there is no book to delete. Please add a book first.\n");
        return head;
    }
    puts("\nPlease choose the index of the book to delete.\n");
    book_t *temp = head;
    int max_idx = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        max_idx++;
    }
    int idx = enter_index(max_idx);
    if (idx == 1) {
        temp = head->next;
        free(head);
        puts("");
        return temp;
    }
    temp = head;
    for (int i=1; i < idx-1; i++)
        temp = temp->next;
    book_t *deleted = temp->next;
    temp->next = deleted->next;
    free(deleted);
    puts("");
    return head;
}

void list_books(book_t *head)
{
    if (head != NULL) {
        puts("\nBooks currently on the shelf:\n");
        book_t *ptr = head;
        int i = 1;
        while (ptr != NULL) {
            printf("%d. %s - %s (%d)\n", i, ptr->author, ptr->title, ptr->year);
            ptr = ptr->next;
            i++;
        }
        puts("");
    } else {
        puts("\nSorry, there is no book to list. Please add a book first.\n");
    }
}

int main()
{
    book_t *head = NULL;
    head = add_book(head, create_book("Brian Kernighan, Dennis Ritchie", "The C Programming Language", 1978));
    head = add_book(head, create_book("Nassim Nicholas Taleb", "The Black Swan", 2008));
    head = add_book(head, create_book("Nick Bostrom", "Superintelligence", 2008));
    head = add_book(head, create_book("Daniel Kahneman", "Thinking, Fast and Slow", 2012));
    head = add_book(head, create_book("Ivan Cukic", "Functional Programming in C++", 2018));
    while (1) {
        puts("Main menu. Choose between:");
        puts("  1. Add a book.");
        puts("  2. Remove a book.");
        puts("  3. List all books.");
        puts("  Q. Quit program.");
        printf("Please enter your selection: ");
        switch (safe_getchar()) {
        case '1': head = add_book(head, enter_book()); break;
        case '2': head = remove_book(head); break;
        case '3': list_books(head); break;
        case 'q':
        case 'Q': return 0;
        default: puts("\nPlease type either 1, 2, 3, or Q.\n"); break;
        }
    }
}
