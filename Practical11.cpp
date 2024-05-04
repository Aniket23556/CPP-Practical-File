// Copy the contents of one text file to another file, after removing all whitespaces.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

string removeWhitespace(const string& str) {
    string result;
    for (char c : str) {
        if (!isspace(c)) {
            result += c;
        }
    }
    return result;
}

int main() {
    ifstream inputFile("file1.txt");
    ofstream outputFile("file2.txt");

    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    stringstream buffer;
    buffer << inputFile.rdbuf();
    string content = buffer.str();
    string modifiedContent = removeWhitespace(content);

    outputFile << modifiedContent;

    cout << "Whitespaces removed and content copied successfully!" << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
