#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <ctime>
#include <limits> // Add this header for numeric_limits
#ifdef _WIN32
    #include <windows.h>
#endif

//The project is open for expansion and improvement.
//More features and data to be added!

using namespace std;

double velocity(double distance, double time) //Speed calculation function
{
    return distance / time;
}

double force(double mass, double acceleration) //Force calculation function
{
    return mass * acceleration;
}

double kineticEnergy(double mass, double velocity) //Kinetic energy calculation function
{
    return 0.5 * mass * pow(velocity, 2);
}

double potentialEnergy(double mass, double height) //Potential energy calculation function
{
    const double g = 9.81; // gravitational acceleration in m/s^2
    return mass * g * height;
}

double finalVelocityWithAirResistance(double initialVelocity, double mass, double time, double airDensity, double dragCoefficient, double crossSectionalArea)
{ //A function that calculates the final velocity of a body moving against air resistance
    const double g = 9.81; // acceleration due to gravity in m/s^2
    const double k = 0.5 * airDensity * dragCoefficient * crossSectionalArea / mass;
    return (initialVelocity + g / k) * exp(-k * time) - g / k;
}

// Color handling for cross-platform compatibility
void setColor(const std::string& color) {
    #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (color == "yellow") SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        else if (color == "bright_cyan") SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        else if (color == "bright_magenta") SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        else SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    #else
        if (color == "yellow") std::cout << "\033[1;93m";
        else if (color == "bright_cyan") std::cout << "\033[1;96m";
        else if (color == "bright_magenta") std::cout << "\033[1;95m";
        else std::cout << "\033[0m";
    #endif
}

// Logger class for error handling
class Logger {
public:
    static void log(const std::string& message) {
        std::ofstream logFile("physics_calc.log", std::ios::app);
        time_t now = time(0);
        logFile << ctime(&now) << message << "\n";
        logFile.close();
    }
};

void displayHeader() {
    setColor("bright_cyan");
    std::cout << "==========================================\n";
    std::cout << "   Physical Values Calculator v1.0\n";
    std::cout << "   Created by Adrian Lesniak\n";
    std::cout << "==========================================\n\n";
    
    setColor("yellow");
    std::cout << "PROGRAM FEATURES:\n";
    std::cout << "1. Velocity Calculator - Calculates speed from distance and time (v = d/t)\n";
    std::cout << "2. Force Calculator - Determines force using mass and acceleration (F = ma)\n";
    std::cout << "3. Kinetic Energy - Calculates energy of motion (Ek = 1/2*m*v^2)\n";
    std::cout << "4. Potential Energy - Calculates stored energy due to position (Ep = mgh)\n";
    std::cout << "5. Air Resistance - Calculates final velocity with air resistance\n";
    std::cout << "6. Date Calculator - Special calculations using dates with constants\n";
    std::cout << "   (PI, Golden Ratio, Speed of Light, Fibonacci)\n";
    std::cout << "==========================================\n";
    
    setColor("bright_cyan");
    std::cout << "\nAll calculations are saved to 'calculations.txt'\n";
    std::cout << "Error logs are stored in 'physics_calc.log'\n\n";
    setColor("");
}

void displayMenu() {
    setColor("bright_cyan");
    std::cout << "\nMAIN MENU:\n";
    std::cout << "1. Calculate Velocity (distance/time)\n";
    std::cout << "2. Calculate Force (mass * acceleration)\n";
    std::cout << "3. Calculate Kinetic Energy\n";
    std::cout << "4. Calculate Potential Energy\n";
    std::cout << "5. Calculate Final Velocity with Air Resistance\n";
    std::cout << "6. Date Calculations\n";
    std::cout << "0. Exit\n\n";
    setColor("");
    std::cout << "Enter your choice: ";
}

void saveResult(const std::string& calculation, double result) {
    std::ofstream outFile("calculations.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << "Calculation: " << calculation << " | Result: " << result << "\n";
        outFile.close();
    } else {
        Logger::log("Error: Could not open file for saving results");
    }
}

void waitForKeypress() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

