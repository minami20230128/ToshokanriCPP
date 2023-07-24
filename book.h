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

        std::vector<std::string> getAuthors()
        {
            return this->authors;
        }

        void setTitle(std::string title)
        {
            this->title = title;
        }

        void setPublisher(std::string publisher)
        {
            this->publisher = publisher;
        }

        void setDate(std::string date)
        {
            this->date = date;
        }

        void setAuthor(std::string author)
        {
            this->authors.push_back(author);
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