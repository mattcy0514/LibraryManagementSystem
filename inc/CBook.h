#ifndef CBOOK_H_
#define CBOOK_H_
#include <iostream>
class CBook
{
  private:
  std::string title;
  std::string author;
  std::string ISBN;
  bool        status;

  public:
  CBook(const std::string title, const std::string author,
        const std::string ISBN);
  ~CBook();
  CBook(const CBook& other);
  CBook(CBook&& other) noexcept;
  CBook&               operator=(const CBook& other);
  CBook&               operator=(CBook&& other) noexcept;
  friend std::ostream& operator<<(std::ostream& os, CBook& book);
  std::string          getTitle() const;
  std::string          getAuthor() const;
  std::string          getISBN() const;
  bool                 isAvailabe() const;
  void                 setTitle(std::string title);
  void                 setAuthor(std::string author);
  void                 setISBN(std::string ISBN);
  void                 borrowBook();
  void                 returnBook();
};
#endif