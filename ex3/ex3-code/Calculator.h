//-----------------------include-------------------------
#pragma once
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include "ExceptionFile.h"
#include "ExceptionMaxShape.h"
#include "ExceptionResize.h"
#include <cstdlib>
#include "ColorText.h"
#include "Macros.h"
//--------------------------------------------------------
class CalculatorItem;
//---------------------class Calculator------------------- 
class Calculator
{
public:
	//-------------function-------------------------------
	Calculator() ;//Ctor of Calculator
	~Calculator() = default; // default Dtor of Calculator
	void run(); //run
	void optionsOnLoop(const std::string&);//optionsOnLoop
	std::shared_ptr<CalculatorItem> operator[](int index) const;//operator[]
	bool getIsOpen()const { return m_isOpen; }
private:
	//------------ Private Function-----------------------
	static std::string getUserCommand(); //getUserCommand
	static void exit();//msg exit
	static void help();//msg help
	void calculateArea();//calculateArea
	void calculatePerimeter();//calculatePerimeter
	void drawItem();//drawItem
	void findAllSameShapes();//findAllSameShapes
	void deleteItem();//deleteItem
	void findMin();//findMin
	void findMax();//findMax
	void same(int index) const;//same
	void printItemList() const;//printItemList
	//--------------------- Adds functions-----------------
	static void ExceptionMsg() { std::cout << "EXCEPTION:"; }// exception msg
	static void ErrorCommand();//ErrorCommand
	void FileMode();// modes of read from file 
	void readFromFile();//read from file
	void createShape();//createShape
	void StoreOnDataBase();//StoreOnDataBase
	void insertShapes();//insertShapes
	bool isContainDigit(const std::string&)const;//isContainDigit
	void checkNumberShapes();//checkNumberShapes
	//---------------function of catch exception---------------
	void rangeError(int)const;//rangeError
	void maxMsgException() const ;//maxMsgException
	void maxShapeMsgException() const;//maxShapeMsgException
	void fileException();//fileException
	void msgException()const;//msgException
	bool isContainedAlpha(const std::string&)const;//isContainedAlpha
	void restOfLine();//restOfLine
	//--------------------------data members------------------------
	std::ifstream myfile;//file 
	bool m_isOpen;// check if the file is open
	unsigned int m_index; //for the line number
	bool m_is_Exception;// check if throw exeption
	bool flag;//for the second opening the file
	int max_shape;//max_shape
	std::string m_garbage_collector;
	bool m_valid_max_shape;//check if max shape is valid
	std::vector<std::string> m_matrix;//read all the commands from the file to the matrix
	std::vector<std::shared_ptr<CalculatorItem>> m_calculatorItems;//m_calculatorItems
	std::string command; //command
	bool m_replacefile;//m_replacefile
	
};

