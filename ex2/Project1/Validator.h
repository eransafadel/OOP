#pragma once
//----------------------------IncludeSection----------------------------------------
#include "Field.h"
//-----------------------------------------------------------------------------------

//---------template class Validator--------------------------------------------------
template<typename T>
class Validator:public AbsValidator
{
public:
	
	virtual bool test(const AbsField& toTest);//test the field
	 virtual ~Validator(){}//dtor

protected:
	virtual bool validatorTest(const T& val) = 0;//validatorTest
};
//-------------------------------------------------------------------------------------

//-------------template func test-----------------------------------------------------------
template<typename T>
inline bool Validator<T>::test(const AbsField & toTest)
{
	const Field<T>* fieldTest = dynamic_cast<const Field<T>*>(&toTest);

	if (fieldTest)// if is valid 
		return validatorTest(fieldTest->getData());
	else
		return true;
}
//---------------------------------------------------------------------------------------
