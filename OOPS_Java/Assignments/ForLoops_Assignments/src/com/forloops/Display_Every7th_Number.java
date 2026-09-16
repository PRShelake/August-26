package com.forloops;

public class Display_Every7th_Number {

	public static void main(String[] args) {
		for (int i = 1; i <=200; i++ ) {
			System.out.print((i += 6) + " ");
		}

	}

}
