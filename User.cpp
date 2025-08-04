#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Includes/User.h"

using namespace std;

vector<accountInfo> loadAccountsFromFile(const string& filename) {
    vector<accountInfo> accounts;
    ifstream infile(filename);

    if (!infile) {
        cerr << "Unable to open file " << filename << endl;
        return accounts;
    }

    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        accountInfo account;

        // Read all fields with proper separation
        if (iss >> account.accountNumber >> account.password
                >> account.balance >> account.username) {
            accounts.push_back(account);
                } else {
                    cerr << "Warning: Unable to parse line: " << line << endl;
                }
    }

    infile.close();
    return accounts;
}