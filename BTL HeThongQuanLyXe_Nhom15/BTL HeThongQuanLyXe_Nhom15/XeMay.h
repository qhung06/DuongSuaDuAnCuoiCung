#pragma once
#include "Xe.h"

class XeMay : public Xe
{
    double giave;
public:
    XeMay();
    void nhap() override;
    void xuat() override;
    double getgiave() const override;
};
