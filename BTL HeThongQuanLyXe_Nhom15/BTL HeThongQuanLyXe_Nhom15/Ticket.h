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
    long long fee, tongGio;

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
    void tongthoigiangui();
	void giave();
    long long getfee() const ;
	long long gettonggiogui() const ;
};
