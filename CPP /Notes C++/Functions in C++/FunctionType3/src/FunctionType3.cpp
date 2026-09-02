//============================================================================
// Name        : FunctionType3.cpp
// Author      : praveenkumar
// Version     :
// Copyright   : Your copyright notice
// Description : Function with return type and without parameters:
//============================================================================

#include <iostream>
using namespace std;

//Declaration Function with return type and without parameters:
int add(){
	return 100; // if replace 100 to 0 then output will be 0;
}

int main() {
	int val = add(); // call the function & store in val variable in integer data type

	cout << val << endl; // prints the value
	return 0;
}
