#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string readFile(string fileName)
{
    string strReturnString;
    // We use the try catch in this iteration of the program
    ifstream ifile(fileName.c_str());
    // In this version, the error handling is done by the 
    // main() method which is calling the function readFile().

    if (!ifile.is_open())
    {
        throw runtime_error("Unable to open file.  Check if file exists ...");
    }
    string line;
    while (getline(ifile, line))
    {
        strReturnString += line + "\n";
    }
    // Always close open files
    ifile.close();
    return strReturnString;
}

int main()
{
    string fileName{ "input1.txt" };
    // Ensure the path is escaped in Windows Machines
    // If the file is in the same path as the file, it will work.
    // Uncomment the following two lines to get input from user.
    /* cout << "Enter the file name: ";
    cin >> fileName;
    */
    try 
    {
        string strReturnString = readFile(fileName);
        cout << "File strReturnString:\n" << strReturnString << endl;
    } // Error handler mechanism immediately follows the try block
    catch (const runtime_error& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    return (EXIT_SUCCESS);
}
