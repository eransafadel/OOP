//---------------include-----------------------
#pragma once
#include <iostream>
//---------------class ExceptionResize---------
class ExceptionResize : public std::exception
{
public:
	ExceptionResize() = default; // default Ctor 
	~ExceptionResize() = default; // default Dtor 
};

