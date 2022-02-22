#include "coin.h"
#include "cylinder.h"
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

//prototype of functions so the functions can stay below the main but still run
void ReadData(string file);
void WriteData(string file);

int main()
{
int number_of_coins;
	Coin c1;
	Cylinder cy1;

	cout << "Working" << endl;
	return 0;
}


void ReadData(string file){
ifstream fd(file);
}

void WriteData(string file){
ofstream fd(file);
}
