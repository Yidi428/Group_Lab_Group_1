#include <iostream>
#include <string>
using namespace std;

int main() {

    string pass;
    bool oneUpperCase = false;
    bool hasDigit = false;
    bool isSixDigits = false;
    bool oneLowerCase = false;

    cout << "Enter your password (no spaces): ";

    cin >> pass;

    char passArray[pass.size() + 1];
    strcpy(passArray, pass.c_str());


    if ( strlen(passArray) >= 6 ) {

        isSixDigits = true;
        
    }

    for ( int i = 0; i < strlen(passArray); ++i ) {

        if ( isupper(passArray[i]) ) {
            oneUpperCase = true;
        }

        if ( islower(passArray[i]) ) {
            oneLowerCase = true;
        }
        
    }

    for ( int i = 0; i < strlen(passArray); ++i ) {

        if ( isdigit(passArray[i]) ) {
            hasDigit = true;
        }
        
    }

    if ( oneLowerCase && isSixDigits && hasDigit && oneUpperCase ) {

        cout << "Good to go! Use the password!." << endl;
        
    } else {

        cout << "Password did not meet criteria." << endl;
        cout << "Criteria:" << endl;
        cout << "At least one lowercase letter, one uppercase letter, one digit, and at least 6 characters." << endl;
        
    }

    return 0;
}