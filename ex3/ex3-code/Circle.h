//-------------------include---------------------
#pragma once
#include "Shape.h"
//-----------------global member-----------------	
const double PI = 3.141592653589793238463;
//-----------------class Circle-----------------
class Circle : public Shape
{
public:
	//---------------function-------------------
	Circle(std::istream& is);//Ctor of Circle
	virtual ~Circle() = default;//default Dtor of Circle
	double area() const override; //area
	double perimeter() const override;//perimeter
	void draw() const override;//draw
	void printDetails()const override;//printDetails
protected:
	//---------------data member-------------
	double m_radius;//m_radius
};

