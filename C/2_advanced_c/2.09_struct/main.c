/* How to use structures. */
#include <stdio.h>

typedef struct {
    char author[40];
    char title[30];
    short year;
} book_t;

void list_titles(book_t *shelf, int n)
{
    book_t *ptr = shelf;
    while (ptr != shelf + n) {
        printf("%s\n", ptr->title);
        ptr++;
    }
}

void set_book(book_t *shelf, int i, book_t book)
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
    list_titles(shelf, 5);
    puts("-- add book --");
    book_t new_book = { "Peppa Pig", "Peppa Pig: Up and Down", 2019 };
    set_book(shelf, 5, new_book);
    list_titles(shelf, 6);
}
