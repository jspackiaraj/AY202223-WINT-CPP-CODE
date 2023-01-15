#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;

string readFile(string fileName)
{
    // We use the try catch in this iteration of the program
    ifstream ifile(fileName.c_str());
    // In this version, the error handling is done by the 
    // main() method which is calling the function readFile().

    if (!ifile.is_open())
    {
        throw runtime_error("Unable to open file.  Check if file exists ...");
    }
    string line { "" };
    // Set up a variable to store the intermediate value
    double returnSum { 0.0 };
    int intCnt { 0 };
    while (getline(ifile, line))
    {
        // There is a chance that the number cannot be converted
        // to a float, say it has a space or is a non-numeric string
        // We test this condition with a try block
        try {
            returnSum += stod(line);
        }
        catch (const invalid_argument& e)
        {
            throw e; // An invalid_argument error is thrown.
        }
        intCnt++;
    }
    // Assuming we get an empty file to be read by the program
    // We can use the file_size() method.  The file path should
    // be a valid path and we convrert the name to a path data.
    // can check now the file size.
    filesystem::path file_path(fileName.c_str());
    // if additionallly namespace filesystem; was used, then we 
    // can do away with the prefixed filesystem scope resolution.
    
    if (is_regular_file(file_path)) {
        uintmax_t intFileSize = { file_size(file_path) };
        cout << "File Size is " << intFileSize << " bytes."
            << endl;
        if (intFileSize == 0) {
            throw 1;
        }
    }
    // Always close open files
    ifile.close();
    // IF the file had no newline , then 
    return to_string(returnSum);
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
    catch (int e) // Catch an integer error
    {
        cerr << "Caught an error, looks like a divide by zero ... " << e << endl;
    }
    catch (const runtime_error& e) // Catch a string error 
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const invalid_argument& e) // Catch a string error 
    {
        cerr << "Error: " << e.what() << endl;
        cerr << "Looks like the file contains text data" << endl;
    }
    return (EXIT_SUCCESS);
}
