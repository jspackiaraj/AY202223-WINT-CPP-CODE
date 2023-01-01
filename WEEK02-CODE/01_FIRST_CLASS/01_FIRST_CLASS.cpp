#include <iostream>
#include <string>
using namespace std;
class Human
{
public:
	string name;
	int age;

void IntroduceSelf()
{
    cout << "Hi, My Name is " + name << " and am ";
    cout << age << " years old" << endl;
}
};

int main()
{
	// An object of class Human with attribute name as "John Doe"
	Human firstMan;

	firstMan.name = {"John Doe"};
	firstMan.age = {30};

	// An object of class Human with attribute name as "Jane Doe"
	Human firstWoman;
	firstWoman.name = {"Jane Doe"};
	firstWoman.age = {28};

	firstMan.IntroduceSelf();
	firstWoman.IntroduceSelf();
	return 0;
}
