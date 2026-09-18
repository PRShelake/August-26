package com.easy;

class Employee {

    String name;
    int yearOfJoining;
    double salary;
    String address;

    // Constructor
    Employee(String name, int yearOfJoining, double salary, String address) {
        this.name = name;
        this.yearOfJoining = yearOfJoining;
        this.salary = salary;
        this.address = address;
    }

    void display() {
        System.out.println(name + "\t" + yearOfJoining + "\t " + salary + "\t" + address);
    }

    public static void main(String[] args) {

        Employee e1 = new Employee(
            "Robert",   1994,   50000,   "64C-WallsStreat"
        );

        Employee e2 = new Employee(
            "Sam", 2000, 60000, "68D-Walls Streat"
        );

        Employee e3 = new Employee(
            "John", 1999, 55000, "26B-WallsStreat"
        );

        System.out.println("Name   \tYearOfJoining     \tSalary\tAddress");

        e1.display();
        e2.display();
        e3.display();
    }
}