// Create a Triangle class. Add exception handling statements to ensure the following
// conditions: all sides are greater than 0 and sum of any two sides is greater than the third
// side. The class should also have overloaded functions for calculating the area of a right
// angled triangle as well as using Heron's formula to calculate the area of any type of
// triangle.


#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0 || side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
            throw "Invalid triangle sides";
        }
    }
    
    double perimeter(double s1, double s2, double s3){
        return s1 + s2 + s3;
    }

    double area(double base, double height) {
        return 0.5 * base * height;
    }

    double area(double s1, double s2, double s3) {
        double s = (s1 + s2 + s3) / 2;
        double area = s * (s - s1) * (s - s2) * (s - s3);
        if (area > 0) {
            return sqrt(area);
        } else {
            return 0;
        }
    }
};

int main() {
    try {
        Triangle t1(5, 12, 13);
        cout << "Perimeter of the right-angled triangle: " << t1.perimeter(5, 12, 13) << endl;

        Triangle t2(5, 12, 13);
        cout << "Area of the right-angled triangle: " << t2.area(12, 5) << endl;

        Triangle t3(12, 15, 20);
        cout << "Perimeter of the triangle: " << t3.perimeter(12, 15, 20) << endl;

        Triangle t4(12, 15, 20);
        cout << "Area of the triangle using Heron's formula: " << t4.area(12, 15, 20) << endl;

        Triangle t5(2, 0, 5);
    }

    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    return 0;
}

