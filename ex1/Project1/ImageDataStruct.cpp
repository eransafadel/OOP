#include "ImageDataStruct.h"




//---------------------Ctor ImageDataStruct----------------------------------------
ImageDataStruct::ImageDataStruct()
{
}
//---------------------------------------------------------------------------------

//------------------------------------Ctor----------------------------------------
//---------------------------------ImageDataStruct---------------------------------
ImageDataStruct::ImageDataStruct(int h = 0, int w = 0)
	:m_height(h),m_width(w) 
{
	if (m_height > 0 && m_width > 0)
	{
		m_pixels = new Pixel*[m_height];
		for (int i = 0; i < m_height; i++)
			m_pixels[i] = new Pixel[m_width];
	}
	else
		m_pixels = nullptr;
}
//-------------------------------------------------------------------------------

//------------------------Copy-Ctor-----------------------------------------------
//-------------ImageDataStruct----------------------------------------------------
ImageDataStruct::ImageDataStruct(const ImageDataStruct& other)
	:m_width(other.m_width),m_height(other.m_height), m_pixels( new Pixel*[m_height])
{		
			for (int i = 0; i < m_height; i++)	//new cells of size to other
				m_pixels[i] = new Pixel[m_width];

			for (int i = 0; i < m_height; i++)
				for (int j = 0; j < m_width; j++)
					m_pixels[i][j] = other.m_pixels[i][j];
}

//-----------------------------operator=-------------------------------------
//------------------Assienment operator--------------------------------------
ImageDataStruct& ImageDataStruct::operator=(const ImageDataStruct & other)
{
	if (this != &other)
	{
		ImageDataStruct temp (other);
		temp.swap(*this);
	}
	return (*this);
}

//-----------Swap - Helperfunc------------------------------------------------
// swap from this to other 
void ImageDataStruct::swap(ImageDataStruct & other)
{
	using std::swap;
	swap(m_width, other.m_width);
	swap(m_height, other.m_height);
	swap(m_pixels, other. m_pixels);
}

//-------------------~ImageDataStruct-----------------------------------------
ImageDataStruct::~ImageDataStruct()
{
	if (m_height > 0)// if there is something to delete
	{
		for (int i = 0; i < m_height; i++)  //Delete m_pixels of *this
			delete[]m_pixels[i];
		delete[] m_pixels;// realese 
	}
}
//------------------------------------------------------------------------------

//-----------------------operator==--------------------------------------------
bool ImageDataStruct::operator==(const ImageDataStruct & other) const
{
	for (int i = 0; i < m_height; i++)
		for (int j = 0; j < m_width; j++)
			if (m_pixels[i][j] != other.m_pixels[i][j])
				return false;
	return true;
}
//----------------------------------------------------------------------------

//---------------------------operator+----------------------------------------
ImageDataStruct ImageDataStruct::operator+(const ImageDataStruct & other)const
{
 ImageDataStruct temp (std::max((*this).getHight(), other.getHight()), (*this).getWidth() + other.getWidth());// big temp imageData
 temp.insertToTempData(*this, other);
 return temp;
}
//---------------------------------------------------------------------------

//----------------------insertToTempData-------------------------------------
// insert data to temp ImageDataStruct
void ImageDataStruct::insertToTempData(const ImageDataStruct & first,
	const ImageDataStruct & sec) const
{
	for (int i = 0; i < first.getHight(); i++)
		for (int j = 0; j < first.getWidth(); j++)
			m_pixels[i][j] = first(i,j);
	int k;// index for loop
	for (int i = 0; i < sec.getHight(); i++)
		for (int j = first.getWidth(),  k = 0; j < getWidth()&&k<sec.getWidth(); j++,k++)
			m_pixels[i][j] = sec(i,k);
}
//--------------------------------------------------------------------------


//---------------------operator<<-------------------------------------------
std::ostream & operator<<(std::ostream & os, const ImageDataStruct& imgD)
{
	for (int i = 0; i < imgD.getHight(); i++)
	{
		for (int j = 0; j < imgD.getWidth(); j++)
			os << imgD(i,j).getColor();
		os << std::endl;
	}
	return os;
}
//-------------------------------------------------------------------------
