#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/* string mostFrequentCharacter() {
    return;
} */

int main() {
    
    string str;

    cout << "Please enter one word: ";
    cin >> str;

    char arr[str.length()];

    strcpy(arr, str.c_str());

    cout << "In your word, here's the most repeating characters: ";

    //prints char array
    /* for (int i = 0; i < strlen(arr); i++) {
        cout << arr[i] << " " ;
    } */

    //cout << endl

    for (int i = 0; i < sizeof(arr); i++) {

    }

    return 0;
}