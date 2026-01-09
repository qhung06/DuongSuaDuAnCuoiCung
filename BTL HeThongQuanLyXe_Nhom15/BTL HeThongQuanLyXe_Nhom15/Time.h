#pragma once
#include <iostream>
using namespace std;

class Time
{
    int gio, phut;
public:
    Time();

    int getgio() const;
    int getphut() const;

    void setgio(int gio);
    void setphut(int phut);

    int tohours() const;

    friend ostream& operator<<(ostream& os, const Time& t);
    friend istream& operator>>(istream& is, Time& t);
};
