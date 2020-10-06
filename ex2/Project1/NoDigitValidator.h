#pragma once
//-------------------------IncludeSection------------------------------------------------
#include "Validator.h"
#include <string>
//---------------------------------------------------------------------------------------

//-------------NoDigitValidator---------------------------------------------------------
class NoDigitValidator:public Validator<std::string>
{
public:
	virtual void printError(std::ostream& ostr)
	{ ostr << " Can't contain digits "; }//printError

protected:
	virtual bool validatorTest(const std::string& val); // validatorTest

};
//---------------------------------------------------------------------------------------

