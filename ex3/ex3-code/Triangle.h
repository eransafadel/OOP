//----------------include---------------------
#pragma once
#include "Shape.h"
//----------------class Triangle-------------
class Triangle : public Shape
{
public:
	//----------function----------------------
	Triangle(std::istream& is);//Ctor of Triangle
	virtual ~Triangle() = default;//default Dtor of Triangle
	double area() const override;//area
	double perimeter() const override;//perimeter
	void draw() const override;//draw
	void printDetails() const override;//printDetails
private:
	//------------data members------------------
	int m_width;//m_width
	int m_height;//m_height
};

