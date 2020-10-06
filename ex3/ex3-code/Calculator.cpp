//---------------------include-------------------------------
#include "CalculatorItem.h"
#include "Calculator.h"
#include "Add.h"
#include "Subtraction.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Multiply.h"
#include "Utils.h"
#include <iostream>
#include <cstdlib>
//------------------------using-----------------------------
using std::cout;
using std::cin;
using std::endl;
using std::string;
//------------------function--------------------------------

//---------------getUserCommand------------------------------
//function that get from user command
string Calculator::getUserCommand()
{
	string act;
	cout << endl << "Please enter a command (\"help\" for command list):" << endl;
	cin >> act;
	return act;
}
//----------------exit--------------------------------------
//function tht print msg exit
void Calculator::exit()
{
	cout << "Goodbye.";
}
//---------------calculateArea-----------------------------
//function that calculate the Area and print details
void Calculator::calculateArea()
{
	int index;
	if (m_isOpen)
		index = Utils::readInt(myfile);
	else
		index = Utils::readInt(std::cin);
	rangeError(index);//check if index in range
	cout << "Area ";
	m_calculatorItems[index]->printDetails();
	cout << " = " << m_calculatorItems[index]->area() << endl;
}
//-----------------calculatePerimeter--------------------
//function that calculate the Perimeter and print details
void Calculator::calculatePerimeter()
{
	int index;
	if (m_isOpen)
		index = Utils::readInt(myfile);
	else
		index = Utils::readInt(std::cin);
	rangeError(index);//check if index in range
	cout << "Perimeter ";
	m_calculatorItems[index]->printDetails();
	cout << " = " << m_calculatorItems[index]->perimeter() << endl;
}
//------------------drawItem---------------------------
//function that draw item 
void Calculator::drawItem()
{
	int index;
	if (m_isOpen)
		index = Utils::readInt(myfile);
	else
		index = Utils::readInt(std::cin);
	rangeError(index);//check if index in range
	m_calculatorItems[index]->draw();
}
//------------------findAllSameShapes--------------------
//function that find all same shapes
void Calculator::findAllSameShapes()
{
	int index;
	if (m_isOpen)
		index = Utils::readInt(myfile);
	else
		index = Utils::readInt(std::cin);
	rangeError(index);//check if index in range
	same(index);
}
//------------------deleteItem--------------------------
//function the delete item
void Calculator::deleteItem()
{
	int index;
	if(m_isOpen)
		index = Utils::readInt(myfile);
	else
		index = Utils::readInt(std::cin);
	rangeError(index);//check if index in range
	m_calculatorItems.erase(m_calculatorItems.begin() + index);
}
//-----------------findMin--------------------------------
//function that find Min area in m_calculatorItems
void Calculator::findMin()
{
	int amount;
	if (m_isOpen)
		amount = Utils::readInt(myfile);
	else
		amount = Utils::readInt(std::cin);

	if (amount < MIN_RANGE || amount > m_calculatorItems.size())
		throw std::exception();
	//in first time (for Comparison)
	int index;
	if (m_isOpen)
		index = Utils::readInt(myfile);
	else
		index = Utils::readInt(std::cin);
	rangeError(index);//check if index in range
	double min = m_calculatorItems[index]->area();

	for (int i = 0; i < amount - 1; i++)
	{
		int index;
		if (m_isOpen)
			index = Utils::readInt(myfile);
		else
			index = Utils::readInt(std::cin);
		rangeError(index);//check if index in range
		min = m_calculatorItems[index]->area() < min ? m_calculatorItems[index]->area() : min;
	}
	cout << "The minimum area is:" << min << endl;
}
//--------------------findMax-----------------------
//function that find Max area in m_calculatorItems
void Calculator::findMax()
{
	int amount;
	if (m_isOpen)
		amount = Utils::readInt(myfile);
	else
		amount = Utils::readInt(std::cin);

	if (amount < MIN_RANGE || amount > m_calculatorItems.size())
		throw std::exception();
	//Calculates the largest area of all selected shapes, return the index of the maxim
	double max = 0;
	for (int i = 0; i < amount; i++)
	{
		int index;
		if (m_isOpen)
			index = Utils::readInt(myfile);
		else
			index = Utils::readInt(std::cin);
		rangeError(index);//check if index in range
		max = m_calculatorItems[index]->area() > max ? m_calculatorItems[index]->area() : max;
	}
	cout << "The maximum area is:" << max << endl;
}
//--------------------Calculator----------------------------------
//Ctor of Calculator that update data members
Calculator::Calculator()
	:myfile("example.txt"),m_isOpen(false), m_index(MIN_RANGE),
	m_is_Exception(false),max_shape(MIN_RANGE),m_valid_max_shape(false), flag(false), m_replacefile(false)
{
}
//----------------------run---------------------------------------
//the main function in this class, performs actions at user request
void Calculator::run()
{
	checkNumberShapes();
	while (true)
	{
		try
		{
			if (m_replacefile)
				throw ExceptionFile();
			if (m_is_Exception)
			{
				FileMode();
				continue;
			}
			else 
			{
			printItemList();
			//the user request is in the form of string
			 command = getUserCommand();
			}
			//create a basic shape and put it in the calculator
			if (command == "cre")
			{
				createShape();
				continue;
			}
			//exit from program
			if (command == "exit")
			{
				exit();
				return;
			}
			optionsOnLoop(command);	// the rest of the commands
			
		}
		catch (const ExceptionResize&) 
		{
			maxMsgException();
			restOfLine();
		}
		catch (const ExceptionMaxShape&)
		{
			
			maxShapeMsgException();	
			restOfLine();
		}
		catch (const ExceptionFile&)
		{
		
			fileException();
			m_replacefile = false;
			restOfLine();
		}
		catch (const std::exception&)
		{
			if (!m_isOpen)
			{
				SetOutputColor();
				ErrorCommand();
				ResetOutputColor();
				restOfLine();
			}
			else 
				m_replacefile = true;
		}	
	}
}
//----------------------optionsOnLoop-----------------------------
//function that performs the rest of the actions at user request
void Calculator::optionsOnLoop(const std::string & command)
{
	//request for the list of option to action(-to requests)
	if (command == "help")
	{
		help();
		return;
	}
	//calculate the area of a shape from the calculator, the shape is requested by number(-index)
	if (command == "area")
	{
		calculateArea();
		return;
	}
	//calculate the perimeter of a shape from the calculator, the shape is requested by number(-index)
	if (command == "per")
	{
		calculatePerimeter();
		return;
	}
	//create a new shape that consist of multiple of one shape, and put it in the calculator
	if (command == "mul")
	{
		if (m_calculatorItems.size() >= max_shape)
			throw ExceptionMaxShape();
		if(m_isOpen)
			m_calculatorItems.push_back(std::make_shared<Multiply>(myfile, *this));
		else
			m_calculatorItems.push_back(std::make_shared<Multiply>(std::cin, *this));
		return;
	}
	//create a new shape that consist of add of one shape and another shape, and put it in the calculator
	if (command == "add")
	{
		if (m_calculatorItems.size() >= max_shape)
			throw ExceptionMaxShape();
		if(m_isOpen)
			m_calculatorItems.push_back(std::make_shared<Add>(myfile, *this));
		else
			m_calculatorItems.push_back(std::make_shared<Add>(std::cin, *this));
		return;
	}
	//create a new shape that consist of subtraction of one shape from another shape, and put it in the calculator
	if (command == "sub")
	{
		if (m_calculatorItems.size() >= max_shape)
			throw ExceptionMaxShape();
		if(m_isOpen)
			m_calculatorItems.push_back(std::make_shared<Subtraction>(myfile, *this));
		else
			m_calculatorItems.push_back(std::make_shared<Subtraction>(std::cin, *this));
		return;
	}
	//Draws the shape (regardless of its actual size)
	if (command == "draw")
	{
		drawItem();
		return;
	}
	//Prints all indexes of the shapes that are equal in their area and perimeter to the selected shape
	if (command == "same")
	{
		findAllSameShapes();
		return;
	}
	//Deletes the required shape from the calculator and arranges the indexes of the other shapes
	if (command == "del")
	{
		deleteItem();
		return;
	}
	//Finds and prints the largest of the shapes in the calculator, according to the user selection
	if (command == "min")
	{
		findMin();
		return;
	}
	//Finds and prints the smallest of the shapes in the calculator, according to the user selection
	if (command == "max")
	{
		findMax();
		return;
	}
	//read commands on file
	if (command == "read")
	{
		readFromFile();
		return;
	}
	//resize max shape 
	if (command == "resize")
	{
		m_valid_max_shape = false;
		checkNumberShapes();
		if (max_shape < m_calculatorItems.size())
			throw ExceptionResize();
	}
	else
	{
		if (m_isOpen)// cuz the file 
			throw ExceptionFile();
		else
		throw std::exception();//If you type another command
	}
}
//----------------------operator[]-----------------------------------
//function that create operator[] to m_calculatorItems
std::shared_ptr<CalculatorItem> Calculator::operator[](int index) const
{
	if (index < MIN_RANGE || index >= m_calculatorItems.size())
		throw std::exception();
	return m_calculatorItems[index];
}
//--------------------------help---------------------------------------
//Prints a help screen with a list of possible commands and a brief explanation of it
void Calculator::help()
{
	cout << "Following is the list of the calculator's available commands" << endl
		<< "cre(ate) #shape <R - Rectangle | T-triangle | C- circle>" << endl
		<< "area num - Computes the area of shape #num" << endl
		<< "per(imeter) num - Computes the perimeter of shape #num" << endl
		<< "draw num - Draw the shape" << endl
		<< "#num mul(tiply) num x - Creates an item that is the multiplication of shape #num x times" << endl
		<< "add num1 num2 - Creates an item that is the sum of item #num1 and function #num2" << endl
		<< "sub num1 num2 - Creates an item that is the subtraction of item #num1 and function #num2" << endl
		<< "min n #num1-#numN - Returns the smallest area in the chosen shapes. n - the requested shapes: #num1..." << endl
		<< "max n #num1-#numN - Returns the biggest area in the chosen shapes. n - the requested shapes: #num1..." << endl
		<< "same num - Returns shapes with which have the same area and perimeter to the shape #num" << endl
		<< "del(ete) num - Deletes item #num from function list" << endl
		<< "help - Prints this help screen" << endl
		<< "exit - Exits the program." << endl;
}
//------------------ErrorCommand------------------------------------
//function that print msg Error
void Calculator::ErrorCommand()
{
	SetOutputColor();
	ExceptionMsg();
	cout<< "Input is invalid please enter a valid command\n";
	ResetOutputColor();
}
//--------------FileMode---------------------------------------------
//function that read commacnd on file and chack if all lines is valid
void Calculator::FileMode()
{
	static string line;
	while (!myfile.eof())
	{
		if (m_is_Exception)// so get the line of Excep
		{
			//getline(myfile, m_garbage_collector);
			m_is_Exception = false;
			//m_index++;
		}
		myfile >> line;
		if (line == "cre")
		{
			createShape();
			
			continue;
		}
		if (line == "exit")
		{
			exit();
			_exit(EXIT_SUCCESS);
		}
		optionsOnLoop(line);
		getline(myfile, line);//finish the rest line
		m_index++;
	}
	// if we finish to read
	{
		myfile.close();
		m_isOpen = false; // the file close
		m_is_Exception = false;
	}
}
//--------------------readFromFile-------------------------
//function that read from file the all command and throw exception if file is invalid
void Calculator::readFromFile()
{
	StoreOnDataBase();
	myfile.open("example.txt");
	m_isOpen = myfile.is_open();
	if (!m_isOpen)
		throw std::exception();
	FileMode();
}
//---------------------same-----------------------------------
//Prints all indices of the shapes that are equal in their area and scope to the selected shape
void Calculator::same(int index) const
{
	const double area = m_calculatorItems[index]->area();
	const double perimeter = m_calculatorItems[index]->perimeter();
	for (auto i = 0; i < m_calculatorItems.size(); ++i)
	{
		if (m_calculatorItems[i]->area() == area 
			&& m_calculatorItems[i]->perimeter() == perimeter
			&& i != index)
		{
			cout << i << ": ";
			m_calculatorItems[i]->printDetails();
			cout << endl;
		}
	}
	cout << endl;
}
//--------------------------createShape---------------------------------
//create new shape Rectangle/circle/triangle and insert to the list of the shapes (to the vector)
void Calculator::createShape()
{
	std::string c;
	m_isOpen ? myfile >> c: cin >> c; //read on ffile or cin
	if (!isContainedAlpha(c))
		throw std::exception();
	char shape = toupper(c[MIN_RANGE]);

	if ((shape == 'R' || shape == 'C'|| shape == 'T') && m_calculatorItems.size() >= max_shape)
		throw ExceptionMaxShape();

	if (shape == 'R')
	{
		m_isOpen ? m_calculatorItems.push_back(std::make_shared<Rectangle>(myfile)) :
			m_calculatorItems.push_back(std::make_shared<Rectangle>(std::cin));
		m_index++;
	}
	else if (shape == 'C')
	{
		m_isOpen ? m_calculatorItems.push_back(std::make_shared<Circle>(myfile)) :
			m_calculatorItems.push_back(std::make_shared<Circle>(std::cin));
		m_index++;
	}
	else if (shape == 'T')
	{
		m_isOpen ? m_calculatorItems.push_back(std::make_shared<Triangle>(myfile)) :
			m_calculatorItems.push_back(std::make_shared<Rectangle>(std::cin));
		m_index++;
	}
	else
	{
		if (m_isOpen) 
			throw ExceptionFile();
		else
			throw std::exception();
	}
}

