#include "Xe.h"

Xe::Xe()
{
	type = "";
	plate = "";
}

string Xe::gettype() 
{
	return type;
}

string Xe::getplate() 
{
	return plate;
}

void Xe::settype(string type) 
{
	this->type = type;
}

void Xe::setplate(string plate) 
{
	this->plate = plate;
}