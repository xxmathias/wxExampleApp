    //Book: Has attributes for title, author, and isCheckedOut (a boolean).

#include <string>


#ifndef BOOK_HPP
#define BOOK_HPP

class Book {
    public:
        Book(std::string title, std::string author, bool isCheckoutOut) : title_(title), author_(author), isCheckedOut_(isCheckoutOut) {}
        ~Book() {};
        std::string getTitle() {return title_;}
        std::string getAuthor() {return author_;}
        bool isCheckedOut() {return isCheckedOut_;}

    private:
        std::string title_;
        std::string author_;
        bool isCheckedOut_;
};

#endif