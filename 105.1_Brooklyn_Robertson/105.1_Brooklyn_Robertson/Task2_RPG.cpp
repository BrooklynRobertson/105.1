// brooklyn_robertson_105.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Task2.h"

class Player {
protected:
    string name;
    Race race;
    int hitPoints;
    int magicPoints;
public:
    //default constructor, initializes a player with preset values
    Player(string name = "player", Race race = Race::HUMAN, int hitPoints = 0, int magicPoints = 0) {
        this->name = name;
        //name = Player::name;
        this->race = race;
        //std::string raceStr = ;
        this->hitPoints = hitPoints;
        this->magicPoints = magicPoints;
    };

    //gets name
    string getName() {
        return name;
    }

    //sets name
    void setName() {
        std::cout << "What would you like your player to be called?\n\t\t";
        std::cin >> name;
    }

    //gets the name of the race type to a const char* so i can std::cout it
    const char* getRaceName(enum Race race) {//enum gets race name, and returns a const char pointer for easy access
        switch (race) {
        case Race::HUMAN:
            return "HUMAN";
            break;
        case Race::ELF:
            return "ELF";
            break;
        case Race::DWARF:
            return "DWARF";
            break;
        case Race::ORC:
            return "ORC";
            break;
        case Race::TROLL:
            return "TROLL";
            break;
        }
    }

    //gets race
    Race getRace() {
        getRaceName(race);
        return race;
    }

    //sets race
    void setRace() {
        int temp;
        std::cout << "Which race do you want?\n\t\t" <<
            "1. Human!\n2. Elf\n3. Dwarf!\n4. Orc!\n5. Troll!\n";
        std::cin >> temp;
        switch (temp) {
        case 1:
            race = Race::HUMAN;
            break;
        case 2:
            race = Race::ELF;
            break;
        case 3:
            race = Race::DWARF;
            break;
        case 4:
            race = Race::ORC;
            break;
        case 5:
            race = Race::TROLL;
            break;
        default:
            race = Race::HUMAN;
            "Your race is being set to HUMAN as default....\n";
            break;
        }
    }

    int getHitPoints() {
        return hitPoints;
    }

    void setHitPoints(int hitPoints) {
        std::cout << "Hit points updated to: " << hitPoints;
    }

    int getMagicPoints() {
        return magicPoints;
    }

    void setMagicPoints(int magicPoints) {
        std::cout << "Magic points updated to: " << magicPoints;
    }
    string attack() {
        return "No attack method defined yet!";
    }
};

//worriar class
class Warrior : public Player {
private:


public:
    Warrior(Race race = Race::HUMAN, int hitPoints = 200, int magicPoints = 0) {
        this->name = Player::getName();
        this->race = getRace();
    }
    string attack() {
        return "\nI will destroy you with my sword!\n";
    }
    
};

//preist class
class Preist : public Player {
public:
    Preist(Race race = Race::HUMAN, int hitPoints = 100, int magicPoints = 200) {
        this->name = Player::getName();
        this->race = getRace();
    }
    string attack() {
        return "\nI will assault you with holy wrath!\n";
    }
 
};

//mage cclass
class Mage : public Player {
public:
    Mage() {}
    Mage(string name, Race race = Race::HUMAN, int hitPoints = 200, int magicPoints = 0) {
        this->name = Player::getName();
        this->race = getRace();
    }
    string attack() {
        return "\nI will crush you with my arcane missiles!\n";
    }
};

//function to show all players in each class
void showAllPlayers(std::vector<Warrior> w, std::vector<Preist> p, std::vector<Mage> m) {

    std::cout << "-----------" << "\n WARRIORS LIST: \n" << "-----------";

    for (Warrior warrior : w) {
        std::cout << warrior.getName();
        std::cout << "\n\n";
        std::cout << warrior.getRaceName(warrior.getRace());
        std::cout << "\n\n";
        std::cout << warrior.attack();
    }
    std::cout << "-----------" << "\n PREISTSS LIST: \n" << "-----------";
    for (Preist preist : p) {
        std::cout << preist.getName();
        std::cout << "\n\n";
        std::cout << preist.getRaceName(preist.getRace());
        std::cout << "\n\n";
        std::cout << preist.attack();
    }

    std::cout << "-----------" << "\n MAGES LIST: \n" << "-----------";
    for (Mage mage : m) {
        std::cout << mage.getName();
        std::cout << "\n\n";
        std::cout << mage.getRaceName(mage.getRace());
        std::cout << "\n\n";
        std::cout << mage.attack();
    }
}

int main()
{
    //variables needed and vectors
    int choice{ 0 };
    std::vector<Warrior> warriors;
    std::vector<Preist> preists;
    std::vector<Mage> mages;

    Warrior w;
    Preist p;
    Mage m;

    //dowhile to create players
    do {
        std::cout << "CHARACTER CREATION:\n" << "Which of the following would you like?\n" <<
            "1. Create a Warrior!\n 2. Create a Preist!\n 3. Create a Mage!\n 4. Finish creating player characters!\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "You chose Warrior!\n";
            //w = *new Warrior();
            w.setName();
            std::cout << "Name updated: " << w.getName() << "\n";
            w.setRace();
            std::cout << "Your new race is " << w.getRaceName(w.getRace()) << ".\n";

            warriors.push_back(w);
            std::cout << warriors.size();
            break;
        case 2:
            std::cout << "You chose Preist!\n";
            p.setName();
            p.setRace();
            preists.push_back(p);
            break;
        case 3:
            std::cout << "You chose Mage!\n";
            m.setName();
            m.setRace();
            mages.push_back(m);
            break;
        case 4:
            std::cout << "Character Creation Done!.......\n You can now move to the next level!\n";
            showAllPlayers(warriors, preists, mages);
            break;
        default:
            std::cout << "Try again........\n";
            break;
        }
    } while (choice != 4);

}
