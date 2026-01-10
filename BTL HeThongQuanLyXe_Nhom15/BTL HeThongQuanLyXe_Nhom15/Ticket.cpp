#include "Ticket.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

Ticket::Ticket(int id) : id(id), xe(nullptr), fee(0), tongGio(0) {}

Ticket::~Ticket()
{
    delete xe;
}

void Ticket::taove(const Time& timein, const Date& datein, const Xe& xe)
{
    this->timein = timein;
    this->datein = datein;

    if (xe.gettype() == "Oto")
        this->xe = new Oto();
    else
        this->xe = new XeMay();

    this->xe->setplate(xe.getplate());
}

void Ticket::settimeout(const Time& timeout)
{
    this->timeout = timeout;
}

void Ticket::setdateout(const Date& dateout)
{
    this->dateout = dateout;
}

void Ticket::giave()
{
	tongthoigiangui();
    fee = tongGio * xe->getgiave();
}

void Ticket::tongthoigiangui()
{
    long long gioVao = datein.tohours() + timein.tohours();
    long long gioRa = dateout.tohours() + timeout.tohours();
    tongGio = gioRa - gioVao;
    if (tongGio < 1)
        tongGio = 1;
}

void Ticket::xuatve(const Time& timeout, const Date& dateout)
{
    this->timeout = timeout;
    this->dateout = dateout;

	giave();
	tongthoigiangui();

    system("cls");
    cout << "=======================================" << endl
        << "              VE GUI XE                " << endl
        << "=======================================" << endl
        << "ID ve:               " << setw(4) << setfill('0') << id << endl
        << "Loai xe:             " << xe->gettype() << endl
        << "Bien so:             " << xe->getplate() << endl
        << "---------------------------------------" << endl
        << "Thoi gian vao:       " << timein << " " << datein << endl
        << "Thoi gian ra:         " << timeout << " " << dateout << endl
        << "---------------------------------------" << endl
        << "Tong so gio gui:     " << tongGio << " gio" << endl
        << "Tong tien:           " << fee << " VND" << endl
        << "=======================================" << endl
        << "    CAM ON QUY KHACH - HEN GAP LAI !    " << endl
        << "=======================================" << endl;
}



int Ticket::getid() const { return id; }
Xe* Ticket::getxe() const { return xe; }
Time Ticket::gettimein() const { return timein; }
Time Ticket::gettimeout() const { return timeout; }
Date Ticket::getdatein() const { return datein; }
Date Ticket::getdateout() const { return dateout; }
long long Ticket::getfee() const { return fee;}
long long Ticket::gettonggiogui() const  { return tongGio; }
