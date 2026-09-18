package com.conditional;

public class If_else_Statement  {

    static void isDivisibleByPrime(int n) {

        if (n % 11 == 0) {
            System.out.println("Eleven");
        }
        else if (n % 3 == 0) {
            System.out.println("Three");
        }
        else if (n % 2 == 0) {
            System.out.println("Two");
        }
        else {
            System.out.println("-1");
        }
    }

    public static void main(String[] args) {

        isDivisibleByPrime(44);

    }
}

