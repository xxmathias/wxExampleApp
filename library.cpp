#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "book.hpp"
#include "patron.hpp"
#include "library.hpp"

bool Library::isBookBorrowed(Book* targetBook) {
    for (const auto& patron : allPatrons_) {
        auto borrowedBooks = patron->getBorrowedBooks();
        if (std::find(borrowedBooks.begin(), borrowedBooks.end(), targetBook) != borrowedBooks.end()) {
            return true;
        }
    }
    return false;
}

void Library::returnBook(Book* bookToReturn, Patron* fromPatron) {
    auto borrowedBooks = fromPatron->getBorrowedBooks();
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), bookToReturn);
    
    if (it != borrowedBooks.end()) {
        fromPatron->removeBook(bookToReturn);
        allBooks_.push_back(bookToReturn);
        std::cout << "\nBook titled \"" << bookToReturn->getTitle() << "\" returned by " << fromPatron->getName() << ".\n";
    } else {
        std::cout << "\nError: \"" << bookToReturn->getTitle() << "\" not checked out by " << fromPatron->getName() << ".\n";
    }
}

void Library::addBook(Book* newBook) {
    allBooks_.push_back(newBook);
    std::cout << "\nBook titled \"" << newBook->getTitle() << "\" added to the library.\n";
}

void Library::addPatron(Patron* newPatron) {
    allPatrons_.push_back(newPatron);
    std::cout << "\nWelcome, " << newPatron->getName() << "! You are now registered with our library.\n";
}

void Library::checkoutBook(Book* wantedBook, Patron* targetPatron) {
    auto it = std::find(allBooks_.begin(), allBooks_.end(), wantedBook);
    
    if (it != allBooks_.end()) {
        if (!isBookBorrowed(wantedBook)) {
            targetPatron->addBook(wantedBook);
            allBooks_.erase(it);
            std::cout << "\n" << targetPatron->getName() << " has checked out the book titled \"" << wantedBook->getTitle() << "\".\n";
        } else {
            std::cout << "\nError: The book titled \"" << wantedBook->getTitle() << "\" is already borrowed.\n";
        }
    } else {
        std::cout << "\nError: The book titled \"" << wantedBook->getTitle() << "\" does not exist in our library.\n";
    }
}
