#include "CReturnTransaction.h"
CReturnTransaction::CReturnTransaction(CBook& book, CUser& user):
    book(book), user(user) {

}
CReturnTransaction::~CReturnTransaction() {

}
void CReturnTransaction::execute() {
    user.returnBook(book);
}