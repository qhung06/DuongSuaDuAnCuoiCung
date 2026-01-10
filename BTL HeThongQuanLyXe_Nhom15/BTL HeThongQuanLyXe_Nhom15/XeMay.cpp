#include "XeMay.h"

XeMay::XeMay()
{
    type = "XeMay";
    giave = 5000;
}

void XeMay::nhap()
{
	cout << "Nhap bien so xe may: ";
	cin >> plate;
}

void XeMay::xuat()
{
	cout << "Da tim thay xe voi ID ve da nhap.\n";
	cout << "nhan Enter de xuat ve.";
}

double XeMay::getgiave() const
{
    return giave;
}
