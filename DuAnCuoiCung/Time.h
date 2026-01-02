#pragma once
#include <iostream>
using namespace std;
class Time
{
	float gio, phut;
public:
	Time();
	float getgio();
	float getphut();
	void setgio(float gio);
	void setphut(float phut);
	Time operator-(Time t);
	friend ostream& operator<<(ostream& os, Time t);
	friend istream& operator>>(istream& is, Time& t);
	int tohours();


};

