#ifndef BOOK
#define BOOK

#include <string>

class Book{
    std::string title;
    std::string author;
    std::string ISBN;

    public:
    Book(std::string t, std::string a, std::string isbn);

    std::string getTitle();
    std::string getAuthor();
    std::string getISBN();

};

#endif
