#pragma once
//------------IncludeSection--------------------------------------------------------
#include <string>
#include <vector>
#include "Macros.h"
//----------------------------------------------------------------------------------

//---------class AbstractName--------------------------------------------------------
class AbstractName
{
public:
	AbstractName(){}// Ctor
	~AbstractName(){}//Dtor
	virtual const std::string& getName()const = 0;//getName
	void setName(int n) { m_index_name = n; }//setName

protected:
	int m_index_name;//m_index_name
};
//-----------------------------------------------------------------------------------
