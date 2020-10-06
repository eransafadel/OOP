#pragma once
//-----------------IncludeSection-------------------------------------------------
#include"AbsField.h"
#include <iostream>
//---------------------------------------------------------------------------------

//------------class AbsValidator---------------------------------------------------
class AbsValidator
{
public:

	virtual ~AbsValidator() {};//dtor
	virtual bool test(const AbsField& toTest) = 0; // to check if field data is ok
	virtual void printError(std::ostream& ostr) = 0; // to print the error of the test
};
//---------------------------------------------------------------------------------

