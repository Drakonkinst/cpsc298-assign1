#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int maxRoomCapacity;
    int numPeople;
    
    cout << "Please input the maximum room capacity: ";
    cin >> maxRoomCapacity;
    
    // Room capacity cannot be negative
    if(maxRoomCapacity < 0) {
        cout << "Invalid room capacity!" << endl;
        return 1;
    }
    
    cout << "Please input the number of people attending the meeting: ";
    cin >> numPeople;

    if(numPeople < 0) {
        cout << "Invalid number of people attending!" << endl;
        return 1;
    }
    
    if(numPeople <= maxRoomCapacity) {
        int numExtra = maxRoomCapacity - numPeople;
        cout << "It is legal to hold this meeting. " << numExtra <<
            " additional people may legally attend." << endl;
    } else {
        // Room exceeds max capacity
        int numOverLimit = numPeople - maxRoomCapacity;
        cout << "It is illegal to hold this meeting due to fire regulations! "
            << numOverLimit << " people must be excluded in order to meet" <<
            " regulations." << endl;
    }

    return 0;
}
