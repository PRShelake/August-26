package com.conditional;
import java.util.Scanner;

public class User_input_Nested_if {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the age :");
		int age = sc.nextInt();
		
		System.out.println("Is has Voter id(True/False) :");
		Boolean ID = sc.nextBoolean();
		
		if (age>=18) {
			if(ID) {
				System.out.println("He is Elegible for Votting");
			}
		}
		

	}

}
