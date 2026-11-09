#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student {
    int id;
    string name;
    float maths, science, english;
    float average;
};

int main() {
    Student students[5];
    int highestIndex = 0;

    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details of student " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> students[i].id;

        cout << "Name: ";
        cin >> ws;
        getline(cin, students[i].name);

        cout << "Mathematics mark: ";
        cin >> students[i].maths;
        cout << "Science mark: ";
        cin >> students[i].science;
        cout << "English mark: ";
        cin >> students[i].english;

        students[i].average =
            (students[i].maths + students[i].science + students[i].english) / 3.0f;

        if (students[i].average > students[highestIndex].average || i == 0) {
            highestIndex = i;
        }
    }

    cout << "\nStudents with an average of at least 60:\n";
    for (int i = 0; i < 5; i++) {
        if (students[i].average >= 60) {
            cout << "ID: " << students[i].id
                 << ", Name: " << students[i].name
                 << ", Average: " << students[i].average << '\n';
        }
    }

    cout << "\nHighest average:\n";
    cout << "Name: " << students[highestIndex].name
         << ", Average: " << students[highestIndex].average << '\n';

    return 0;
}
