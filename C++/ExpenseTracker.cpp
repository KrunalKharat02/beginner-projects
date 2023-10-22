#include<bits/stdc++.h>
using namespace std;
#ifdef _WIN32
const string CLEAR_COMMAND = "cls";
#else
const string CLEAR_COMMAND = "clear";
#endif

// Global array of month names
const string months[] = { "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December" };

// Expense structure to hold expense details
struct Expense {
    string category;
    double amount;
    string month;
};

// Function to clear the screen
void clearScreen() {
    system(CLEAR_COMMAND.c_str());
}

// Function to validate user input for menu choices
int validateChoice(int min, int max) {
    int choice;
    while (true) {
        cin >> choice;
        if (choice >= min && choice <= max) {
            return choice;
        }
        else {
            clearScreen();
            cout << "Invalid choice. Please try again: ";
        }
    }
}

// Function to add an expense
void addExpense() {
    clearScreen();
    cout << "Expense Tracker - Add Expense\n";
    cout << "-----------------------------\n";
    
    // Input category and amount
    string category;
    double amount;
    
    cout << "Enter the category: ";
    cin.ignore(); // Clear the newline left in the input buffer
    getline(cin, category);
    
    cout << "Enter the amount: ";
    cin >> amount;

    // Get the current month
    time_t now = time(0);
    tm* timeInfo = localtime(&now);
    string currentMonth = months[timeInfo->tm_mon];

    // Create an Expense object
    Expense expense = { category, amount, currentMonth };

    // Save the expense to a file (expense.txt)
    ofstream file("expense.txt", ios::app);
    if (file.is_open()) {
        file << expense.category << "," << expense.amount << "," << expense.month << "\n";
        file.close();
        cout << "\nExpense added successfully for " << expense.month << ".\n";
    }
    else {
        cerr << "Failed to open the expenses file (expense.txt) for writing." << endl;
    }

    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

// Function to view expenses for a specific month
// Function to view expenses for a specific month
void viewExpensesForMonth(const string& selectedMonth) {
    clearScreen();
    cout << "Expense Summary for " << selectedMonth << ":\n";
    cout << "----------------------------------------\n";
    cout << left << setw(15) << "Category" << right << "Total Amount\n";
    cout << "----------------------------------------\n";

    double totalSpent = 0.0;
    map<string, double> categoryExpenses;

    ifstream file("expense.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream ss(line);
            string category, month, lineData;
            double amount;
            char comma;

            if (getline(ss, lineData, ',')) {
                category = lineData;
            }
            if (getline(ss, lineData, ',')) {
                // Convert lineData to a double for the amount
                amount = stod(lineData);
            }
            if (getline(ss, lineData, ',')) {
                month = lineData;
            }

            if (month == selectedMonth) {
                categoryExpenses[category] += amount;
                totalSpent += amount; // Update total expense here
            }
        }
        file.close();

        for (const auto& entry : categoryExpenses) {
            cout << left << setw(15) << entry.first << right << entry.second << endl;
        }
    }
    else {
        cerr << "Failed to open the expenses file (expense.txt) for reading." << endl;
    }

    cout << "----------------------------------------\n";
    cout << "Total spent for " << selectedMonth << ": " << totalSpent << endl;
    cout << "----------------------------------------\n";
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}


// Function to display all expenses from the text file
// Function to display all expenses from the text file
void displayAllExpenses() {
    clearScreen();
    cout << "All Expenses:\n";
    cout << "----------------------------------------\n";
    cout << left << setw(15) << "Category" << left << setw(10) << "Amount" << "Month\n";
    cout << "----------------------------------------\n";

    double totalSpent = 0.0;
    map<string, double> categoryExpenses;

    ifstream file("expense.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream ss(line);
            string category, month, lineData;
            double amount;
            char comma;

            if (getline(ss, lineData, ',')) {
                category = lineData;
            }
            if (getline(ss, lineData, ',')) {
                // Convert lineData to a double for the amount
                amount = stod(lineData);
            }
            if (getline(ss, lineData, ',')) {
                month = lineData;
            }

            totalSpent += amount;
            categoryExpenses[category] += amount;

            cout << left << setw(15) << category << left << setw(10) << amount << month << endl;
        }
        file.close();

        for (const auto& entry : categoryExpenses) {
            cout << "----------------------------------------\n";
            cout << "Total spent for " << entry.first << ": " << entry.second << endl;
        }
    }
    else {
        cerr << "Failed to open the expenses file (expense.txt) for reading." << endl;
    }

    cout << "----------------------------------------\n";
    cout << "Total spent for all months: " << totalSpent << endl;
    cout << "----------------------------------------\n";
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}


// Function to view spending summary
void viewSummary() {
    clearScreen();
    cout << "Expense Tracker - View Spending Summary\n";
    cout << "----------------------------------------\n";
    cout << "Select an option:\n";
    cout << "1. View expenses of the current month\n";
    cout << "2. Select a specific month\n";
    cout << "3. View all expenses\n";
    cout << "----------------------------------------\n";
    cout << "Enter your choice: ";

    int option = validateChoice(1, 3);

    switch (option) {
        case 1: {
            // View expenses of the current month
            time_t now = time(0);
            tm* timeInfo = localtime(&now);
            string currentMonth = months[timeInfo->tm_mon];
            viewExpensesForMonth(currentMonth);
            break;
        }
        case 2: {
            // Select a specific month
            clearScreen();
            cout << "Select a month to view expenses:\n";
            cout << "----------------------------------------\n";

            for (int i = 0; i < 12; ++i) {
                cout << i + 1 << ". " << months[i] << endl;
            }

            cout << "----------------------------------------\n";
            cout << "Enter the number of the month: ";
            int monthChoice = validateChoice(1, 12);

            string selectedMonth = months[monthChoice - 1];
            viewExpensesForMonth(selectedMonth);
            break;
        }
        case 3: {
            // View all expenses
            displayAllExpenses();
            break;
        }
        default:
            clearScreen();
            cout << "Invalid option. Please try again.\n";
            break;
    }
}

int main() {
    // Ensure the expense.txt file exists
    ofstream expenseFile("expense.txt", ios::app);
    expenseFile.close();

    while (true) {
        clearScreen();
        cout << "Expense Tracker Menu:\n";
        cout << "----------------------\n";
        cout << "1. Add Expense\n";
        cout << "2. View Spending Summary\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        
        int choice = validateChoice(1, 3);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewSummary();
                break;
            case 3:
                clearScreen();
                cout << "Exiting Expense Tracker. Goodbye!\n";
                return 0;
        }
    }

    return 0;
}