/*
TOPICS:
1. Space and time
2. Planets values
3. Quantum phisics
4.


Dualism:
Black Hole / White Hole
Matter / Antimatter


I Ching:

0.znak feng shui

void pierwsza()
{
cout << _______ << endl;
cout << _______ << endl;
cout << _______ << endl;
cout << _______ << endl;
cout << _______ << endl;
cout << _______ << endl;
}

void druga()
cout << ___ ___ 4.  _______ 5.  ___ ___ 6.  _______ 7.  ___ ___ 8.  ___ ___
cout << _______     ___ ___     _______     ___ ___     _______     _______     ___ ___     _______
cout << _______     ___ ___     ___ ___     ___ ___     ___ ___     _______     ___ ___     ___ ___
cout << _______     ___ ___     ___ ___     ___ ___     _______     ___ ___     ___ ___     ___ ___
cout << _______     ___ ___     ___ ___     _______     _______     _______     _______     ___ ___
cout << _______     ___ ___     _______     ___ ___     _______     ___ ___     ___ ___


1.  _______ 2.  ___ ___ 3.  ___ ___ 4.  _______ 5.  ___ ___ 6.  _______ 7.  ___ ___ 8.  ___ ___
    _______     ___ ___     _______     ___ ___     _______     _______     ___ ___     _______
    _______     ___ ___     ___ ___     ___ ___     ___ ___     _______     ___ ___     ___ ___
    _______     ___ ___     ___ ___     ___ ___     _______     ___ ___     ___ ___     ___ ___
    _______     ___ ___     ___ ___     _______     _______     _______     _______     ___ ___
    _______     ___ ___     _______     ___ ___     _______     ___ ___     ___ ___     ___ ___

9.  _______ 10. _______ 11. ___ ___ 12. _______ 13. _______ 14. _______ 15. ___ ___ 16. ___ ___
    _______     _______     ___ ___     _______     _______     ___ ___     ___ ___     ___ ___
    ___ ___     _______     ___ ___     _______     _______     _______     ___ ___     _______
    _______     ___ ___     _______     ___ ___     _______     _______     _______     ___ ___
    _______     _______     _______     ___ ___     ___ ___     _______     ___ ___     ___ ___
    _______     _______     _______     ___ ___     _______     _______     ___ ___     ___ ___

17. ___ ___ 18. _______ 19. ___ ___ 20. _______ 21. _______ 22. _______ 23. _______ 24. ___ ___
    _______     ___ ___     ___ ___     _______     ___ ___     ___ ___     ___ ___     ___ ___
    _______     ___ ___     ___ ___     ___ ___     _______     ___ ___     ___ ___     ___ ___
    ___ ___     _______     ___ ___     ___ ___     ___ ___     _______     ___ ___     ___ ___
    ___ ___     _______     _______     ___ ___     ___ ___     ___ ___     ___ ___     ___ ___
    _______     ___ ___     _______     ___ ___     _______     _______     ___ ___     _______

25. _______ 26. _______ 27. _______ 28. ___ ___ 29. ___ ___ 30. _______ 31. ___ ___ 32. ___ ___
    _______     ___ ___     ___ ___     _______     _______     ___ ___     _______     ___ ___
    _______     ___ ___     ___ ___     _______     ___ ___     _______     _______     _______
    ___ ___     _______     ___ ___     _______     ___ ___     _______     _______     _______
    ___ ___     _______     ___ ___     _______     _______     ___ ___     ___ ___     _______
    _______     _______     _______     ___ ___     ___ ___     _______     ___ ___     ___ ___

33. _______ 34. ___ ___ 35. _______ 36. ___ ___ 37. _______ 38. _______ 39. ___ ___ 40. ___ ___
    _______     ___ ___     ___ ___     ___ ___     _______     ___ ___     _______     ___ ___
    _______     _______     _______     ___ ___     ___ ___     _______     ___ ___     _______
    _______     _______     ___ ___     _______     _______     ___ ___     _______     ___ ___
    ___ ___     _______     ___ ___     ___ ___     ___ ___     _______     ___ ___     _______
    ___ ___     _______     ___ ___     _______     _______     _______     ___ ___     ___ ___

41. _______ 42. _______ 43. ___ ___ 44. _______ 45. ___ ___ 46. ___ ___ 47. ___ ___ 48. ___ ___
    ___ ___     _______     _______     _______     _______     ___ ___     _______     _______
    ___ ___     ___ ___     _______     _______     _______     ___ ___     _______     ___ ___
    ___ ___     ___ ___     _______     _______     ___ ___     _______     ___ ___     _______
    _______     ___ ___     _______     _______     ___ ___     _______     _______     _______
    _______     _______     _______     ___ ___     ___ ___     ___ ___     ___ ___     ___ ___

49. ___ ___ 50. _______ 51. ___ ___ 52. _______ 53. _______ 54. ___ ___ 55. ___ ___ 56. _______
    _______     ___ ___     ___ ___     ___ ___     _______     ___ ___     ___ ___     ___ ___
    _______     _______     _______     ___ ___     ___ ___     _______     _______     _______
    _______     _______     ___ ___     _______     _______     ___ ___     _______     _______
    ___ ___     _______     ___ ___     ___ ___     ___ ___     _______     ___ ___     ___ ___
    _______     ___ ___     _______     ___ ___     ___ ___     _______     _______     ___ ___

57. _______ 58. ___ ___ 59. _______ 60. ___ ___ 61. _______ 62. ___ ___ 63. ___ ___ 64. _______
    _______     _______     _______     _______     _______     ___ ___     _______     ___ ___
    ___ ___     _______     ___ ___     ___ ___     ___ ___     _______     ___ ___     _______
    _______     ___ ___     ___ ___     ___ ___     ___ ___     _______     _______     ___ ___
    _______     _______     _______     _______     _______     ___ ___     ___ ___     _______
    ___ ___     _______     ___ ___     _______     _______     ___ ___     _______     ___ ___
*/

