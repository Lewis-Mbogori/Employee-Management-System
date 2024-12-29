#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
// Base class: Employee
class Employee {
protected:
string name;
int id;
double salary;
public:
Employee(string empName, int empId) : name(empName), id(empId), salary(0.0) {}
virtual void calculateSalary() = 0; // Pure virtual function for salary calculation
virtual void displayDetails() const = 0; // Pure virtual function for displaying details
virtual ~Employee() {}
};
// Derived class: FullTimeEmployee
class FullTimeEmployee : public Employee {
private:
double basicSalary;
double allowance;
public:
FullTimeEmployee(string empName, int empId, double basic, double allow)
: Employee(empName, empId), basicSalary(basic), allowance(allow) {}
void calculateSalary() override {
salary = basicSalary + allowance; // Salary = Basic + Allowance
}
void displayDetails() const override {
cout << "Full-Time Employee - Name: " << name
<< ", ID: " << id << ", Salary: " << salary << endl;
}
};
// Derived class: PartTimeEmployee
class PartTimeEmployee : public Employee {
private:
double hourlyRate;
int hoursWorked;
public:
PartTimeEmployee(string empName, int empId, double rate, int hours)
: Employee(empName, empId), hourlyRate(rate), hoursWorked(hours) {}
void calculateSalary() override {
salary = hourlyRate * hoursWorked; // Salary = Hourly Rate * Hours Worked
}
void displayDetails() const override {
cout << "Part-Time Employee - Name: " << name
<< ", ID: " << id << ", Salary: " << salary << endl;
}
};
void displayMenu() {
cout << "\n--- Employee Management System ---\n";
cout << "1. Add Full-Time Employee\n";
cout << "2. Add Part-Time Employee\n";
cout << "3. Calculate Salaries\n";
cout << "4. Display Employee Details\n";
cout << "5. Exit\n";
cout << "Enter your choice: ";
}
int main() {
vector<Employee*> employees; // Store employee objects
int choice;
do {
displayMenu();
cin >> choice;
if (choice == 1) {
// Add Full-Time Employee
string name;
int id;
double basic, allowance;
cout << "Enter Name, ID, Basic Salary, Allowance: ";
cin >> name >> id >> basic >> allowance;
employees.push_back(new FullTimeEmployee(name, id, basic, allowance));
}
else if (choice == 2) {
// Add Part-Time Employee
string name;
int id;
double hourlyRate;
int hoursWorked;
cout << "Enter Name, ID, Hourly Rate, Hours Worked: ";
cin >> name >> id >> hourlyRate >> hoursWorked;
employees.push_back(new PartTimeEmployee(name, id, hourlyRate, hoursWorked));
}
else if (choice == 3) {
// Calculate Salaries
for (auto &emp : employees) {
emp->calculateSalary();
}
cout << "Salaries calculated successfully!\n";
}
else if (choice == 4) {
// Display Employee Details
if (employees.empty()) {
cout << "No employees to display!\n";
} else {
for (const auto &emp : employees) {
emp->displayDetails();
}
}
}
else if (choice == 5) {
// Exit
cout << "Exiting the program. Goodbye!\n";
}
else {
// Invalid Input
cout << "Invalid choice. Please try again.\n";
}
} while (choice != 5);
// Clean up dynamically allocated memory
for (auto &emp : employees) {
delete emp;
}
return 0;
}