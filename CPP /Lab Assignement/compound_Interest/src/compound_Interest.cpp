#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double P, R, T, Amount, CI;
	cout << "Enter Principle:";
	cin>>P;

	cout << "Enter Rate:";
	cin>>R;

	cout << "Enter Time:";
	cin>>T;

	Amount = P * pow((1+R/100), T);
	CI = Amount - P;

	cout << "Compound Interest: " << CI << endl;
	cout << " Total Amount: " << Amount << endl;

	return 0;
}
