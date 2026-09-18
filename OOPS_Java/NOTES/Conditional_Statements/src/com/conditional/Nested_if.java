package com.conditional;

public class Nested_if {

	public static void main(String[] args) {
		
		int age = 21;
		boolean hasVoterID = true;
		
		if(age>=18) { 
			if(hasVoterID) {
				System.out.println("You are eligible");
			}
		}
  
	}

}
