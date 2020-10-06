//------------------include---------------------------------
#pragma once
#include "BinaryOperation.h"
//----------------------------------------------------------
class Calculator;
//---------------class Add---------------------------------
class Add: public BinaryOperation
{
public:
	//------------------function----------------------------
	Add(std::istream& is, const Calculator& calculator);//Ctor of Add
	virtual ~Add() = default;//default Dtor of Add
	double area() const override; //area
	double perimeter() const override;//perimeter
	void draw() const override;//draw
	void printDetails() const override;//printDetails
};

