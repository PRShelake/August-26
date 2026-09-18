package com.string;

public class Reverse_String {

	public static void main(String[] args) {

		        String str = "CDAC KHARGHAR";
		        String reverse = "";

		        for (int i = str.length() - 1; i >= 0; i--) {
		            reverse = reverse + str.charAt(i);
		        }

		        System.out.println("The given string is: " + str);
		        System.out.println("The string in reverse order is:" + reverse);
		    }

	}

