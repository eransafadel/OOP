//---------------------------include & using-----------------------------
#include "Multiply.h"
#include <iostream>
#include "Utils.h"
#include "Calculator.h"
using std::cout;
using std::endl;
//-------------------------Multiply--------------------------------------
//Ctor of Multiply that read from user m_item and m_multi
Multiply::Multiply(std::istream& is, const Calculator& calculator)
{
	m_item = calculator[Utils::readInt(is)];
	m_multi = Utils::readInt(is);
}
//---------------------------area------------------------------------
//function that calculates the area of item
double Multiply::area() const
{
	return m_item->area() * m_multi;
}
//----------------------perimeter------------------------------------
//function that calculates the perimeter of item
double Multiply::perimeter() const
{
	return m_item->perimeter() * m_multi;
}
//----------------------draw----------------------------------------
//function that draw item
void Multiply::draw() const
{
	m_item->draw();
	cout << "\tx" << m_multi << endl;
}
//-------------------printDetails-----------------------------------
//function that print details of item
void Multiply::printDetails() const
{
	cout << "(";
	m_item->printDetails();
	cout << ") * (" << m_multi << ") times";
}