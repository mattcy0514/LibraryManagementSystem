#include "CUser.h"

CUser::CUser(const int userID, const std::string name):
    userID(userID), name(name), borrowedBooks({}), reservations({}) {

}
CUser::~CUser() {

}
CUser::CUser(const CUser& other):
    userID(other.userID), name(other.name) {

}
CUser::CUser(CUser&& other) noexcept:
    userID(other.userID), name(std::move(other.name)), borrowedBooks(std::move(other.borrowedBooks)), reservations(std::move(other.reservations)) {
        other.userID = 0;
        other.name = "";
        other.borrowedBooks = {};
        other.reservations = {};
}

CUser& CUser::operator=(const CUser& other) {
    if (this != &other) {
        this->userID = other.userID;
        this->name = other.name;
        this->borrowedBooks = other.borrowedBooks;
        this->reservations = other.reservations;
    }
    return *this;
}
CUser& CUser::operator=(CUser&& other) noexcept {
    if (this != &other) {
        this->userID = other.userID;
        this->name = std::move(other.name);
        this->borrowedBooks = std::move(other.borrowedBooks);
        this->reservations = std::move(other.reservations);
        other.userID = 0;
        other.name = "";
        other.borrowedBooks = {};
        other.reservations = {};
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, CUser& user) {
    os << "UserID: " << user.getUserID() << std::endl;
    os << "Name: " << user.getName() << std::endl;
    return os;
}

int CUser::getUserID() const {
    return this->userID;
}

std::string CUser::getName() const {
    return this->name;
}

std::vector<std::reference_wrapper<CBook>> CUser::getBorrowedBooks() {
    return this->borrowedBooks;
}

std::vector<std::reference_wrapper<CBook>> CUser::getReservations() {
    return this->reservations;
}

void CUser::setUserID(int userID) {
    this->userID = userID;
}
void CUser::setName(std::string name) {
    this->name = name;
}
void CUser::borrowBook(CBook& book) {
    book.borrowBook();
    this->borrowedBooks.push_back(book);
}
void CUser::returnBook(CBook& book) {
    book.returnBook();
    auto it = std::find_if(this->borrowedBooks.begin(), this->borrowedBooks.end(), [book](CBook& found_book) {
        return book.getISBN() == found_book.getISBN();
    });
    if (it != this->borrowedBooks.end()) {
        this->borrowedBooks.erase(it);
    }
}