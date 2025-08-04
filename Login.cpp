#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Includes/Login.h"
#include "Includes/Home.h"
#include "Includes/User.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

void login() {
    using namespace std;

    const int maxAttempts = 3;
    string inputAccount;
    string inputPassword;

    vector<accountInfo> accounts = loadAccountsFromFile("file.txt");
    if (accounts.empty()) {
        cerr << RED << "No account data found or failed to open file." << RESET << endl;
        return;
    }

    for (int attempt = maxAttempts; attempt > 0; --attempt) {
        system("cls");
        cout << "************* WELCOME TO Benny&CO BANK *************" << endl;
        cout << "Acc NO. : ";
        cin >> inputAccount;
        cout << "Password: ";
        cin >> inputPassword;

        bool loginSuccess = false;
        accountInfo loggedUser;

        for (const auto& acc : accounts) {
            if (inputAccount == acc.accountNumber && inputPassword == acc.password) {
                loginSuccess = true;
                loggedUser = acc;
                break;
            }
        }

        if (loginSuccess) {
            std::cout << GRN << "Login successful! Welcome " << loggedUser.username << RESET << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            system("cls");
            double balance = std::stod(loggedUser.balance);
            User activeUser(loggedUser.username, balance);
            mainHome(activeUser);

            return;
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
        } else {
            cout << RED << "Login failed!" << RESET << endl;
            cout << "Please try again. " << attempt - 1 << " trial"
                 << (attempt - 1 == 1 ? "" : "s") << " remaining." << endl;
            this_thread::sleep_for(chrono::seconds(2));
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
        }
    }

    cout << RED << "\nMaximum login attempts reached. Exiting." << RESET << endl;
}
