//-----------------include----------------------------
#include "BinaryOperation.h"
#include "Utils.h"
#include "Calculator.h"
//--------------BinaryOperation------------------------
//Ctor of BinaryOperation that read two data and update data members
BinaryOperation::BinaryOperation(std::istream& is, const Calculator& calculator)
{
	m_item1 = calculator[Utils::readInt(is) ];
	m_item2 = calculator[Utils::readInt(is) ];
}
