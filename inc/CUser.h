#ifndef CUSER_H_
#define CUSER_H_
#include <iostream>
#include "CBook.h"
class CUser {
    private:
        int userID;
        std::string name;
        std::vector<std::reference_wrapper<CBook>> borrowedBooks;
        std::vector<std::reference_wrapper<CBook>> reservations;
    
    public:
        CUser(const int userID, const std::string name);
        ~CUser();
        CUser(const CUser& other);
        CUser(CUser&& other) noexcept;
        CUser& operator=(const CUser& other);
        CUser& operator=(CUser&& other) noexcept;
        friend std::ostream& operator<<(std::ostream& os, CUser& user);
        int getUserID() const;
        std::string getName() const;
        std::vector<std::reference_wrapper<CBook>> getBorrowedBooks();
        std::vector<std::reference_wrapper<CBook>> getReservations();
        void setUserID(int userID);
        void setName(std::string name);
        void borrowBook(CBook& book);
        void returnBook(CBook& book);
        void reserveBook(CBook& book);
        void cancelReservation(CBook& book);
};
#endif