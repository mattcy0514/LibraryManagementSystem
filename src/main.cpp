#include "CBook.h"
#include "CUser.h"
#include "CReturnTransaction.h"
#include "CBorrowTransaction.h"
#include <iostream>

int main() {
    CBook book1("Book1", "Author1", "ISBN-1111");
    CUser user1(1, "User1");

    std::cout << "Before borrowing:\n" << book1 << std::endl;

    // Borrow transaction
    CBorrowTransaction borrowTrans(book1, user1);
    borrowTrans.execute();

    std::cout << "After borrowing:\n" << book1 << std::endl;

    // Return transaction
    CReturnTransaction returnTrans(book1, user1);
    returnTrans.execute();

    std::cout << "After returning:\n" << book1 << std::endl;

    return 0;
}
