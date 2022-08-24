// brooklyn_robertson_105.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "Task1.h";


class Location   {
private:
    int degrees;
    float minutes;
    char direction;
std::string lat,lon;
public:
    


    //Default constructor with default values upon creation
    Location(int degrees = 0, float minutes = 0, char direction = ' ', std::string lat = "", std::string lon = "") {
        this->degrees = degrees;
        this->minutes = minutes;
        this->direction = direction;
        this->lat = std::to_string(degrees) + "\xF8" + std::to_string(minutes) + direction;
        this->lon = std::to_string(degrees) + "\xF8" + std::to_string(minutes) + direction;
        //location object created (eg, latitude) constructor  calls getpos for user input to return the value to where it was called/created.
       
    }

    //function to get location position (latitude and longitude)
    Location getpos() {
        int  degrees;
        float minutes;
        char direction;
        
        std::cout << "Please enter degrees: (between 0-180)\n";
        std::cin >> degrees;
        if (degrees < 0 || degrees > 180) {
            std::cout << "Number has to be between 0 and 180!\n";
            std::cin.fail();
        }
        //positions.push_back(std::to_string(degrees));
        std::cout << "Please enter minutes: (0-60)\n";
        std::cin >> minutes;
        if (minutes < 0 || minutes > 60) {
            std::cout << "Number has to be between 0 and 60!\n";
            std::cin.fail();
        }
        //positions.push_back(minutes)
        std::cout << "Please enter direction ('N', 'S', 'E' or 'W')\n";
        std::cin >> direction;
        switch (toupper(direction)) {
        case 'N': case 'n': case 'S': case 's':
            if (degrees > 90) {
                std::cout << "WARNING: North and South (latitude) coordinates need to be 90\xf8 or less... \n";
            }
            break;

        default:
            break;
        }
        
        Location position; //creating a location position
        //std::vector<Location*> positions;//creating a vector for that location position for easy access later

        position = degrees;
        

        //

        //positions.push_back(&position);//adding location object's address of position to the vector

        return position;// returning back to Yacht class(where it was created)
    }
};

class Yacht {

protected:

    int serialNumber;
    Location* latitude, * longitude;
    //std::vector<Location*> location;//vector of a yacht position

public:



    Yacht(int serialNumber) {
        this->serialNumber = serialNumber;

        //creating the location objects
        std::cout << "Latitude : " ;
        this->latitude = new Location();

        std::cout << "Longitude :";
        this->longitude = new Location();
        
    }


    //returns a position (longitude or latitude) in a easier to use format by calling getpos in Locatoin class
    Location get_pos() {
        Location *pos1, pos2;
        
        pos1 = latitude;
    
        pos2 = longitude->getpos();

        std::cout << "This is latitude: " << &latitude;


        return *latitude;
    }



    std::string display() {

        return "hi";
    };

};
    int main()
    {
        int yachtCount{ 0 }; //counter for each yacht created
        Location lat, lon;
        std::vector<Yacht> contestants; //vector to store our yachts(contestents in race)



        //make yachts
        for (int i = 0; i < 3; i++) {
            std::cout << "Enter details for Yacht " << i + 1 << ": \n";
            yachtCount++;

            contestants.push_back(Yacht(i));
            contestants[i].get_pos();
            std::cout << "Yacht recorded!\n";

        }


        //print yachts
        for (int i = 0; i < contestants.size(); i++) {


        }
    };



