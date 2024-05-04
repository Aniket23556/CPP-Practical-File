// Write a program to compute the sum of the first n terms of the following series:
// sum = 1-1/(2)^2+1/(3)^3- ........

// The number of terms n is to be taken from the user through the command line. If the
// command line argument is not found then prompt the user to enter the value of n.


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    double sum = 0.0;
    cout << "Enter the number of terms: ";
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0)
            sum -= 1/pow(i,i); // subtracting even terms
        else
            sum += 1/pow(i,i); // adding odd terms
        // sum += 1.0/i;
    }
    cout << "Sum of series: " << sum;
    return 0;
}

