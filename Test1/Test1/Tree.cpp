#include "Tree.h"
#include <string>

void Tree::setName(std::string _name) { name = _name; }
void Tree::setHeight(double h) { height = h; }

std::string Tree::getName() { return name; }
double Tree::getHeight() { return height; }
