#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <iterator>
#include <list>
using namespace std;
double computeVariance(list<double> listNumbs, double* dblMeanMark, bool boolDebugMode = { false }) {
	// Creating an iterator
	list<double>::iterator it;
	double dblMean{ 0.0 };
	double dblTmpMark{ 0.0 };
	for (it = listNumbs.begin(); it != listNumbs.end(); it++) {
		dblMean += *it;
		if (boolDebugMode) {
			cout << endl << *it << endl;
		}
	}
	if (boolDebugMode) {
		cout << endl << "Sum is " << dblMean << endl;
	}
	dblMean = dblMean / listNumbs.size();
	cout << endl <<"Mean is " << dblMean <<endl;
	for (it = listNumbs.begin(); it != listNumbs.end(); it++) {
		dblTmpMark += pow(*it - dblMean, 2);
	}
	*dblMeanMark = dblMean;
	return dblTmpMark / (listNumbs.size() - 1);
}

int main() {
	std::ifstream outfile;
	bool boolDebugMode = false;
	bool boolNoDecoratorMode = true;
	bool boolNoErrorOpeningFile = false;
	// Get the number of values
	int intLineCount{ 0 };
	int intValidVals{ 0 };
	int intAbsentees{ 0 };
	int intStudentsWhoPassed{ 0 };
	int intStudentsWhoFailed{ 0 };
	double dblMean{ 0.0 };
	double dblTmpMark{ 0.0 };
	double dblSD{ 0.0 };
	list <double> dblValidMarksList;
	string line;
	string strFileName{ "test.txt" };

	if (boolDebugMode) {
		std::cout << "Enter the file name to open (with full path): ";
	}
	/*
	Uncomment the line below to enter a custom file name
	*/
	//cin >> strFileName;
	if (boolDebugMode) {
		std::cout << endl << strFileName << endl;
	}
	outfile.open(strFileName);
	if (outfile.is_open())
	{
		boolNoErrorOpeningFile = true;
		if (boolDebugMode) {
			std::cout << endl << "File Open" << endl;
		}
		std::cout << "================" << endl;
		while (getline(outfile, line)) {
			if (boolDebugMode) {
				std::cout << line << endl;
			}
			if (intLineCount > 0) {
				if (line == "AA") {
					intAbsentees++;
				}
				else {
					intValidVals++;
					dblTmpMark = stod(line);
					if (boolDebugMode) {
						std::cout << "Numeric Val: " << dblTmpMark << endl;
					}
					dblValidMarksList.push_back(dblTmpMark);
					if (dblTmpMark < 20.0) {
						intStudentsWhoFailed++;
					}
				}
			}
			intLineCount++;
		}
	
		outfile.close();
		dblSD = pow(computeVariance(dblValidMarksList, &dblMean), 0.5);
		intStudentsWhoPassed = intValidVals - intStudentsWhoFailed - intAbsentees;
		std::cout << "================" << endl;
		std::cout << "           The mean mark is : " << dblMean << endl;
		std::cout << "         The SD of marks is : " << dblSD << endl;
		std::cout << "     Num. of Valid Students : " << intValidVals << endl;
		std::cout << "          Num. of Absentees : " << intAbsentees << endl;
		std::cout << "Num. of Students who Passed : " << intStudentsWhoPassed << endl;
		std::cout << "Num. of Students who failed : " << intStudentsWhoFailed << endl;
		std::cout << "================" << endl;
		if (boolDebugMode) {
			std::cout << endl << "DONE ...";
		}
	}
	else {
		std::cout << "Error in opening file.  Code did not run as intended. " << endl;
	}
	return 0;
}
