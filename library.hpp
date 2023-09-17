
    //Library: Has methods for addBook(), addPatron(), checkoutBook() (a patron checks out a book), and returnBook() (a patron returns a book). 
    //It should also have a list of all books and all patrons.


#include <string>
#include <vector>
#include "book.hpp"
#include "patron.hpp"

#ifndef LIBRARY_HPP
#define LIBRARY_HPP


class Library {
public:
    Library() : allBooks_(), allPatrons_() {}
    Library(std::vector<Book*> allBooks, std::vector<Patron*> allPatrons) : allBooks_(allBooks), allPatrons_(allPatrons) {} 
    ~Library() {}

    void addBook(Book* newBook);
    void addPatron(Patron* newPatron);
    void checkoutBook(Book* wantedBook, Patron* targetPatron);
    void returnBook(Book* bookToReturn, Patron* fromPatron);
    std::vector<Book*> getAllBooks() { return allBooks_; }
    std::vector<Patron*> getAllPatrons() { return allPatrons_; }
    void removeBook(Book* book);
    bool isBookBorrowed(Book* targetBook);

private:
    std::vector<Book*> allBooks_;
    std::vector<Patron*> allPatrons_;
};

class DigitalLibrary : public Library {
public:
    DigitalLibrary() : Library(), url_("") {}  // Default constructor
    DigitalLibrary(std::vector<Book*> allBooks, std::vector<Patron*> allPatrons, std::string url) 
        : Library(allBooks, allPatrons), url_(url) {}

    std::string getUrl() const {
        return url_;
    }

private:
    std::string url_;
};


#endif