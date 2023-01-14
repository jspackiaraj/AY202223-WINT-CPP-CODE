#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static float readFile() {
    ifstream ifile("input1.txt");
    float returnSum = {0.0};
    if (ifile.is_open()) {
        string line;
        while (!ifile.eof()) {
            getline(ifile, line);
            returnSum += stoi(line);
        }
        ifile.close();
        return returnSum;

    } else {
        return NULL;
    }
}

int main(int argc, char** argv) {
    try {
        cout << readFile();
    } catch (exception e) {
        cout << "Failed reading file\n";
    }
    return (EXIT_SUCCESS);
}
