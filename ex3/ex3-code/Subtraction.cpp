//--------------------------include-----------------------------
#include "Subtraction.h"
#include <iostream>
using std::cout;
using std::endl;
//------------------------Subtraction-----------------------------
//Ctor of Subtraction that call BinaryOperation
Subtraction::Subtraction(std::istream& is, const Calculator& calculator)
	: BinaryOperation(is, calculator) { }
//----------------------area--------------------------------------
//function that calculates the area of Subtraction of the shapes
double Subtraction::area() const
{
	return m_item1->area() - m_item2->area();
}
//-------------------perimeter-----------------------------------
//function that calculates the perimeter of Subtraction of the shapes
double Subtraction::perimeter() const
{
	return m_item1->perimeter() - m_item2->perimeter();
}
//-----------------draw-----------------------------------------
//function that draw the Subtraction of the shapes
void Subtraction::draw() const
{
	m_item1->draw();
	cout << "\t-" << endl;
	m_item2->draw();
}
//-----------------printDetails-------------------------------
//function that print details of Subtraction of the shapes
void Subtraction::printDetails() const
{
	cout << "(";
	m_item1->printDetails();
	cout << ") - (";
	m_item2->printDetails();
	cout << ")";
}
