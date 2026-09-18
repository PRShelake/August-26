package com.easy;

import java.util.Scanner;

class Triangle {

    int side1;
    int side2;
    int side3;

    // Constructor
    Triangle(int side1, int side2, int side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter side 1: ");
        int a = sc.nextInt();

        System.out.print("Enter side 2: ");
        int b = sc.nextInt();

        System.out.print("Enter side 3: ");
        int c = sc.nextInt();

        // Creating object
        Triangle t = new Triangle(a, b, c);

        // Perimeter
        int perimeter = t.side1 + t.side2 + t.side3;

        // Area using Heron's formula
        double s = perimeter / 2.0;

        double area = Math.sqrt(
            s * (s - t.side1) *
            (s - t.side2) *
            (s - t.side3)
        );

        System.out.println("Area of triangle = " + area);
        System.out.println("Perimeter of triangle = " + perimeter);

        sc.close();
    }
}