#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip> // For formatting
#include "Includes/CreateAccount.h"
#include "Includes/User.h"

using namespace std;

void createAccount() {
    accountInfo newAccount;
    string confirmPassword;

    system("cls");
    cout << "************* CREATE NEW ACCOUNT *************" << endl;

    // Get account details
    cout << "Enter Account Number: ";
    cin >> newAccount.accountNumber;

    // Check if account already exists
    vector<accountInfo> accounts = loadAccountsFromFile("file.txt");
    for (const auto& acc : accounts) {
        if (acc.accountNumber == newAccount.accountNumber) {
            cout << "Account number already exists!" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            return;
        }
    }

    cout << "Enter Username: ";
    cin >> newAccount.username;

    // Password input with confirmation
    while (true) {
        cout << "Enter Password: ";
        cin >> newAccount.password;
        cout << "Confirm Password: ";
        cin >> confirmPassword;

        if (newAccount.password == confirmPassword) {
            break;
        }
        cout << "Passwords do not match! Try again." << endl;
    }

    // Set initial balance
    newAccount.balance = "0.0";

    // Save to file with proper formatting
    ofstream outFile("file.txt", ios::app);
    if (!outFile) {
        cerr << "Failed to open account file!" << endl;
        return;
    }

    // Format the output with consistent spacing
    outFile << "\n"<< newAccount.accountNumber << " "
            << newAccount.password << " "
            << newAccount.balance << " "
            << newAccount.username << "\n"; // Use \n instead of endl for consistency

    outFile.close();

    cout << "Account created successfully!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
}