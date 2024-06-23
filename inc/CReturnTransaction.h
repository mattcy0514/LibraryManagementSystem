#ifndef CRETURNTRANSACTION_H_
#define CRETURNTRANSACTION_H_
#include "ITransaction.h"
#include "CBook.h"
#include "CUser.h"
class CReturnTransaction : public ITransaction {
    private:
    CBook& book;
    CUser& user;
    public:
    CReturnTransaction(CBook& book, CUser& user);
    ~CReturnTransaction();
    void execute() override;
};
#endif