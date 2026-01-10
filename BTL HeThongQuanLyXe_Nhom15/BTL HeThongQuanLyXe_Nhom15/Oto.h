#pragma once
#include "Xe.h"

class Oto : public Xe
{
    double giave;
public:
    Oto();
	void nhap() override;
	void xuat() override;
    double getgiave() const override;
};
