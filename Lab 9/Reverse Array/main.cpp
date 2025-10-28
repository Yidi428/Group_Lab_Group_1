
#include <iostream>
using namespace std;

void reverseArray(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int max = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        if (max != i) {
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }
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

    reverseArray(array, size);

    cout << endl;

    cout << "Here's the reversed array: ";

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    cout << endl;

    delete [] array;

    return 0;
}