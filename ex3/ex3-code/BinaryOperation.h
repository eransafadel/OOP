//--------------include-------------------------------
#pragma once
#include "CalculatorItem.h"
#include <memory>
//----------------------------------------------------
class Calculator;
//---------------class BinaryOperation----------------
class BinaryOperation : public CalculatorItem
{
public:
	//----------------function-------------------------
	BinaryOperation(std::istream& is, const Calculator& calculator);//Ctor of BinaryOperation
	virtual ~BinaryOperation() = default; //default Dtor of BinaryOperation
protected:
	//------------data members-------------------------
	std::shared_ptr<CalculatorItem> m_item1; //m_item1
	std::shared_ptr<CalculatorItem> m_item2;//m_item2
};

