#pragma once
#include "book.h"
#include <vector>
#include <algorithm>
#include <string>
#include <map>

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
                    itr = booklist.erase(itr);
                    break;
                }
            }
        }

        Book searchBook(std::string title)
        {
            for(auto book : booklist)
            {
                if(book.getTitle() == title)
                {
                    return book;
                }
            }
        }

        Book searchBookByAuthor(std::string searchingAuthor)
        {
            for(auto book : booklist)
            {
                auto authors = book.getAuthors();
                for(auto author : authors)
                {
                    if(author == searchingAuthor)
                    {
                        return book;
                    }
                }
            }
        }

        std::vector<Book> sortBooksByAuthor()
        {
            auto ritr = booklist.rbegin();

            while(ritr != booklist.rend())
            {
                prevbook = 
                if(ritr->isFormar())
                ritr++;

            }
        }
};