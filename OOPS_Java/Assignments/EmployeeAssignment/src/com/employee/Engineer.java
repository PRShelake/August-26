package com.employee;

public class Engineer extends Employee {

    private String technology;

    public Engineer(String name, double salary, String technology) {
        super(name, salary);
        this.technology = technology;
    }

    public String getTechnology() {
        return technology;
    }

    @Override
    public String getEmployeeType() {
        return "Engineer";
    }

    @Override
    public String toString() {
        return super.toString()
                + ", Technology: " + technology;
    }
}