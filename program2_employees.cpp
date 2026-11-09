#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    float basicSalary, allowance, deduction, netSalary;
};

int main() {
    Employee employees[5];
    int highestIndex = 0;

    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details of employee " << i + 1 << ":\n";
        cout << "Employee ID: ";
        cin >> employees[i].id;

        cout << "Name: ";
        cin >> ws;
        getline(cin, employees[i].name);

        cout << "Basic salary: ";
        cin >> employees[i].basicSalary;
        cout << "Allowance: ";
        cin >> employees[i].allowance;
        cout << "Deduction: ";
        cin >> employees[i].deduction;

        employees[i].netSalary =
            employees[i].basicSalary + employees[i].allowance - employees[i].deduction;

        if (i == 0 || employees[i].netSalary > employees[highestIndex].netSalary) {
            highestIndex = i;
        }
    }

    cout << "\nNet salary of all employees:\n";
    for (int i = 0; i < 5; i++) {
        cout << "ID: " << employees[i].id
             << ", Name: " << employees[i].name
             << ", Net Salary: " << employees[i].netSalary << '\n';
    }

    cout << "\nEmployee receiving the highest net salary:\n";
    cout << "ID: " << employees[highestIndex].id
         << ", Name: " << employees[highestIndex].name
         << ", Net Salary: " << employees[highestIndex].netSalary << '\n';

    return 0;
}
