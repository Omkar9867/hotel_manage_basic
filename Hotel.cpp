#include "Hotel.h"
using namespace std;

Hotel::Hotel() {
    // Initialize room numbers from 1 to 100
    for (int i = 1; i <= 100; ++i)  {
        roomNumbers.push_back(i);
    }
}
// Function to check if room is available:
// Logic: find returns bookedRooms.end() if roomNumber is not found, this will return boolean accordingly.
bool Hotel::isRoomAvailable(int roomNumber) {
    return find(bookedRooms.begin(), bookedRooms.end(), roomNumber) == bookedRooms.end();
}

// Check rooms availability from roomNumbers
void Hotel::checkRoomAvailability() {
    cout << "Available rooms: ";
    for (const auto roomNumber : roomNumbers) { //auto means automatically figure out the type.
        cout << roomNumber << " " ;
    }
}

// Function to display all booked rooms
void Hotel::displayCustomers() {
    if (customers.empty()) {
        cout << "No rooms are currently booked.\n";
        return;
    }

    cout << "\nBooked Rooms Details:\n";
    cout << "-----------------------------------\n";
    for (const auto &cust : customers) {
        cout << "Name: " << cust.name << ", Room: " << cust.roomNumber << ", Phone: " << cust.phoneNumber << endl;
    }
    cout << "-----------------------------------\n";
}

// Book a room
void Hotel::bookRoom() {
    Customer newCustomer;
    cout << "Enter customer name:";
    cin.ignore();
    getline(cin, newCustomer.name);

    cout << "Enter customer phone number: ";
    cin >> newCustomer.phoneNumber;

    cout << "Enter room number: ";
    cin >> newCustomer.roomNumber;
    if(!isRoomAvailable(newCustomer.roomNumber)){
        cout << "Room is already booked. Please choose another room." << endl;
        return;
    }
    customers.push_back(newCustomer);
    bookedRooms.push_back(newCustomer.roomNumber);

    // remove room numbers from roomNumbers list
    roomNumbers.erase(remove(roomNumbers.begin(), roomNumbers.end(), newCustomer.roomNumber), roomNumbers.end());
    cout << "Room " << newCustomer.roomNumber << " booked successfully for " << newCustomer.name << endl;
}

// Checkout a room
void Hotel::checkoutRoom() {
    int roomNumber;
    cout << "Enter room number to checkout: ";
    cin >> roomNumber;

    bool found = false;
    for (size_t i = 0; i < customers.size(); i++){
        if(customers[i].roomNumber == roomNumber){
            customers.erase(customers.begin() + i); // Here you know the exact position by i, so directly erase
            bookedRooms.erase(remove(bookedRooms.begin(), bookedRooms.end(), roomNumber), bookedRooms.end()); // While here we should use remove to move that to tail and then erase the tail i.e. end()
            cout << "Room " << roomNumber << " checked out successfully." << endl;
            // Add room number back to available rooms
            roomNumbers.push_back(roomNumber); 
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Room " << roomNumber << " not found or already vacant!\n";
    }
}

