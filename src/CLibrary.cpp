#include "CLibrary.h"

CLibrary::CLibrary()
{
}

CLibrary& CLibrary::getInstance()
{
  static CLibrary instance;
  return instance;
}

void CLibrary::addBook(CBook& book)
{
  books.push_back(book);
}

void CLibrary::removeBook(std::string& ISBN)
{
  books.erase(std::find_if(books.begin(), books.end(), [&](const CBook& book) {
    return book.getISBN() == ISBN;
  }));
}

void CLibrary::addUser(CUser& user)
{
  users.push_back(user);
}

void CLibrary::removeUser(int userID)
{
  users.erase(std::find_if(users.begin(), users.end(), [&](const CUser& user) {
    return user.getUserID() == userID;
  }));
}

void CLibrary::processTransaction(ITransaction* transaction)
{
  if (CBorrowTransaction* borrowTransaction =
          dynamic_cast<CBorrowTransaction*>(transaction)) {
    transactions.push_back(borrowTransaction);
  } else if (CReturnTransaction* returnTransaction =
                 dynamic_cast<CReturnTransaction*>(transaction)) {
    transactions.push_back(returnTransaction);
  }
}

void CLibrary::processAllTransactions()
{
  for (auto transaction : transactions) {
    transaction->execute();
  }
  transactions.clear();
}
std::vector<CBook> CLibrary::searchBooks(const std::string& query,
                                         const std::string& type)
{
  std::vector<CBook> results;
  // Implement search logic based on query and type
  // Example: search by title, author, ISBN, etc.
  for (const auto& book : books) {
    if (book.get().getTitle() == query || book.get().getAuthor() == query ||
        book.get().getISBN() == query) {
      results.push_back(book);
    }
  }
  return results;
}
