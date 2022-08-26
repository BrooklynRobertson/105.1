// brooklyn_robertson_105.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Task4.h"

class Alien {
	int weight, height, prestiege;
	char gender;

	std::string name{"Alien"};
public:
	Alien() : weight(0), height(0), gender('m')
	{
		prestiege = 0;
		
	}

	//constructor with presetvalues
	Alien(int weight, int height, char gender) : weight(50), height(90), gender('f')
	{
		prestiege = 0;
	}

	
	//gets us a surprise gender returned
	char genderReveal() {
		char g;
		bool isBoy = (rand() % 2) != 0; //using as a flag to get rand value of 0 or 1 

		if (isBoy) {
			g = 'm';

		}
		else {
			g = 'f';

		}
		return g;
	}

	//gets weight
	int getWeight() {

		return weight;
	}

	//sets weight
	void setWeight() {
		std::cout << "\nEnter Aliens weight: ";
		std::cin >> weight;
	}

	//overloading setweight for param for my ease in main functoin
	void setWeight(int w) {
		w = weight;
	}

	//gets height
	int getHeight() {
		return height;
	}

	//sets height
	void setHeight() {
		std::cout << "\nEnter Aliens height: ";
		std::cin >> height;
	}

	//overloading set height for param for my ease in main functoin
	void setHeight(int h) {
		h = height;
	}

	//gets gender
	char getGender() {

		return gender;
	}

	void setGender() {
		std::cout << "\nEnter Aliens gender (m or f): ";
		std::cin >> gender;
	}


	//returns prestiege value
	int getPrestiege() {
		int genderPoints {0};

		//get gender points
		this->gender == 'm' ? genderPoints = 2 : 3;
		this->gender == 'f' ? genderPoints = 3 : 2;//just showing i can do ternary hehe
		
		prestiege = weight * height * genderPoints;
		return prestiege ;
	}

	//overloaded operator + to assign alien object the sum of two other objects by height and weight / 2
Alien operator + (const Alien& obj) const {
	Alien alien;
	
	alien.weight = (this->weight + obj.weight)/2;
	alien.height = (this->height + obj.height)/2;
	alien.gender = alien.genderReveal();
	
	return alien;	
};

//overload operator to show ==
void operator == (const Alien& obj) {
	bool value;
	Alien alien;

	//true statement
	value = this->prestiege == obj.prestiege;
	if (value) {
		std::cout << "\nAlien 5 == Alien 6? TRUE";
	}
	if (!value) {
		std::cout << "\nAlien 5 == Alien 6? FALSE";
	}
};

//overload operator to show !=
void operator != (const Alien& obj) {
	bool value;
	Alien alien;

	//true statement
	value = this->prestiege != obj.prestiege;

	if (value) {
		std::cout << "\nAlien 5 != Alien 6? TRUE";
	}
	if (!value) {
		std::cout << "\nAlien 5 != Alien 6? FALSE";
	}
};

//overload operator to show >
void operator > (const Alien& obj) {
	bool value;
	Alien alien;

	//true statement
	value = this->prestiege > obj.prestiege;

	if (value) {
		std::cout << "\nAlien 5 > Alien 6? TRUE";
	}
	if (!value) {
		std::cout << "\nAlien 5 > Alien 6? FALSE";
	}
};

//overload operator to show <
void operator < (const Alien& obj) {
	bool value;
	Alien alien;

	//true statement
	value = this->prestiege < obj.prestiege;

	if (value) {
		std::cout << "\nAlien 5 < Alien 6? TRUE";
	}
	if (!value) {
		std::cout << "\nAlien 5 < Alien 6? FALSE";
	}
};

//overload operator to show <=
void operator <= (const Alien& obj) {
	bool value;
	Alien alien;

	//true statement
	value = this->prestiege <= obj.prestiege;

	if (value) {
		std::cout << "\nAlien 5 <= Alien 6? TRUE";
	}
	if (!value) {
		std::cout << "\nAlien 5 <= Alien 6? FALSE";
	}
};

//overload operator to show >=
void operator >= (const Alien& obj) {
	bool value = true;
	Alien alien;

	//true statement
	value = this->prestiege >= obj.prestiege;

	if (value) {
		std::cout << "\nAlien 5 >= Alien 6? TRUE";
	}
	if (!value) {
		std::cout << "\nAlien 5 >= Alien 6? FALSE";
	}

}

};
	
	







int main()
{

	//creating our 4 parent aliens
	int choice;
	bool looping = true;

	Alien male(0, 0, 'm');
	Alien female(0, 0, 'f');
	Alien child(0, 0, '?');

	Alien Alien1, Alien2, Alien3, Alien4, Alien5, Alien6;//storing variables for alien parents and babies;
	//I create my aliens first
	
	while (looping) {
		std::cout << "\n\nChoose (I SUGGEST CHOOSING 1, THEN 2, THEN 3): \n 1. Create Alien Pairs\n" <<
			"2. Create an offspring\n 3. Compare offspring prestiege\n 4.Exit\n\n";
		std::cin >> choice;

		switch (choice) {
		case 1:
			//create pairing
			std::cout << "\nchoose alien1 male info: ";
			male.setWeight();
			male.setHeight();

			std::cout << "\nChoose alien2 female info: ";
			female.setWeight();
			female.setHeight();

			Alien1 = male;
			Alien2 = female;

			std::cout << "Pair created.\n";
			break;
		case 2:
			//create offspring based on pairing
			child = male + female;
			child.genderReveal();
			Alien5 = child;
			std::cout << "offspring created.\n\n";
			
			//me, creating the other 2 pair
			Alien3.setWeight(35); Alien3.setHeight(125);
			Alien4.setWeight(87); Alien4.setHeight(167);
			Alien6 = Alien3 + Alien4;
			break;
		case 3:
			//do prestige
			std::cout << "Alien 5 prestiege: " << Alien5.getPrestiege() << " \t Alien 6 Prestiege: " << Alien6.getPrestiege() << "\n";
			Alien5 == Alien6;
			Alien5 != Alien6;
			Alien5 > Alien6;
			Alien5 >= Alien6;
			Alien5 < Alien6;
			Alien5 <= Alien6;
			break;
		case 4:
			looping = false;
			break;//exit
		default:
			break;
		}
	}
}



