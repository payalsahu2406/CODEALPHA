//PROGRAM FOR REGISTRATION & LOGIN SYSTEM

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // save username or password in file
    ofstream file("user_data.txt");
    if (file.is_open()) {
        file << username << endl << password << endl;
        file.close();
        cout << "✅ Registration successful!\n";
    } else {
        cout << "❌ Error in registration!\n";
    }
}

bool loginUser() {
    string username, password, savedUsername, savedPassword;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Read stored username and password from file
    ifstream file("user_data.txt");
    if (file.is_open()) {
        getline(file, savedUsername);
        getline(file, savedPassword);
        file.close();

        // Check credentials
        if (username == savedUsername && password == savedPassword) {
            cout << "✅ Login successful!\n";
            return true;
        } else {
            cout << "❌ Invalid username or password!\n";
            return false;
        }
    } else {
        cout << "❌ No registered user found! Register first.\n";
        return false;
    }
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoose an option: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
        cout << "Now login to continue...\n";
        loginUser();
    } else if (choice == 2) {
        loginUser();
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}