//---------------------printItemList--------------------------------
//print the list of the shapes that in the vector
void Calculator::printItemList() const
{
	cout << "max shapes: " << max_shape << endl;
	int i = MIN_RANGE;
	cout << "\nThis is the shapes list:" << endl;
	for (auto& item : m_calculatorItems)
	{
		cout << i++ << ": ";
		item->printDetails();
		cout << endl;
	}
}
//---------------------StoreOnDataBase-----------------------------------
//function that open thr file and read from file all commands and insert to matrix and close file
void Calculator::StoreOnDataBase()
{
	m_matrix.resize(0);
	m_index = 0;
	static string temp;
	if (flag)
		myfile.open("example.txt");
	m_isOpen = myfile.is_open();
	if (!m_isOpen)
		throw std::exception();
	for (int i = 0; !myfile.eof(); i++)
	{
		getline(myfile, temp);
		m_matrix.push_back(temp);
	}
	myfile.close();
	flag = true;
}
//-----------------insertShapes---------------------------------------------
//function that calls from the user how many shapes to insert
//and throw exception if the data is invalid 
void Calculator::insertShapes()
{
	string m_count;
	
	if (m_isOpen)
		myfile >> m_count;
	else
	{
		cout << "PLEASE ENTER MAX OF SHAPES\n";
		cin >> m_count;
	}

	if (!isContainDigit(m_count) ||(stoi(m_count) <= MIN_RANGE || stoi(m_count) > MAX_RANGE ))
		throw std::exception();

	max_shape = stoi(m_count);
	m_valid_max_shape = true;
}
//-----------------isContainDigit-------------------------------------------
//function returns false if value contains not only numbers, otherwise returns true
bool Calculator::isContainDigit(const std::string & var)const
{
	for (int i = 0; i < var.size(); i++)
	{
		if (!isdigit(var[i]))
			return false;
	}
	return true;
}
//----------------checkNumberShapes--------------------------------------
//function that calls from the user max shape and throw exception if the data is invalid 
void Calculator::checkNumberShapes()
{
	while (!m_valid_max_shape) 
	{
		try {
			insertShapes();
		}
		catch (std::exception&)
		{
			std::string line;
			msgException();
			getline(std::cin, line);
		}
	}
}
//----------------------rangeError--------------------------
//function that check if index is range, otherwise throw exception
void Calculator::rangeError(int index)const
{
	if (index < MIN_RANGE || index >= m_calculatorItems.size())
		throw std::exception();
}
//----------------maxShapeMsgException------------------------
//function that print MsgException of error on max shape
void Calculator::maxShapeMsgException() const
{
	SetOutputColor();
	ExceptionMsg();
	cout << "NUMBER SHAPES OUT OF RANGE\nADD MORE SHAPES- PRESS RESIZE\n";
	ResetOutputColor();
}
//------------------fileException-------------------------------
//function that print MsgException of error on file
void Calculator::fileException()
{
	SetOutputColor();
	ExceptionMsg();
	cout << "ERROR IN LINE " << m_index << endl;
	cout << "THE LINE WITH ERROR IS: " << m_matrix[m_index] << endl;
	ResetOutputColor();
	cout << "YOU WANT TO CONTINUE READ THE FILE? PRESS y:PRESS OTHER \n";
	char c;
	cin >> c;
	if (c == 'y') // if you want to continue read from file
		m_is_Exception = true;

	else// close the file 
	{
		m_isOpen = false;
		myfile.close();
	}
}
//------------------msgException---------------------------
//function that print msg Exception 
void Calculator::msgException() const
{
	SetOutputColor();
	ExceptionMsg();
	cout << "The number is invalid\n";
	ResetOutputColor();
}
//---------------------isContainedAlpha-------------------------
//function that check if str is conatied only alpha
bool Calculator::isContainedAlpha(const std::string & str) const
{
	for(int i =0; i < str.size(); i++)
		if(!isalpha(str[i]) || str.size() > MIN_CHAR)
			return false;
	return true;
}
//---------------restOfLine----------------------------------
//function that rest of line when throw exception
void Calculator::restOfLine() 
{
	std::string line;
	if (m_isOpen)
		getline(myfile, line);
	else
		getline(std::cin, line);
	m_index++;
}
//--------------maxMsgException---------------------------
//function that print msg Exception of error in amount of shape
void Calculator::maxMsgException()const
{
	SetOutputColor();
	ExceptionMsg();
	cout << "Enter size that equal or bigger than:" << m_calculatorItems.size() << endl;
	cout << "Or delete items from end of list\n";
	ResetOutputColor();
}
