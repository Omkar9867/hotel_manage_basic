#ifndef HOTEL_H
#define HOTEL_H

#include "Customer.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Hotel {
    private:
        vector<Customer> customers;
        vector<int> roomNumbers;
        vector<int> bookedRooms;

    public:
        Hotel();
        // Function to check if room is available:
        // Logic: find returns bookedRooms.end() if roomNumber is not found, this will return boolean accordingly.
        bool isRoomAvailable(int roomNumber);

        // Check rooms availability from roomNumbers
        void checkRoomAvailability();

        // Function to display all booked rooms
        void displayCustomers();

        // Book a room
        void bookRoom();

        // Checkout a room
        void checkoutRoom();
};
#endif