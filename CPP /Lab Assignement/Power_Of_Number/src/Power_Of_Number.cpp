#include <iostream>
#include <cmath>
using namespace std;

int main() {

	double base, exponent, result ;
	cout << "Enter the value1:";
	cin >> base;
	cout << "Enter the value2 :";
	cin >> exponent;

	result = pow(base, exponent);
	cout<<"The power of the given number is:" << result << endl;
	return 0;
}
