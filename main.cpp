#include "Hotel.h"

int main() {
    Hotel hotel;
    int choice;

    while (true) {
        cout << "\n===== Hotel Management System =====\n";
        cout << "1. Book Room\n";
        cout << "2. Display Booked Rooms\n";
        cout << "3. Check Out\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.bookRoom();
                break;
            case 2:
                hotel.displayCustomers();
                break;
            case 3:
                hotel.checkoutRoom();
                break;
            case 4:
                cout << "Exiting... Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}