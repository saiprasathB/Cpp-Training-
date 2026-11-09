#include <iostream>
#include <string>
using namespace std;

int main() {
    string state;

    cout << "Enter device state (Off, Starting, Running, Error): ";
    cin >> state;

    if (state == "Off" || state == "off") {
        cout << "Device is switched Off.\n";
    } else if (state == "Starting" || state == "starting") {
        cout << "Device is Starting.\n";
    } else if (state == "Running" || state == "running") {
        cout << "Device Operating Normally.\n";
    } else if (state == "Error" || state == "error") {
        cout << "Restart Required.\n";
    } else {
        cout << "Invalid device state.\n";
    }

    return 0;
}
