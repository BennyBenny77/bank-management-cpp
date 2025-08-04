#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

class User {
private:
    string username;
    double balance;

public:
    User(const string& username, double balance)
        : username(username), balance(balance) {}

    string getUsername() const { return username; }
    double getBalance() const { return balance; }
    void setBalance(double newBalance) { balance = newBalance; }
};

// Struct definition
struct accountInfo {
    std::string accountNumber;
    std::string password;
    std::string balance;
    std::string username;

    std::string getAccount() const { return accountNumber; }
    std::string getPassword() const { return password; }
    std::string getBalance()  const { return balance; }
    std::string getUsername() const { return username; }
};


// Function declaration
std::vector<accountInfo> loadAccountsFromFile(const std::string& filename);

#endif // USER_H
