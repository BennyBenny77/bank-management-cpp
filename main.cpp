#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

#include "Includes/Login.h"
#include "Includes/createAccount.h"

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define RESET "\x1B[0m"

int main() {
    using namespace std;
    int choice;

    while (true) {
        home:
        system("cls");
        cout << "************* WELCOME TO Benny&CO BANK *************" << endl;
        cout << "1. Login to your Account" << endl;
        cout << "2. Create a new Account" << endl;
        cout << "3. Terms of Service" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Select your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                createAccount();
                break;
            case 3:
                cout << "Showing terms of service..." << endl;
                this_thread::sleep_for(chrono::seconds(1));
                system("cls");
                goto home;
                break;
            case 4:
                cout << "Exiting... Goodbye!" << endl;
                return 0;
            default:
                cout << RED << "Enter a valid choice!" << RESET << endl;
                this_thread::sleep_for(chrono::seconds(1));
#ifdef _WIN32
                system("cls");
#else
                system("clear");
#endif
                break;
        }
    }
}
