//---------------------include----------------------------------------
#include "Utils.h"
#include <iostream>

//------------------readInt-------------------------------------------
//function that read from user number and if is invalid throw exception,
//if valid return the number
int Utils::readInt(std::istream& is)
{
	static std::string number;
	std::string str;
	is >>number;
	if (is.fail()|| !isContainDigit(number))
	{
		is.clear();
		//std::getline(is, str);
		throw std::exception();
	}
	return stoi(number);
}
//--------------isContainDigit----------------------------------------------------
//function returns false if value contains not only numbers, otherwise returns true
bool Utils::isContainDigit(const std::string & var)
{
		for (int i = 0; i < var.size(); i++)
		{
			if (!isdigit(var[i]))
				return false;
		}
		return true;
}

