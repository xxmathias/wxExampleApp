#ifndef PATRON_HPP
#define PATRON_HPP

#include <string>
#include <vector>
#include <algorithm>
#include "book.hpp"

class Patron {
public:
    Patron(std::string name) : name_(name) {}
    ~Patron() {}

    void addBook(Book* newBook) {
        borrowedBooks_.push_back(newBook);
    }

    std::string getName() const {
        return name_;
    }

    std::vector<Book*> getBorrowedBooks() const {
        return borrowedBooks_;
    }

    void removeBook(Book* bookToRemove) {
        auto it = std::find(borrowedBooks_.begin(), borrowedBooks_.end(), bookToRemove);
        if (it != borrowedBooks_.end()) {
            borrowedBooks_.erase(it);
        }
    }


private:
    std::string name_;
    std::vector<Book*> borrowedBooks_;
};

#endif
