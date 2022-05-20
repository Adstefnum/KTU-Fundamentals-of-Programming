#include "subscriber.h"
#include <sstream>
#include <iomanip>
#include <string>

void Subscriber::Set(std::string _surname, std::string _address, std::string _newsPCode, int _noNewsPr, int _begPeriod, int _lenPeriod){

        surname = _surname;
        address = _address;
        newsPCode = _newsPCode;
        begPeriod = _begPeriod;
        lenPeriod = _lenPeriod;
        noNewsPr = _noNewsPr;
}

std::string Subscriber::Print(){

    std::stringstream ret;
	ret << std::left<< std::setw(12) << surname << std::setw(20) << address<< std::setw(15) << newsPCode 
		<< std::setw(15) << begPeriod  <<std::setw(15) << lenPeriod << std::setw(15) << noNewsPr << std::endl;
    return ret.str();
} 
