#pragma once
#include "subscriber.h"

class Company : Subscriber
{
    public:
        static const int CMax = 100;

    private:
        Subscriber Sb[CMax];
        int n;

    public:
        Company(): n(0) {}
        int Get() { return n;}
        Subscriber Get(int i) { return Sb[i]; }
        void Set(const Subscriber & ob) { Sb[n++] = ob; }
		int OrderedMost();
		void Sort();
};
