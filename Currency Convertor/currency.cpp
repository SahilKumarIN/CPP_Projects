#include <iostream>
#include <limits> // For input validation
using namespace std;

// Function to get conversion rates
float get_conversion_rate(int from, int to) {
    // Conversion rates relative to INR
    float conversion_rates[5][5] = {
        {1, 0.012, 0.011, 1.61, 0.0097},  // INR -> USD, EUR, JPY, GBP
        {83.0, 1, 0.92, 134.6, 0.79},     // USD -> INR, EUR, JPY, GBP
        {90.5, 1.08, 1, 146.9, 0.86},     // EUR -> INR, USD, JPY, GBP
        {0.62, 0.0074, 0.0068, 1, 0.0058}, // JPY -> INR, USD, EUR, GBP
        {103.1, 1.27, 1.16, 170.2, 1}     // GBP -> INR, USD, EUR, JPY
    };

    return conversion_rates[from - 1][to - 1];
}

// Function to display available currency options
void display_currency_options() {
    cout << "Available currencies:\n";
    cout << "1. INR (Indian Rupee)\n";
    cout << "2. USD (US Dollar)\n";
    cout << "3. EUR (Euro)\n";
    cout << "4. JPY (Japanese Yen)\n";
    cout << "5. GBP (British Pound)\n";
}

// Function to handle input validation for currency selection
int get_currency_option(const string& prompt) {
    int option;
    while (true) {
        cout << prompt;
        cin >> option;
        if (cin.fail() || option < 1 || option > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid option. Please select a valid currency option (1-5).\n";
        } else {
            break;
        }
    }
    return option;
}

// Function for performing currency conversion
void currency_converter() {
    display_currency_options();

    // Ask for the source currency
    int from_currency = get_currency_option("\nSelect the currency you have (1-5): ");
    
    // Ask for the target currency
    int to_currency = get_currency_option("Select the currency you want to convert to (1-5): ");
    
    if (from_currency == to_currency) {
        cout << "Both currencies are the same. No conversion needed.\n";
        return;
    }

    // Get the amount to convert
    float amount;
    cout << "Enter the amount you want to convert: ";
    while (!(cin >> amount)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid amount. Please enter a valid number: ";
    }

    // Get conversion rate
    float conversion_rate = get_conversion_rate(from_currency, to_currency);
    float converted_amount = amount * conversion_rate;

    // Display the result
    string currencies[] = {"INR", "USD", "EUR", "JPY", "GBP"};
    cout << "Your amount " << amount << " " << currencies[from_currency - 1] << " is " 
         << converted_amount << " " << currencies[to_currency - 1] << ".\n";

    // Ask if the user wants to convert another currency
    cout << "\nDo you want to convert another currency? (1 for Yes, 2 for No): ";
    int new_option;
    while (!(cin >> new_option) || (new_option != 1 && new_option != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid option. Please enter 1 to proceed or 2 to exit: ";
    }

    if (new_option == 1) {
        currency_converter(); // Recursively call for new conversion
    }
}

int main() {
    currency_converter();
    cout << "Thank you for using the currency converter!" << endl;
    return 0;
}
