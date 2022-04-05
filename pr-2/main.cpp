#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "book.h"
#include <fstream>
#include <stdio.h>

void ReadData(std::string file, std::string &student_name,Book books[], int &nc);
void WriteData(std::string file, std::string student_name,Book books[], int nc);
int main(){
        Book books[10];
        std::string file;
        int nc; std::string student_name;
        std::cout<< "Please Enter the name(or path) of the file containing the student data:";
        std::cin >> file;
        
        std::ofstream("Result.txt");
        ReadData(file,student_name,books,nc);
        WriteData("Result.txt",student_name,books,nc);

        return 0;
}



void ReadData(std::string file,std::string &student_name, Book books[], int &nc){
        std::ifstream fd(file);
        std::string first_name, last_name;
fd >> nc; fd.ignore();
fd>> first_name; fd>> last_name; fd >> std::ws;
student_name = first_name + " " + last_name;
for (int i=0; i<nc; i++){

        fd>> first_name; fd>> last_name; fd >> std::ws; last_name.pop_back();
         books[i].author = first_name + " " + last_name;
       // std::getline(fd,books[i].author,','); fd >> std::ws;
        fd >> books[i].no_of_pages;
        fd >> books[i].price;
        fd.ignore();
}
fd.close();
}

void WriteData(std::string file, std::string student_name,Book books[], int nc){
        std::ofstream ft(file, std::ios::app);
ft.setf(std::ios::fixed); ft.setf(std::ios::left);
ft << "Number of books: " << nc << std::endl;
ft << "Name of Student: " << student_name << std::endl;
ft << "List of Books: \n";
ft << "---------------------------------------------\n";
ft << "|    Author   |   No of Pages  |   Price    | \n";
ft << "---------------------------------------------\n";
        for (int i=0; i<nc; i++){
ft << "|   " << std::setw(15) << books[i].author << " |   " << std::setprecision(1) << std::setw(5) << books[i].no_of_pages << "   |   "  <<std::setw(6)<< books[i].price << " |   "  << std::endl;
        }
ft << "---------------------------------------------\n";
        ft.close();
}
