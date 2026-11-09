#include <iostream>
#include <string>
using namespace std;

int main() {
    string state;

    cout << "Enter network state (Disconnected, Connecting, Connected, Reconnecting, Failed): ";
    cin >> state;

    if (state == "Disconnected" || state == "disconnected") {
        cout << "Network is disconnected. Please connect to a network.\n";
    } else if (state == "Connecting" || state == "connecting") {
        cout << "Connecting to the network. Please wait...\n";
    } else if (state == "Connected" || state == "connected") {
        cout << "Network connected successfully.\n";
    } else if (state == "Reconnecting" || state == "reconnecting") {
        cout << "Network connection lost. Trying to reconnect...\n";
    } else if (state == "Failed" || state == "failed") {
        cout << "Network connection failed. Please try again.\n";
    } else {
        cout << "Invalid network state.\n";
    }

    return 0;
}
