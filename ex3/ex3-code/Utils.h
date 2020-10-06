//---------------include---------------------
#pragma once
#include <istream>
#include <string>
#include "Calculator.h"
//---------------class Utils-----------------
class Utils
{
public:
	//------------function------------------
	Utils() = delete;//no Ctor
	~Utils() = delete;//no Dtor
	static int readInt(std::istream& is); //readInt
	static bool isContainDigit(const std::string & var);// isContainDigit

	
};

