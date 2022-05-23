#include "company.h"
#include <string>
#include <limits>
#include <sstream>
#include <iomanip>



int Company::OrderedMost() {

	int index = 0;
	int max = std::numeric_limits<int>::min();
	for (int i = 0; i < n - 1; i++) {
		if (Sb[i].getnoNewsPr() > max) {
			max = Sb[i].getnoNewsPr();
			index = i;
		}
	}

	return index;
}

//Bubble Sort--O(n^2) time
void Company::Sort()
{
	int i, j;
	for (i = 0; i < n - 1; i++){
		Subscriber min = Sb[i];
		// Last i elements are already
		// in place
		for (j = 0; j < n - i - 1; j++) {
			if (Sb[j] < Sb[j + 1])
				std::swap(Sb[j], Sb[j + 1]);
		}
		
	}
	
}	
