#pragma once
#include "Oto.h"
#include "XeMay.h"
#include "Date.h"
#include "Time.h"
class Ticket
{
	int id;
	Xe* xe;
	Date datein;
	Time timein;
	Date dateout;
	Time timeout;
	double fee;
public:
	Ticket(int id);
	void taove(Time timein,Date datein,Xe &xe);
	void xuatve(Time timeout,Date dateout);
	Xe* getxe();
	int getid();
	Time gettimein();
	Time gettimeout();
	Date getdatein();
	Date getdateout();

};

