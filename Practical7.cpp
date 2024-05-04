// Write a program to calculate GCD of two numbers.

#include <iostream>
using namespace std;

int CalculaeGCD(int num1, int num2) {
    int i, gcd;
        for(i=1;i<=num1; i++)
        {
            if (num1%i==0 && num2%i==0)
            {
                gcd=i;
            }
        }  
        return gcd;
}

int main() {
    int n1 , n2;
    cout << "Enter the First number:";
    cin >> n1 ;
    cout<< "Enter the Second number:";
    cin >> n2;

    // CalculaeGCD(num1, num2);
    cout << "The GCD of " << n1 << " and " << n2 << " is " << CalculaeGCD(n1,n2);

    return 0 ;
}
