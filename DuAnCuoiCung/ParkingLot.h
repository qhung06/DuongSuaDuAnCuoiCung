#pragma once
#include "Ticket.h"

class ParkingLot
{
    Ticket* ve[1000];
    int n;
    int max;
    int soxemay;
    int soxeoto;

public:
    ParkingLot();

    void themxe(const Date& datein);
    void xuatxe(const Date& dateout);
    void danhsachxe();
    void kiemtrachotrong();
    void timkiem();
	void tinhdoanhthu();
    void hienthixe();
    void thongtinravao(const Date& today);
};