//DEFINING CONSTANTS

const float pi_number = 3.1415;
const double long golden_ratio = 1.6180339887;
const int fib_numbers[44]={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733};
const int speed_light = 299792458; // m/s
// 299792458 meters per second, that is 299792,458 km/s or 1.079.252.849 km/h


//FREQUENCY:
int human_hearing[19980]; // The human ear can hear sounds between 20 and 20,000 Hz
float shumann_resonance = 7.83;
//Shumann Resonance of the earth’s atmosphere between the earth and ionosphere
//(electromagnetic, not sound)

//---------------------------------------------------------------------

//DEFINING VARIABLES

int mass_energy_equivalence_E; // E = m*c^2
int photon_energy_E;
int speed_V; // V=S/T
int time_T; // T=S/V
int way_S; // (A*T^2)/2  //T^2=T to second power
int acceleration_A; // (A*V)/T
int gravitational_acceleration; //g-9,81^m(s^2)


int mechanical_work_W; // W=F*s
int force_F; //F=m(mass)*a(acceleration)[N(Niuton)]
int shift_s; // When an external force acts on a body and causes it to move, we say that mechanical work is done. Work is calculated from the formula W = F ⋅ s, multiplying the value of the force F by the value of the displacement s, if the directions of the force and displacement are the same.
int mass_M; // m(mass) = V(volume= m/d) * d(density= m/v)
int hight_H; // The distance traveled through the body, to facilitate it, can be called the height (h) from which the body fell: s = h. Velocity is expressed by the formula of accelerated motion v=at. To calculate the height from which a body fell, it is enough to measure the date of the fall.
int power_P; // P=W/T   //Power is the amount of work done per unit of time (1 second). We can also more generally say that power is the rate of change from one form of energy to another. Power formula: Let's calculate the power P by dividing the work by the time in which this work was done: P = W / t, where P - power, W - work, t - time.int kinetic_energy_Ek; // (M*V^2)/2   //Wzór na energię kinetyczną E k = m v 2 / 2 zawiera prędkość , która jak wiemy jest wielkością względną – tzn. wartość prędkości zależy od układu, względem którego mierzymy tę prędkość. Zauważmy zatem, że wartość energii kinetycznej ciała zależy od układu odniesienia.
int density; // M/V V-volume: ( V=a*b*c ) //In physics, the formula for density is ρ = m / V, where ρ is the density, m is the mass, V is the volume of the substance. The density of a substance is calculated by dividing the mass of a body by its volume.float energy; // e = m*c^2


// FUNCTIONS:
int spooky_particle(bool y, bool x)
{
    if (y==1) x=0;
    else if (x==0) y=0;
    return (y || x) ? 1 : 0; // Add return statement
}

float strange_signal()
{
    const float light_years = 4000.00;
    const float interval = 18.18;
    return light_years / interval; // Add return statement and use variables
}

