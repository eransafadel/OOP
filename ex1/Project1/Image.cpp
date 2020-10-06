#include "Image.h"


//------------------Defult Ctor----------------------------------------
Image::Image()	
	:Image(0,0)
{}
//--------------------------------------------------------------------
//--------------Ctor-------------------------------------------------
Image::Image(int height, int width)
 :m_image_data(height,width)
{
}
//------------------------------------------------------------------

//---------------Ctor------------------------------------------------
Image::Image(const ImageDataStruct & a)
: m_image_data(a)
{
}
//------------------------------------------------------------------


//-------------------------Dtor--------------------------------------
Image::~Image()
{
}
//-------------------------------------------------------------------

//--------------Copy ctor----------------------------------------------
// copy the image to other new mage
Image::Image(const Image & other)
	:Image(other.getHeight(),other.getWidth())
{
	for(int i=0;i<other.getHeight();i++)
		for (int j = 0; j < other.getWidth(); j++)
			m_image_data(i,j) = other.m_image_data(i, j);
}
//----------------------------------------------------------------------


//-----------------------operator==   ------------------------------------
// return if the image equal to other image
bool Image::operator==(const Image & other) const
{
	return(getHeight() == other.getHeight() && getWidth() == other.getWidth() && m_image_data == other.m_image_data);
}
//----------------------------------------------------------------------

//-------------------------------operator=------------------------------
//---------------------- Assign operator--------------------------------
// take 2 images and assign other with this 
Image & Image::operator=(const Image & other)
{
	if (this != &other)
		m_image_data = other.m_image_data;
	return *this;
}

//------------------------operator+=--------------------------------------
//return the result of plus of 2 images and change this 
const Image Image::operator+(const Image & other) const
{
	return Image(m_image_data + other.m_image_data);
}
//------------------------------------------------------------------------

bool operator!=(const Image & im1, const Image & im2)
{
	return !(im1 == im2);
}

//------------------------operator+=--------------------------------------
//return the result of plus of 2 images and change this 
 Image& operator+=(Image & im1, const Image & im2)
{
	return im1 = im1+im2 ;
}
 //------------------------------------------------------------------------

 //--------------------------operator<<------------------------------------
 //					print the image to ostream
std::ostream & operator<<(std::ostream & os, const Image & image)
{
	for (int i = 0; i < image.getHeight(); i++)
	{
		for (int j = 0; j < image.getWidth(); j++)
		os << image(i, j);
	os << '\n';
	}
	return os;
}
//------------------------------------------------------------------------


//---------------------------------operator>>-------------------------------
// refresh image by new size 
std::istream & operator>>(std::istream & is, Image & image)
{
	using std::string;
	string tempstr;
	int height, width;
	is >> height >> width;
	getline(is, tempstr);
	Image temp(height, width);
	for (int i = 0; i < height; i++)
	{
	getline(is, tempstr);// read a line to tempstr
	for (int j = 0; j < width; j++)
		 temp(i, j).setColor((unsigned char)tempstr[j]);
	}
	getline(is, tempstr);
	image = temp;
	return is;	
}

//-------------------------- operator|= -----------------------------------
// //Crop between images takes the darker color and change this
Image & operator|=(Image & image1, const Image & image2)
{
	return image1 = image1 | image2;
}
//------------------------------------------------------------------------

//--------------------------- operator|---------------------------------------------
//Crop between images takes the darker color
Image operator|(const Image & im1, const Image & im2)
{
	using std::max;
	Image temp(max(im1.getHeight(), im2.getHeight()), max(im1.getWidth(), im2.getWidth()));
	for (int i = 0; i < im1.getHeight(); i++)
		for (int j = 0; j < im1.getWidth(); j++)
			temp(i, j) |= im1(i, j);

	for (int i = 0; i < im2.getHeight(); i++)
		for (int j = 0; j < im2.getWidth(); j++)
			temp(i, j) |= im2(i, j);
	return temp;
}
//--------------------------------------------------------------------------------

//---------------------------operator&----------------------------------------------
//Crop between images takes the lighter color
Image operator&(const Image & im1, const Image & im2)
{
	using std::min;
	Image temp(min(im1.getHeight(), im2.getHeight()), min(im1.getWidth(), im2.getWidth()));
	for (int i = 0; i < min(im1.getHeight(), im2.getHeight()); i++)
		for (int j = 0; j < min(im1.getWidth(), im2.getWidth()); j++)
			temp(i, j) = im1(i, j) & im2(i,j);
	return temp;
}
//------------------------------------------------------------------------------

//---------------------operator&=-------------------------
//Crop between images takes the lighter color and change this
Image operator&=(Image & im1, const Image & im2)
{
	return im1 = im1 & im2;
}
//--------------------------------------------------------

//------------------------operator*------------------------
// mul by 2 images
Image operator*(const Image & im1, unsigned int n)
{
	Image temp;
	for (int i = 0; i < n; i++)
		temp += im1;
	return temp;
}
//--------------------------------------------------------

//----------------------operator*--------------------------
Image operator*(unsigned int n, const Image & im1)
{
	return Image(im1*n);
}
//---------------------------------------------------------

//---------------------operator*=-------------------------
//-----------------chenge this ---------------------------
Image operator*=(Image & im1, unsigned int n)
{
	return im1 = im1 * n;
}
//--------------------------------------------------------


//-----------------operator++-----------------------------
//-- change this the actually one
Image & operator++(Image & my)
{
	Image temp(my.getHeight(), my.getWidth() * 2);
	for (int i = 0; i < my.getHeight(); i++)
		for (int j = 0,k=0 ;j < my.getWidth(); j++,k+=2)
			temp(i, k)= temp(i,k+1)= my(i, j);
	my = temp;
	return my;
}
//-------------------operator++----------------------------
// change this and return a copy before changes
Image operator++(Image & my, int)
{
	Image temp(my);
	++my;
	return temp;
}

//------------------ operator----------------------------
//--------------the actually one -----------------------
Image & operator--(Image & my)
{
	Image temp(my.getHeight(), my.getWidth()/2);
	for (int i = 0; i < my.getHeight(); i ++)
		for (int j = 1 ,k=0; k < temp.getWidth(); j+=2,k++)
			temp(i, k) = my(i, j);
	my = temp;
	return my;
}
//-------------------------------------------------------

//-----------------  operator--    ----------------------
//-- change this and return a copy before changes 
Image operator--(Image & my, int)
{
	Image temp(my);
	--my;
	return temp;
}
//--------------------------------------------------------






