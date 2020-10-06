#pragma once
//----------------IncludeSection--------------------------------------------------------
#include <iostream>
#include "AbstractName.h"
//---------------------------------------------------------------------------------------

//----------------------template class ValuesToNames-------------------------------------
template<typename T>
class ValuesToNames
{
public:
	int getData() const { return m_data; }; //getData
	void setData(const int & a) { // setData
		m_data = a; 
		m_type.setName(m_data);
	};   
	 const std::string& getName() const;//getName
	operator int() const { return m_data; }; // case operator to int(must work on const object!)
private:
	int m_data; // Data
	T m_type;//m_type
	
};
//----------------------------------------------------------------------------------------

//-------------template getName-----------------------------------------------------------
//get the name from each vector of ClassName , CurrencyName, DestinationName
template<typename T>
const std::string& ValuesToNames<T>::getName() const {
	return m_type.getName();
}
//----------------------------------------------------------------------------------------

//-----------------template operator<----------------------------------------------------
template<typename T>
bool operator<(const ValuesToNames<T> & fv, const int& a)
{
	return int(fv) < a;
}
//---------------------------------------------------------------------------------------

//----------template operator>-----------------------------------------------------------
template<typename T>
bool operator>(const ValuesToNames<T> & fv, const int& a)
{	
	return int(fv) > a;
}
//---------------------------------------------------------------------------------------

//------------------template operator<<--------------------------------------------------
// --------------------print the name----------------------------------------------------
template<typename T>
inline std::ostream & operator<<(std::ostream & os, const ValuesToNames<T> & fv)
{
	os << fv.getName();
	return os;
}
//---------------------------------------------------------------------------------------

//--------------operator>>---------------------------------------------------------------
//--------cin to setData-----------------------------------------------------------------
template<typename T>
inline  std::istream & operator>>(std::istream & is, ValuesToNames<T> & fv)
{
	int x;
	is >> x;
	fv.setData(x);
	
	return is;
}
//----------------------------------------------------------------------------------------