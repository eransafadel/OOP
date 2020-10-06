//-----------------------include & using----------------------
#include "Triangle.h"
#include <iostream>
#include "Utils.h"
using std::cout;
using std::endl;
//---------------------Triangle---------------------------------
//Ctor that Triangle that read from user width and height and check if valid
Triangle::Triangle(std::istream& is)
	: Shape("Triangle")
{
	cout << "Please enter length of the width:" << endl;
	m_width = Utils::readInt(is);
	cout << "Please enter length of the height:" << endl;
	m_height = Utils::readInt(is);
}
//------------------printDetails---------------------------------
//function that print details of Triangle
void Triangle::printDetails()const
{
	printName();
	cout << "(w:" << m_width << ", h:" << m_height << ")";
}
//-------------------area--------------------------------------
//function that calculates the area of Triangle
double Triangle::area() const
{
	return static_cast<double>(m_width * m_height) / 2;
}
//-----------------perimeter-----------------------------------
//function that calculates the perimeter of Triangle
double Triangle::perimeter() const
{
	const double sqrtResult = sqrt(m_width/2 * (m_width/2) + m_height * m_height);//להחליף שם למשתנה
	return 2 * sqrtResult + m_width;
}
//---------------draw-----------------------------------------
//function that draw Triangle
void Triangle::draw() const
{
	printDetails();
	cout << endl;

	int k = 0;
	for (int i = 1; i <= m_width/2; i++) 
	{
		// Print spaces 
		for (int j = i; j < m_width/2; j++) {
			std::cout << " ";
		}
		while (k != 2 * i - 1) {
			if (k == 0 || k == 2 * i - 2)
				std::cout << "*";
			else
				std::cout << " ";
			k++;
		}
		k = 0;
		std::cout << std::endl; // print next row 
	}
	// print last row 
	for (int i = 0; i < m_width; i++) {
		std::cout << "*";
	}
	std::cout << std::endl;
}

