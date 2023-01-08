// C++ program to demonstrate read/write of class
#include <iostream>
#include <fstream>
using namespace std;

// Class to define the properties
// The following is the template
// of the class.
class GameStat {
public:
	// Instance variables
	std::string strName;
	int Age{ 0 }, Score{ 0 };

	// Function declaration of input() to input info
	int input();

	// Function declaration of output_highest_scorer() to
	// extract info from file Data Base
	int output_highest_scorer();
};

// Function definition of input() to input info
// input belongs to the class GameStat. Note the 
// way it is defined
int GameStat::input()
{
	// Object to write in file
	ofstream outfile;

	// Opening file in append mode
	outfile.open("Stats.txt", ios::app);

	// Object of class GameStat to input data in file
	GameStat obj;

	// Feeding appropriate data in variables
	std::string strName = { "Jane Doe" };
	int age { 18 }, score { 7500 };
	int intIteration{ 0 };

	// Assigning data into object
	obj.strName = strName;
	obj.Age = age;
	obj.Score = score;

	// Writing the object's data in file
	outfile.write((char*)&obj, sizeof(obj));
	std::cout << "The data point " << ++intIteration << " done .. " << endl;

	// Feeding appropriate data in variables
	strName = { "John Doe" };
	age = { 21 };
	score = { 6500 };

	// Assigning data into object
	obj.strName = strName;
	obj.Age = age;
	obj.Score = score;

	// Writing the object's data in file
	outfile.write((char*)&obj, sizeof(obj));
	std::cout << "The data point " << ++intIteration << " done .. " << endl;

	// Feeding appropriate data in variables
	strName = { "John Doe2" };
	age = { 21 };
	score = { 8000 };

	// Assigning data into object
	obj.strName = strName;
	obj.Age = age;
	obj.Score = score;

	// Writing the object's data in file
	outfile.write((char*)&obj, sizeof(obj));
	std::cout << "The data point " << ++intIteration << " done .. " << endl;


	return 0;
}

// Function definition of output_highest_scorer() to
// extract info from the file
int GameStat::output_highest_scorer()
{
	std::cout << "Preparing to read the data from file ..." << endl;
	// Object to read from file
	ifstream outfile;

	// Opening file in input mode
	//
	outfile.open("Stats.txt", ios::in);

	std::cout << "File successfully opened ..." << endl;
	// Object of class GameStat to input data in file
	GameStat obj;
	// max to store maximum ratings
	int max = { 0 };
	// Highest_rated stores the name of highest rated GameStat
	string Highest_scorer{ "" };
	std::cout << "Variables successfully declared ..." << endl;

	// Reading from file into object "obj"
	outfile.read((char*)&obj, sizeof(obj));
	std::cout << "Processing the individual achievements" << endl;
	// Checking till we have the feed
	while (!outfile.eof()) {
		// Assigning max ratings
		std::cout << "\tProcessing the record of : " << obj.strName << endl;
		if (obj.Score > max) {
			max = obj.Score;
			Highest_scorer = obj.strName;
		}

		// Checking further
		outfile.read((char*)&obj, sizeof(obj));
	}

	std::cout << "---------------------------------" << endl;

	// Output is the highest rated GameStat
	std::cout << "The Highest Scorere on records is " << Highest_scorer;
	return 0;
}

// Driver code
int main()
{
	GameStat object;
	// Inputting the data
	std::cout << "---------------------------------" << endl;
	std::cout << "Creating the file and entering data" << endl;
	object.input();
	std::cout << "---------------------------------" << endl;
	std::cout << "Reading from the file created" << endl;
 	// Extracting the best scorer
	object.output_highest_scorer();
	std::cout << "---------------------------------" << endl;
	std::cout << "Program successfully run" << endl;
	return 0;
}
