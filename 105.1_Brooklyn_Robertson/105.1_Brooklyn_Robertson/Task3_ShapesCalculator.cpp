// brooklyn_robertson_105.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Task3.h"

class Shape {
protected:
	double base, height, result;//our member variables that derived classes will inherit
	std::string name;
public:
	Shape() : base(0), height(0), result(0), name("Default")
	{ 	}

	//function to display the physical shape
	virtual void printShape()  {
		std::cout << "If you see this, you called the printShape() function in the SHAPE class.\n\n\n";
	}

	//returns the calculation of the area of a shape, takes double datatype values as param 
	double calcArea(double a, double b) {
		return a * b;
	}

	//takes input from user
	void setData()  {
		std::cout << "Please enter base in centimeters: \n";
		std::cin >> base;
		std::cout << "Please enter height in centimeters: \n;";
		std::cin >> height;
	}
	
	//gets value from private area of object
	double getData(double c) { return c; }
	
	//function displays a menu title containing 21 top & bottom astericks lines
	void shapeMenu() {


		//loop to iterate three times:
		//first and last iterations print the astericks line, 
		for (int i = 0; i < 3; i++) {
			if (i == 1) {
				std::cout << "\n* Shapes Calculator *\n";//middle iteration prints the formatted param string name.
			}
			else {

				for (int j = 0; j < 21; j++) {//print '*' 21 times in a line
					std::cout << '*';
				}
			}
			std::cout << "\n";//new line after each line, including at the end of program.
		}
	}

	//OVERLOADED function (takes string param to reuse wth different names as the menu title)
	void shapeMenu(std::string s) {
		

		//loop to iterate three times:
		//first and last iterations print the astericks line, 
		for (int i = 0; i < 3; i++) {
			if (i == 1) {
				std::cout << "\n* " << s << " *\n";//middle iteration prints the formatted param string name.
			}
			else {
				
				for (int j = 0; j < 21; j++) {//print '*' 21 times in a line
					std::cout << '*';
				}
			}
			std::cout << "\n";//new line after each line, including at the end of program.
		}
	}

	//OVERLOADED function (custom set astericks length) as well as string input
	void shapeMenu(std::string s, int n) {

		
		for (int i = 0; i < 3; i++) {//n takes value taken at function call
			if (i == 1) {
				std::cout << "\n* " << s << " *\n";
			}
			else {
				
				for (int j = 0; j < n; j++) {//n value taken at function call
					std::cout << '*';
				}
			}
			std::cout << "\n";//new line after each line, including at the end of program.
		}
	}


	void giveResult(double result) {
		std::cout << "The result is: " << result << " square centimeters (sq.cm)\n\n";
		
	}
};


//derived/child class of base/parent class (Shape)
class Circle : public Shape {
	//our member variables
	const double pi{3.14};
	double radius, result;
	std::string name{ "Circle Calculator" };

public:
	Circle() : Shape()
	{
		height = pi; base = radius; Shape::result = result; Shape::name = name;
		this->shapeMenu(name, 23);
		
	}

	//function to display the physical shape
	void printShape() {
		int choice;
		bool looping = false;
		std::cout << "\n\n";
		for (int i = 0; i < 20; i++) {
			for (int j = 50; j > 20; j--) {
				std::cout << '*';
			}
			std::cout << "\n";
		}
		while (looping) {
			std::cout << "\n\n\nPlease choose (1, 2 or 3) of following options: \n" <<
				"1. Area (Area = radius * 2 * pi sq.units)\n" <<
				"2. Perimeter (Perimeter = pi * radius squared sq.units)\n" <<
				"3. Go back to main menu (Shapes Calculator)\n";

			std::cin >> choice;

			switch (choice) {
			case 1:
				setData();
				result = calcArea(pi, radius);//calculate area and get result
				giveResult(result);
				break;
			case 2:
				setData();
				result = calcPerimeter(pi, radius);//calculate perimeter and get result
				giveResult(result);
				break;
			case 3:
				looping = false;//end the loop
				break;
			}

		}
	}
	

	//returns the calculation of the area of a circle. a is pi so is overloaded
	double calcArea(const double a, double b) {
		b *= b;
		return a * b;
	}


	//function returns perimeter based on given parameters. a is pi so is overloaded
	double calcPerimeter(const double a, double b) {
		double c{0};
		c *= a * 2;
		c = a * b;
		return c;
	}


	//takes input from user (only radius)
	void setData() {
		std::cout << "Please enter radius in centimeters: \n";
		std::cin >> base;
	}


