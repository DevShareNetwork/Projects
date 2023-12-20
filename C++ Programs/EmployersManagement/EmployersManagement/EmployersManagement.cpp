#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

struct Employee {
    string name;
    int id;
    float percentage;
    string position;
    int age;
};

const int MAX_EMPLOYEES = 50;
int currentID = 1; // Starting ID

void writeToFile(Employee emp[], int size, const string& filename) {
    ofstream fileOut(filename);
    for (int i = 0; i < size; ++i) {
        fileOut << emp[i].name << ","
            << emp[i].id << ","
            << emp[i].percentage << ","
            << emp[i].position << ","
            << emp[i].age << endl;
    }
    fileOut.close();
    cout << "The file is saved." << endl;
}

void readFromFile(Employee emp[], int& size, const string& filename) {
    ifstream fileIn(filename);
    string line;
    size = 0;
    if (!fileIn) {
        cout << "The file is not loaded." << endl;
    }
    else {
        while (getline(fileIn, line) && size < MAX_EMPLOYEES) {
            istringstream iss(line);
            getline(iss, emp[size].name, ',');
            iss >> emp[size].id;
            iss.ignore();
            iss >> emp[size].percentage;
            iss.ignore();
            getline(iss, emp[size].position, ',');
            iss >> emp[size].age;
            size++;
        }
        currentID = size > 0 ? emp[size - 1].id + 1 : 1; // Update currentID based on the last employee's ID
        fileIn.close();
        cout << "The file is loaded." << endl;
    }

}

void addEmployee(Employee emp[], int& size) {
    if (size >= MAX_EMPLOYEES) {
        cout << "Maximum capacity reached." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    cout << "Enter employee full name: ";
    getline(cin, emp[size].name);
    emp[size].id = currentID++; // Assign and increment the current ID
    cout << "Enter percentage: ";
    cin >> emp[size].percentage;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer before reading position
    cout << "Enter position: ";
    getline(cin, emp[size].position);
    cout << "Enter age: ";
    cin >> emp[size].age;
    size++;
}

void listEmployees(Employee emp[], int size) {
    if (size == 0) {
        cout << "No employees to display." << endl;
        return;
    }

    // Display table header
    cout << left
        << setw(5) << "No."
        << setw(20) << "Name"
        << setw(10) << "ID"
        << setw(10) << "%"
        << setw(20) << "Position"
        << setw(5) << "Age" << endl;
    cout << string(70, '-') << endl; // Draw a line for the table header

    // Display each employee's information in a row
    for (int i = 0; i < size; ++i) {
        cout << left
            << setw(5) << i + 1
            << setw(20) << emp[i].name
            << setw(10) << emp[i].id
            << setw(10) << emp[i].percentage
            << setw(20) << emp[i].position
            << setw(5) << emp[i].age << endl;
    }
}


void editEmployee(Employee emp[], int size) {
    int number;
    cout << "Enter employee number to edit: ";
    cin >> number;
    if (number < 1 || number > size) {
        cout << "Invalid employee number!" << endl;
        return;
    }
    number--; // Adjust for zero-based indexing
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    cout << "Editing Employee: " << emp[number].name << endl;
    cout << "Enter new name: ";
    getline(cin, emp[number].name);
    cout << "Enter new percentage: ";
    cin >> emp[number].percentage;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer before reading position
    cout << "Enter new position: ";
    getline(cin, emp[number].position);
    cout << "Enter new age: ";
    cin >> emp[number].age;
}


void deleteEmployee(Employee emp[], int& size) {
    int number;
    cout << "Enter employee number to delete: ";
    cin >> number;
    if (number < 1 || number > size) {
        cout << "Invalid employee number!" << endl;
        return;
    }
    number--; // Adjust for zero-based indexing
    for (int i = number; i < size - 1; i++) {
        emp[i] = emp[i + 1];
    }
    size--;
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;
    int choice;
    readFromFile(employees, numEmployees, "db_devshare.txt");
    do {
        cout << "1. Add Employee\n";
        cout << "2. List Employees\n";
        cout << "3. Edit Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. Save to File\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addEmployee(employees, numEmployees);
            break;
        case 2:
            listEmployees(employees, numEmployees);
            break;
        case 3:
            editEmployee(employees, numEmployees);
            break;
        case 4:
            deleteEmployee(employees, numEmployees);
            break;
        case 5:
            writeToFile(employees, numEmployees, "db_devshare.txt");
            break;
        case 0:
            writeToFile(employees, numEmployees, "db_devshare.txt");
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}