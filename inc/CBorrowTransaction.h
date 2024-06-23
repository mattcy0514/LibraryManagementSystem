#ifndef CBORROWTRANSACTION_H_
#define CBORROWTRANSACTION_H_
#include "CBook.h"
#include "CUser.h"
#include "ITransaction.h"
class CBorrowTransaction : public ITransaction
{
  private:
  CBook& book;
  CUser& user;

  public:
  CBorrowTransaction(CBook& book, CUser& user);
  ~CBorrowTransaction();
  CBook& getBook();
  CUser& getUser();
  void execute() override;
};
#endif