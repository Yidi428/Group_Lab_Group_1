#include <iostream>
#include <cstring>
#include <string>
using namespace std;

 char* mostFrequentCharacter(char* arr, int size) {
    char* newArr = new char[size];

    for (int i = 0; i < size; i++) {
        
    }

    return "";
}

int main() {
    
    string str;

    cout << "Please enter one word: ";

    cin >> str;

    char arr[str.length()];

    int arraySize = sizeof(arr);

    strcpy(arr, str.c_str());

    cout << "In your word, here's the most repeating characters: ";

    //prints char array

    /* for (int i = 0; i < strlen(arr); i++) {

        cout << arr[i] << " " ;

    } */

    //cout << endl

    //come back later

    mostFrequentCharacter(arr, arraySize);

    return 0;
}