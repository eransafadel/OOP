//-------------------IncludeSection---------------------------------------------------
#include <string>
#include <cctype>
#include "Validator.h"
#include "Field.h"
#include "NoDigitValidator.h"
//-------------------------------------------------------------------------------------

//---------------------validatorTest----------------------------------------------------
bool NoDigitValidator::validatorTest(const std::string & val)
{
	for (size_t i = 0; i < val.length(); i++) // move on loop the check if there digit
		if (std::isdigit(val[i]))
			return false;
	return true;
}
//---------------------------------------------------------------------------------------
