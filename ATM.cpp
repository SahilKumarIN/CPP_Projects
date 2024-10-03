#include <iostream>
using namespace std;

// Function prototypes
void displayMenu();
void checkBalance(double balance);
double deposit(double balance);
double withdraw(double balance);

int main() {
    // Initial variables
    const int PIN = 1234;  // Preset PIN for simplicity
    int enteredPin;
    double balance = 1000.00;  // Initial balance
    int attempts = 0;
    int maxAttempts = 3;
    int choice;

    // PIN verification
    while (attempts < maxAttempts) {
        cout << "Enter your 4-digit PIN: ";
        cin >> enteredPin;

        if (enteredPin == PIN) {
            cout << "\nPIN verified successfully!\n";
            do {
                // Display ATM menu
                displayMenu();
                cout << "\nChoose an option: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        checkBalance(balance);
                        break;
                    case 2:
                        balance = deposit(balance);
                        break;
                    case 3:
                        balance = withdraw(balance);
                        break;
                    case 4:
                        cout << "Exiting...\n";
                        break;
                    default:
                        cout << "Invalid choice! Please try again.\n";
                }
            } while (choice != 4);  // Loop until the user chooses to exit
            break;
        } else {
            attempts++;
            cout << "Incorrect PIN. Attempts remaining: " << maxAttempts - attempts << endl;
        }

        if (attempts == maxAttempts) {
            cout << "Maximum attempts reached. Exiting program.\n";
        }
    }

    return 0;
}

// Function to display ATM menu
void displayMenu() {
    cout << "\n=== ATM MENU ===";
    cout << "\n1. Check Balance";
    cout << "\n2. Deposit";
    cout << "\n3. Withdraw";
    cout << "\n4. Exit";
}

// Function to check balance
void checkBalance(double balance) {
    cout << "Your current balance is: $" << balance << endl;
}

// Function to deposit money
double deposit(double balance) {
    double depositAmount;
    cout << "Enter deposit amount: $";
    cin >> depositAmount;

    if (depositAmount > 0) {
        balance += depositAmount;
        cout << "Deposit successful! New balance: $" << balance << endl;
    } else {
        cout << "Invalid amount!\n";
    }

    return balance;
}

// Function to withdraw money
double withdraw(double balance) {
    double withdrawAmount;
    cout << "Enter withdraw amount: $";
    cin >> withdrawAmount;

    if (withdrawAmount > 0 && withdrawAmount <= balance) {
        balance -= withdrawAmount;
        cout << "Withdrawal successful! New balance: $" << balance << endl;
    } else if (withdrawAmount > balance) {
        cout << "Insufficient funds!\n";
    } else {
        cout << "Invalid amount!\n";
    }

    return balance;
}
