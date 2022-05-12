#include "book.h"

//function to set author provided externally to the private variable
void Book::setAuthor(std::string _author){  author = _author; }

//function to set no of pages provided externally to the private variable
void Book::setNoPages(int nop){ no_of_pages = nop; }

//function to set price provided externally to the private variable
void Book::setPrice(double _price){ price = _price; }

//function to get private variables externally
std::string Book::getAuthor(){ return author;  }
int Book::getNoPages(){return no_of_pages;}
double Book::getPrice(){ return price; }



