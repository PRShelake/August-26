package com.string;
import java.util.Scanner;


public class Program1 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String str = sc.nextLine();

        System.out.print("Enter the index: ");
        int index = sc.nextInt();

        System.out.println("Original String = " + str);
        System.out.println("The character at position " + index + " is " 
                           + str.charAt(index));

        sc.close();
    }
}