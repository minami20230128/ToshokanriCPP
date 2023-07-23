#include "bookshelf.h"
#include "main.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/algorithm/string.hpp>

//コンパイル方法　g++ -std=c++17 main.cpp -o 実行ファイル名（何でもいい）
//git push ToshokanriCPP main


int main()
{
    while(1)
    {
        int number = menu();
        switch(number)
        {
            case 1:
                showAllBooks();
                break;
            case 2:
                showAllBooksByAuthor();
                break;
            case 3:
                searchBooksByTitle();
                break;
            case 4:
                searchBooksByAuthor();
                break;
            case 5:
                addBooks();
                break;
            case 6:
                deleteBooks();
                break;
            case 7:
                saveBooks();
                break;
            case 8:
                loadBooks();
                break;
            case 9:
                modifyBooks();
                break;
        }
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
    for(auto&& book : tmpbooklist)
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
    std::cout << "書籍の冊数を入力してください。" << std::endl;
    int index;
    std::cin >> index;
    std::string title, publisher, date;
    std::vector<std::string> authors;
    std::vector<Book> books;

    for(int i = 0; i < index; i++)
    {
        std::cout << "書籍の題名を入力してください。" << std::endl;
        
        std::cin >> title;
        std::cout << "書籍の出版社名を入力してください。" << std::endl;
        std::string publisher;
        std::cin >> publisher;
        std::cout << "書籍の出版年月日を入力してください。" << std::endl;
        std::string date;
        std::cin >> date;
        std::cout << "書籍の著者の人数を入力してください。" << std::endl;
        int authornumber;
        std::cin >> authornumber;
        
        for(int i = 0; i < authornumber; i++)
        {
            std::cout << "書籍の著者を入力してください。" << std::endl;
            std::string author;
            std::cin >> author;
            authors.push_back(author);
        }

        Book book(title, publisher, date, authors);
        books.push_back(book);
    }

    bookshelf.setBookshelf(books);
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
    std::cout << "保存するファイル名を入力してください。" << std::endl;
    std::string filename;
    std::cin >> filename;
    auto tmpbooklist = bookshelf.getBookshelf();
    std::ofstream ofs(filename);

    if(!ofs)
    {
        std::cout << "ファイルが開けませんでした。" << std::endl;
    }
    for(auto&& book : tmpbooklist)
    {
        ofs << "書籍名," << book.getTitle() << ",出版社名," << book.getPublisher() << ",出版年月日," << book.getDate() << ",著者";
        for(auto&& author : book.getAuthors())
        {
            ofs << "," << author;
        }
        ofs << std::endl;
    }

    ofs.close();
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

        std::string title = bookinfos[1];
        std::string publisher = bookinfos[3];
        std::string date = bookinfos[5];

        auto authoritr = bookinfos.begin() + 7;

        while (authoritr != bookinfos.end())
        {
            authors.push_back(*authoritr);
            authoritr++;
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