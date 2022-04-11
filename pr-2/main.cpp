#include <limits>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "book.h"
#include <fstream>
#include <stdio.h>
#include <algorithm>


struct CheapReturn{
        std::string author;
        double cheapest;
        int no_of_pages;
};


void ReadData(std::string file, std::string &student_name,Book books[], int &nc);
void WriteMainData(std::string file, std::string student_name,Book books[], int nc);
void WriteCalcData(std::string file, std::string result); 
CheapReturn CheapestBook(Book books[], std::string student_name,int nc,bool write);
void SumAllBooks(Book books[], std::string student_name,int nc);
CheapReturn CheapestRent(Book books[],Book books_1[],std::string student_name, std::string student_name_1,int nc, int nc_1,bool write);
void PagesLessThanCheapest(Book books[], Book books_1[],Book ReturnBook[], std::string student_name, std::string student_name_1,int nc, int nc_1);

int main(){
        const int arr_size =100;
        Book books[arr_size],books_1[arr_size],ReturnBook[arr_size*2];
        std::string file;
        int nc,nc_1; std::string student_name, student_name_1;
        
        ReadData("Data.txt",student_name,books,nc);
        ReadData("Data2.txt",student_name_1,books_1,nc_1);
        
        std::ofstream("Result.txt",std::ofstream::trunc);
        WriteMainData("Result.txt",student_name,books,nc);
        WriteMainData("Result.txt",student_name_1,books_1,nc_1);


        //cheapest book and sum of all books for first student
        CheapestBook(books,student_name,nc,true);
        SumAllBooks(books, student_name,nc);

        //cheapest book and sum of all books for second student
        CheapestBook(books_1,student_name_1,nc_1,true);
        SumAllBooks(books_1, student_name_1,nc_1);

       //Cheapest book rented
     CheapestRent(books,books_1,student_name,student_name_1,nc,nc_1,true);

     //Create Collection of books with less pages that the cheapest book
    PagesLessThanCheapest(books, books_1,ReturnBook,student_name,student_name_1,nc,nc_1);
        return 0;
}

void PagesLessThanCheapest(Book books[], Book books_1[], Book ReturnBook[], std::string student_name, std::string student_name_1,int nc,int nc_1){
int pages_cheap = CheapestRent(books,books_1,student_name,student_name_1,nc,nc_1,false).no_of_pages;
std::string author;
int no_of_pages;
int count=-1;
double price;
for(int i=0;i<nc;i++){

        if(books[i].getNoPages()<pages_cheap){
            author = books[i].getAuthor();
            ReturnBook[i].setAuthor(author);
            price = books[i].getPrice();
            ReturnBook[i].setPrice(price);
            no_of_pages = books[i].getNoPages();
            ReturnBook[i].setNoPages(no_of_pages);
            count += 1;
        }
}

for(int i=0;i<nc_1;i++){

        if(books_1[i].getNoPages()<pages_cheap){
            author = books_1[i].getAuthor();
            ReturnBook[count].setAuthor(author);
            price = books_1[i].getPrice();
            ReturnBook[count].setPrice(price);
            no_of_pages = books_1[i].getNoPages();
            ReturnBook[count].setNoPages(no_of_pages);
            count += 1;
        }
}
    std::ofstream fd("Result.txt",std::ios::app);
    fd.setf(std::ios::fixed); fd.setf(std::ios::left); 

fd << "\nList of Books with pages less than the cheapest book: \n";
fd << "---------------------------------------------\n";
fd << "|    Author   |   No of Pages  |   Price    | \n";
fd << "---------------------------------------------\n";
        for (int i=0; i<count; i++){
fd << "|   " << std::setw(15) << ReturnBook[i].getAuthor() << " |   " << std::setprecision(1) << std::setw(5) << ReturnBook[i].getNoPages() << "   |   "  <<std::setw(6)<< ReturnBook[i].getPrice() << " |   "  << std::endl;
        }
fd << "---------------------------------------------\n"<<std::endl;
        fd.close();
    }


