/* How to use structures. */
#include <stdio.h>

typedef struct {
    char author[40];
    char title[30];
    short year;
} book_t;

void list_titles(book_t shelf[], int max_i)
{
    book_t *ptr = shelf;
    while (ptr != shelf + max_i + 1) {
        printf("%s\n", ptr->title);
        ptr++;
    }
}

void set_book(book_t shelf[], int i, book_t book)
{
    shelf[i] = book;
}

int main()
{
    book_t shelf[10] = {
        { "Brian Kernighan, Dennis Ritchie", "The C Programming Language", 1978 },
        { "Nassim Nicholas Taleb", "The Black Swan", 2008 },
        { "Nick Bostrom", "Superintelligence", 2008 },
        { "Daniel Kahneman", "Thinking, Fast and Slow", 2012 },
        { "Ivan Cukic", "Functional Programming in C++", 2018 },
    };
    list_titles(shelf, 4);
    puts("-- add book --");
    book_t new_book = { "Peppa Pig: Up and Down", "Peppa Pig", 2019 };
    set_book(shelf, 5, new_book);
    list_titles(shelf, 5);
}
