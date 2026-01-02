#include "Ticket.h"

Ticket::Ticket(int id)
{
	this->id = id;
	xe = nullptr;
	fee = 0;
}

void Ticket::taove(Time timein, Date datein, Xe &xe)        //????????????
{
	this->timein = timein;
	this->datein = datein;
	this->xe = &xe;
}

void Ticket::xuatve(Time timeout, Date dateout)
{
	this->timeout = timeout;
	this->dateout = dateout;
	int totalhours = (dateout - datein).tohours() + (timeout - timein).tohours();
	if (xe->gettype() == "Oto")
	{
		Xe *temp;
		temp = new Oto();
		fee = totalhours * temp->getgiave();
	}
	else if (xe->gettype() == "XeMay")
	{
		Xe* temp;
		temp = new XeMay();
		fee = totalhours * temp->getgiave();
	}
	cout << "=========VE XE=========" << endl;
	cout << "ID ve: " << id << endl;
	cout << "Loai xe: " << xe->gettype() << endl;
	cout << "Bien so: " << xe->getplate() << endl;
	cout << "Thoi gian vao: " << timein << endl;
	cout << "Ngay vao: " << datein << endl;
	cout << "Thoi gian ra: " << timeout << endl;
	cout << "Ngay ra: " << dateout << endl;
	cout << "-----------------------" << endl;
	cout << "Tong phi: " << fee << " VND" << endl;
}

int Ticket::getid()
{
	return id;
}

Xe* Ticket::getxe()
{
	return xe;
}

Time Ticket::gettimein()
{
	return timein;
}

Time Ticket::gettimeout()
{
	return timeout;
}

Date Ticket::getdatein()
{
	return datein;
}

Date Ticket::getdateout()
{
	return dateout;
}




