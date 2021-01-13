#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv) {
    double weightInOunces;
    const double OUNCE_TO_METRIC_TON = 35273.92;

    cout << "Please input the weight of a cereal package in ounces: ";
    cin >> weightInOunces;
    
    // Weight must be positive
    if(weightInOunces <= 0) {
        cout << "Invalid weight!" << endl;
        return 1;
    }
    
    double weightInMetricTons = weightInOunces / OUNCE_TO_METRIC_TON;
    cout << endl << "Weight in Metric Tons: " << weightInMetricTons << endl;
    
    // Round up to ensure there are enough boxes
    int boxesNeeded = ceil(OUNCE_TO_METRIC_TON / weightInOunces);
    cout << "Number of Boxes Needed: " << boxesNeeded << endl;
    
    return 0;
}
