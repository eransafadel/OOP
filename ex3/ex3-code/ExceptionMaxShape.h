//--------------include----------------------
#pragma once
#include <iostream>
//-------------class ExceptionMaxShape----------
class ExceptionMaxShape : public std::exception
{
public:
	ExceptionMaxShape() = default ;// default Ctor 
	~ExceptionMaxShape() = default;// default Dtor
};

