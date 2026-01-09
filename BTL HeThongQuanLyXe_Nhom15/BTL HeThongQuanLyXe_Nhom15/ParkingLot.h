#pragma once
#include "Ticket.h"
#include <iomanip>
#define MAXXEMAY 5
#define MAXOTO 5
#define MAXSLOT (MAXXEMAY + MAXOTO)
class ParkingLot
{
    Ticket* ve[1000];
    int n;
    int max;
    int soxemay;
    int soxeoto;

public:
    ParkingLot();

    int getsoxemay() const;
    int getsoxeoto() const;

    void themxe(const Date& datein);
    void xuatxe(const Date& dateout);
    void danhsachxe();
    void kiemtrachotrong();
    void timkiem();
    void tinhdoanhthu();
    void hienthixe();
    void thongtinravao(const Date& today);
};
