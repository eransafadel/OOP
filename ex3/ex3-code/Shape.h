//----------------include---------------------
#pragma once
#include <string>
#include "CalculatorItem.h"
//--------------class Shape-------------------
class Shape : public CalculatorItem
{
public:
	//-----------function----------------------
	Shape(const std::string& name);//Ctor of Shape
	virtual ~Shape() = default; //default Dtor of shape
	virtual void isRange(int); //isRange
protected:
	//----------protected function------------
	void printName() const;//printName
private:
	//--------------data member---------------
	std::string m_name;
};