void calculation_date()
{
    float energy;
    long date;
    // Remove unused 'mass' variable
    
    //cout << " Enter body weight (kg): " ;
    //cin >> mass;
    cout << "Enter the date without spaces: " << endl;
    cin >> date;

    cout << "\nDate * PI number: " << setprecision(2)
    << fixed << date*pi_number << endl;

    cout << "\nData * golden ratio: " << setprecision(2)
    << fixed << date*golden_ratio << endl;

    energy=date*(pow(speed_light, 2));
    cout << "\nE=MC2 equals: " << setprecision(2) << fixed << energy << endl;

    for(int i=0; i<=43 ; i++)
    {
    cout << "Date * fibonacci numbers: " << setprecision(2)
    << fixed << fib_numbers[i]*date << endl;
    }
}

//---------------------------------------------------------------------

int main() {
    int choice;
    
    while (true) {
        system("cls||clear");
        displayHeader();
        displayMenu();
        
        try {
            std::cin >> choice;
            
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::runtime_error("Invalid input");
            }

            switch (choice) {
                case 0:
                    setColor("bright_cyan");
                    std::cout << "\nThank you for using the program!\n";
                    setColor("");
                    return 0;
                    
                case 1: {
                    double distance, time;
                    setColor("green");
                    std::cout << "\nVELOCITY CALCULATION\n";
                    std::cout << "Enter distance (m): ";
                    std::cin >> distance;
                    std::cout << "Enter time (s): ";
                    std::cin >> time;
                    double result = velocity(distance, time);
                    std::cout << "Velocity: " << result << " m/s\n";
                    saveResult("Velocity", result);
                    break;
                }
                
                case 2: {
                    double mass, acceleration;
                    setColor("yellow");
                    std::cout << "\nFORCE CALCULATION\n";
                    std::cout << "Enter mass (kg): ";
                    std::cin >> mass;
                    std::cout << "Enter acceleration (m/s²): ";
                    std::cin >> acceleration;
                    double result = force(mass, acceleration);
                    std::cout << "Force: " << result << " N\n";
                    saveResult("Force", result);
                    break;
                }
                
                case 3: {
                    double mass, velocity;
                    setColor("yellow");
                    std::cout << "\nKINETIC ENERGY CALCULATION\n";
                    std::cout << "Enter mass (kg): ";
                    std::cin >> mass;
                    std::cout << "Enter velocity (m/s): ";
                    std::cin >> velocity;
                    double result = kineticEnergy(mass, velocity);
                    std::cout << "Kinetic Energy: " << result << " J\n";
                    saveResult("Kinetic Energy", result);
                    break;
                }
                
                case 4: {
                    double mass, height;
                    setColor("yellow");
                    std::cout << "\nPOTENTIAL ENERGY CALCULATION\n";
                    std::cout << "Enter mass (kg): ";
                    std::cin >> mass;
                    std::cout << "Enter height (m): ";
                    std::cin >> height;
                    double result = potentialEnergy(mass, height);
                    std::cout << "Potential Energy: " << result << " J\n";
                    saveResult("Potential Energy", result);
                    break;
                }
                
                case 5: {
                    double initialVelocity, mass, time, airDensity, dragCoefficient, area;
                    setColor("yellow");
                    std::cout << "\nFINAL VELOCITY WITH AIR RESISTANCE\n";
                    std::cout << "Enter initial velocity (m/s): ";
                    std::cin >> initialVelocity;
                    std::cout << "Enter mass (kg): ";
                    std::cin >> mass;
                    std::cout << "Enter time (s): ";
                    std::cin >> time;
                    std::cout << "Enter air density (kg/m³): ";
                    std::cin >> airDensity;
                    std::cout << "Enter drag coefficient: ";
                    std::cin >> dragCoefficient;
                    std::cout << "Enter cross sectional area (m²): ";
                    std::cin >> area;
                    double result = finalVelocityWithAirResistance(initialVelocity, mass, time, airDensity, dragCoefficient, area);
                    std::cout << "Final Velocity: " << result << " m/s\n";
                    saveResult("Final Velocity with Air Resistance", result);
                    break;
                }
                
                case 6: {
                    setColor("yellow");
                    std::cout << "\nDATE CALCULATIONS\n";
                    calculation_date();
                    break;
                }
                
                default:
                    throw std::runtime_error("Invalid menu choice");
            }
            
        } catch (const std::exception& e) {
            setColor("bright_magenta");
            std::cout << "Error: " << e.what() << std::endl;
            setColor("");
            Logger::log(std::string("Error occurred: ") + e.what());
        }
        
        waitForKeypress();
    }
    
    return 0;
}
