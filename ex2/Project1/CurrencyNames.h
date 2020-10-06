#pragma once
//-----------IncludeSection-----------------------------------------------
#include "AbstractName.h"
#include <string>
//------------------------------------------------------------------------

//------------------class CurrencyNames-----------------------------------
class CurrencyNames :public AbstractName
{
public:
	CurrencyNames(){}//Ctor
	~CurrencyNames() {}//dtor
	const std::string& getName()const final;// getname
	
	operator int() const { return m_index_name; }// cast to int 
private:
	std::vector<std::string> m_currency_names = { "","NIS" ,"Euro" 
		,"Dollar" };// vector of string
};
//---------------------------------------------------------------------------


