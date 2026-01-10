#include "Oto.h"

Oto::Oto()
{
    type = "Oto";
    giave = 20000;
}

void Oto::nhap()
{
    cout << "Nhap bien so o to: ";
    cin >> plate;
}

void Oto::xuat()
{
    cout << "Da tim thay xe voi ID ve da nhap.\n";
    cout << "nhan Enter de xuat ve.";
}

double Oto::getgiave() const
{
    return giave;
}
