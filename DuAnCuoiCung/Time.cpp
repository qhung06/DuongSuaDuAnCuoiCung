#include "Time.h"

Time::Time() : gio(0), phut(0) {}

int Time::getgio() const { return gio; }
int Time::getphut() const { return phut; }

void Time::setgio(int gio) { this->gio = gio; }
void Time::setphut(int phut) { this->phut = phut; }

Time Time::operator-(const Time& t) const
{
    Time kq;
    int total1 = gio * 60 + phut;
    int total2 = t.gio * 60 + t.phut;
    int diff = total1 - total2;

    kq.gio = diff / 60;
    kq.phut = diff % 60;
    return kq;
}

int Time::tohours() const
{
    int totalMinutes = gio * 60 + phut;
    return (totalMinutes + 59) / 60;
}

ostream& operator<<(ostream& os, const Time& t)
{
    os << t.gio << ":" << t.phut;
    return os;
}

istream& operator>>(istream& is, Time& t)
{
    is >> t.gio >> t.phut;
    return is;
}
