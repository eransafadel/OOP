#pragma once
//------------------IncludeSection---------------------------------------------
#include "AbstractName.h"
//-----------------------------------------------------------------------------

//-------------class DestinationNames------------------------------------------
class DestinationNames : public AbstractName
{
public:
	DestinationNames(){}//Ctor
	~DestinationNames() {}//Dtor
	const std::string& getName() const final;//getname
	operator int() const { return m_index_name; }//cast to int 

private:
	std::vector<std::string> m_DestinationNames = { "","Rome" ,"Prague" 
		,"New York","India","Thailand" };//cast to int 
};
//----------------------------------------------------------------------------



