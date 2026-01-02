#include "Time.h"

Time::Time()
{
	gio = 0;
	phut = 0;
}

float Time::getgio()
{
	return gio;
}
float Time::getphut()
{
	return phut;
}

void Time::setgio(float gio)
{
	this->gio = gio;
}

void Time::setphut(float phut)
{
	this->phut = phut;
}

Time Time::operator-(Time t)
{
	Time kq;
	kq.gio = gio - t.gio;
	kq.phut = phut - t.phut;
	return kq;
}

int Time::tohours()
{
	float time1;
	int time2;
	time1 = gio + (phut / 60.0);
	time2 = gio + (phut / 60.0);
	if (time1 > time2)
		time2 = time2 + 1;
	return time2;
}

ostream& operator<<(ostream& os, Time t)
{
	os << t.gio << ":" << t.phut;
	return os;
}

istream& operator>>(istream& is, Time& t)
{
	is >> t.gio;
	is >> t.phut;
	return is;
}
