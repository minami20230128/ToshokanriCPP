#include "bookshelf.h"
#include "main.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/algorithm/string.hpp>

//コンパイル方法　g++ -std=c++11 main.cpp -o 実行ファイル名（何でもいい）

int main()
{
    int number = menu();
    
    switch(number)
    {
        case 1:
            showAllBooks();
        case 2:
            showAllBooksByAuthor();
        case 3:
            searchBooksByTitle();
        case 4:
            searchBooksByAuthor();
        case 5:
            addBooks();
        case 6:
            deleteBooks();
        case 7:
            saveBooks();
        case 8:
            loadBooks();
        case 9:
            modifyBooks();
    }

    return 0;
}

int menu()
{
    std::cout << "メニューを選択して下さい。" << std::endl;
    std::cout << "1.全ての書籍を見る" << std::endl;
    std::cout << "2.著者別に書籍を見る" << std::endl;
    std::cout << "3.書籍を検索する" << std::endl;
    std::cout << "4.書籍を著者名から検索する" << std::endl;
    std::cout << "5.書籍を追加する" << std::endl;
    std::cout << "6.書籍を削除する" << std::endl;
    std::cout << "7.書籍情報を保存する" << std::endl;
    std::cout << "8.書籍情報を読み込む" << std::endl;
    std::cout << "9.書籍情報を修正する" << std::endl;

    int number;
    std::cin >> number;

    return number;
}

void showAllBooks()
{
    std::vector <Book> tmpbooklist = bookshelf.getBookshelf();
    for(auto book : tmpbooklist)
    {
        showBook(book);
    }
}

void showAllBooksByAuthor()
{
    
}

void searchBooksByTitle()
{
    std::cout << "検索したい書籍の題名を入力してください。" << std::endl;
    std::string title;
    std::cin >> title;
    auto book = bookshelf.searchBook(title);
    showBook(book);
}

void searchBooksByAuthor()
{
    std::cout << "検索したい書籍の著者名を入力してください。" << std::endl;
    std::string author;
    std::cin >> author;
    auto book = bookshelf.searchBookByAuthor(author);
    showBook(book);
}

void addBooks()
{
    std::cout << "書籍の題名を入力してください。" << std::endl;
    std::string title;
    std::cin >> title;
    std::cout << "書籍の出版社名を入力してください。" << std::endl;
    std::string publisher;
    std::cin >> publisher;
    std::cout << "書籍の出版年月日を入力してください。" << std::endl;
    std::string date;
    std::cin >> date;
    std::cout << "書籍の著者を入力してください。" << std::endl;
    std::string author;
    std::cin >> author;

}

void deleteBooks()
{
    std::cout << "消去したい書籍の題名を入力してください。" << std::endl;
    std::string title;
    std::cin >> title;
    auto book = bookshelf.searchBook(title);
    std::cout << "以下の書籍を削除しますか？y/n" << std::endl;
    showBook(book);
    std::string yn;
    std::cin >> yn;

    if(yn == "y")
    {
        bookshelf.deletebook(title);
    }
}

void saveBooks()
{

}

void loadBooks()
{
    std::cout << "読み込むファイルの名前を入力して下さい。" << std::endl;
    std::string filename;
    std::cin >> filename;

    std::ifstream file(filename);
    std::string line;
    std::vector<Book> tmpbooklist;

    while(std::getline(file, line))
    {
        std::vector<std::string> bookinfos, authors;
        
        boost::split(bookinfos, line, boost::is_any_of(","));

        std::string title = bookinfos[0];
        std::string publisher = bookinfos[1];
        std::string date = bookinfos[2];

        auto itr = bookinfos.begin() + 3;

        while (itr != bookinfos.end())
        {
            authors.push_back(*itr);
            itr++;
        }

        Book book(title, publisher, date, authors);
        tmpbooklist.push_back(book);
    }

    bookshelf.setBookshelf(tmpbooklist);
}

void modifyBooks()
{

}
    
void showBook(Book book)
{
    std::cout << book.getTitle() << std::endl;
    std::cout << book.getPublisher() << std::endl;
    std::cout << book.getDate() << std::endl;

    for(auto author : book.getAuthors())
    {
        std::cout << author << std::endl;
    }
}