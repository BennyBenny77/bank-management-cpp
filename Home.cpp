#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "Includes/User.h"
#include "Includes/Deposit.h"

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define RESET "\x1B[0m"

void mainHome(const User& user) {
    using namespace std;
    int choice;

    while (true) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        cout << "************* WELCOME, " << user.getUsername() << " *************" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Logout" << endl << endl;
        cout << "Select your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                depositBalance(const_cast<User&>(user));
                //cout << "Deposit feature not yet implemented." << endl;
                break;
            case 2:
                cout << "Withdraw feature not yet implemented." << endl;
                break;
            case 3:
                cout << "Your current balance is: " << user.getBalance() << endl;
                break;
            case 4:
                cout << "Logging out... Goodbye!" << endl;
                return;
            default:
                cout << RED << "Enter a valid choice!" << RESET << endl;
                //this_thread::sleep_for(chrono::seconds(1));
                break;
        }

        this_thread::sleep_for(chrono::seconds(2));
    }
}
