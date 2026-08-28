//============================================================================
// Name        : largest_of_three_number.cpp
// Author      : praveenkumar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int a = 3 ;
	int b = 4 ;
	int c = 8 ;

	if( a >= b ){
		if( a >= c )
			    cout << a;
			else
				cout<< c;
		}

   else {
	   if( b >= c)
			cout << b ;
		else
			cout << c ;
			}

	return 0;
}
