#include "Ticket.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

Ticket::Ticket(int id) : id(id), xe(nullptr), fee(0) {}

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

void Ticket::xuatve(const Time& timeout, const Date& dateout)
{
    this->timeout = timeout;
    this->dateout = dateout;

    // Quy ??i to‡n b? th?i gian v? t?ng s? gi?
    long long gioVao = datein.tohours() + timein.tohours();
    long long gioRa = dateout.tohours() + timeout.tohours();

    long long tongGio = gioRa - gioVao;

    // ??m b?o t?i thi?u 1 gi? g?i
    if (tongGio < 1)
        tongGio = 1;

    // T˙ãh ti?n tr?c ti?p t? ??i t??ng xe
    fee = tongGio * xe->getgiave();
    system("cls");
    // In vÅE
    cout << "=======================================" << endl
        << "              VE GUI XE                " << endl
        << "=======================================" << endl
        << "ID ve:               " << setw(4) << setfill('0') << id << endl
        << "Loai xe:             " << xe->gettype() << endl
        << "Bien so:             " << xe->getplate() << endl
        << "---------------------------------------" << endl
        << "Thoi gian vao:        " << timein << " " << datein << endl
        << "Thoi gian ra:       " << timeout << " " << dateout << endl
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
long long Ticket::getfee() const {
    long long gioVao = datein.tohours() + timein.tohours();
    long long gioRa = dateout.tohours() + timeout.tohours();

    long long tongGio = gioRa - gioVao;
    long long feetemp;
    // ??m b?o t?i thi?u 1 gi? g?i
    if (tongGio < 1)
        tongGio = 1;

    // T˙ãh ti?n tr?c ti?p t? ??i t??ng xe
    feetemp = tongGio * xe->getgiave();
    return feetemp;
}
