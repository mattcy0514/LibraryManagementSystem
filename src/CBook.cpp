#include "CBook.h"
CBook::CBook(const std::string title, const std::string author,
             const std::string ISBN)
    : title(title), author(author), ISBN(ISBN), status(true)
{
}
CBook::~CBook()
{
}
CBook::CBook(const CBook& other)
    : title(other.title),
      author(other.author),
      ISBN(other.ISBN),
      status(other.status)
{
}

CBook::CBook(CBook&& other) noexcept
    : title(std::move(other.title)),
      author(std::move(other.author)),
      ISBN(std::move(other.ISBN)),
      status(other.status)
{
  other.title  = "";
  other.author = "";
  other.ISBN   = "";
  other.status = false;
}

CBook& CBook::operator=(const CBook& other)
{
  if (this != &other) {
    this->title  = other.title;
    this->author = other.author;
    this->ISBN   = other.ISBN;
    this->status = other.status;
  }
  return *this;
}

CBook& CBook::operator=(CBook&& other) noexcept
{
  if (this != &other) {
    this->title  = std::move(other.title);
    this->author = std::move(other.author);
    this->ISBN   = std::move(other.ISBN);
    this->status = false;
  }
  return *this;
}

std::ostream& operator<<(std::ostream& os, CBook& book)
{
  os << "Title: " << book.getTitle() << std::endl;
  os << "Author: " << book.getAuthor() << std::endl;
  os << "ISBN: " << book.getISBN() << std::endl;
  os << "Available: " << (book.isAvailabe() ? "Yes" : "No") << std::endl;
  return os;
}

std::string CBook::getTitle() const
{
  return this->title;
}
std::string CBook::getAuthor() const
{
  return this->author;
}
std::string CBook::getISBN() const
{
  return this->ISBN;
}

bool CBook::isAvailabe() const
{
  return this->status;
}

void CBook::setTitle(std::string title)
{
  this->title = title;
}

void CBook::setAuthor(std::string author)
{
  this->author = author;
}

void CBook::setISBN(std::string ISBN)
{
  this->ISBN = ISBN;
}

void CBook::borrowBook()
{
  if (this->status) {
    this->status = false;
    std::cout << "Book is borrowed" << std::endl;
  }
  else {
    std::cout << "Book cannot be borrowed" << std::endl;
  }
}
void CBook::returnBook()
{
  if (!this->status) {
    this->status = true;
    std::cout << "Book is returned" << std::endl;
  }
  else {
    std::cout << "Book cannot be returned" << std::endl;
  }
}