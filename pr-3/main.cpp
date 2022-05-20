#include <iostream>
#include "company.h"
#include <string>
#include <fstream>
#include <iomanip> 

const char dataFile[] = "Data.txt";
const char resFile[] = "Result.txt";

void Read(Company & company);
void Print(Company & company, std::string tableName);

int main(){
    Company _company;
    Read(_company);
    Print(_company, "Initial Data");
    return 0;
}


void Read(Company & company){
    std::ifstream fd(dataFile);
    Subscriber sb;
    std::string _surname, _address, _newsPCode;
    int _begPeriod, _lenPeriod, _noNewsPr;
    bool hasSpace = true;
    int noSub = 0;

    while (!fd.eof() && hasSpace) { 
        getline(fd,_surname, ',');  fd >> std::ws; 
        getline(fd, _address, ',');  fd >> std::ws;
        getline(fd, _newsPCode, ',');  fd >> std::ws;
        fd >> _begPeriod;
        fd >> _lenPeriod;
        fd >> _noNewsPr;
        noSub++;
 if(0<_begPeriod && _begPeriod<=12 && 0<_lenPeriod && _lenPeriod<=12 ){

       sb.Set(_surname,  _address,  _newsPCode, _noNewsPr,  _begPeriod, _lenPeriod);
       fd.ignore('\n');

 }

 else{
     std::cout<< "Your data has negatives or other invalid data types. Please correct it." << std::endl;
     exit(1);
 }
        if (noSub - 1 < Company::CMax ){
            company.Set(sb);
               std::cout <<_surname<<  _address<<  _newsPCode<< _noNewsPr<<  _begPeriod<< _lenPeriod;
               std::cout << company.Get();
               std::cout<<noSub;
        
        }

        else {
            hasSpace = false;
        }  

    fd.close();
}}

void Print(Company & company, std::string tableHeader){
    std::ofstream fr(resFile,std::ofstream::trunc|std::ofstream::out);
    fr.setf(std::ios::fixed); fr.setf(std::ios::left);
    fr << "-------------------------------------------------------------------------------------\n";
    fr << std::setw(30) << tableHeader << std::endl;
    fr << "-------------------------------------------------------------------------------------\n";
    fr << " Surname     Address     NewsPaperCode  Period Begins   Period Length  Number of NewsPapers\n";
    fr << "-------------------------------------------------------------------------------------\n";
    for (int i = 0; i < company.Get(); i++)
    fr << company.Get(i).Print();
    fr << "--------------------------------------------------------------------------------------\n\n\n";
    fr.close();
}
