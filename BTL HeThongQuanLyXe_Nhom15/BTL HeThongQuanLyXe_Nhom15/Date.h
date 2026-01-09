#pragma once
#include <iostream>
using namespace std;

class Date
{
    int ngay, thang, nam;
public:
    Date();

    int getngay() const;
    int getthang() const;
    int getnam() const;

    void setngay(int ngay);
    void setthang(int thang);
    void setnam(int nam);

    int tohours() const;

    friend ostream& operator<<(ostream& os, const Date& d);
    friend istream& operator>>(istream& is, Date& d);
};