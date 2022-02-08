// L1antra-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "kugis.h"
using namespace std;


//double kugis::Turis() {
//	return (1.0 / 3) * 3.1415 * H * (R * R + R * r + r * r);
//}

int main()
{

	double h, R, r, V;
	const double pi = 3.1415;
	cout << "enter the height\n";
	cin >> h;
	cout << "Enter the radiuses:";
	cin >> R >> r;
	V = (1.0 / 3) * pi * h * (R * R + R * r + r * r);
	cout << "Volume = " << V << endl;
	return 0;
}


//int main() {
//	kugis k;
//	double H, R, r;
//	cout << "Enter the height:";
//	cin >> H;
//	cout << "Enter the radiuses:";
//	cin >> R >> r;
//	k.Set(H, R, r);
//	cout << "Volume = " << k.Turis() << endl;
//
//		return 0;
//}
