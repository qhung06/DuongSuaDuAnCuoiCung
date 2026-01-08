#pragma once
#include "Oto.h"
#include "XeMay.h"
#include "Date.h"
#include "Time.h"

class Ticket
{
    int id;
    Xe* xe;
    Date datein, dateout;
    Time timein, timeout;
    long long fee;

public:
    Ticket(int id);
    ~Ticket();

    void taove(const Time& timein, const Date& datein, const Xe& xe);
    void xuatve(const Time& timeout, const Date& dateout);

    void settimeout(const Time& timeout);
    void setdateout(const Date& dateout);

    int getid() const;
    Xe* getxe() const;
    Time gettimein() const;
    Time gettimeout() const;
    Date getdatein() const;
    Date getdateout() const;
    long long getfee() const;
};
