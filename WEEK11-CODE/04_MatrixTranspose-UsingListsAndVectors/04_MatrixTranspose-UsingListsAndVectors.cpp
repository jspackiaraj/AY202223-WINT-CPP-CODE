#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
	std::ifstream infile;
	bool boolDebugMode = false;
	bool boolNoDecoratorMode = true;
	bool boolNoErrorOpeningFileA = false;
	// Get the number of values
	int intLineCount{ 0 };
	int intNumRowsMatA{ 0 };
	int intNumColsMatA{ 0 };
	int intCntI{ 0 };
	int intCntJ{ 0 };
	string line{ "" };
	// Declaring Vectors
	list<list<double>> dblListA;
	list<double> dblInnerList;
	vector<vector<double>> dblVectB;
	string strFileNameMatA{ "matA.txt" };
	if (!boolNoDecoratorMode) {
		std::cout << "Enter the file with matrix A to open (with full path): ";
	}
	/*
	Uncomment the line below to enter a custom file name
	*/
	// cin >> strFileNameMatA;
	if (boolDebugMode) {
		std::cout << endl << strFileNameMatA << endl;
	}
	if (!boolNoDecoratorMode) {
		std::cout << "Printing out the Matrix Details: ";
	}
	infile.open(strFileNameMatA);
	if (infile.is_open())
	{
		if (boolDebugMode) {
			std::cout << endl << "File for Mat A is Opened for reading" << endl;
		}
		std::cout << "================" << endl;
		// Reset all counters
		intCntI = 0;
		intCntJ = 0;	// Initializing of the column counter is important before entering
						// the loop.  When a file is to be read as a matrix, counters 
						// should be carefully set.
		while (getline(infile, line)) {
			if (intCntJ == 0) {
				// Row data is encountered.  Reset the list storing the inner list
				list<double> dblInnerList;
			}
			if (intLineCount == 0) {
				intNumRowsMatA = stoi(line);
				if (boolDebugMode) {
					std::cout << "Number of Rows in Matrix A is : " << intNumRowsMatA << endl;
				}
			}
			if (intLineCount == 1) {
				intNumColsMatA = stoi(line);
				if (boolDebugMode) {
					std::cout << "Number of Cols in Matrix A is : " << intNumColsMatA << endl;
				}				
				intCntI = 0;
			}
			if (intLineCount > 1) {
				dblInnerList.push_back(stod(line));
				if (boolDebugMode) {
					cout << endl << stod(line) << "   ";
				}
				if (++intCntJ == intNumColsMatA) {
					intCntJ = 0;
					dblListA.push_back(dblInnerList);
					dblInnerList.clear();
					intCntI++;
					if (intCntI > intNumRowsMatA) {
						intCntI = 0;
					}
				}
			}
			intLineCount++;
		}
		infile.close();
		if (boolDebugMode) {
			// Print out the Array Values
			std::cout << endl << "File for Mat A is successfully stored in a List" << endl;
			std::cout << "================" << endl << endl;
			// Loop through the list and print the vals
			// itrI and itrJ will be of data type list<double>:: iterator
			intCntI = 0;
			intCntJ = 0;
			for (auto itrI = dblListA.begin(); itrI != dblListA.end(); itrI++) {
				list<double>& dblInnerList = *itrI;
				intCntI++;
				for (auto itrJ = dblInnerList.begin(); itrJ != dblInnerList.end(); itrJ++) {
					intCntJ++;
					std::cout << "A[" << intCntI << "][" << intCntJ << "] " << *itrJ << "\t";
				}
				std::cout << endl;
			}
			std::cout << "================" << endl;
		}
		boolNoErrorOpeningFileA = true;
	}
	else {
		std::cout << endl << "File for MAT A not opened.  Program will terminate." << endl;
		boolNoErrorOpeningFileA = false;
	}
	// Matrix Transposition is done here
	// The rows and columns of Matrix B should be the same as the columns
	// and rows of  Matrix A.  We will also check if the file has been read successfully.	
	if (boolNoErrorOpeningFileA) {
		// Initialize the vector
		vector<vector<double>> dblVectB(intNumColsMatA, vector<double> (intNumRowsMatA));
		std::cout << endl;
		// Reset Counters
		intCntI = 0;
		intCntJ = 0;
		if (boolDebugMode) {
			std::cout << "================" << endl << endl;
			cout << "Populating the vector from the List ..." << endl;
		}
		for (auto itrI = dblListA.begin(); itrI != dblListA.end(); itrI++) {
			list<double>& dblInnerList = *itrI;
			for (auto itrJ = dblInnerList.begin(); itrJ != dblInnerList.end(); itrJ++) {
				dblVectB[intCntJ][intCntI] = *itrJ;
				if (boolDebugMode) {
					cout << dblVectB[intCntJ][intCntI] << endl;
				}
				intCntJ++;
			}
			intCntI++;
			intCntJ = 0;
		}
		if (boolDebugMode) {
			std::cout << "================" << endl << endl;
			std::cout << "Loop through the transposed Array" << endl;
			std::cout << "================" << endl << endl;
		
			// Reset Counters
			intCntI = 0;
			intCntJ = 0;
			// Loop through the transposed array, and print the values
			for (intCntI = 0; intCntI < dblVectB.size(); intCntI++) {
				for (intCntJ = 0; intCntJ < intNumRowsMatA; intCntJ++) {
					cout << dblVectB[intCntI][intCntJ] << "\t";
				}
				std::cout << endl;
			}
		}
		// Loop through the array, add the values and print the values one per row, as required by the question
		std::cout << "================" << endl << endl;
		std::cout << "================" << endl << endl;
		std::cout << "Print the values one per row, as required by the question, with the Array size in the beginning" << endl;
		std::cout << "================" << endl;
		std::cout << intNumColsMatA << endl;
		std::cout << intNumColsMatA << endl;
		for (intCntI = 0; intCntI < dblVectB.size(); intCntI++) {
			for (intCntJ = 0; intCntJ < intNumRowsMatA; intCntJ++) {
				cout << dblVectB[intCntI][intCntJ] << endl;
			}
		}
		std::cout << endl << "End of Run .." << endl;
	}
	else {
		cout << endl << "Exiting as one of the files is having an error .." << endl;
	}
	return EXIT_SUCCESS;
}
