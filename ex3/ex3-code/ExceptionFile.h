//--------------include-------------------------
#pragma once
#include <iostream>
//------------------class ExceptionFile----------
class ExceptionFile :public std::exception
{
public:
	ExceptionFile() = default;//defalut Ctor 
	~ExceptionFile() = default;//defalut Dtor 
};

