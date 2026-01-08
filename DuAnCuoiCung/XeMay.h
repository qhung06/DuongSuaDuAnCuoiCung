#pragma once
#include "Xe.h"

class XeMay : public Xe
{
    double giave;
public:
    XeMay();
    double getgiave() const override;
};
