#pragma once
#include "Macros.h"





class Pixel
{
public:
	
	Pixel( );//Pixel
	unsigned char getColor()const { return m_color; }//getColor
	void setColor(unsigned char c) { m_color = c; }//setColor
	~Pixel();//Dtor

private:
	unsigned char m_color;//m_color

};
//--------------GlobalOperators-----------------------------------
bool operator==(const Pixel& p1, const Pixel& p2);//operator==
bool operator!=(const Pixel& p1, const Pixel& p2);//operator!=
std::ostream& operator<<(std::ostream& os, const Pixel& image);//operator<<
std::istream& operator>>(std::istream& is, Pixel& other);//operator>>
Pixel operator|(const Pixel& p1, const Pixel& p2);//operator|
Pixel& operator|=( Pixel& p1, const Pixel& p2);//operator|=
Pixel operator&(const Pixel& p1, const Pixel& p2);//operator&
Pixel& operator&=( Pixel& p1, const Pixel& p2);//operator&=
//---------------------------------------------------------------

