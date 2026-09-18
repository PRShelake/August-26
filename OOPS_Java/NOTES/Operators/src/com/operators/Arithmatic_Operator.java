package com.operators;

import java.util.Scanner;  // scanner package


public class Arithmatic_Operator 
{
	public static void main(String[]args) 
	{
		
		// type 1 
		int num3 = 3;
		int num4 = 5;
		
		System.out.println(num3+num4);
		System.out.println(num3-num4);
		System.out.println(num3*num4);
		System.out.println(num3/num4);
		System.out.println(num3%num4);
		
		
		// using user input;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number1:");
		int num1 = sc.nextInt();
	
		System.out.println("Enter the number2:");
		int num2 = sc.nextInt();		  
		  
		System.out.println(num1+num2);
		System.out.println(num1-num2);
		System.out.println(num1*num2);
		System.out.println(num1/num2);
		System.out.println(num1%num2);
		
   }
}