	double getBase(double c) { return c; }
};

//derived/child class of base/parent class (Shape)
class Rectangle : public Shape {

	double length, width, result;//our member variables that derived classes will inherit
	std::string name{ "Rectangle" };

public:
	Rectangle() : Shape() //default contructor
	{
		std::cout << "rectangle initialized....\n";
		base = length; height = width, Shape::result = result;
		this->shapeMenu(name, 23);
		this->printShape();//displays rectangle shape
		
	}
	//function to display the physical shape
		//function to display the physical shape and loop to get calulations done
	void printShape() {
		int choice;
		bool looping = false;

		//nested loop orints rectangle shape
		std::cout << "\n\n";
		for (int i = 0; i < 18; i++) {
			for (int j = 0; j < 8; j++) {
				std::cout << '*';
			}
			std::cout << "\n";
		}
		while (looping) {
			std::cout << "Please choose (1, 2 or 3) of following options: \n" <<
				"1. Area (Area = length * width sq.units)\n" <<
				"2. Perimeter (Perimeter = length * width * 2 sq.units)\n" <<
				"3. Go back to main menu (Shapes Calculator)\n";

			std::cin >> choice;

			switch (choice) {
			case 1:
				setData();
				result = calcArea(length,width);//calculate area and get result
				giveResult(result);
				break;
			case 2:
				setData();
				result = calcPerimeter(length, width);//calculate perimeter and get result
				giveResult(result);
				break;
			case 3:
				looping = false;//end the loop
				Shape::shapeMenu();
				break;
			}

		}
	}

	//returns the calculation of the area of a shape, takes double datatype values as param 
	double calcArea(double a, double b) {
		return a * b;
	}

	//function returns perimeter based on given parameters
	double calcPerimeter(double a, double b) {
		return (a * b) * 2;
	}


	//getter, returns a value
	double getData(double c) { return c; }

//OVERLOADED function to display menu title and name
	void shapeMenu(std::string s, int n) {


		for (int i = 0; i < 3; i++) {//n takes value taken at function call
			if (i == 1) {
				std::cout << "*" << name << "*";//middle iteration prints the title .
			}
			else {
				//n value taken at function call
				for (int j = 0; j < n; j++) {
					std::cout << '*';
				}
			}
			std::cout << "\n";//new line after each line, including at the end of program.
		}
	}	
	

	//function override to change values to display relevant variables to user (length/width)
	void setData() {
		std::cout << "\nPlease enter length in cm: ";
		std::cin >> length;
		std::cout << "\nPlease enter width in cm: ";
		std::cin >> width;
	}
};

//derived/child class of base/parent class (Shape)
class Square : public Shape {
	double side, result;//our member variables that derived classes will inherit
	std::string name{ "Square Calculator" };

public:
	Square() : Shape() //default contructor
	{
		std::cout << "square initialized....\n";
		base = side; height = side, Shape::result = this->result;//setting default values
		this->shapeMenu(name, 24);//runs menu for square
		this->printShape();//displays squares shape 

	}
	//function to display the physical shape and loop to get calulations done
	void printShape() {
		int choice;
		bool looping = false;
		
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 10; j++) {
				std::cout << '*';
			}
			std::cout << "\n";
		}
		looping = true;
		while (looping) {
std::cout << "Please choose (1, 2 or 3) of following options: \n" <<
			"1. Area (Area = side * side sq.units)\n" <<
			"2. Perimeter (Perimeter = 4 * side sq.units)\n" <<
			"3. Go back to main menu (Shapes Calculator)\n";

		std::cin >> choice;
		
		switch (choice) {
		case 1:
			setData();
			result = calcArea(side);//calculate area and get result
			giveResult(result);
			break;
		case 2:
			setData();
			result = calcPerimeter(side);//calculate perimeter and get result
			giveResult(result); std::cout << "This is what is happening? Name: " << name << "\t side " << side << "base: " << base << " height:    " << height << "result : " << result;
			break;
		case 3:
			looping = false;//end the loop
			break;
		}
		
		}
	}

	//OVERLOADED returns the calculation of the area of a square
	double calcArea(double a) {
		return (a *= a) * 4;
	}

	//OVERLOADED function returns square perimeter based on single param
	double calcPerimeter(double a) {
		return (a *= a) * 2;
	}


	//getter, returns a value
	double getData(double c) { return c; }

	//OVERLOADED function to display menu title and name
	void shapeMenu(std::string s, int n) {

		std::cout << "\n\n";
		for (int i = 0; i < 3; i++) {//n takes value taken at function call
			if (i == 1) {
				std::cout << "* " << name << " *";//middle iteration prints the title .
			}
			else {
				//n value taken at function call
				for (int j = 0; j < n; j++) {
					std::cout << '*';
				}
			}
			std::cout << "\n";//new line after each line, including at the end of program.
		}
	}


	//function override to change values to display relevant variable to user (side of square)
	void setData() {
		std::cout << "\nPlease enter side in cm: ";
		std::cin >> side;
	}
};

