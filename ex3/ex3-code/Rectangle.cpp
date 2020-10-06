//----------------------include & using--------------------------
#include "Rectangle.h"
#include "Utils.h"
#include <iostream>
using std::cout;
using std::endl;
//---------------------Rectangle----------------------------------
//Ctor that Rectangle that read from user width and height and check if valid
Rectangle::Rectangle(std::istream& is)
: Shape("Rectangle")
{
	cout << "Please enter length of the width:" << endl;
	m_width = Utils::readInt(is);
	isRange(m_width);
	cout << "Please enter length of the height:" << endl;
	m_height = Utils::readInt(is);
	isRange(m_height);
}
//--------------------------area------------------------------------
//function that calculates the area of Rectangle
double Rectangle::area() const 
{
	return m_width * m_height;
}
//------------------------Rectangle---------------------------------
//function that calculates the perimeter of Rectangle
double Rectangle::perimeter() const
{
	return m_height * 2 + m_width * 2;
}
//------------------------draw------------------------------------
//function that draw Rectangle
void Rectangle::draw() const
{
	printDetails();
	cout << endl;
	for (int i = 1; i <= m_height; i++)
	{
		for (int j = 1; j <= m_width; j++)
		{
			if (i == 1 || i == m_height || j == 1 || j == m_width)
				std::cout << '*';
			else
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
}
//-------------------printDetails-----------------------------
//function that print details of Rectangle
void Rectangle::printDetails() const
{
	printName();
	cout << "(w:" << m_width << ", h:" << m_height <<")";
}
