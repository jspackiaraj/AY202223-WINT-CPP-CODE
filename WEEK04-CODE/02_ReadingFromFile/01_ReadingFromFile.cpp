#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int main() {
	std::ifstream outfile;
	string strFileName{ "example.txt" };
    string line;
	std::cout << endl << strFileName <<endl; 
	outfile.open(strFileName); // append instead of overwrite
	if (outfile.is_open())
	{
		std::cout << endl << "File Open" << endl;
		cout << "================"<< endl;
		while ( getline(outfile,line) ){
		    std:: cout << line << endl;
		}
		outfile.close();
		cout << "================"<< endl;
	    cout << endl << "DONE ...";
	}
	else
	{
		cout << endl << "Unable to open file";
	}
	return 0;
}
