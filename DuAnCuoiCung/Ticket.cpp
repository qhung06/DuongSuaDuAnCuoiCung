#include "Ticket.h"
#include <iostream>
#include <cstdlib>
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

    // Quy ??i toàn b? th?i gian v? t?ng s? gi?
    long long gioVao = datein.tohours() + timein.tohours();
    long long gioRa = dateout.tohours() + timeout.tohours();

    long long tongGio = gioRa - gioVao;

    // ??m b?o t?i thi?u 1 gi? g?i
    if (tongGio < 1)
        tongGio = 1;

    // Tính ti?n tr?c ti?p t? ??i t??ng xe
    fee = tongGio * xe->getgiave();
	system("cls");
    // In vé
    cout << "========= VE XE =========" << endl;
    cout << "ID ve: " << id << endl;
    cout << "Loai xe: " << xe->gettype() << endl;
    cout << "Bien so: " << xe->getplate() << endl;
    cout << "Thoi gian vao: " << timein << " " << datein << endl;
    cout << "Thoi gian ra:  " << timeout << " " << dateout << endl;
    cout << "Tong so gio gui: " << tongGio << endl;
    cout << "Tong tien: " << fee << " VND" << endl;
	system("pause");
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

    // Tính ti?n tr?c ti?p t? ??i t??ng xe
    feetemp = tongGio * xe->getgiave();
    return feetemp;
}
