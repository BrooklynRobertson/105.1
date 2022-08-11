// brooklyn_robertson_105.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Task1.h"




class Yacht {

protected:
    int serialNumber;
    Location *location;


public:
    Yacht(){}
    Yacht(int serialNumber) {
        this->serialNumber = serialNumber;
        //this->Yacht::location = Location::getpos();
        // yachtCount++;
         //latitude = this->Yacht::get_pos();
         //this->Yacht::get_pos() = longitude;
    }


    Location get_pos(vector<string> *lat, vector<string> *lon) {
     Yacht::location->getpos() = *lat , lon;
        return *location;
    }

    void display(Location latitude, Location longitude) {
        std::cout << "Yacht serial number: " << serialNumber <<
            "\t Yacht Location: ";

    }


};





    class Location : public Yacht {
    private:
        //member variables
        int degrees;
        float minutes;
        char direction;

        //lat and long vectors to store
        std::vector<string> longitude, latitude;


    public:
        //Default constructor with default values
        Location(int degrees = 0, float minutes = 0, char direction = ' ') {
            this->degrees = degrees;
            this->minutes = minutes;
            this->direction = direction;
        }

        bool isLat;//bool to validate latitude values
        bool isLong;

        //get latitude & longitude position (degree, minutes and direction) from user (then store in vector)
        std::vector<string> getpos() {

            std::cout << "Please enter degrees: (between 0-180)\n";
            std::cin >> degrees;

            std::cout << "Please enter minutes: (0-60)\n";
            std::cin >> minutes;

            while (isLong) {
                if (degrees < 180 && degrees > -180) {

                    longitude.push_back(std::to_string(degrees) + "\xF8");//add degrees to longi vector & add degree character
                    longitude.push_back(std::to_string(minutes) + "\x27"); //add minutes to longivector & add apostrophe character
                    std::cout << "Please enter direction ('N','S','E', or 'W': \n";
                    std::cin >> direction;
                    if (toupper(direction) == 'N' || 'S' || 'E' || 'W') {
                        longitude.push_back(std::to_string(direction));
                        isLong = false;
                        isLat = true;
                    }
                    else {
                        longitude.push_back(std::to_string(direction));//if all else fails, add what user said.
                        isLong = false;
                        isLat = true;
                    }
                }
            }
            while (isLat) {
                if (degrees < 90 && degrees > -90) {
                    std::cout << "Please enter 'N' for North or 'S' for South: \n";
                    std::cin >> direction;

                    latitude.push_back(std::to_string(degrees) + "\xF8");//add degrees to latitude vector & add degree character
                    latitude.push_back(std::to_string(minutes) + "\x27"); //add minutes to lat vector & add apostrophe character

                    //figure out whether to use N or S
                    switch (toupper(direction)) {
                    case 'N':
                        latitude.push_back(" N");
                        isLat = false;
                        isLong = true;
                        break;
                    case 'S':
                        latitude.push_back(" S");
                        isLat = false;
                        isLong = true;
                        break;
                    default:
                        latitude.push_back(std::to_string(direction));//if all else fails, add what user said.
                        break;
                    }
                    isLat = false;
                    isLong = true;
                }
                else {
                    std::cout << "Latitude must be 0 - 89\xF8..... \n";
                    std::cin.clear();
                }
            }

        }




        /*if (degrees < 0  || degrees > 180) {
            std::cout << "number must be or be between 0 and 180!\n";
        }
        else {
            if (degrees == 0 || degrees <= 90) {
                latitude = degrees;
            else if (degrees == 180 || degrees > 90) {
                longitude = degrees;
            }
            }
        }*/
        /*std::cout << "Please enter direction: ('N','S','E' or 'W')\n";
        std::cin >> direction;
        switch (std::tolower(direction)) {
        case 'n':
            compassDirection = Direction::N;
            break;
        case 's':
            compassDirection = Direction::S;
        case 'e':
            compassDirection = Direction::E;
            break;
        case 'w':
            compassDirection = Direction::W;
            break;
        default:
            break;
        }*/
       // std::cout << "Coordinates recorded.....\n";

    
};



int main()
{
    std::vector<Yacht*> yachts;
    for (int i = 0; i < 3; i++) {
        yachts.push_back(new Yacht(i));
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
