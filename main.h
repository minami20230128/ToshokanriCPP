#pragma once
#include <string>
#include "book.h"
#include "bookshelf.h"

Bookshelf bookshelf;

void showAllBooks();

void showAllBooksByAuthor();

void searchBooksByTitle();

void searchBooksByAuthor();

void addBooks();

void deleteBooks();

void saveBooks();

void loadBooks();

void modifyBooks();

int menu();

void showBook(Book book);



