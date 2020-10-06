#pragma once
#include "Pixel.h"
#include <algorithm>


class ImageDataStruct
{
public:
	
	ImageDataStruct();//Defult Ctor
	ImageDataStruct(int h,int w);//Ctor
	ImageDataStruct(const ImageDataStruct& other);//CopyCtor
	ImageDataStruct& operator=(const ImageDataStruct& other);//AssignmentOperator
	void swap(ImageDataStruct& other);//Helper func Swap 
	~ImageDataStruct();//Dtor
	
	//--------------LocalOperators-------------------------------
	bool operator==(const ImageDataStruct& other)const;//operator==
	ImageDataStruct operator+(const ImageDataStruct& other)const ;//operator+
	Pixel& operator()(unsigned int i, unsigned int j) { return m_pixels[i][j]; }//operator()
	const Pixel& operator()(unsigned int i, unsigned int j)const { return (*this).m_pixels[i][j]; }//operator()

	//------------------GetFunctions----------------------------
	int getHight()const { return m_height; }//getHight
	int getWidth()const { return m_width; }//getWidth

	
private:
	int m_height,//m_height
	m_width;//m_width
	Pixel** m_pixels;//m_pixels
	void insertToTempData(const ImageDataStruct& first, const ImageDataStruct& sec)const;//Utillity-insertToTempData
	
	
};
std::ostream&  operator<<(std::ostream& os, const ImageDataStruct& imgD);//GlobalOperator <<

