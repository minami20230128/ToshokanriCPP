#pragma once
#include <vector>
#include <string>

class Book
{
    public:
        Book(std::string title,std::string publisher, std::string date, std::vector<std::string> authors) 
        {
            this->title = title;
            this->publisher = publisher;
            this->date = date;
            this->authors = authors;
        }

        ~Book()
        {

        }
    
        std::string getTitle()
        {
            return this->title;
        }

        std::string getPublisher()
        {
            return this->publisher;
        }

        std::string getDate()
        {
            return this->date;
        }

        std::vector<std::string> getAuthor()
        {
            return this->authors;
        }

    private:
        std::string title;
        std::string publisher;
        std::string date;
        std::vector<std::string> authors;
};

class ForeignBook : Book
{
    private:
        std::string translator;
};