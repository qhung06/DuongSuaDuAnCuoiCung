#include "Date.h"

Date::Date()
{
	ngay = 1;
	thang = 1;
	nam = 2025;
}

int Date::getngay()
{
	return ngay;
}

int Date::getthang()
{
	return thang;
}

int Date::getnam()
{
	return nam;
}

void Date::setngay(int ngay)
{
	this->ngay = ngay;
}

void Date::setthang(int thang)
{
	this->thang = thang;
}

void Date::setnam(int nam)
{
	this->nam = nam;
}

Date Date::operator-(Date d)
{
	Date kq;
	kq.ngay = ngay - d.ngay;
	kq.thang = thang - d.thang;
	kq.nam = nam - d.nam;
	return kq;
}

ostream& operator<<(ostream& os, Date d)
{
	os << d.ngay << "/" << d.thang << "/" << d.nam;
	return os;
}

istream& operator>>(istream& is, Date& d)
{
	is >> d.ngay;
	is >> d.thang;
	is >> d.nam;
	return is;
}

int Date::tohours()
{
	int totaldays = nam * 365 + thang * 30 + ngay;
	return totaldays * 24;
}


