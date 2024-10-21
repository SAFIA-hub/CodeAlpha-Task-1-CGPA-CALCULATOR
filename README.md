#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee {
private:
    string username;  // Store username
    string password;  // Store password

public:
    void signup();
    void login();
};

void Employee::signup() {
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // Open file in append mode
    ofstream file;
    file.open("database.txt", ios::app);  // Append mode

    if (file.is_open()) {
        file << username << " " << password << endl;  // Write username and password
        file.close();
        cout << "Registration successful!" << endl;
    } else {
        cout << "Error opening file for writing!" << endl;
    }
}

void Employee::login() {
    string inputUsername, inputPassword;
    cout << "Enter Username: ";
    cin >> inputUsername;
    cout << "Enter Password: ";
    cin >> inputPassword;

    // Open the file for reading
    ifstream file("database.txt");
    string storedUsername, storedPassword;
    bool loginSuccess = false;

    if (file.is_open()) {
        // Loop through the file to check credentials
        while (file >> storedUsername >> storedPassword) {
            // Check if the input matches stored credentials
            if (storedUsername == inputUsername && storedPassword == inputPassword) {
                loginSuccess = true;
                break;
            }
        }
        file.close();

        if (loginSuccess) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Invalid credentials!" << endl;
        }
    } else {
        cout << "Error opening file for reading!" << endl;
    }
}

int main() {
    Employee emp;
    int choice;

    do {
        cout << "1. Signup" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                emp.signup();
                break;
            case 2:
                emp.login();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
