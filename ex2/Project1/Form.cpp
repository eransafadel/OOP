#include "Form.h"

//---------------addField--------------------------------------------------------
void Form::addField(AbsField * f)
{
	 m_fields.push_back(f); 
}
//------------------------------------------------------------------------------


//-------------------------fillForm------------------------------------------------
void Form::fillForm()
{
	static bool firstTime = true; // to get input in the first time

	for (size_t i = 0; i < m_fields.size(); i++)
	{						// get input in the first time or the field is ilegal
		if (firstTime || !(m_fields[i])->isLegal())
			(m_fields[i])->get_input(); // get input
	}
	if (!firstTime)
	{
		for (size_t i = 0; i < m_Formvalidators.size(); i++)
			if (!(m_Formvalidators[i]->test()))
				(m_Formvalidators[i])->fillField();
	}

	firstTime = false; // after first data input

}
//----------------------------------------------------------------------------------


//------------------validateForm----------------------------------------------------
bool Form::validateForm()
{
	// check if the fields are ok
	for (size_t i = 0; i < m_fields.size(); i++)
		if (!(m_fields[i])->isLegal())
			return false;

	// check if the form is ok
	for (size_t i = 0; i < m_Formvalidators.size(); i++)
		if (!(m_Formvalidators[i]->test()))
			return false;

	return true;
}
//-----------------------------------------------------------------------------------

//----------operator<<---------------------------------------------------------------
std::ostream & operator<<(std::ostream & os, const Form & fo)
{
	// print all the fields
	for (size_t i = 0; i < fo.m_fields.size(); i++)
		((fo.m_fields)[i])->print(os);

	for (size_t i = 0; i < fo.m_Formvalidators.size(); i++)
		if (!(fo.m_Formvalidators[i]->test()))
		{
			os << "* ";
			(fo.m_Formvalidators)[i]->printError(os);
			os << std::endl;
		}

	return os;

}
//------------------------------------------------------------------------------------
