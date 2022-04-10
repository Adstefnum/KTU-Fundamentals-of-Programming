#pragma once
#include <string>

class Book{

        private:
            std::string author;
            int no_of_pages;
            double price;

       public:
            void setAuthor(std::string _author);
            void setPrice(double _price);
            void setNoPages(int nop);

            std::string getAuthor();
            int getNoPages();
            double getPrice();

};
