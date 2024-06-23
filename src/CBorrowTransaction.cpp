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
CBook& CBorrowTransaction::getBook() {
  return this->book;
}
CUser& CBorrowTransaction::getUser() {
  return this->user;
}