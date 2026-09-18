package com.easy;

import java.util.Scanner;

class Employeer {

    double salary;
    int hours;

    // getInfo()
    void getInfo(double salary, int hours) {
        this.salary = salary;
        this.hours = hours;
    }

    // Add $10 if salary is less than $500
    void addSal() {
        if (salary < 500) {
            salary = salary + 10;
        }
    }

    // Add $5 if working hours are more than 6
    void addWork() {
        if (hours > 6) {
            salary = salary + 5;
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter salary: ");
        double salary = sc.nextDouble();

        System.out.print("Enter working hours per day: ");
        int hours = sc.nextInt();

        Employeer e = new Employeer();

        e.getInfo(salary, hours);
        e.addSal();
        e.addWork();

        System.out.println("Final Salary = $" + e.salary);
    }
}