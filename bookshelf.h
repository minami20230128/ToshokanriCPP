#pragma once
#include "book.h"
#include <vector>
#include <algorithm>
#include <string>

class Bookshelf
{
    private:
        std::vector<Book> booklist;
    
    public:
        std::vector<Book> getBookshelf()
        {
            std::vector<Book>tmpbookshelf(booklist);

            return tmpbookshelf;
        }

        void setBookshelf(std::vector <Book> books)
        {
            booklist.insert(booklist.end(), books.begin(), books.end());
        }

        void deletebook(std::string title)
        {
            for(auto itr = booklist.begin(); itr != booklist.end(); itr++)
            {
                if (itr->getTitle() == title)
                {
                    booklist.erase(itr);
                }
            }
        }
};