#pragma once
//-------------IncludeSection--------------------------------------------------------
#include <vector>
#include "AbstractName.h"
//------------------------------------------------------------------------------------

//--------------class ClassNames-----------------------------------------------------
class ClassNames :public AbstractName
{
public:
	ClassNames(){}//ctor
	~ClassNames(){}//dtor
	const std::string& getName()const final;//getName
	operator int() const { return m_index_name; }// cast to int 

private:
	std::vector<std::string> m_class_names= { "","First Class" ,"Business Class" ,
		"Economy Class" };// vector of strings
	
};
//------------------------------------------------------------------------------------




