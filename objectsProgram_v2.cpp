// Name: Aaron Pelto
// Week: 14
// Program: CST 180 C++ Programming Objects Program Assignment

// URL - http://websites.delta.edu/donaldsouthwell/cst180/cst180_prog9.pdf

/*
OUTPUT EXAMPLE

At Saginaw, the temperature is 35 degrees Fahrenheit (2 degrees Celsius), the dew point is 31 degrees
Fahrenheit, winds are from the northwest at 14 miles per hour, pressure is 30.09 inches of mercury,
and it is raining.

*/

/*
PROGRAM REQUIREMENT

Your program should include a driver program to read one line of coded weather data at a time as well
as a class designed to store and manage information related to one weather observation. Your class
should store all of the fields coming in from the data file defined with an appropriate data type for each.
The class should include constructor(s) and set/get functions, as required.

Extraction of the information from the raw data should be defined in the class. File processing should be
included in your main driver function. As you read a new coded weather observation, format it from the
raw form to extract all of the various fields in the appropriative data type. Invoke a function on your
weather observation object to write the narrative information for the given observation. Then, read the
next line in the file and process it the same way.

The main task to be performed as a function in your class will be to extract, or "parse", the data from
the input string, decode it, and perform some conversions before you can store the information in the
member variables of your class object. Utilize the standard C++ string class for string processing. Be sure
your data members that are to be stored as character strings use the string class. This implies that
class composition will be included by having your weather observation class contain objects of the
standard string class.


*/

/*
Station Codes
AMN Alma
BAX Bad Axe
FNT Flint
LAN Lansing
MBS Saginaw
MOP Mount Pleasant
*/

/*
Wind Direction
N north
NE northeast
E east
SE southeast
S south
SW southwest
W west
NW northwest
*/

/*
Weather Types
CLD skies are cloudy
PC skies are partly cloudy
CLR skies are clear
R it is raining
S it is snowing
DR drizzle is reported
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

class weatherConst
{
private:
    char station[4];
    float temp;
    float dewPoint;
    char wDirection[4];
    float wSpeed;
    char pressure[5];
    char conditions[4];

public:
    // Set Methods
    void setStation(char[]);
    void setTemp(float);
    void setDewPoint(float);
    void setWDirection(char[]);
    void setWSpeed(float);
    void setPressure(char[]);
    void setConditions(char[]);

    // Get Methods
    void getStation() const;
    float getTemp() const;
    float getDewPoint() const;
    void getWDirection() const;
    float getWSpeed() const;
    void getPressure() const;
    void getConditions() const;
};

// Function Prototypes
void weatherConst::setStation(char *)
{
}

void weatherConst::setTemp(float)
{
}

void weatherConst::setDewPoint(float)
{
}

void weatherConst::setWDirection(char[])
{
}

void weatherConst::setWSpeed(float)
{
}

void weatherConst::setPressure(char[])
{
}

void weatherConst::setConditions(char[])
{
}

// Get Functions
void weatherConst::getStation() const
{
    string s;
    s = station;

    if (s == "AMN")
    {
        s = "Alma";
    }
    else if (s == "BAX")
    {
        s = "Bad Axe";
    }
    else if (s == "FNT")
    {
        s = "Flint";
    }
    else if (s == "LAN")
    {
        s = "Lansing";
    }
    else if (s == "MBS")
    {
        s = "Saginaw";
    }
    else if (s == "MOP")
    {
        s = "Mount Pleasant";
    }

    return s;
}

float weatherConst::getTemp() const
{
    return (temp - 32) * 5 / 9;
}

float weatherConst::getDewPoint() const
{
    return dewPoint;
}

void weatherConst::getWDirection() const
{
    char wDirection[] = "";
    return string(wDirection);
}

float weatherConst::getWSpeed() const
{
    return wSpeed * 1.151;
}

void weatherConst::getPressure() const
{
    return pressure;
}

void weatherConst::getConditions() const
{
    return conditions;
}

int main()
{
    weatherConst weatherData[6];

    char Rstation[4];
    char tempHolder[4];
    char dewPointHolder[4];
    char speedHolder[4];
    float Rtemp;
    float RdewPoint;
    char RwDirection[3];
    float RwSpeed;
    char Rpressure[5];
    char Rconditions[4];

    // open file
    ifstream inFile;
    inFile.open("weatherObs.txt");
    if (!inFile)
    {
        cout << "File open error!";
        exit(-1);
    }

    // process the data strings from the file using the comma delimiters
    while (!inFile.getline(Rstation, 4, ',').eof())
    {
        inFile.getline(tempHolder, 4, ',');
        inFile.getline(dewPointHolder, 4, ',');
        inFile.getline(RwDirection, 3, ',');
        inFile.getline(speedHolder, 4, ',');
        inFile.getline(Rpressure, 5, ',');
        inFile.getline(Rconditions, 4);

        // convert the numerical values to numerical datatypes
        Rtemp = atoi(tempHolder);
        RdewPoint = atoi(dewPointHolder);
        RwSpeed = atoi(speedHolder);

        cout << Rstation << ' ' << Rtemp << ' ' << RdewPoint << ' ' << RwDirection
             << ' ' << RwSpeed << ' ' << Rpressure << ' ' << Rconditions << endl;
    }

    // close file
    inFile.close();

    cin.ignore(80, '\n'); // clear input buffer

    for (int i = 0; i < 6; i++)
    {
        weatherData[i].setStation(Rstation);
        weatherData[i].setTemp(Rtemp);
        weatherData[i].setDewPoint(RdewPoint);
        weatherData[i].setWDirection(RwDirection);
        weatherData[i].setWSpeed(RwSpeed);
        weatherData[i].setPressure(Rpressure);
        weatherData[i].setConditions(Rconditions);
    }

    for (int i = 0; i < 6; i++)
    {
        weatherData[i].getStation();
        weatherData[i].getTemp();
        weatherData[i].getDewPoint();
        weatherData[i].getWDirection();
        weatherData[i].getWSpeed();
        weatherData[i].getPressure();
        weatherData[i].getConditions();
    }
    return 0;
}
