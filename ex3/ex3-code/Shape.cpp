//------------------------include---------------------------
#include "Shape.h"
#include <iostream>
//-----------------------Shape------------------------------
//Ctor of Shape that update data member
Shape::Shape(const std::string& name) 
: m_name(name) 
{ }
//----------------------isRange---------------------------
//function that check if val is valid, overwise throw exception
void Shape::isRange(int val)
{
	if (val <= 0)
		throw std::exception();
}
//---------------------printName---------------------------
//function that print Name
void Shape::printName() const
{
	std::cout << m_name;
}