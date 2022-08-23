// brooklyn_robertson_105.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "Task1.h";


class Location   {
private:
    int degrees;
    float minutes;
    char direction;

public:
    std::string position;
    //Default constructor with default values
    Location(int degrees = 0, float minutes = 0, char direction = 'x') {
        this->degrees = degrees;
        this->minutes = minutes;
        this->direction = direction;

        //this->position = std::to_string(degrees) + "\xf8" + std::to_string(minutes) + "'" + direction;

    }

    //function to get location
    Location getpos() {
        std::cout << "Please enter degrees: (between 0-180)\n";
        std::cin >> degrees;

        std::cout << "Please enter minutes: (0-60)\n";
        std::cin >> minutes;

        std::cout << "Please enter direction ('N', 'S', 'E' or 'W')\n";
        std::cin >> direction;


        Location located = degrees + minutes + direction;
        return located;
    }
};

class Yacht {

protected:
    
    int serialNumber;
    Location* latitude = { new Location() };
    Location* longitude{ new Location() };

public:
    
    

    Yacht(int serialNumber) {
            this->serialNumber = serialNumber;
            
        }


    //function to recieve user input for a location
    Location get_pos() {
        Location location{ location.getpos() };
       /* *latitude = latitude->getpos();
        *longitude = longitude->getpos();*/

        int degrees;
        float minutes;
        char direction;
        std::cout << "Please enter degrees: (between 0-180)\n";
        std::cin >> degrees;
        degrees += '\xF8';
        std::cout << "Please enter minutes: (0-60)\n";
        std::cin >> minutes;
        
        std::cout << "Please enter direction ('N', 'S', 'E' or 'W')\n";
        std::cin >> direction;

        location = degrees + '\xF8' + minutes + '.' + direction;
        //std::string position = std::to_string(degrees) + "\xF8" + std::to_string(minutes) + "'" + direction;
       // display(*latitude, *longitude);
        
        return location;
    }
        


        void display(Location latitude, Location longitude) {
            //std::string position = std::to_string(degrees) + "\xF8" + std::to_string(minutes) + "'" + direction;
            std::cout << "Yacht serial number: " << serialNumber <<
                "\t Yacht Location: " << "\n Latitude: " << this->latitude <<
                "\t Longitude: " << this->longitude;

        }

    };


int main()
{ 
    int yachtCount{0}; //counter for each yacht created
    Location lat, lon;
    std::vector<Yacht> contestants; //vector to store our yachts(contestents in race)
    
    //Yacht *y(0);

    //make yachts
   /* for (int i = 0; i < 3; i++) {*/
        std::cout << "Enter details for Yacht " << 1 << ": \n";
        yachtCount++;
         contestants.push_back(Yacht(1));
        std::cout << "Yacht recorded!\n";
       
   // }
    
        
    //print yachts
    for (int i = 0; i < contestants.size(); i++) {
        
       contestants[i].display(contestants[i].get_pos(), contestants[i].get_pos());
    }
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
