#pragma once
//--------------------IncludeSection---------------------------------------------
#include "Validator.h"
//-------------------------------------------------------------------------------

//---------------------TemplateClass RangeValidator------------------------------
template <typename T>
class RangeValidator:public Validator<T>
{
public:
	// get min and max range
	RangeValidator(const int&  min, const int& max) : minVal(min), maxVal(max) {};//RangeValidator
	virtual void printError(std::ostream& ostr);//printError

private:
	const int minVal;//minVal
	const int maxVal;//maxVal
	virtual bool validatorTest(const T& val);	// test if data is in range
};
//-----------------------------------------------------------------------------------

//----------------template func printError-------------------------------------------
//-----------ptint our of range if isnt valid---------------------------------------
template<typename T>
inline void RangeValidator<T>::printError(std::ostream & ostr)
{
	ostr << " out of range";
}
//-----------------------------------------------------------------------------------

//-------------template func validatorTest-------------------------------------------
// -------------------check is the vals are in range --------------------------------
template<typename T>
bool RangeValidator<T>::validatorTest(const T & val)
{
	return (val > minVal - 1 && val < maxVal + 1); // check if is on range
}
//-----------------------------------------------------------------------------------



