// writing a text file
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    cout << "The file will be written in the same directory where the executable is " << endl;
    ofstream myfile("example.txt");
    if (myfile.is_open())
    {
        myfile << "Hello World.\n";
        myfile << "On Windows machines, the file will be created with line endings LF CR"<< endl;
        myfile << "For running on Linux machines, the file will have to be saved with LF Line Ending" << endl;
        myfile.close();
    }
    else cout << "Unable to open file";
    return 0;
}
