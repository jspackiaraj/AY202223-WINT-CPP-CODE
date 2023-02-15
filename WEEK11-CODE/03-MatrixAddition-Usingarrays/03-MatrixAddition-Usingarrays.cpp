//
#pragma once

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	std::ifstream infile;
	bool boolDebugMode = false;
	bool boolNoDecoratorMode = true;
	bool boolNoErrorOpeningFileA = false;
	bool boolNoErrorOpeningFileB = false;
	// Get the number of values
	int intLineCount{ 0 };
	int intValidVals{ 0 };
	int intNumRowsMatA{ 0 };
	int intNumColsMatA{ 0 };
	int intNumRowsMatB{ 0 };
	int intNumColsMatB{ 0 };
	int intCntI{ 0 };
	int intCntJ{ 0 };
	int intCntK{ 0 };
	// Declaring Arrays for dynamic array using pointers
	double** dblMatA;
	double** dblMatB;
	double** dblMatC;
	string line{ "" };
	string strFileNameMatA{ "matA.txt" };
	string strFileNameMatB{ "matB.txt" };

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
		std::cout << "Enter the file with matrix B to open (with full path): ";
	}
	/*
	Uncomment the line below to enter a custom file name
	*/
	// cin >> strFileNameMatB;
	if (boolDebugMode) {
		std::cout << endl << strFileNameMatB << endl;
	}

	infile.open(strFileNameMatA);
	if (infile.is_open())
	{
		if (boolDebugMode) {
			std::cout << endl << "File for Mat A is Opened for reading" << endl;
		}
		std::cout << "================" << endl;
		while (getline(infile, line)) {
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
				// Initialise a block in memory for the array
				dblMatA = new double*[intNumRowsMatA];
				for (intCntI = 0; intCntI < intNumRowsMatA; intCntI++) {
					dblMatA[intCntI] = new double[intNumColsMatA];
				}
				intCntI = 0;
			}
			if (intLineCount > 1) {
				dblMatA[intCntI][intCntJ] = stod(line);
				if (boolDebugMode) {
					cout << endl << stod(line) << "   " << dblMatA[intCntI][intCntJ];
				}
				if (++intCntJ == intNumColsMatA) {
					intCntJ = 0;
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
			std::cout << endl << "File for Mat A is successfully stored in an Array" << endl;
			std::cout << "================" << endl << endl;
			// Loop through the array and print the vals
			for (intCntI = 0; intCntI < intNumRowsMatA; intCntI++) {
				for (intCntJ = 0; intCntJ < intNumColsMatA; intCntJ++) {
					std::cout << "A[" << intCntI << "][" << intCntJ <<"] " << dblMatA[intCntI][intCntJ] << "\t";
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
	// There is no need to traverse Matrix 2, if Matrix 1 has an error
	infile.open(strFileNameMatB);
	if (infile.is_open() and boolNoErrorOpeningFileA)
	{
		// boolNoErrorOpeningFile = true;
		if (boolDebugMode) {
			std::cout << endl << "File for Mat B is Opened for reading" << endl;
		}
		std::cout << "================" << endl;
		intLineCount = 0;
		while (getline(infile, line)) {
			if (intLineCount == 0) {
				intNumRowsMatB = stoi(line);
				if (boolDebugMode) {
					std::cout << "Number of Rows in Matrix B is : " << intNumRowsMatB << endl;
				}
			}
			if (intLineCount == 1) {
				intNumColsMatB = stoi(line);
				if (boolDebugMode) {
					std::cout << "Number of Cols in Matrix B is : " << intNumColsMatB << endl;
				}
				// Initialise a block in memory for the array
				dblMatB = new double* [intNumRowsMatB];
				for (intCntI = 0; intCntI < intNumRowsMatB; intCntI++) {
					dblMatB[intCntI] = new double[intNumColsMatB];
				}
				intCntI = 0;
				intCntJ = 0;
			}
			if (intLineCount > 1) {
				dblMatB[intCntI][intCntJ] = stod(line);
				if (boolDebugMode) {
					cout << endl << stod(line) << "   " << dblMatB[intCntI][intCntJ];
				}
				if (++intCntJ == intNumColsMatB) {
					intCntJ = 0;
					intCntI++;
					if (intCntI > intNumRowsMatB) {
						intCntI = 0;
					}
				}
			}
			intLineCount++;
		}
		infile.close();
		if (boolDebugMode) {
			// Print out the Array Values
			std::cout << endl << "File for Mat B is successfully stored in an Array" << endl;
			std::cout << "================" << endl << endl;
			// Loop through the array and print the vals
			for (intCntI = 0; intCntI < intNumRowsMatB; intCntI++) {
				for (intCntJ = 0; intCntJ < intNumColsMatB; intCntJ++) {	
					std::cout << "B[" << intCntI << "][" << intCntJ << "] " << dblMatB[intCntI][intCntJ] << "\t";
				}
				std::cout << endl;
			}
			std::cout << "================" << endl;
		}
		boolNoErrorOpeningFileB = true;
	}
	else {
		std::cout << endl << "File for MAT B not opened.  Program will terminate." << endl;
		boolNoErrorOpeningFileB = false;
	}
	// Matrix Addition is done here
	// The rows and columns of Matrix A and Matrix B should be the same for addition to be 
	// possible.  We will also check if both the files have been read successfully.
	if (boolNoErrorOpeningFileA and boolNoErrorOpeningFileB) {
		if (intNumRowsMatA == intNumRowsMatB and intNumColsMatA == intNumColsMatB) {
			//Matrix Addition is possible
			// Initialize Matrix C
			// Initialise a block in memory for the array
			dblMatC = new double* [intNumRowsMatA];
			for (intCntI = 0; intCntI < intNumRowsMatA; intCntI++) {
				dblMatC[intCntI] = new double[intNumColsMatA];
			}
			intCntI = 0;
			intCntJ = 0;
			// Loop through the array, add the values and print the values
			for (intCntI = 0; intCntI < intNumRowsMatA; intCntI++) {
				for (intCntJ = 0; intCntJ < intNumColsMatA; intCntJ++) {
					dblMatC[intCntI][intCntJ] = dblMatA[intCntI][intCntJ] + dblMatB[intCntI][intCntJ];
					std::cout << "C[" << intCntI << "][" << intCntJ << "] " << dblMatC[intCntI][intCntJ] << "\t";
				}
				std::cout << endl;
			}
			// Loop through the array, add the values and print the values one per row
			std::cout << "================" << endl << endl;
			for (intCntI = 0; intCntI < intNumRowsMatA; intCntI++) {
				for (intCntJ = 0; intCntJ < intNumColsMatA; intCntJ++) {
					dblMatC[intCntI][intCntJ] = dblMatA[intCntI][intCntJ] + dblMatB[intCntI][intCntJ];
					std::cout << "C[" << intCntI << "][" << intCntJ << "] " << dblMatC[intCntI][intCntJ] << endl;
				}
			}
			std::cout << endl << "End of Run .." << endl;
		}
		else {
			cout << endl << "Matrix Addition is NOT possible as rows and column numbers are not matching" << endl;
		}
	}
	else {
		cout << endl << "Exiting as one of the files is having an error .." << endl;
	}
	// Garbage Collection
	// Delete the arrays created
	// This frees back the resources back to the Operating System
	for (intCntI = 0; intCntI < intNumRowsMatA; intCntI++) {
		delete[] dblMatA[intCntI];
		delete[] dblMatB[intCntI];
		delete[] dblMatC[intCntI];
	}
	return EXIT_SUCCESS;
}
