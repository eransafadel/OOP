//---------------------include----------------------
#pragma once
#include "Shape.h"
//-------------------class Rectangle----------------
class Rectangle: public Shape
{
public:
	//----------------function-----------------------
	Rectangle(std::istream& is);//Ctor of Rectangle
	virtual ~Rectangle() = default;//default Dtor of Rectangle
	double area() const override;//area
	double perimeter() const override;//perimeter
	void printDetails() const override;//printDetails
	void draw() const override;//draw
private:
	//-------------data members-----------------------
	int m_width{};//m_width
	int m_height{};//m_height
};

