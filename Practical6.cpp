// Write a program to search a given element in a set of N numbers.

#include <iostream>
using namespace std;

bool searchElement(const int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    int* numbers = new int[N];
    cout << "Enter " << N << " numbers:\n";
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    int element;
    cout << "Enter the element to search: ";
    cin >> element;

    if (searchElement(numbers, N, element)) {
        cout << "Element found in the set." << endl;
    } else {
        cout << "Element not found in the set." << endl;
    }

    return 0;
}
