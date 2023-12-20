# Employee Management System

## Overview
This Employee Management System is a console-based C++ application designed for managing employee records. It supports operations like adding, editing, and deleting employee details, and maintains data persistence through file storage.

## Features

- **Add Employees:** Users can add new employee records to the system.
- **List Employees:** Displays a list of all employees in the system.
- **Edit Employees:** Allows modification of existing employee records.
- **Delete Employees:** Enables removal of employee records from the system.
- **Save to File:** Persist employee data to a file, ensuring data is retained across sessions.

## Usage
After launching the program, follow the on-screen prompts to manage employee data:
- **Add Employee:** Input details for a new employee.
- **List Employees:** View all employee records.
- **Edit Employee:** Modify details of an existing employee.
- **Delete Employee:** Remove an employee from the system.
- **Save to File:** Save current employee data to db_devshare.txt.
- **Exit:** Terminate the program and save changes.
- Choose an option by entering the corresponding number.

## File Structure
**Employee Struct:** A structure to define employee attributes like name, ID, position, and age.
Function Definitions:
<li>writeToFile: Saves the current state of employees to a file. </li>
<li>readFromFile: Loads employee data from a file.</li>
<li>addEmployee: Adds a new employee to the system.</li>
<li>listEmployees: Lists all employees in the system.</li>
<li>editEmployee: Edits the details of an existing employee.</li>
<li>deleteEmployee: Deletes an employee from the system.</li>
<li>Main Function: The entry point of the application, handling user input and program flow.</li>

## Contributions
Contributions are welcome. Fork the project, make changes, and submit a pull request.



## Installation

### Prerequisites
- C++ Compiler (GCC, Clang, MSVC)
- Standard Template Library (STL)

### Steps
1. Clone the repository or download the source code.
2. Compile the program using a C++ compiler:
   ```bash
   g++ main.cpp -o EmployeeManagement.exe
   ./EmployeeManagement.exe

