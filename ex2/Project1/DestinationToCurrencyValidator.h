#pragma once
//-----------IncludeSection--------------------------------------------------
#include "FormValidator.h"
//----------------------------------------------------------------------------


//-------------Template Class DestinationToCurrencyValidator------------------
template<typename T1, typename T2>
class DestinationToCurrencyValidator:public FormValidator
{
public:
	DestinationToCurrencyValidator(T1* DestField, T2* CurrencyField):// Ctor
		m_DestField(DestField), m_CurrencyField(CurrencyField) {};//--------
	virtual bool test();//test
	virtual void printError(std::ostream& ostr);//printError
	virtual void fillField();//fillField

private:
	T1 * m_DestField;//m_DestField
	T2* m_CurrencyField;//m_CurrencyField
};
//--------------------------------------------------------------------------------

//---------------------------test-------------------------------------------------
//------template function that check if the field that we put on form 
// between the destination and currency are actually valid if so return true
// else return false
template<typename T1, typename T2>
inline bool DestinationToCurrencyValidator<T1, T2>::test()
{
	if (m_DestField->getData() == 3)// fly to newYork
		return(m_CurrencyField->getData() != 2);// cannot pay with Euro

		if (m_DestField->getData() == 1 ||
			m_DestField->getData() == 2)// fly to Rome or Prauge

			return (m_CurrencyField->getData() != 3);// Cannot pay with Dollar 

			return true;
}
//---------------------------------------------------------------------------------

//--------------------------printError---------------------------------------------
//template function that print the error if Destination and Currency don't match 
template<typename T1, typename T2>
inline void DestinationToCurrencyValidator<T1, T2>::printError(std::ostream & ostr)
{
	ostr << " Destination and Currency don't match ";
}
//----------------------------------------------------------------------------------


// -------------------fillField----------------------------------------------------
// ------------func that fill The field -------------------------------------------
template<typename T1, typename T2>
inline void DestinationToCurrencyValidator<T1, T2>::fillField()
{
	m_DestField->get_input();//getTheInput
	m_CurrencyField->get_input();//getTheInput
}
//----------------------------------------------------------------------------------
