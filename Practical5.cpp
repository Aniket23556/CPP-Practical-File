// Write a program to merge two ordered arrays to get a single ordered array.


#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    // Merge the arrays until one of them is exhausted
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        result[k++] = arr1[i++];
    }

    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2;
    cout << "Enter the size of the first array: ";
    cin >> size1;
    cout << "Enter the size of the second array: ";
    cin >> size2;

    int* arr1 = new int[size1];
    cout << "Enter the elements of the first array in ascending order: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    int* arr2 = new int[size2];
    cout << "Enter the elements of the second array in ascending order: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    int resultSize = size1 + size2;
    int* result = new int[resultSize];

    mergeArrays(arr1, size1, arr2, size2, result);

    cout << "Merged Array: ";
    for (int i = 0; i < resultSize; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
