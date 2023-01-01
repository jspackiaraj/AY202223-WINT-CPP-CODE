#include <iostream>
using namespace std;

class Human
{
public:
string name;

private:
// Private member data:
int age;

public:
void SetAge(int inputAge)
{
age = inputAge;
}

// Human lies about his / her age (if over 30)
int GetAge()
{
if (age > 30)
return (age - 2);
else
return age;
}
void IntroduceSelf()
{
    cout << "Hi, My Name is " + name << endl;
}
};

int main()
{
// An object of class Human with attribute name as "John Doe"
Human firstMan;

firstMan.name = {"John Doe"};
firstMan.SetAge(32);

// An object of class Human with attribute name as "Jane Doe"
Human firstWoman;
firstWoman.name = {"Jane Doe"};
firstWoman.SetAge(28);

firstMan.IntroduceSelf();
cout << "Age of firstMan " << firstMan.GetAge() << endl;
firstWoman.IntroduceSelf();
cout << "Age of firstWoman " << firstWoman.GetAge() << endl;
return 0;
}
