// Create a Matrix class. Write a menu-driven program to
// perform following Matrix operations (exceptions should be thrown by the
// functions if matrices passed to them are incompatible and handled by the main()
// function):


    //  a.Sum   
    //  b.Product    
    //  c. Transpose


#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class Matrix {
private:
    int rows;
    int cols;
    int mat[MAX_SIZE][MAX_SIZE];

public:
    Matrix() : rows(0), cols(0) {}

    void inputMatrix() {
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "Enter elements of the matrix:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Enter element at position (" << i + 1 << "," << j + 1 << "): ";
                cin >> mat[i][j];
            }
        }
    }

    void displayMatrix() const {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Sum of two matrices
    Matrix sum(const Matrix other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices must be of the same size for addition.");
        }

        Matrix result;
        result.rows = rows;
        result.cols = cols;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }

        return result;
    }

    // Product of two matrices
    Matrix product(const Matrix other) const {
        if (cols != other.rows) {
            throw invalid_argument("Number of columns in first matrix must be equal to number of rows in second matrix for multiplication.");
        }

        Matrix result;
        result.rows = rows;
        result.cols = other.cols;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }

        return result;
    }

    // Transpose of the matrix
    Matrix transpose() const {
        Matrix result;
        result.rows = cols;
        result.cols = rows;

        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                result.mat[i][j] = mat[j][i];
            }
        }

        return result;
    }
};


int main() {
    int rows, cols;
    Matrix mat1,mat2, result;

    int choice = 1;
    int choose = 1;
    while (choice!=5) {
        cout << "Select operation:\n";
        cout << "1. Create Matrices\n";
        cout << "2. Sum\n";
        cout << "3. Product\n";
        cout << "4. Transpose\n";
        cout << "5. Exit\n";
        cout<< "Enter Your Choice:";
        cin >> choice;

        switch (choice) {
            case 1:
            //Details For First matrix
                cout << "Enter details for the first matrix:\n";
                mat1.inputMatrix();
            //Details For Second matrix
                cout << "Enter details for the second matrix:\n";
                mat2.inputMatrix();
                break;
            case 2:
                result = mat1.sum(mat2);
                cout << "Sum of Matrix";mat1.displayMatrix();cout<<"and";mat2.displayMatrix();cout<< "is:\n";
                result.displayMatrix();
                break;
            case 3:
                result = mat1.product(mat2);
                cout << "Product of Matrix";mat1.displayMatrix();cout<<"and";mat2.displayMatrix();cout<< "is:\n";
                result.displayMatrix();
                break;
            case 4:{
                while(choose!=0){
                    cout<<"Select Matrix for Transpose\n";
                    cout<<"1. Transpose of Martix1\n";
                    cout<<"2. Transpose of Martix2\n";
                    cout<<"0. Exit\n";
                    cout<< "Enter Your Choice:";
                    cin >> choose;

                    switch (choose){
                        case 1:
                            result = mat1.transpose();
                            cout << "Transpose of Matrix";mat1.displayMatrix();cout<<"is:\n";
                            result.displayMatrix();
                            break;
                        case 2:
                            result = mat2.transpose();
                            cout << "Transpose of Matrix";mat2.displayMatrix();cout<<"is:\n";
                            result.displayMatrix();
                            break;
                        case 0:
                            cout<<"Exiting from Transpose function\n";
                            break;
                        default:
                            cout << "Invalid choice\n";
                            break;
                    }
                }
                break;
            }

            case 5:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice\n";
                break;
        }
    }
    return 0;
}

