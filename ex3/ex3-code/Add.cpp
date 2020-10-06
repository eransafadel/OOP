//------------------include & using------------------------
#include "Add.h"
#include <iostream>
using std::cout;
using std::endl;
//----------------------Add--------------------------------
//Ctor of Add
Add::Add(std::istream& is, const Calculator& calculator)
	: BinaryOperation(is, calculator) { }
//Add::Add(std::shared_ptr<CalculatorItem> item1, std::shared_ptr<CalculatorItem> item2)
//: BinaryOperation(item1, item2)
//{}
//------------------area----------------------------------
//function that calculates the area of shape
double Add::area() const
{
	return m_item1->area() + m_item2->area();
}
//---------------perimeter---------------------------------
//function that calculates the perimeter of shape
double Add::perimeter() const
{
	return m_item1->perimeter() + m_item2->perimeter();
}
//---------------draw-------------------------------------
//function that draw the shape
void Add::draw() const
{
	m_item1->draw();
	cout << "\t+" << endl;
	m_item2->draw();
}
//---------------printDetails-----------------------------
//function that print Details
void Add::printDetails() const
{
	cout << "(";
	m_item1->printDetails();
	cout << ") + (";
	m_item2->printDetails();
	cout << ")";
}