#include <iostream>
#include <math.h>
using namespace std;

// Define an apartment complex with a unique set of parameters
class apartmentRevenueEqn {
  public:
    float priceOut = 0;
    float rentFinal = 0;
    float maxRevenue = 0;
    float rentInitial = 0;
    float maintenanceCost = 0;
    
    int totalApts = 0;
    int occupiedApts = 0;
};

// create an instance of class apartmentRevenueEqn to store this iteration's attributes
apartmentRevenueEqn r;

// Request and store user input
void takeInput() {
  cout << "Enter total number of units: ";
  cin >> r.totalApts;
  
  cout << '\n' << "Enter 100% occupation rent price: ";
  cin >> r.rentInitial;
  
  cout <<'\n' << "Enter the increase in rent which causes one unit to become vacant: ";
  cin >> r.priceOut;
  
  cout << '\n' << "Enter the amount to maintain a vacant unit: ";
  cin >> r.maintenanceCost;
}

// Runs numbers to get optimal rent and the number of apartments occupied at that rent price
void calculateMaxRent() {
  r.rentFinal = (r.rentInitial + r.priceOut * r.totalApts - r.maintenanceCost) / 2;
  r.occupiedApts = floor(r.totalApts - ((r.rentFinal-r.rentInitial)/r.priceOut));
}

// Corrects the step function integral issue
void fixSmoothing() {
    r.rentFinal = r.rentFinal - fmod(r.rentFinal, r.priceOut) + (r.priceOut - 0.01);
}

// Calculates the revenue based on earlier rent price and occupied apartments. 
void calculateMaxRevenue() {
  r.maxRevenue = r.occupiedApts * r.rentFinal;
  r.maxRevenue = r.maxRevenue - (r.maintenanceCost *(r.totalApts - r.occupiedApts));
}

int main() {
  // Call functions to modify rentFinal and maxRevenue attributes
  takeInput();
  calculateMaxRent();
  fixSmoothing();
  calculateMaxRevenue();

  // Display output
  cout << "Optimal rent is $" << r.rentFinal << '\n';
  cout << "Number of units occupied: " << r.occupiedApts << '\n';
  cout << "Maximum revenue is $" << r.maxRevenue;
  return 0;
}

// this is a somewhat flawed problem because increasing rent by an arbitrarily small amount does not always result in a decrease in occupied apartments, much as it does in real life. As such, we, the programmer, need to account for the 'resolution' of this function not being super high. In simpler terms, this problem is best modelled by a step function. We are able to increase the rent by just one cent less than would make another tenant move out (in the example, raising rent by $39.99 would not cause a decrease in occupancy).

// Likewise, the function describing revenue is not a perfect parabola. It is not technically differentiable, but if we assume that it is, then de-smooth its output, we get a reasonable approximation of what the maximum revenue is. That explains why graphing this function and using a C++ program to compute the maximum with the derivative I pre-calculated are slightly different. The tolerance is dependent entirely upon what percentage of the increase in rent which would cause one unit to go vacant is made up by the smallest available division of currency (the cent, $0.01).