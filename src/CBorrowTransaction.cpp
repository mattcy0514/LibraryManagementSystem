#include "CBorrowTransaction.h"
CBorrowTransaction::CBorrowTransaction(CBook& book, CUser& user)
    : book(book), user(user)
{
}
CBorrowTransaction::~CBorrowTransaction()
{
}
void CBorrowTransaction::execute()
{
  user.borrowBook(book);
}