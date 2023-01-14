#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string readFile(string fileName)
{
    string strReturnString;
    // We use the try catch in this iteration of the program
    ifstream ifile(fileName.c_str());
    // The if block is enclosed in a try .. catch block
        // We can eliminate the else block, by using the following construct
    try
    {
        if (!ifile.is_open())
        {
            throw runtime_error("FNF");
        }
    } // Error handler mechanism immediately follows the try block
    catch(const runtime_error& e)
    // Store the contents in address of e, of 
    // the data type runtime_error
    {
        return e.what();
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
    string strReturnString = readFile(fileName);
    if (strReturnString == "FNF")
    {
        cout << "Error: Unable to open file.  Check if file exists ..." << endl;
    }
    else
    {
        cout << "File strReturnString:\n" << strReturnString << endl;
    }
    return (EXIT_SUCCESS);
}
