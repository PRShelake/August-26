#include <iostream>
using namespace std;

int main() {

	int a,b,x;
	cout << "enter the value of two number :"<< endl;
	cin>>a>>b;

	cout << "Before swaping the value of a:"<< a <<" b:" <<b <<endl;

	x=a;
	a=b;
	b=x;
	cout << "Bfter swaping the value of a:"<< a <<" b:" <<b <<endl;

	return 0;
}
