// C++ program to demonstrate read/write of class
// objects in C++.
#include <iostream>
#include <fstream>
using namespace std;

// Class to define the properties
class GameStat {
public:
	// Instance variables
	string strName;
	int Age{ 0 }, Score{ 0 };

	// Function declaration of input() to input info
	int input();

	// Function declaration of output_highest_score() to
	// extract info from file Data Base
	int output_highest_score();
};

// Function definition of input() to input info
int GameStat::input()
{
	// Object to write in file
	ofstream outfile;

	// Opening file in append mode
	outfile.open("Stats.txt", ios::app);

	// Object of class GameStat to input data in file
	GameStat obj;

	// Feeding appropriate data in variables
	string strName = { "Jane Doe" };
	int age = { 18 }, score = { 7500 };

	// Assigning data into object
	obj.strName = strName;
	obj.Age = age;
	obj.Score = score;

	// Writing the object's data in file
	outfile.write((char*)&obj, sizeof(obj));

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

	return 0;
}

// Function definition of output_highest_score() to
// extract info from file Data Base
int GameStat::output_highest_score()
{
	// Object to read from file
	ifstream outfile;

	// Opening file in input mode
	//
	outfile.open("Stats.txt", ios::in);

	// Object of class GameStat to input data in file
	GameStat obj;

	// Reading from file into object "obj"
	outfile.read((char*)&obj, sizeof(obj));

	// max to store maximum ratings
	int max = { 0 };

	// Highest_rated stores the name of highest rated GameStat
	string Highest_score{ "" };

	// Checking till we have the feed
	while (!outfile.eof()) {
		// Assigning max ratings
		if (obj.Score > max) {
			max = obj.Score;
			Highest_score = obj.strName;
		}

		// Checking further
		outfile.read((char*)&obj, sizeof(obj));
	}

	// Output is the highest rated GameStat
	cout << Highest_score;
	return 0;
}

// Driver code
int main()
{
	// Creating object of the class
	GameStat object;

	// Inputting the data
	object.input();

	// Extracting the max rated GameStat
	object.output_highest_score();
	return 0;
}
