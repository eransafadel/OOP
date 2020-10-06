#pragma once
#include "FormValidator.h"
#include "Field.h"
//-----------Template Class DestinationToClassValidator---------------------
template<typename T1,typename T2>
class DestinationToClassValidator:public FormValidator
{
public:
	DestinationToClassValidator(T1 * dest, T2 * className):// Ctor
		m_DestField(dest), m_classNameField(className) {};//--
	virtual bool test();// test 
	virtual void fillField();// fill the field
	virtual void printError(std::ostream& ostr);// printError

private:
	T1 * m_DestField;// m_DestField
	T2* m_classNameField;//m_classNameField
};
//-------------------------------------------------------------------------------


//--------------Template function test-------------------------------------------
// check if the fields  bonds  of destination and class are valid 
//if so return true else return false--------------------------------------------
template<typename T1, typename T2>
inline bool DestinationToClassValidator<T1, T2>::test()
{
	if (m_DestField->getData() == 1 || m_DestField->getData() == 2)
		return (m_classNameField->getData() != 3);
		if (m_DestField->getData() == 4 || m_DestField->getData() == 5)
			return (m_classNameField->getData() != 1);
			return true;
}
//--------------------------------------------------------------------------------


//-----------------template func that fillField-----------------------------------
template<typename T1, typename T2>
inline void DestinationToClassValidator<T1, T2>::fillField()
{
	m_DestField->get_input();//getInput
	m_classNameField->get_input();//getInput
}
//---------------------------------------------------------------------------------


//--------------------------printError---------------------------------------------
//template function that print the error if Destination and Class don't match 
template<typename T1, typename T2>
inline void DestinationToClassValidator<T1, T2>::printError(std::ostream & ostr)
{
	ostr << " Destination and Class don't match ";
}
//---------------------------------------------------------------------------------
