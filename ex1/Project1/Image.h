#pragma once
#include"ImageDataStruct.h"
#include <algorithm>
#include <string>
#include <sstream>

class Image
{
public:

	Image();//Defualt Ctor
	Image(int height, int width);//Ctor
	Image(const ImageDataStruct& a);//Ctor
	Image(const Image& other);//Copy Ctor
	~Image();//Dtor
	
	//-------------------GetFuncions-------------------------------------------------------------------
	int getHeight()const { return m_image_data.getHight(); }// Inline func getHeight
	int getWidth()const { return m_image_data.getWidth(); }	//Inline func getWidth
	//------------------LocalOperators-----------------------------------------------------------------
	bool operator==(const Image & other)const;//operator==
	Image& operator=(const Image & other);//operator=
	const Pixel& operator()(unsigned int i, unsigned int j)const { return m_image_data(i,j); }//operator()
    Pixel& operator()(unsigned int i, unsigned int j) { return m_image_data(i, j); }//operator()
	const Image  operator+(const Image & other)const ;//operator+
	
private:
	ImageDataStruct m_image_data;//m_image_data
};
//--------------GlobalOperators---------------------------------------------------------------------
bool operator!=(const Image & im1, const Image & im2);// operator!=
Image&  operator+=(Image & im1, const Image & im2);// operator+=
std::ostream& operator<<(std::ostream& os, const Image& image);// operator<<
std::istream& operator>>(std::istream& is, Image& image);//operator>>
Image& operator|=( Image& image1, const Image& image2);// operator|=
Image operator|(const Image& im1, const Image& im2);// operator|
Image operator&(const Image& im1, const Image& im2);// operator&
Image operator&=(Image& im1, const Image& im2);// operator&=
Image operator*(const Image& im1, unsigned int n);// operator*
Image operator*(unsigned int n,const Image& im1);// operator*
Image operator*=(Image& im1, unsigned int n);// operator*=
Image& operator++(Image& my);// operator++
Image operator++(Image& my, int);// operator++
Image& operator--(Image& my);// operator--
Image operator--(Image& my, int);// operator--
//------------------------------------------------------------------------------------------------