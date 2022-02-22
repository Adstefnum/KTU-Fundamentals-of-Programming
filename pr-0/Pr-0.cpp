#include <cmath>
#include <iostream>
#include <stdio.h>
using namespace std;

int func_1(int x)
{
	return x + 2 * pow(x, 2);
}

int func_2(int x)
{
	return pow(x, 2) + 4;
}

double func_3(int x)
{
	int ans = 2 * pow(x, 2) + 3;
	return pow(ans, 0.5);
}

int main()
{

	int x;
	double ans;
	cout << "Please enter the value of x:";
	cin >> x;

	if (x >= -5 && x <= 0) {
		ans = func_1(x);
	}

	else if (x > 0 && x < 3) {
		ans = func_2(x);
	}

	else {
		ans = (double)func_3(x);
	}

	cout << "The answer is:" << ans << endl;
	return 0;
}
