#pragma once
#include <iostream>
using namespace std;
class Date

{
	int ngay, thang, nam;
public:
	Date();
	int getngay();
	int getthang();
	int getnam();
	void setngay(int ngay);
	void setthang(int thang);
	void setnam(int nam);
	Date operator-(Date d);
	friend ostream& operator<<(ostream& os, Date d);
	friend istream& operator>>(istream& is, Date& d);
	int tohours();
};

