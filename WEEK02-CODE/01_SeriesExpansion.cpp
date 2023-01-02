// 03_SeriesExpansion.cpp :
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;
class SeriesExpansionSinX {
private:
	double x{ 0.0 }; // The value for which a series solution is to be found
	double tmpSinX{ 0.0 };
	int cntI{ 0 };
	int NoOfDigits{ 10 };
	stringstream strOutputTxt{ "" };
	stringstream strOutputTxt2{ "" };
private:
	double jspRnd(double dblNoToRound, int digits) {
		double roundedVal = { 0.0f };
		roundedVal = round(dblNoToRound * pow(10, digits)) / pow(10, digits);
		return roundedVal;
	}
private:
	long double factorial(long double factN) {
		if (factN == 0) {
			return 1;
		}
		else{
			return factN * factorial(factN - 1);
		}
	}
private:
	void sinx() {
		double sinXCalc{ 0.0 }, diff{ 0.0 };
		do {
			sinXCalc = jspRnd(tmpSinX + pow(-1, cntI) * (pow(x, 2 * cntI + 1) / factorial(2 * cntI + 1)), NoOfDigits);
			cntI++;
			diff = jspRnd(sinXCalc - tmpSinX, NoOfDigits);
			tmpSinX = sinXCalc;
			strOutputTxt << std::fixed << setprecision(NoOfDigits) << "Iteration Number : " << cntI << " The Difference is : " << diff << " Value of Sin " << x << " is : " << tmpSinX<< endl;
			strOutputTxt2 << std::fixed << setprecision(NoOfDigits) << "Iteration Number : " << cntI << " The Difference is : " << std::setw(NoOfDigits + 5) << diff << " Value of Sin " << std::setw(NoOfDigits + 5) << x << " is : " << std::setw(NoOfDigits + 5) << tmpSinX << endl;
		} while (diff != 0.0 && cntI < 160);
	}
public:
	void set_xVal(double dblX) {
		x = jspRnd(dblX, NoOfDigits);
	}
	void set_xDegVal(double dblx) {
		const double pi{ 3.14159265358979323846 };
		const double Deg180{ 180.0 };
		x = jspRnd(jspRnd(dblx, NoOfDigits) * jspRnd(pi, NoOfDigits) / Deg180, NoOfDigits);
	}
	void setNoOfDigits(int intDigits) {
		NoOfDigits = intDigits;
	}
	double getSinx() {
		sinx();
		return tmpSinX;
	}
	void getOutputTxt() {
		cout << strOutputTxt.str();
	}
	void getOutputTxt2() {
		cout << strOutputTxt2.str();
	}
};

int main()
{
	SeriesExpansionSinX sinX1;
		double dblX{ 1.570796 };
		//std::cin >> dblX;
		sinX1.set_xVal(dblX);
		std::cout << "The value of Sin " << dblX << " radians is " << sinX1.getSinx() << endl;
		sinX1.getOutputTxt();
	SeriesExpansionSinX sinX2;
		dblX = { 1.570796 };
		//std::cin >> dblX;
		sinX2.set_xVal(dblX);
		sinX2.setNoOfDigits(3);
		std::cout << endl << endl;
		std::cout << "The value of Sin " << dblX << " radians is " << sinX2.getSinx() << endl;
		sinX2.getOutputTxt();
	SeriesExpansionSinX sinX3;
		dblX = { 90 };
		//std::cin >> dblX;
		sinX3.set_xDegVal(dblX);
		sinX3.setNoOfDigits(3);
		std::cout << endl << endl;
		std::cout << "The value of Sin " << dblX << " degrees is " << sinX3.getSinx() << endl;
		sinX3.getOutputTxt2();
	return 0;
}
