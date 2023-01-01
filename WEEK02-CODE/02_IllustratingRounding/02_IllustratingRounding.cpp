// 002_DistanceBetweenPoints.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
class Point
{
public:
	double x1, y1, x2, y2;
private:
	double distance;
private:
	double jspRnd(double dblNoToRound, int digits) {
		double roundedVal = { 0.0f };
		roundedVal = round(dblNoToRound * pow(10, digits)) / pow(10, digits);
		return roundedVal;
	}
private:
	double distanceBetweenTwoPoints(double x, double y, double a, double b) {
		return pow((pow(x - a, 2) + pow(y - b, 2)),0.5);
	}
public:
	void setDistance() {
		distance = distanceBetweenTwoPoints(x1, y1, x2, y2);
	}
	double getDistance(int NoOfDigits) {
		return jspRnd(distance, NoOfDigits);
	}
};
int main()
{
	Point NewPoint;
	NewPoint.x1 = { 10.50 };
	NewPoint.y1 = { 12.50 };
	NewPoint.x2 = { 22.90 };
	NewPoint.y2 = { 17.650 };
	NewPoint.setDistance();
	// Calculator Answr is 13.4656
	int intNoOfPlaces = { 2 };

	cout << "The distance between the two points is " << NewPoint.getDistance(intNoOfPlaces + 5) <<endl;
	cout << std::setprecision(5) << "The distance between the two points is " << NewPoint.getDistance(intNoOfPlaces + 10) << endl;
	cout << std::fixed << std::setprecision(5) << "The distance between the two points is " << NewPoint.getDistance(intNoOfPlaces + 10) << endl;
	cout << std::setprecision(5) << "The distance between the two points is " << NewPoint.getDistance(intNoOfPlaces) << endl;
	return 0;
}
