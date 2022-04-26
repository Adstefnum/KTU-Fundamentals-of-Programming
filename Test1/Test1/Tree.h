#pragma once
#include <string>

class Tree
{

private:
	std::string name;
	double height;

public:
	void setName(std::string _name);
	void setHeight(double h);

	std::string getName();
	double getHeight();
};

