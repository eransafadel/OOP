#pragma once
class AbsValidator;// for  not circular include
//-------------IncludeSection-------------------------------------------------------
#include <iostream>

//-----------------------------------------------------------------------------------

//-------class AbsField--------------------------------------------------------------
class AbsField
{
public:

	virtual void get_input() = 0;//pure virtual  get input 
	virtual void addValidator(AbsValidator*) = 0;//pure virtual addValidator
	virtual std::ostream& print(std::ostream & os) const = 0; //pure virtual  print the print
	virtual bool isLegal() const = 0; //pure virtual check if that data in the field is legal
	virtual ~AbsField() {};//Dtor
};
//-------------------------------------------------------------------------------------

