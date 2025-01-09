#include <iostream>
using namespace std;

/*  [Explanation]
    Hotel Management System:
    - This program simulates a hotel management system where users can book rooms, order food, and view the sales information.
    - The system tracks the availability of rooms, pasta, shakes, maggie, and chicken rolls.
    - It allows users to book these items and generates revenue information based on the sales.
*/

int main() {
    int quantity = 0; // Quantity for booking items
    int menuChoice; // Menu choice input from user

    // Available quantities of items in the hotel
    int availableRooms = 0, availablePasta = 0, availableShakes = 0, availableMaggie = 0, availableChickenRolls = 0;

    // Sold quantities of items
    int soldRooms = 0, soldPasta = 0, soldShakes = 0, soldMaggie = 0, soldChickenRolls = 0;

    // Total revenue generated from sales
    int totalRevenueRooms = 0, totalRevenuePasta = 0, totalRevenueShakes = 0, totalRevenueMaggie = 0, totalRevenueChickenRolls = 0;

    // Getting available quantities from the hotel manager
    cout << "\t Quantity of items in Hotel " << endl;
    cout << "Enter total number of rooms available: " << endl;
    cin >> availableRooms;
    
    cout << "Enter total number of pasta available: " << endl;
    cin >> availablePasta;
    
    cout << "Enter total number of shakes available: " << endl;
    cin >> availableShakes;
    
    cout << "Enter total number of maggie available: " << endl;
    cin >> availableMaggie;
    
    cout << "Enter total number of chicken rolls available: " << endl;
    cin >> availableChickenRolls;

    // Hotel menu for the user to select from
    menu:
    cout << "Select from the menu: " << endl;
    cout << "1) Room" << endl;
    cout << "2) Pasta" << endl;
    cout << "3) Shake" << endl;
    cout << "4) Maggie" << endl;
    cout << "5) Chicken Roll" << endl;
    cout << "6) Information of today's sales and collection" << endl;
    cout << "7) Exit" << endl;

    cout << "Please enter your choice: " << endl;
    cin >> menuChoice;

    switch (menuChoice) {
        case 1:
            cout << "Enter number of rooms required: " << endl;
            cin >> quantity;
            
            if (availableRooms - soldRooms >= quantity) {
                soldRooms += quantity;
                availableRooms -= quantity;
                totalRevenueRooms += (2000 * quantity);
                cout << "Booking successful!" << endl;
            } else {
                cout << "Sorry! We don't have sufficient rooms." << endl;
                cout << "Available rooms: " << availableRooms - soldRooms << endl;
            }
            break;

        case 2:
            cout << "Enter number of pasta required: " << endl;
            cin >> quantity;
            
            if (availablePasta - soldPasta >= quantity) {
                soldPasta += quantity;
                availablePasta -= quantity;
                totalRevenuePasta += (300 * quantity);
                cout << "Booking successful!" << endl;
            } else {
                cout << "Sorry! We don't have sufficient pasta." << endl;
                cout << "Available pasta: " << availablePasta - soldPasta << endl;
            }
            break;

        case 3:
            cout << "Enter number of shakes required: " << endl;
            cin >> quantity;
            
            if (availableShakes - soldShakes >= quantity) {
                soldShakes += quantity;
                availableShakes -= quantity;
                totalRevenueShakes += (100 * quantity);
                cout << "Booking successful!" << endl;
            } else {
                cout << "Sorry! We don't have sufficient shakes." << endl;
                cout << "Available shakes: " << availableShakes - soldShakes << endl;
            }
            break;

        case 4:
            cout << "Enter total number of maggie required: " << endl;
            cin >> quantity;
            
            if (availableMaggie - soldMaggie >= quantity) {
                soldMaggie += quantity;
                availableMaggie -= quantity;
                totalRevenueMaggie += (150 * quantity);
                cout << "Booking successful!" << endl;
            } else {
                cout << "Sorry! We don't have sufficient maggie." << endl;
                cout << "Available maggie: " << availableMaggie - soldMaggie << endl;
            }
            break;

        case 5:
            cout << "Enter total number of chicken rolls required: " << endl;
            cin >> quantity;
            
            if (availableChickenRolls - soldChickenRolls >= quantity) {
                soldChickenRolls += quantity;
                availableChickenRolls -= quantity;
                totalRevenueChickenRolls += (470 * quantity);
                cout << "Booking successful!" << endl;
            } else {
                cout << "Sorry! We don't have sufficient chicken rolls." << endl;
                cout << "Available chicken rolls: " << availableChickenRolls - soldChickenRolls << endl;
            }
            break;

        case 6:
            // Displaying the information of sales and collection for the day
            cout << "\t Information about sales and collection" << endl;
            cout << "Number of rooms rented: " << soldRooms << endl;
            cout << "Remaining rooms: " << availableRooms - soldRooms << endl;
            cout << "Income generated by renting rooms: " << totalRevenueRooms << endl;

            cout << "Sold pasta: " << soldPasta << endl;
            cout << "Remaining pasta: " << availablePasta - soldPasta << endl;
            cout << "Income generated by selling pasta: " << totalRevenuePasta << endl;

            cout << "Sold shakes: " << soldShakes << endl;
            cout << "Remaining shakes: " << availableShakes - soldShakes << endl;
            cout << "Income generated by selling shakes: " << totalRevenueShakes << endl;

            cout << "Sold maggie: " << soldMaggie << endl;
            cout << "Remaining maggie: " << availableMaggie - soldMaggie << endl;
            cout << "Income generated by selling maggie: " << totalRevenueMaggie << endl;

            cout << "Sold chicken rolls: " << soldChickenRolls << endl;
            cout << "Remaining chicken rolls: " << availableChickenRolls - soldChickenRolls << endl;
            cout << "Income generated by selling chicken rolls: " << totalRevenueChickenRolls << endl;
            
            cout << "Total revenue generated: " << totalRevenueRooms + totalRevenuePasta + totalRevenueMaggie + totalRevenueShakes + totalRevenueChickenRolls << endl;
            break;

        case 7:
            cout << "Thank you for visiting!" << endl;
            break;

        default:
            cout << "Re-enter a valid option." << endl;
    }

    cout << endl;
    // Looping back to the menu
    goto menu;
    
    return 0;
}
