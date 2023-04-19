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

const int SIZE = 36;

class weatherConst
{
private:
public:
    string stationCode;          // 3 Digit Station Code
    double temperatureFarenheit; // Temperature in Farenheit
    double temperatureCelcius;
    double dewPoint;      // Dew Point
    string windDirection; // Wind Direction - Example NE
    double windSpeed;     // Wind Speed in MPH
    double pressure;      // Reported Pressure in xx.xx format
    string weatherType;   // Up to 3 Digit Weather Type

    // Default Constructor
    weatherConst();
    // Constructor with Parameters
    weatherConst(string, double, double, double, string, double, double, string);
    // Convert Farenheit to Celcius
    double get_Celcius(void);
    // Convert Knots to MPH
    double get_windMPH(void);
    // Load Data from weatherObs.txt
    void inputData(fstream &);
    void displayWeather();
};

weatherConst::weatherConst()
{
    stationCode = "";
    temperatureFarenheit = 00.00;
    temperatureCelcius = 00.00;
    dewPoint = 00.00;
    windDirection = "";
    windSpeed = 00.00;
    pressure = 00.00;
    weatherType = "";
}

/* weatherConst::weatherConst(string sc, double tf, double tc, double dp, string wd, double ws, double p, string wt);
{

    stationCode = sc;
    temperatureFarenheit = tf;
    temperatureCelcius = tc;
    dewPoint = dp;
    windDirection = wd;
    windSpeed = ws;
    pressure = p;
    weatherType = wt;
}
 */
// Calculate Celcius Temperature
double weatherConst ::get_Celcius(void)
{
    return (temperatureFarenheit - 32) * 5 / 9;
}

// Calculate MPH by converting knots to MPH
double weatherConst ::get_windMPH(void)
{
    return (windSpeed * 1.151);
}

void loadWeather(weatherConst[], int);
void outputWeather(weatherConst[], int);

int main()
{

    int i;

    weatherConst weatherInput[SIZE];
    fstream inputFile;
    inputFile.open("weatherObs.txt");

    for (i = 0; i < SIZE; i++)
        weatherInput[i].inputData(inputFile);

    for (i = 0; i < SIZE; i++)
        weatherInput[i].displayWeather();

    cout << endl;
}

void weatherConst::inputData(fstream &infile)
{
    infile >> stationCode;
    infile >> temperatureFarenheit;
    infile >> dewPoint;
    infile >> windDirection;
    infile >> windSpeed;
    infile >> pressure;
    infile >> weatherType;
}

void weatherConst::displayWeather()
{
    cout << stationCode << endl;
    cout << temperatureFarenheit << endl;
    cout << dewPoint << endl;
    cout << windDirection << endl;
    cout << windSpeed << endl;
    cout << pressure << endl;
    cout << weatherType << endl;
}
