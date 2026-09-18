package com.employee;

import java.io.Serializable;

public abstract class Employee implements Serializable {

    private String name;
    private double salary;

    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    public abstract String getEmployeeType();

    @Override
    public String toString() {
        return "Type: " + getEmployeeType()
                + ", Name: " + name
                + ", Salary: " + salary;
    }
}