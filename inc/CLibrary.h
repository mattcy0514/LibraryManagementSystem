#ifndef CLIBRARY_H_
#define CLIBRARY_H_

#include <string>
#include <vector>

#include "CBook.h"
#include "CBorrowTransaction.h"
#include "CReturnTransaction.h"
#include "CUser.h"

class CLibrary
{
  private:
  std::vector<std::reference_wrapper<CBook>> books;
  std::vector<std::reference_wrapper<CUser>> users;
  std::vector<ITransaction*>                 transactions;

  public:
  CLibrary();

  // Singleton instance
  static CLibrary& getInstance();

  void               addBook(CBook& book);
  void               removeBook(std::string& ISBN);
  void               addUser(CUser& user);
  void               removeUser(int userID);
  void               processTransaction(ITransaction* transaction);
  void               processAllTransactions();
  std::vector<CBook> searchBooks(const std::string& query,
                                 const std::string& type);
};

#endif  // CLIBRARY_H_
