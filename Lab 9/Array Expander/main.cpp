
#include <iostream>
using namespace std;

void arrayExpander(int* arr, int size) {
    return;
}

int main() {

    int size;

    cout << "Enter array size to populate from 1 to Size: ";
    cin >> size;

    int* array = new int[size];

    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }

    cout << endl;

    cout << "Here's your array: ";

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    arrayExpander(array, size);

    cout << endl;

    cout << "Here's the expanded array: ";

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    cout << endl;

    delete [] array;

    return 0;
}