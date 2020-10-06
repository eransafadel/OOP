#pragma once
//-------------IncludeSection--------------------------------------------
#include <vector>
#include "AbsField.h"
#include "FormValidator.h"
//-----------------------------------------------------------------------------

//------------------class Form--------------------------------------------------
class Form
{
public:
	void addField(AbsField *f);// addField
	void addValidator(FormValidator *f) { m_Formvalidators.push_back(f); }//addValidator
	void fillForm();// get user input for not legal fields
	
	bool validateForm();// check if the fileds are legals
	friend std::ostream& operator<<(std::ostream& os, const Form &fo);
private:
	std::vector<AbsField*> m_fields;//m_fields
	std::vector<FormValidator*> m_Formvalidators;//m_Formvalidators

};
//---------------------------------------------------------------------------------
//----------operator<<-------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Form &fo); // print Form

