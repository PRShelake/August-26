package com.employee;

public class EmployeeNode {

    Employee employee;

    EmployeeNode previous;
    EmployeeNode next;

    public EmployeeNode(Employee employee) {
        this.employee = employee;
    }
}