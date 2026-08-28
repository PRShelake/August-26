//============================================================================
// Name        : elseif.cpp
// Author      : praveenkumar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	//int marks = 40;
	int marks;
	cout << "Enter your marks : ";
	cin >> marks ;


	if(marks >= 85){//-->less than && greaterthan
		cout << "First Class with Distiction";
	}

    else if (marks >= 75){
    	cout << "First Class" ;
    }

    else if (marks >= 65 ){
    		cout << "Second Class";
    }

    else if (marks >= 50 ){
    		cout << "Third Class";
    }


    else{
    	cout << "fail";
    }
	return 0;
}
