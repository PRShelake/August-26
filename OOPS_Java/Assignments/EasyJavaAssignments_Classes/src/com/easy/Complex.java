package com.easy;

import java.util.Scanner;

class Complex {

    int real;
    int imaginary;

    // Constructor
    Complex(int real, int imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    // Sum
    Complex sum(Complex c) {
        return new Complex(
            real + c.real,
            imaginary + c.imaginary
        );
    }

    // Difference
    Complex difference(Complex c) {
        return new Complex(
            real - c.real,
            imaginary - c.imaginary
        );
    }

    // Product
    Complex product(Complex c) {
        int r = (real * c.real) - (imaginary * c.imaginary);
        int i = (real * c.imaginary) + (imaginary * c.real);

        return new Complex(r, i);
    }

    // Display
    void display() {
        System.out.println(real + " + " + imaginary + "i");
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // First complex number
        System.out.print("Enter real part of first number: ");
        int r1 = sc.nextInt();

        System.out.print("Enter imaginary part of first number: ");
        int i1 = sc.nextInt();

        // Second complex number
        System.out.print("Enter real part of second number: ");
        int r2 = sc.nextInt();

        System.out.print("Enter imaginary part of second number: ");
        int i2 = sc.nextInt();

        Complex c1 = new Complex(r1, i1);
        Complex c2 = new Complex(r2, i2);

        Complex s = c1.sum(c2);
        Complex d = c1.difference(c2);
        Complex p = c1.product(c2);

        System.out.print("Sum = ");
        s.display();

        System.out.print("Difference = ");
        d.display();

        System.out.print("Product = ");
        p.display();
    }
}