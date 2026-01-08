#pragma once
#include <string>
using namespace std;

class Xe
{
protected:
    string type;
    string plate;
public:
    Xe();
    virtual ~Xe() {}

    string gettype() const;
    string getplate() const;

    void settype(const string& type);
    void setplate(const string& plate);

    virtual double getgiave() const = 0;
};
