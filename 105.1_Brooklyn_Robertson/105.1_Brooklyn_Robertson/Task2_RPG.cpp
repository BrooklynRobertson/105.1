// brooklyn_robertson_105.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Task2.h"

class Player {
    string name;
    Race race;
    int hitPoints;
    int magicPoints;
public:
    Player(string name, Race race, int hitPoints, int magicPoints) {
        this->name = name;
        this->race = race;
        this->hitPoints = hitPoints;
        this->magicPoints = magicPoints;
    };

    string getName() {
        return name;
    }

    Race whatRace() {
        return race;
    }

    string setRace() {
        return;
    }
    int getHitPoints() {
        return hitPoints;
    }
    int getMagicPoints() {
        return magicPoints;
    }
    void setName(string name) {

    }
    void setRace(Race race) {

    }
    void setHitPoints(int hitPoints) {

    }
    void setMagicPoints(int magicPoints) {

    }
    string attack() {
        return;
    }
};

class Warrior : public Player {
    Warrior(string name, Race race, int hitPoints, int magicPoints) : Player(name, race, hitPoints, magicPoints) {

    }
};

class Preist : public Player {

};

class Mage : public Player {

};



int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
