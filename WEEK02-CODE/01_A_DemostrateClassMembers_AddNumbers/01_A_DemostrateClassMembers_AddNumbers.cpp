#pragma once
#include <iostream>
using namespace std;

class AddTwoNumbers
{
private:
    double dblA;
    double dblB;
    double dblC;
public:
    // Constructor to set values of dblA and dblB
    AddTwoNumbers(double a, double b)
    {
        dblA = a;
        dblB = b;
    }

    // Method to add dblA and dblB and store the result in dblC
    void Sum()
    {
        dblC = dblA + dblB;
    }

    // Method to return the result of the addition
    double getSoln()
    {
        return dblC;
    }
};

int main()
{
    double a, b;
    cout << "Enter two numbers to be added: ";
    //Watch this construct below to get two numbers
    cin >> a >> b;
    // You can use white space or an enter key to get the two numbers
    // Create an object of the class and pass the two numbers as arguments to the constructor
    AddTwoNumbers numbers(a, b);
    // Call the exposed method to add the numbers
    numbers.Sum();

    cout << "The sum of the numbers is: " << numbers.getSoln() << endl;
    // The following line demonstrates the order in which the data has been pushed into the variables.
    cout << "The first number is " << a;

    return 0;
}
