#pragma once
class kugis
{
private:
	double H, R, r;
public:
	kugis(void) : H(0), R(0), r(0) {}
	~kugis(void) {}
	void Set(double a, double b, double c) { H = a, R = b, r = c; }

double Turis();


};

