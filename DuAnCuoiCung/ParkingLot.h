#pragma once
#include "Ticket.h"

class ParkingLot
{
    Ticket* ve[1000];
    int n;
    int max;

public:
    ParkingLot();

    void themxe(const Date& datein);
    void xuatxe(const Date& dateout);
    void danhsachxe();
};
