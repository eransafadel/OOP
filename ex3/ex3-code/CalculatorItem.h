//---------------include-------------------------
#pragma once
//------------------class CalculatorItem----------
class CalculatorItem
{
public:
	//-------------function-------------------------
	CalculatorItem() = default; //Ctor of CalculatorItem
	virtual ~CalculatorItem() = default; //default Dtor of CalculatorItem
	virtual double area() const = 0; //area
	virtual double perimeter() const = 0;//perimeter
	virtual void draw() const = 0;//draw
	virtual void printDetails() const = 0;//printDetails
};

