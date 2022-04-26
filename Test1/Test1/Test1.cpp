#include <iostream>
#include <string>
#include "Tree.h"
#include <fstream>
#include <iomanip>

//function prototypes or declarations
void ReadData(std::string fn, Tree T[], int &n);
void DisplayData(Tree T[], int n);
int Max(Tree T[], int n);
int Aver(Tree T[], int n);
int Many(Tree T[], int n);

int main()
{
	//class list and number integer declaration
	Tree T[100]; int n;

	//Read tree data
	ReadData("trees1.txt",T,n);

	//Display initial data
	DisplayData(T, n);

	//Display the height of the tallest tree
	std::cout << "The tallest tree has an height of " << Max(T, n) <<" metres"<< std::endl;

	//Display the average height of trees
	std::cout << "The average height of the trees is " << Aver(T, n) << " metres" << std::endl;

	//Display the number of trees with an height more than 30 metres
	std::cout << "The number of trees with an height taller than 30 metres is " << Many(T, n) << std::endl;
}

void ReadData(std::string fn, Tree T[], int &n) {
	std::ifstream fd(fn);
	std::string _name; double _height;
	fd >> n; fd.ignore();
	for (int i = 0; i < n; i++) {
		fd >> _name; T[i].setName(_name);
		fd >> _height; T[i].setHeight(_height);
		fd.ignore();
	}
	fd.close();
}

void DisplayData(Tree T[], int n) {
	std::cout << "\nNumber of Trees: " << n << std::endl;
	std::cout << "List of Trees: \n";
	std::cout << "-------------------------\n";
	std::cout << "|    Name   |   Height  | \n";
	std::cout << "-------------------------\n";
	for (int i = 0; i < n; i++) {
		std::cout << "|   " << std::setw(7) << T[i].getName() << " |   "
			 << std::setw(5) << T[i].getHeight() << "   |   " << std::endl;
	}
	std::cout << "-------------------------\n" << std::endl;
}

//Find the height of the tallest tree
int Max(Tree T[], int n){
	int max=0;
	for (int i = 0; i < n; i++) {
		if (T[i].getHeight() > max) {
			max = T[i].getHeight();
		}
	}
	return max;

}

//Find the average height of trees
int Aver(Tree T[], int n){
	int aver=0;
	for (int i = 0; i < n; i++) {
		aver += T[i].getHeight();
	}
	return aver;
}

//Find the number of trees with an height more than 30 metres
int Many(Tree T[], int n){
	int count = 0;
	for (int i = 0; i < n; i++) {
		if(T[i].getHeight()>30){
			count += 1;
		}	
	}
	return count;
}