/*
Written by Lucas Stephen on May 11, 2022 for CPS 171
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    // Input and Initialisation
    float lengthCenti = 0;                                                          // initialise length variable, in centimeters
    cout << "Input a one-dimensional length, in centimeters: ";                     // prompt user to input length
    cin >> lengthCenti;                                                             // accept input and store in length variable

    // Calculate areas and their differences
    float lengthMeter = lengthCenti / 100;
    float squareArea = lengthMeter * lengthMeter;                                   // calculate raw square area
    float circleArea = 3.14159 * lengthMeter * lengthMeter;                         // calculate raw circle area
    float difference = squareArea - circleArea;                                     // calculate difference between square and circle area
    float cubeVolmLo = floor(lengthMeter * lengthMeter * lengthMeter);              // calculate floor volume of cube
    float cubeVolmHi = ceil(lengthMeter * lengthMeter * lengthMeter);               // calculate ceiling volume of cube

    // Output, using setprecision and showpoint as shown in example output
    cout << setprecision(5) << showpoint << "You entered: " << lengthCenti << " cm. or " << lengthMeter << " m." << '\n';       // setprecision of 
    cout << setprecision(8) << showpoint << "Area of Square (sq. m.): " << squareArea << '\n';
    cout << setprecision(8) << showpoint << "Area of Circle (sq. m.): " << circleArea << '\n';
    cout << setprecision(8) << showpoint << "Difference (sq. m.): " << difference << '\n' << '\n';
    cout << setprecision(8) << showpoint << "Cube volume, rounded down (cu. m.): " << cubeVolmLo << '\n';
    cout << setprecision(8) << showpoint << "Cube Volume, rounded up (cu. m.): " << cubeVolmHi;

    return 0;
}

