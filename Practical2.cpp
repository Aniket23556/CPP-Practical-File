// Write a program to remove the duplicates from an array.

#include <iostream>
using namespace std;


void removeDuplicates(int arr[], int& n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; ++k) {
                    arr[k] = arr[k + 1];
                }
                --n;
            } else {
                ++j;
            }
        }
    }
}

int main() {
    // Example array with duplicates
    // int arr[] = {1, 2, 3, 2, 4, 5, 6, 3, 7, 8, 1};
    // int n = sizeof(arr) / sizeof(arr[0]);

    int size = 100;
    cout << "Enter the size of the array: ";
    cin >> size;

    // int arr[size];
    int* arr = new int[size];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Remove duplicates
    removeDuplicates(arr, size);

    // Print array after removing duplicates
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

