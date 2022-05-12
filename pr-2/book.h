#pragma once
#include <string>

class Book{
//private variables for internal calculations
        private:
            std::string author;
            int no_of_pages;
            double price;
//public methods that can be accessed from outside the class to access the 
//private variables.
       public:
            void setAuthor(std::string _author);
            void setPrice(double _price);
            void setNoPages(int nop);

            std::string getAuthor();
            int getNoPages();
            double getPrice();

};
