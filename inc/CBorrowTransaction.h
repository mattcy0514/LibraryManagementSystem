#ifndef CBORROWTRANSACTION_H_
#define CBORROWTRANSACTION_H_
#include "ITransaction.h"
#include "CBook.h"
#include "CUser.h"
class CBorrowTransaction : public ITransaction {
    private:
    CBook& book;
    CUser& user;
    public:
    CBorrowTransaction(CBook& book, CUser& user);
    ~CBorrowTransaction();
    void execute() override;
};
#endif