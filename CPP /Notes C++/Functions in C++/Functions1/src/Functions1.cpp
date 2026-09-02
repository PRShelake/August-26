//============================================================================
// Name        : Functions1.cpp
// Author      : praveenkumar
// Version     :
// Copyright   : Your copyright notice
// Description : Function with retun type and with parameters
//             : if I replace inline 15 return c; -> return o; then output will be 0
//============================================================================

#include <iostream>
using namespace std;

int add(int a, int b){
	int c= a+b;
	return c;
}

int main() {
	int result = add(10,20);
	cout << result;
	return 0;
}
