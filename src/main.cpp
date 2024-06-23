#include <iostream>
#include <vector>

#include "CBook.h"
#include "CBorrowTransaction.h"
#include "CLibrary.h"
#include "CReturnTransaction.h"
#include "CUser.h"

int main()
{
  CLibrary& library = CLibrary::getInstance();

  // Create books
  CBook book1("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
  CBook book2("1984", "George Orwell", "9780451524935");

  // Add books to the library
  library.addBook(book1);
  library.addBook(book2);

  // Create users
  CUser user1(1, "Alice");
  CUser user2(2, "Bob");

  // Add users to the library
  library.addUser(user1);
  library.addUser(user2);

  // Borrow book transactions
  CBorrowTransaction borrowTransaction1(book1, user1);
  CBorrowTransaction borrowTransaction2(book2, user2);

  // Return book transactions
  CReturnTransaction returnTransaction1(book1, user1);
  CReturnTransaction returnTransaction2(book2, user2);

  // Process transactions in the library
  library.processTransaction(&borrowTransaction1);
  library.processTransaction(&borrowTransaction2);
  library.processAllTransactions();

  library.processTransaction(&returnTransaction1);
  library.processTransaction(&returnTransaction2);
  library.processAllTransactions();

  // Display books and users (assuming overloaded operator<< for Book and User)
  std::cout << "Book1 Details:\n" << book1 << std::endl;
  std::cout << "Book2 Details:\n" << book2 << std::endl;

  std::cout << "User1 Details:\n" << user1 << std::endl;
  std::cout << "User2 Details:\n" << user2 << std::endl;

  return 0;
}
