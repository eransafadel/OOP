//A class of subtraction between 2 objects from the list, 
//Calculating the circumference and area will be subtraction between the areas of the objects / 
//subtract between the circumference of the objects
//--------------include------------------------
#pragma once
#include <memory>
#include "BinaryOperation.h"
//---------------class Subtraction--------------
class Subtraction: public BinaryOperation
{
public:
	//--------------function---------------------
	Subtraction(std::istream& is, const Calculator& calculator);//Ctor of Subtraction
	virtual ~Subtraction() = default;//default Dtor of Subtraction
	double area() const override;//area
	double perimeter() const override;//perimeter
	void draw() const override;//draw
	void printDetails() const override;//printDetails
};

