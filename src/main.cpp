#include <iostream>

#include "CUser.h"
#include "CBook.h"

int main()
{
  CBook book1("Book1", "Author1", "ISBN-1111");
  CUser user1(1, "Matt Chiang");
  user1.borrowBook(book1);

  for (auto& book : user1.getBorrowedBooks()) {
    std::cout << book << std::endl;
  }
  user1.returnBook(book1);
  for (auto& book : user1.getBorrowedBooks()) {
    std::cout << book << std::endl;
  }
  return 0;
}
