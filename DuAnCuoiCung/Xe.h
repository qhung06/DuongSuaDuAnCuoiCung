#pragma once
#include <string>
using namespace std;
class Xe
{
	string type;
	string plate;
public:
	Xe();
	string gettype();
	string getplate();
	void settype(string type);
	void setplate(string plate);
	virtual double getgiave() = 0;


};

