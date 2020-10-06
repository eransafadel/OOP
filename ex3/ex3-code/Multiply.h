//A class that holds an object from the list and multiplies it by a given number
//-----------include-------------------------------------------
#pragma once
#include <memory>
#include "CalculatorItem.h"
//---------------------------------------------------------------
class Calculator;
//---------------class Multiply-----------------------------------
class Multiply : public CalculatorItem
{
public:
	//----------------function-------------------------------------
	Multiply(std::istream& is, const Calculator& calculator);//Ctor of Multiply
	virtual ~Multiply() = default;//default Dtor of Multiply
	double area() const override;//area
	double perimeter() const override;//perimeter
	void printDetails() const override;//printDetails
	void draw() const override;//draw
private:
	//--------------------data members-----------------------------
	unsigned int m_multi;//m_multi
	std::shared_ptr<CalculatorItem> m_item;//m_item
};

