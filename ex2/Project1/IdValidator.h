#pragma once
//---------------------validator-----------------------------------------------------------
#include "Validator.h"
//-----------------------------------------------------------------------------------------
//--------------class IdValidator-----------------------------------------------------------
class IdValidator:public Validator<uint32_t>
{
public:
	
	virtual void printError(std::ostream& ostr){ ostr << " Wrong control digit"; }//printError
private:
	bool validatorTest(const std::uint32_t& val);//validatorTest
};
//------------------------------------------------------------------------------------

