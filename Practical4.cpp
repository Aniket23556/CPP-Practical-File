// Write a menu driven program to perform string manipulation (without using inbuilt
// string functions):
// a. Show address of each character in string
// b. Concatenate two strings.
// c. Compare two strings
// d. Calculate length of the string (use pointers)
// e. Convert all lowercase characters to uppercase
// f. Reverse the string
// g. Insert a string in another string at a user specified position


#include <iostream>

using namespace std;

// Function to show address of each character in the string
void showAddress(const char *str)
{
    cout << "Address of each character in the string:" << endl;
    for (int i = 0; str[i] != '\0'; i++)
    {
        cout << "Character: " << str[i] << ", Address: " << (void *)&str[i] << endl;
    }
}

// Function to concatenate two strings
void concatenateStrings(const char *str1, const char *str2, char *result)
{
    int i = 0, j = 0;
    while (str1[i] != '\0')
    {
        result[j++] = str1[i++];
    }
    i = 0;
    while (str2[i] != '\0')
    {
        result[j++] = str2[i++];
    }
    result[j] = '\0';
}

// Function to compare two strings
int compareStrings(const char *str1, const char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
    {
        i++;
    }
    return str1[i] - str2[i];
}

// Function to calculate the length of the string using pointers
int stringLength(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

// Function to convert all lowercase characters to uppercase
void toUpperCase(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
        i++;
    }
}

// Function to reverse the string
void reverseString(char *str)
{
    int length = stringLength(str);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to insert a string into another string at a specified position
void insertString(char *str, const char *insertion, int position)
{
    int len1 = stringLength(str);
    int len2 = stringLength(insertion);
    if (position < 0 || position > len1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = len1; i >= position; i--)
    {
        str[i + len2] = str[i];
    }
    for (int i = 0; i < len2; i++)
    {
        str[position + i] = insertion[i];
    }
}

int main()
{
    char str1[100], str2[100], insertion[100], result[200];
    char choice;
    int position;

    cout << "Enter string 1: ";
    cin.getline(str1, 100);
    cout << "Enter string 2: ";
    cin.getline(str2, 100);
    while (choice!= 'h')
    {
        cout << "\nString Manipulation Menu:" << endl;
        cout << "a. Show address of each character in string" << endl;
        cout << "b. Concatenate two strings" << endl;
        cout << "c. Compare two strings" << endl;
        cout << "d. Calculate length of the string" << endl;
        cout << "e. Convert all lowercase characters to uppercase" << endl;
        cout << "f. Reverse the string" << endl;
        cout << "g. Insert a string in another string at a user specified position" << endl;
        cout << "h. End program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 'a':
            showAddress(str1);
            showAddress(str2);
            break;
        case 'b':
            concatenateStrings(str1, str2, result);
            cout << "Concatenated string: " << result << endl;
            break;
        case 'c':
            if (compareStrings(str1, str2) == 0)
            {
                cout << "Strings are equal." << endl;
            }
            else
            {
                cout << "Strings are not equal." << endl;
            }
            break;
        case 'd':
            cout << "Length of string 1: " << stringLength(str1) << endl;
            cout << "Length of string 2: " << stringLength(str2) << endl;
            break;
        case 'e':
            toUpperCase(str1);
            toUpperCase(str2);
            cout << "String 1 in uppercase: " << str1 << endl;
            cout << "String 2 in uppercase: " << str2 << endl;
            break;
        case 'f':
            reverseString(str1);
            reverseString(str2);
            cout << "Reversed string 1: " << str1 << endl;
            cout << "Reversed string 2: " << str2 << endl;
            break;
        case 'g':
            cout << "Enter string to insert: ";
            cin.ignore();
            cin.getline(insertion, 100);
            cout << "Enter position to insert: ";
            cin >> position;
            insertString(str1, insertion, position);
            cout << "String 1 after insertion: " << str1 << endl;
            break;
        case 'h':
            cout << "Exiting program!";
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

