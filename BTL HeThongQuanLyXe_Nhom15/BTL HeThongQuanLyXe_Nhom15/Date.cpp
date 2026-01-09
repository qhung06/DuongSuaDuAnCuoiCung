#include "Date.h"

Date::Date() : ngay(1), thang(1), nam(2025) {}

int Date::getngay() const { return ngay; }
int Date::getthang() const { return thang; }
int Date::getnam() const { return nam; }

void Date::setngay(int ngay) { this->ngay = ngay; }
void Date::setthang(int thang) { this->thang = thang; }
void Date::setnam(int nam) { this->nam = nam; }

int Date::tohours() const
{
    int totalDays = nam * 365 + thang * 30 + ngay;
    return totalDays * 24;
}

ostream& operator<<(ostream& os, const Date& d)
{
    os << d.ngay << "/" << d.thang << "/" << d.nam;
    return os;
}

istream& operator>>(istream& is, Date& d)
{
    is >> d.ngay >> d.thang >> d.nam;
    return is;
}