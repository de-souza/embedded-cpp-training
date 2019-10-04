/* How to manipulate files. */
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

static const book_t EMPTY_BOOK;

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

book_t read_next_book(FILE *fp) {
    book_t book;
    if (fgets(book.author, sizeof(book.author), fp) != NULL) {
            fgets(book.title, sizeof(book.title), fp);
            fscanf(fp, "%hd ", &(book.year));
            book.author[strlen(book.author)-1] = '\0';
            book.title[strlen(book.title)-1] = '\0';
    } else {
        book = EMPTY_BOOK;
    }
    return book;
}

int is_book(book_t book)
{
    return strcmp(book.author, EMPTY_BOOK.author) != 0
        || strcmp(book.title, EMPTY_BOOK.title) != 0
        || book.year != EMPTY_BOOK.year;
}

int is_not_last(book_t *current)
{
    return current->next != NULL;
}

book_t *get_last(book_t *current)
{
    while (is_not_last(current))
        current = current->next;
    return current;
}

int get_steps_to_last(book_t *current)
{
    int steps = 0;
    while (is_not_last(current)) {
        steps++;
        current = current->next;
    }
    return steps;
}

book_t *walk_n_steps(book_t *current, const int n)
{
    for (int i=0; i < n; i++)
        current = current->next;
    return current;
}

book_t *push(book_t *current, const book_t book)
{
    book_t *new = malloc(sizeof(*new));
    if (new == NULL)
        exit(EXIT_FAILURE);
    strcpy(new->author, book.author);
    strcpy(new->title, book.title);
    new->year = book.year;
    new->next = current;
    return new;
}

book_t *pop(book_t *current)
{
    book_t *temp = current;
    current = current->next;
    free(temp);
    return current;
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
    int idx = enter_index(idx_max);
    book_t *current = walk_n_steps(head, idx-1);
    current->next = push(current->next, book);
    puts("\nThe book was successfully added.");
    return head;
}

void display(book_t *head)
{
    if (is_not_last(head)) {
        puts("\nBooks currently in the database:");
        int idx = 0;
        while (is_not_last(head))
            print_book(++idx, *(head = head->next));
        puts("\n");
    } else {
        puts("\nThere is no book in the database.");
    }
}

book_t *delete(book_t *head)
{
    if (is_not_last(head)) {
        puts("\nPlease enter the index of the book to remove.");
        int idx_max = get_steps_to_last(head);
        int idx = enter_index(idx_max);
        book_t *current = walk_n_steps(head, idx-1);
        current->next = pop(current->next);
        puts("\nThe book was successfully deleted.");
    } else {
        puts("\nThere is no book in the database.");
    }
    return head;
}

book_t *clear(book_t *head)
{
    while (is_not_last(head = pop(head)));
    puts("\nSuccessfully cleared database.");
    return head;    
}

book_t *swap_with_next(book_t *first)
{
    book_t *second = first->next;
    first->next = second->next;
    second->next = first;
    return second;
}

book_t *sort(book_t *head)
{
    if (is_not_last(head)) {
        if (is_not_last(head->next)) {
            int done = 0;
            while (!done) {
                book_t *current = head;
                done = 1;
                while (is_not_last(current->next)) {
                    int cmp = strcmp(current->next->author, current->next->next->author);
                    if (cmp > 0) {
                        current->next = swap_with_next(current->next);
                        done = 0;
                    }
                    current = current->next;
                }
            }
        } else {
            puts("\nThere is only one book in the database.");
        }
    } else {
        puts("\nThere is no book in the database.");
    }
    return head;
}

void save_file(book_t *head)
{
    printf("\nPlease enter the path of the file to save: ");
    char buffer[PATH_LEN+2];
    enter_string(buffer, sizeof(buffer));
    FILE *fp = fopen(buffer, "w");
    while (is_not_last(head)) {
        head = head->next;
        fprintf(fp, "%s\n%s\n%d\n", head->author, head->title, head->year);
    }
    fclose(fp);
    puts("\nSuccessfully saved database.");
}

book_t *load_file(book_t *head)
{
    printf("\nPlease enter the path of the file to load: ");
    char buffer[PATH_LEN+2];
    enter_string(buffer, sizeof(buffer));
    FILE *fp = fopen(buffer, "r");
    if (fp != NULL) {
        book_t book;
        int is_success = 0;
        while (is_book(book = read_next_book(fp))) {
            book_t *tail = get_last(head);
            tail->next = push(tail->next, book);
            is_success = 1;
        }
        fclose(fp);
        if (is_success)
            puts("\nSuccessfully loaded file.");
        else
            puts("\nThe file is empty.");
    } else {
        puts("\nFile not found.");
    }
    return head;
}

book_t *display_file(book_t *head)
{
    puts("\nPlease enter the path of the file to display the books from.");
    char buffer[PATH_LEN+2];
    enter_string(buffer, sizeof(buffer));
    FILE *fp = fopen(buffer, "r");
    if (fp != NULL) {
        puts("\nBooks in the file:");
        book_t book;
        int idx = 1;
        int is_success = 0;
        while (is_book(book = read_next_book(fp))) {
            print_book(idx, book);
            idx++;
            is_success = 1;
        }
        fclose(fp);
        if (is_success)
            puts("\n");        
        else
            puts("\nThe file is empty.");
    } else {
        puts("\nFile not found.");
    }
    return head;
}

int main()
{
    book_t *head = init();
    head->next = push(head->next, (book_t) { "Ivan Cukic", "Functional Programming in C++", 2018 });
    head->next = push(head->next, (book_t) { "Daniel Kahneman", "Thinking, Fast and Slow", 2012 });
    head->next = push(head->next, (book_t) { "Nick Bostrom", "Superintelligence", 2008 });
    head->next = push(head->next, (book_t) { "Nassim Nicholas Taleb", "The Black Swan", 2008 });
    head->next = push(head->next, (book_t) { "Brian Kernighan, Dennis Ritchie", "The C Programming Language", 1978 });
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
