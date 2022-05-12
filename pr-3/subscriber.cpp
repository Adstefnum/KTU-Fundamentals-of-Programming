#include "subscriber.h"


void Subscriber::Set(std::string _surname, std::string _address, std::string _newsPCode, int _noNewsPr, int _begPeriod, int _lenPeriod){

        surname = _surname;
        address = _address;
        newsPCode = _newsPCode;
        begPeriod = _begPeriod;
        lenPeriod = _lenPeriod;
        noNewsPr = _noNewsPr;
}

std::string Subscriber::Print(){
    return "";
} 
