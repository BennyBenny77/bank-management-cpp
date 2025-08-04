#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <limits>
#include <cstdio> // For remove() and rename()
#include "Includes/User.h"
#include "Includes/Deposit.h"

using namespace std;

void depositBalance(User& user) {
    double amount;

    cout << "************* WELCOME, " << user.getUsername() << " *************" << endl;
    cout << "Enter the amount you want to deposit: ";

    // Input validation
    while (!(cin >> amount) || amount <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid amount! Please enter a positive number: ";
    }

    // Update balance
    user.setBalance(user.getBalance() + amount);

    cout << "Hey " << user.getUsername() << ", your new balance is: " << user.getBalance() << endl;

    // Load all accounts from file
    vector<accountInfo> accounts = loadAccountsFromFile("file.txt");
    if (accounts.empty()) {
        cerr << "Failed to load accounts or no accounts found!" << endl;
        return;
    }

    // Update the matching account's balance
    bool accountFound = false;
    for (auto& acc : accounts) {
        if (acc.username == user.getUsername()) {
            acc.balance = to_string(user.getBalance());
            accountFound = true;
            break;
        }
    }

    if (!accountFound) {
        cerr << "Account not found in database!" << endl;
        return;
    }

    // Save updated accounts to a temporary file
    string tempFile = "file.tmp";
    ofstream outFile(tempFile);
    if (!outFile) {
        cerr << "Failed to create temporary file!" << endl;
        return;
    }

    for (const auto& acc : accounts) {
        outFile << acc.accountNumber << " "
                << acc.password << " "
                << acc.balance << " "
                << acc.username << "\n";
    }

    outFile.close();

    // Replace the original file
    if (remove("file.txt") != 0) {
        cerr << "Warning: Could not remove old file - " << strerror(errno) << endl;
    }

    if (rename(tempFile.c_str(), "file.txt") != 0) {
        cerr << "Error: Failed to update account file! - " << strerror(errno) << endl;
        // Attempt to restore the temporary file
        rename(tempFile.c_str(), "file_backup.txt");
        cerr << "A backup has been saved as file_backup.txt" << endl;
        return;
    }

    cout << "Balance updated successfully!" << endl;
}