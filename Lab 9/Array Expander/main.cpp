
#include <iostream>
using namespace std;

int* arrayExpander(const int* arr, int size) {
    int* newArr = new int[size * 2];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    for (int i = size; i < size * 2; ++i) {
        newArr[i] = 0;
    }
    return newArr;
}

int main() {
    int size = 0;

    cout << "Enter the size of the array (must be greater than 0). The resulting array will be empty: ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }

    int* expandedArr = arrayExpander(arr, size);

    cout << "Expanded array: ";
    for (int i = 0; i < size * 2; ++i) {
        cout << expandedArr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] expandedArr;

    return 0;
}
