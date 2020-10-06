#pragma once
//----------------class FormValidator---------------------------------------------------
class FormValidator
{
public:
	
	virtual ~FormValidator() {};//Dtor
	virtual bool test() = 0;//pureVirtual test
	virtual void printError(std::ostream& ostr)= 0; //pureVirtual to print error if fail
	virtual void fillField() = 0;////pureVirtual test to fiellFields
};
//--------------------------------------------------------------------------------------

