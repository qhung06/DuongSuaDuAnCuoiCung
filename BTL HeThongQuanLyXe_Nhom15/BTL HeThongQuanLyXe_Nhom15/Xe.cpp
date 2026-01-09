#include "Xe.h"

Xe::Xe() : type(""), plate("") {}

string Xe::gettype() const { return type; }
string Xe::getplate() const { return plate; }

void Xe::settype(const string& type) { this->type = type; }
void Xe::setplate(const string& plate) { this->plate = plate; }
