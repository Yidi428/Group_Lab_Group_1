#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string Date;
    string name;
    int amount;
    int maxAmount = 10000;

    cout << "Enter the date: ";
    getline(cin, Date);
    cout << "Enter the name: ";
    getline(cin, name);
    cout << "Enter the amount: ";
    cin >> amount;

    while ((amount > maxAmount) || (amount < 0)) {
        cout << "Invalid amount entered. Please reenter amount: ";
        cin >> amount;
    }

    cout << "Date: " << Date << endl;
    cout << fixed << setprecision(2);
    cout << "Pay to the Order of: " << name << " $" << amount << endl;

    return 0;
}