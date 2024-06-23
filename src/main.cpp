#include <iostream>

#include "CBook.h"
#include "CBorrowTransaction.h"
#include "CReturnTransaction.h"
#include "CUser.h"

int main()
{
  CBook book1("Book1", "Author1", "ISBN-1111");
  CUser user1(1, "User1");

  // Borrow transaction
  CBorrowTransaction borrowTrans(book1, user1);
  borrowTrans.execute();

  // Return transaction
  CReturnTransaction returnTrans(book1, user1);
  returnTrans.execute();

  return 0;
}
