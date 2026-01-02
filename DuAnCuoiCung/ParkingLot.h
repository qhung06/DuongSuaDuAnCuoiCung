#pragma once
#include "Ticket.h"

class ParkingLot
{
	Ticket* ve[1000];
	int max = 100;
	int soluongxehienco;
	int n=0;
public:
	ParkingLot();
	void themxe(Time timein, Date datein, Xe& xe);
	void xuatxe(int id, Time timeout, Date dateout);
	void themxe(Date datein);
	void xuatxe(Date dateout);
	void danhsachxe();

};

