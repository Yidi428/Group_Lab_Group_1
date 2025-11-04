#include <iostream>
using namespace std;

int* elementShifter(const int* arr, int size) {
    int* newArr = new int[size + 1];
    newArr[0] = 0;
    for (int i = 0; i < size; ++i) {
        newArr[i + 1] = arr[i];
    }
    return newArr;
}

int main() {
    int size = 0;

    cout << "Enter the size of the array (must be greater than 0): ";
    cin >> size;


    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }

    int* shift = elementShifter(arr, size);

    for (int i = 0; i < size + 1; ++i) {
        cout << shift[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] shift;

    return 0;
}
