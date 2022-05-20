#pragma once
#include <string>

class Subscriber{
    private:
        std::string surname, address, newsPCode;
        int begPeriod, lenPeriod, noNewsPr;

    public:
       Subscriber():surname(""), address(""), newsPCode(""), begPeriod(0),lenPeriod(0), noNewsPr(0)  { }
       void Set(std::string _surname, std::string _address, std::string _newsPCode, int _noNewsPr, int _begPeriod, int _lenPeriod);
       std::string Print();
};
