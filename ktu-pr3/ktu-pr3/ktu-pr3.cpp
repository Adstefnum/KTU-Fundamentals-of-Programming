#include <iostream>
#include "company.h"
#include <string>
#include <fstream>
#include <iomanip> 

const char dataFile[] = "Data.txt";
const char resFile[] = "Result.txt";

void Read(Company & company);
void Print(Company & company, std::string tableHeader);
void PrintOrderedMoreThanOneMonth(Company & company, std::string tableHeader);
void PrintOrderedMost(Company & company, std::string tableHeader);


int main() {
	Company _company;

	std::ofstream("Result.txt", std::ofstream::trunc);
	Read(_company);
	Print(_company, "Initial Data");

	_company.Sort();
	PrintOrderedMoreThanOneMonth(_company, "People who ordered more than one month");
	PrintOrderedMost(_company, "Person who ordered most");
	return 0;
}


void Read(Company & company) {
	std::ifstream fd(dataFile);
	Subscriber sb;
	std::string line, _surname, _address, _newsPCode;
	int _begPeriod, _lenPeriod, _noNewsPr;
	bool hasSpace = true;
	int noSub = 0;
	
	while (!fd.eof() && hasSpace) {

		
		getline(fd, _surname, ',');  fd >> std::ws;
		getline(fd, _address, ',');  fd >> std::ws;
		getline(fd, _newsPCode, ',');  fd >> std::ws;
		fd >> _begPeriod;
		fd >> _lenPeriod;
		fd >> _noNewsPr;
		noSub += 1;

		if (0 < _begPeriod && _begPeriod <= 12 && 0 < _lenPeriod && _lenPeriod <= 12 && _begPeriod+_lenPeriod<=13) {

			sb.Set(_surname, _address, _newsPCode, _noNewsPr, _begPeriod, _lenPeriod);

		}

		else {
			std::cout << "Your data has negatives or other invalid data types. Please correct it." << std::endl;
			exit(1);
		}
		if (noSub - 1 < Company::CMax) {
			company.Set(sb);
		}

		else {
			hasSpace = false;
		}
	}

	fd.close();
}

void Print(Company & company, std::string tableHeader) {
	std::string  dash(100, '-');
	std::ofstream fr(resFile, std::ios::app);
	fr.setf(std::ios::fixed); fr.setf(std::ios::left);
	fr << dash + "\n";
	fr << std::setw(30) << tableHeader << std::endl;
	fr << dash + "\n";
	fr << " Surname     Address           NewsPaperCode  Period Begins   Period Length  Number of NewsPapers\n";
	fr << dash + "\n";
	for (int i = 0; i < company.Get(); i++) {
		fr << company.Get(i).Print();
		fr << dash + "\n";
	}

	fr << "\n\n\n\n";
	fr.close();
}


void PrintOrderedMoreThanOneMonth(Company & company, std::string tableHeader) {
	std::string  dash(100, '-');
	std::ofstream fr(resFile, std::ios::app);
	fr.setf(std::ios::fixed); fr.setf(std::ios::left);
	fr << dash + "\n";
	fr << std::setw(30) << tableHeader << std::endl;
	fr << dash + "\n";
	fr << " Surname     Address          Months\n";
	fr << dash + "\n";
	for (int i = 0; i < company.Get(); i++) {
		fr << company.Get(i).OrderedMoreThanOneMonth();
		fr << dash + "\n";
	}
	fr << "\n\n\n\n";
	fr.close();
}

void PrintOrderedMost(Company & company, std::string tableHeader) {
	std::string  dash(100, '-');
	int index = company.OrderedMost();
	std::ofstream fr(resFile, std::ios::app);
	fr.setf(std::ios::fixed); fr.setf(std::ios::left);
	fr << dash + "\n";
	fr << std::setw(30) << tableHeader << std::endl;
	fr << dash + "\n";
	fr << " Surname     Address           NewsPaperCode  Period Begins   Period Length  Number of NewsPapers\n";
	fr << dash + "\n";
	fr << company.Get(index).Print();
	fr << dash + "\n";

	fr << "\n\n\n\n";
	fr.close();
}