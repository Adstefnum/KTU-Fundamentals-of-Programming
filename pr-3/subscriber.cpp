#include "subscriber.h"
#include <sstream>
#include <iomanip>

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
    ret << std::left << std::setw(10) << surname << std::setw(15) << address << std::setw(10) <<
        newsPCode<< std::setw(8) << begPeriod << std::setw(8) << lenPeriod << std::setw(8) << noNewsPr << std::right;
    return ret.str();
}