CheapReturn CheapestRent(Book books[],Book books_1[],std::string student_name, std::string student_name_1,int nc, int nc_1, bool write){
    double cheapest = 0.0;std::string result;
    CheapReturn cheap_1 = CheapestBook(books,student_name,nc,false);
    CheapReturn cheap_2 = CheapestBook(books_1,student_name_1,nc_1,false);
 if (cheap_1.cheapest<cheap_2.cheapest){
        cheapest = cheap_1.cheapest;
  result = "\nThe cheapest was book borrowed by " + student_name+" written by " + cheap_1.author + " and costs " + std::to_string(cheapest) +"\n";
   if (write){WriteCalcData("Result.txt",result);}
  return{"",0.0,cheap_1.no_of_pages};
 }
 else if(cheap_1.cheapest==cheap_2.cheapest){   
 result = "\nBoth students borrowed a book that was of the same price which was the cheapest \nStudent 1: \n Name: " + student_name+ "\nAuthor: " + cheap_1.author + "\n Cost: "+std::to_string(cheap_1.cheapest) +"\nStudent 2: \n Name: " + student_name+ "\nAuthor: " + cheap_2.author + "\n Cost: "+std::to_string(cheap_2.cheapest) + "\n";
   if (write){WriteCalcData("Result.txt",result);}
  return{"",0.0,std::min(cheap_1.no_of_pages,cheap_2.no_of_pages)};
 }
 else{
 cheapest = cheap_2.cheapest;
 result = "\nThe cheapest book was borrowed by " + student_name_1+" written by " + cheap_2.author + " and costs " + std::to_string(cheapest) +"\n";
   if (write){WriteCalcData("Result.txt",result);}
  return{"",0.0,cheap_2.no_of_pages};
}
    return {"",0.0,0};
}

CheapReturn CheapestBook(Book books[], std::string student_name,int nc, bool write){
        double cheapest = std::numeric_limits<double>::max();
        bool more=false;int no_of_pages;
        std::string name, result;
        for(int i=0;i<nc;i++){
            if(books[i].getPrice() < cheapest){
                cheapest = books[i].getPrice();
                name = books[i].getAuthor();
                no_of_pages = books[i].getNoPages();
            }
            else if(books[i].getPrice() == cheapest){
                    more = true;
                    cheapest = books[i].getPrice();
                    name += " ," +books[i].getAuthor()+", ";
                    no_of_pages = books[i].getNoPages();
            } 

        }

        if (write){

                if (more){

                        result = "\n More than one book has the same cheapest price. The authors are: " + name + "and each costs " + std::to_string(cheapest)+"\n";
                }
                else{
                result = "\nThe cheapest book borrowed by " + student_name+" was written by " + name + " and costs " + std::to_string(cheapest) +"\n";
                }
                WriteCalcData("Result.txt",result);
        }
                        return {name,cheapest,no_of_pages};


}
void SumAllBooks(Book books[], std::string student_name,int nc){
      int sum_ = 0;
      for(int i=0;i<nc;i++){
      sum_ += books[i].getPrice();    
      }
      std::string result = "\nThe sum of all prices for books borrowed by " + student_name + " is " + std::to_string(sum_) + "\n";
      WriteCalcData("Result.txt",result);
}

void WriteCalcData(std::string file, std::string result){
        std::ofstream fd(file, std::ios::app);
        fd << std::setprecision(2)<<result;
        fd.close();
}


void ReadData(std::string file,std::string &student_name, Book books[], int &nc){
        std::ifstream fd(file);
        std::string first_name, last_name;int nop;double _price;
fd >> nc; fd.ignore();
fd>> first_name; fd>> last_name; fd >> std::ws;
student_name = first_name + " " + last_name;
for (int i=0; i<nc; i++){

        fd>> first_name; fd>> last_name; fd >> std::ws; last_name.pop_back();
         books[i].setAuthor(first_name + " " + last_name);
        fd >> nop; books[i].setNoPages(nop);
        fd >> _price; books[i].setPrice(_price);
        fd.ignore();
}
fd.close();
}

void WriteMainData(std::string file, std::string student_name,Book books[], int nc){
        std::ofstream ft(file,std::ios::app);
ft.setf(std::ios::fixed); ft.setf(std::ios::left);
ft << "Number of books: " << nc << std::endl;
ft << "Name of Student: " << student_name << std::endl;
ft << "List of Books: \n";
ft << "---------------------------------------------\n";
ft << "|    Author   |   No of Pages  |   Price    | \n";
ft << "---------------------------------------------\n";
        for (int i=0; i<nc; i++){
ft << "|   " << std::setw(15) << books[i].getAuthor() << " |   " << std::setprecision(1) << std::setw(5) << books[i].getNoPages() << "   |   "  <<std::setw(6)<< books[i].getPrice() << " |   "  << std::endl;
        }
ft << "---------------------------------------------\n"<<std::endl;
        ft.close();
}
