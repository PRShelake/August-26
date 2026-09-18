package com.operators;

public class Logical_Operator {

	public static void main(String[] args) {
		int a = 2;
		int b = 3;
		
		int x = 9;
		int y = 10;
		
		boolean z = true;
		
		boolean x1 = true;
		boolean x2 = false;
		
		System.out.println( a>b && x>y);
		System.out.println( a>b || x>y);
		
		System.out.println( !z);
		
		System.out.println( x1 && x2);
		System.out.println( x2 || x1);
		

	}

}
