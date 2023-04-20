// Name: Aaron Pelto
// Week: 14
// Program: CST 180 C++ Programming Objects Program Assignment

// URL - http://websites.delta.edu/donaldsouthwell/cst180/cst180_prog9.pdf

/*
OUTPUT EXAMPLE

At Saginaw, the temperature is 35 degrees Fahrenheit (2 degrees Celsius), the
dew point is 31 degrees Fahrenheit, winds are from the northwest at 14 miles per
hour, pressure is 30.09 inches of mercury, and it is raining.

*/

/*
PROGRAM REQUIREMENT

Your program should include a driver program to read one line of coded weather
data at a time as well as a class designed to store and manage information
related to one weather observation. Your class should store all of the fields
coming in from the data file defined with an appropriate data type for each. The
class should include constructor(s) and set/get functions, as required.

Extraction of the information from the raw data should be defined in the class.
File processing should be included in your main driver function. As you read a
new coded weather observation, format it from the raw form to extract all of the
various fields in the appropriative data type. Invoke a function on your weather
observation object to write the narrative information for the given observation.
Then, read the next line in the file and process it the same way.

The main task to be performed as a function in your class will be to extract, or
"parse", the data from the input string, decode it, and perform some conversions
before you can store the information in the member variables of your class
object. Utilize the standard C++ string class for string processing. Be sure
your data members that are to be stored as character strings use the string
class. This implies that class composition will be included by having your
weather observation class contain objects of the standard string class.


*/

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class weatherConst
{
private:
    string station;
    float temp;
    float dewPoint;
    string wDirection;
    float wSpeed;
    string pressure;
    string conditions;

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
    string getStation() const;
    float getTemp() const;
    float getDewPoint() const;
    string getWDirection() const;
    float getWSpeed() const;
    string getPressure() const;
    string getConditions() const;

    // Celsius Calculator
    float getCelsius();

    // Message Return
    void outputMessage();
};

// Function Prototypes
void weatherConst::setStation(char s[]) { station = s; }

void weatherConst::setTemp(float t) { temp = t; }

void weatherConst::setDewPoint(float d) { dewPoint = d; }

void weatherConst::setWDirection(char w[]) { wDirection = w; }

void weatherConst::setWSpeed(float ws) { wSpeed = ws; }

void weatherConst::setPressure(char p[]) { pressure = p; }

void weatherConst::setConditions(char c[]) { conditions = c; }

// Get Functions
// Returns the station location
string weatherConst::getStation() const
{
    if (station == "AMN")
    {
        return "Alma";
    }
    else if (station == "BAX")
    {
        return "Bad Axe";
    }
    else if (station == "FNT")
    {
        return "Flint";
    }
    else if (station == "LAN")
    {
        return "Lansing";
    }
    else if (station == "MBS")
    {
        return "Saginaw";
    }
    else if (station == "MOP")
    {
        return "Mount Pleasant";
    }
    else
        return "Invalid Station";
}

float weatherConst::getTemp() const { return temp; }

float weatherConst::getDewPoint() const { return dewPoint; }

// Returns the Wind Direction
string weatherConst::getWDirection() const
{
    if (wDirection == "N")
    {
        return "North";
    }
    else if (wDirection == "NE")
    {
        return "North East";
    }
    else if (wDirection == "E")
    {
        return "East";
    }
    else if (wDirection == "SE")
    {
        return "South East";
    }
    else if (wDirection == "S")
    {
        return "South";
    }
    else if (wDirection == "SW")
    {
        return "South West";
    }
    else if (wDirection == "W")
    {
        return "West";
    }
    else if (wDirection == "NW")
    {
        return "North West";
    }
    else
        return "Invalid Wind Direction";
}

// Returns the weather in MPH
float weatherConst::getWSpeed() const { return wSpeed * 1.151; }

// Turns the cstring pressure into Pressure Values
string weatherConst::getPressure() const
{
    return pressure.substr(0, 2) + "." + pressure.substr(2);
}

// Converts the Conditions into Text
string weatherConst::getConditions() const
{

    if (conditions == "CLD")
    {
        return "Skies are cloudy.";
    }
    else if (conditions == "PC")
    {
        return "Skies are partly cloudy.";
    }
    else if (conditions == "CLR")
    {
        return "Skies are clear.";
    }
    else if (conditions == "R")
    {
        return "It is raining.";
    }
    else if (conditions == "S")
    {
        return "It is snowing.";
    }
    else if (conditions == "DR")
    {
        return "Drizzle is reported.";
    }
    else
        return "Invalid Weather Condition";
}

// Converts Farenheit to Celsius
float weatherConst::getCelsius() { return (temp - 32) * 5 / 9; }

/// Output Message for the Text
void weatherConst::outputMessage()
{
    cout << "In " << getStation() << ", ";
    cout << "The temperature is " << getTemp() << " Fahrenheit"
         << " ( " << setprecision(3) << getCelsius()
         << " Celsius)." << endl;
    cout << "The dew point is " << getDewPoint() << " degrees Fahrenheit." << endl;
    cout << "Winds are from the " << getWDirection() << " at " << getWSpeed()
         << " miles per hour." << endl;
    cout << "Pressure is " << getPressure() << " inches of mercury." << endl;
    cout << getConditions() << endl;
}

int main()
{

    // Declares the weather object with 6 entries
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
    int i = 0;
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

        // Loops through the Weather Object Array and places the variables into the class
        weatherData[i].setStation(Rstation);
        weatherData[i].setTemp(Rtemp);
        weatherData[i].setDewPoint(RdewPoint);
        weatherData[i].setWDirection(RwDirection);
        weatherData[i].setWSpeed(RwSpeed);
        weatherData[i].setPressure(Rpressure);
        weatherData[i].setConditions(Rconditions);

        // Displays Weather Information from the Object
        cout << "\nYour Weather Information\n"
             << endl;
        weatherData[i].outputMessage();
        i++;
    }
    // close file
    inFile.close();

    return 0;
}