//derived/child class of base/parent class (Shape)
class Triangle : public Shape {
	double base, height, result;//our member variables that derived classes will inherit
	std::string name{"Triangle Calculator"};
public:
	Triangle() : Shape() //triangle is of obj shape
	{
		std::cout << "triangle made";
		 Shape::base = this->base;//setting values to those of shapes object for best practice
		Shape::height = this->height;
		Shape::result = this->result;
		Shape::name = this->name;
		this->shapeMenu(23);
		this->printShape();
	}

	//function to display a triangle and options for calculation
	void printShape() {
		
		int choice;
		bool looping = false;

		//triangle shape
		std::cout << "\n\n";
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < i; j++)
			{
				std::cout << "* ";
			}
			std::cout << "\n";
		}


			looping = true; 
			while (looping) {
				std::cout << "Please choose (1, 2 or 3) of following options: \n" <<
					"1. Area (Area = 0.5 * base * height sq.units)\n" <<
					"2. Perimeter (Perimeter = 1/2 triangle and pythagorus theorem for side, (sides * 2 + base) * 2 for total sq.units)\n" <<
					"3. Go back to main menu (Shapes Calculator)\n";

				std::cin >> choice;

				switch (choice) {
				case 1:
					setData();
					result = calcArea(base,height);//calculate area and get result
					giveResult(result);
					break;
				case 2:
					setData();
					result = calcPerimeter(base,height);//calculate perimeter and get result
					giveResult(result);
					break;
				case 3:
					looping = false;//end the loop
					break; 
				}

			}
		}
	

	//returns the calculation of the area of a triangle, takes double datatype values as param 
	//formula: 1/2 base * height;
	double calcArea(double a, double b) {
		a *= 0.5;
		return a * b;
	}

	//function returns perimeter of ISOCELES triangle (assuming portico for scope) 
	// 
	//formula: pythag for half the triangle (C^2 = A^2 + B^2) so C is the sides
	// 
	//formula for icoseles perimeter: 2a + b. But then double that result for the other half
	double calcPerimeter(double a, double b) {
		
		double c{0};
		a *= a;//base squared
		b *= b;//height squared
		c *= a + b;//the two sides are now each known as value of c
		c *= 2 + a;//side c times 2 + base a ... 
		c *= 2;//times 2 is perimeter
		
		return c;
	}

	//takes inputs from user
	void setData() {
		std::cout << "Please enter base (longest length of shape)in centimeters: \n";
		std::cin >> base;
		std::cout << "Please enter height (highest point straight to the bottom) in centimeters: \n;";
		std::cin >> height;
	}

	//gets value from private area of triangle
	double getData(double c) { return c; }

	//OVERLOADED function to display menu title and name 
	void shapeMenu(int n) {

		std::cout << "\n\n";
		for (int i = 0; i < 3; i++) {//n takes value taken at function call
			if (i == 1) {
				std::cout << "* " << name << " *";//middle iteration prints the title .
			}
			else {
				//n value taken at function call
				for (int j = 0; j < n; j++) {
					std::cout << '*';
				}
			}
			std::cout << "\n";//new line after each line, including at the end of program.
		}
	}
};

int main()
{
	Shape *ptr;
	
	//function starts program choosing shape or exiting program
	
		int choice{ 0 };
		ptr = new Shape();
		Shape p = *ptr;	
		p.shapeMenu();
		std::cout << "Please choose option (1,2,3,4 or 5) from the following: \n" <<
			"1. Square\n 2. Rectangle\n 3. Triangle\n 4. Circle\n 5. Exit\n";
		std::cin >> choice;

		switch (choice) {
		case 1:
			ptr = new Square();
			ptr->printShape();
			break;
		case 2:
			ptr = new Rectangle();
			ptr->printShape();
			break;
		case 3:
			ptr = new Triangle();
			ptr->printShape();
			break;
		case 4:
			ptr = new Circle();
			ptr->printShape();
			break;
		case 5:
			return 0;
			
	}

}


