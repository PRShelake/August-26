package com.employee;

public class SalesPerson extends Employee {

    private String salesArea;

    public SalesPerson(String name, double salary, String salesArea) {
        super(name, salary);
        this.salesArea = salesArea;
    }

    public String getSalesArea() {
        return salesArea;
    }

    @Override
    public String getEmployeeType() {
        return "Sales Person";
    }

    @Override
    public String toString() {
        return super.toString()
                + ", Sales Area: " + salesArea;
    }
}