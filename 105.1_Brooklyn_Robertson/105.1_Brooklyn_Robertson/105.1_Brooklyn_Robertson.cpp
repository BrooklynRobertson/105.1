// brooklyn_robertson_105.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Task2.h"

class Player {
    string name;
    Race race;
    int hitPoints;
    int magicPoints;
public:
    Player(string name = "player", Race race = HUMAN, int hitPoints = 0, int magicPoints = 0) {
        name = Player::getName();
        race = Player::getRace();
        hitPoints = this->Player::hitPoints;
        magicPoints = this->Player::magicPoints;
    };

    string getName() {
        return name;
    }
    
 
    void setName() {
       std::cout << "What would you like your player to be called?\n\t\t";
       std::cin >> name;
    }

    Race getRace() {
        switch (race) {
        case 0:
            race =  HUMAN;
            break;
        case 1:
            race = ELF;
            break;
        case 2:
            race = DWARF;
            break;
        case 3:
            race = ORC;
            break;
        case 4:
            race = TROLL;
            break;
        default:
            race = HUMAN;
            "Your race is being set to HUMAN as default....\n";
            break;
        }
        return race;
    }

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

class Warrior : public Player {
private:
    std::vector<Warrior> warriors;
public:
    Warrior(string name = "default_warrior", Race race = HUMAN, int hitPoints = 200, int magicPoints = 0) : Player(name, race, hitPoints, magicPoints) {
        name = this->Warrior::getName();
        race = this->getRace();
    }
    string attack() {
        return "\nI will destroy you with my sword!\n";
    }
    ~Warrior() { delete[] & warriors; };
};

class Preist : public Player {
private:
    std::vector<Preist> preists;
public:
    Preist(string name = "default_warrior", Race race = HUMAN, int hitPoints = 100, int magicPoints = 200) : Player(name, race, hitPoints, magicPoints) {
        name = this->Preist::getName();
        race = this->getRace();
    }
    string attack() {
        return "\nI will assault you with holy wrath!\n";
    }
    ~Preist() { delete[] & preists; };
};

class Mage : public Player {
private:
    std::vector<Mage> mages;
public:
    Mage(string name = "default_warrior", Race race = HUMAN, int hitPoints = 200, int magicPoints = 0) : Player(name, race, hitPoints, magicPoints) {
        name = this->Mage::getName();
        race = this->getRace();
    }
    string attack() {
        return "\nI will crush you with my arcane missiles!\n";
    }
    ~Mage() { delete[] &mages; };
};

void showAllPlayers() {
   
    std::cout << "-----------" << "\n WARRIORS LIST: \n" << "-----------";
    
    
    //for (int i = 0; i < x.size(); i++) {
    //    for (int j = 0; j < 5; j++) {
    //        std::cout << j;
      //  }
        // std::cout << "\n";
  //  }


}

int main()
{
    
        int choice{0};
        std::vector< Warrior> warriors;
        std::vector< Preist> preists;
        std::vector< Mage> mages;

        Warrior w;
       Preist p;
       Mage m;

       do {
           std::cout << "CHARACTER CREATION:\n" << "Which of the following would you like?\n\t\t" <<
               "1. Create a Warrior!\n 2. Create a Preist!\n 3. Create a Mage!\n 4. Finish creating player characters!\n";
           std::cin >> choice;

           switch (choice) {
           case 1:
               std::cout << "You chose Warrior!\n";
              w = *new Warrior();
              w.setName();
               w.setRace();
               warriors.push_back(w.getName());
               break;
           case 2:
               std::cout << "You chose Preist!\n";
               p = *new Preist();
               p.setName();
               p.setRace();
               preists.push_back(p.getName());
               break;
           case 3:
               std::cout << "You chose Warrior!\n";
               w = *new Warrior();
               w.setName();
               w.setRace();
               mages.push_back(m.getName());
               break;
           case 4:
               for (int i = 0; i < warriors.size(); i++) {
                   std::cout << &warriors[i];
               }
               /*for (int i = 0; i < preists.size(); i++) {
                   std::cout << preists[i];
               }
               for (int i = 0; i < mages.size(); i++) {
                   std::cout << mages[i];
               }*/
               std::cout << "Character Creation Done!.......\n You can now move to the next level!\n";
               //showAllPlayers();
               return 0;
               
               break;
           default:
               std::cout << "Try again........\n";
               break;
           }
       } while (choice != 4);
             
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
