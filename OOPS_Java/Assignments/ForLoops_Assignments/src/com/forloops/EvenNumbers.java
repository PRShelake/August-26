package com.forloops;

public class EvenNumbers {

	public static void main(String[] args) {
		for(int even=1; even<500; even++) {
			System.out.print((even += 1) + " ");
		}

	}

}
