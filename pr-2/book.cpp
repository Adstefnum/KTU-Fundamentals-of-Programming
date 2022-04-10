#include "book.h"

void Book::setAuthor(std::string _author){  author = _author; }

void Book::setNoPages(int nop){ no_of_pages = nop; }

void Book::setPrice(double _price){ price = _price; }

std::string Book::getAuthor(){ return author;  }
int Book::getNoPages(){return no_of_pages;}
double Book::getPrice(){ return price; }



