//PROGRAM FOR BANKING SYSTEM

#include <iostream>
using namespace std;

class Bank {
private:
    string username, password;
    double balance;

public:
    Bank() { balance = 0.0; } // Constructor to set initial balance

    void registerUser() {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "✅ Registration successful!\n";
    }

    bool login() {
        string uname, pass;
        cout << "Enter username: ";
        cin >> uname;
        cout << "Enter password: ";
        cin >> pass;

        if (uname == username && pass == password) {
            cout << "✅ Login successful!\n";
            return true;
        } else {
            cout << "❌ Invalid username or password!\n";
            return false;
        }
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "✅ Deposited: $" << amount << endl;
        } else {
            cout << "❌ Invalid amount!\n";
        }
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > balance) {
            cout << "❌ Insufficient balance!\n";
        } else if (amount <= 0) {
            cout << "❌ Invalid amount!\n";
        } else {
            balance -= amount;
            cout << "✅ Withdrawn: $" << amount << endl;
        }
    }

    void checkBalance() {
        cout << "💰 Current Balance: $" << balance << endl;
    }
};

int main() {
    Bank user;
    int choice;
    
    while (true) {
        cout << "\n🏦 MENU 🏦\n1. Register\n2. Login\n3. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) user.registerUser();
        else if (choice == 2) {
            if (user.login()) {
                while (true) {
                    cout << "\n🔹 1. Deposit\n🔹 2. Withdraw\n🔹 3. Check Balance\n🔹 4. Logout\nChoose: ";
                    cin >> choice;
                    if (choice == 1) user.deposit();
                    else if (choice == 2) user.withdraw();
                    else if (choice == 3) user.checkBalance();
                    else if (choice == 4) break;
                    else cout << "❌ Invalid choice!\n";
                }
            }
        } 
        else if (choice == 3) {
            cout << "👋 Thank you for using our bank!\n";
            break;
        } 
        else {
            cout << "❌ Invalid choice! Try again.\n";
        }
    }
    return 0;
}
