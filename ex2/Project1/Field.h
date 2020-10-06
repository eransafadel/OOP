#pragma once
//----------IncludeSection-------------------------------------------
#include "AbsField.h"
#include"AbsValidator.h"
#include <vector>
#include <string>
//---------------------------------------------------------------------

//------------TemplateClassField---------------------------------------
template <typename T>
class Field:public AbsField
{
public:
	Field(const std::string ques):m_question(ques){}//Ctor
	virtual void get_input() override;//get_input
	void addValidator(AbsValidator* add) override;//addValidator
	bool isLegal() const override;//isLegal
	virtual T getData() const; // return the field data
	virtual std::ostream& print(std::ostream & os) const; // print the field
private:
	std::vector <AbsValidator*> m_validators;//vector of validators
	T m_data;//Data
	std::string m_question;// questionFromUser 

};
//-----------------------------------------------------------------------

//-----------------------TemplateFunction get_input----------------------
template<typename T>
void Field<T>::get_input()
{
	std::cout << m_question << std::endl; // the question
	std::cin >> m_data; // get from user input
}
//-----------------------------------------------------------------------

//-------------------template func addValidator-------------------------
template<typename T>
void Field<T>::addValidator(AbsValidator * add)
{
	m_validators.push_back(add);// add to vector

}
//----------------------------------------------------------------------

//----------------------Template func isLegal-------------------------
//----check with all the valiadtors if the field data is legal-------
template<typename T>
bool Field<T>::isLegal() const
{
	// check with all the valiadtors if the field data is legal
	for (size_t i = 0; i < m_validators.size(); i++)
		if (!((m_validators[i])->test(*this)))
			return false;

	return true;
}
//----------------------------------------------------------------------

//------------template func getData-------------------------------------
template<typename T>
T Field<T>::getData() const
{
	return m_data;// return data
}
//-----------------------------------------------------------------------

//----------------template func print-------------------------------------------
template<typename T>
inline std::ostream & Field<T>::print(std::ostream & os) const
{
	os << m_question << " = " << m_data << std::endl; // print the data
	for (size_t i = 0; i < m_validators.size(); i++)// running  func test on vector
		if (!((m_validators[i])->test(*this)))// if not valid 
		{
			os << "*";
			(m_validators[i])->printError(os);
			os << std::endl;
		}
	return os;
}
//-----------------------------------------------------------------------------



