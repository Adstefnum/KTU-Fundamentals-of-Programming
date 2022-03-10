#include <map>
#include "coin.h"
#include "cylinder.h"
#include <cmath>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>


using namespace std;

//prototype of functions so the functions can stay below the main but still run

void ReadData(string file, Coin coins[], int &nc);
void WriteData(string file, Coin coins[], int nc);
void  NoOfCoinsInCylinder(Coin coins[], int nc, Cylinder _Cylinder);
void ValueOfCoins(Coin coins[], int nc);
double calcCyVolume(double diameter, double height);

int main()
{
int number_of_coins;
	Coin coins[10];
    Cylinder _Cylinder;
    int nc;
    
   cout << "Enter the diameter then height of the cylinder:" ;
   cin >> _Cylinder.diameter >> _Cylinder.length;



   //creating an empty file 
    ofstream fd("Result.txt");
    fd.close();

    ReadData("Data.txt", coins, nc);
    ValueOfCoins(coins, nc);
    NoOfCoinsInCylinder(coins,nc, _Cylinder);
    WriteData("Result.txt", coins, nc);
    cout << "Done" <<endl;
	return 0;
}


void ReadData(string file, Coin coins[], int &nc){
ifstream fd(file);
fd >> nc; fd.ignore();
for (int i=0; i<nc; i++){
        getline(fd,coins[i].denomination,','); fd >> ws;
        coins[i].denomination.erase(
    std::remove(coins[i].denomination.begin(), coins[i].denomination.end(), '\"'),
    coins[i].denomination.end());
        fd >> coins[i].weight;
        fd >> coins[i].diameter;
        fd >> coins[i].thickness;
        fd.ignore();
}
fd.close();
}

void WriteData(string file, Coin coins[], int nc){
ofstream ft(file, ios::app);
ft.setf(ios::fixed); ft.setf(ios::left);
ft << "Number of coins: " << nc << endl;
ft << "List of Coins: \n";
ft << "---------------------------------------------------------------\n";
ft << "|    Denomination    |   Weight  |   Diameter    |   Thickness |\n";
ft << "---------------------------------------------------------------\n";
        for (int i=0; i<nc; i++){
ft << "|   " << setw(16) << coins[i].denomination << " |   " << setprecision(1) << setw(5) << coins[i].weight << "   |   " << setw(11) << coins[i].diameter << " |   " << setw(7) << coins[i].thickness << "  |" << endl;
        }
ft << "---------------------------------------------------------------\n";
        ft.close();
}

double calcCyVolume(double diameter, double height){
 double r = diameter/2;
 return M_PI * r* r* height;
}

void ValueOfCoins(Coin coins[],int nc){
        double coin_sum;
        int c;
    
            for(int i=0; i<nc; i++){
         c = std::stoi(coins[i].denomination);
         coin_sum += c;

            }
            coin_sum /= 100;
        cout << "The total value of the coins are: " << setprecision(3)<< coin_sum << " Euros" <<endl;
}

//void  NoOfCoinsInCylinder(Coin coins[],int nc, Cylinder _Cylinder){
// 
//   double vol_of_cyl = calcCyVolume(_Cylinder.diameter, _Cylinder.length);
//   for (int i=0; i<nc; i++){
//    if (coins[i].diameter <= _Cylinder.diameter && coins[i].thickness <= _Cylinder.length){
//   double vol_of_coin = calcCyVolume(coins[i].diameter, coins[i].thickness);
//    int no_of_coins = (int)vol_of_cyl/vol_of_coin;
//   cout << "The cylinder can contain " << no_of_coins << " coins of denomination " << coins[i].denomination << endl; 
//   }
//   
//     else{
//     cout << "The diameter of " << coins[i].denomination << " is too big to enter the cylinder.\n";
//     
//     }
//   }
//}

void  NoOfCoinsInCylinder(Coin coins[],int nc, Cylinder _Cylinder){
 

   for (int i=0; i<nc; i++){
    if (coins[i].diameter <= _Cylinder.diameter && coins[i].thickness <= _Cylinder.length){
            int no_of_coins = (int)_Cylinder.length/coins[i].thickness;
   cout << "The cylinder can contain " << no_of_coins << " coins of denomination " << coins[i].denomination << endl; 
   }
   
     else{
     cout << "The diameter of " << coins[i].denomination << " is too big to enter the cylinder.\n";
     
     }
   }
}
