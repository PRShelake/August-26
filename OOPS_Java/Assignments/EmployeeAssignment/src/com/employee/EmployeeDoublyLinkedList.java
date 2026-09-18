package com.employee;

import java.util.ArrayList;
import java.util.List;

public class EmployeeDoublyLinkedList {

    private EmployeeNode head;
    private EmployeeNode tail;

    // Used for next/previous navigation
    private EmployeeNode current;

    // Add employee
    public void add(Employee employee) {

        EmployeeNode newNode = new EmployeeNode(employee);

        if (head == null) {

            head = newNode;
            tail = newNode;
            current = newNode;

        } else {

            tail.next = newNode;
            newNode.previous = tail;
            tail = newNode;
        }
    }

    // First employee
    public Employee first() {

        if (head == null) {
            return null;
        }

        current = head;

        return current.employee;
    }

    // Next employee
    public Employee next() {

        if (current == null) {
            return first();
        }

        if (current.next == null) {
            return null;
        }

        current = current.next;

        return current.employee;
    }

    // Previous employee
    public Employee previous() {

        if (current == null) {
            return last();
        }

        if (current.previous == null) {
            return null;
        }

        current = current.previous;

        return current.employee;
    }

    // Last employee
    public Employee last() {

        if (tail == null) {
            return null;
        }

        current = tail;

        return current.employee;
    }

    // Get all employees
    public List<Employee> getAll() {

        List<Employee> list = new ArrayList<>();

        EmployeeNode temp = head;

        while (temp != null) {

            list.add(temp.employee);

            temp = temp.next;
        }

        return list;
    }

    // Get employees based on type
    public List<Employee> getByType(Class<?> type) {

        List<Employee> list = new ArrayList<>();

        EmployeeNode temp = head;

        while (temp != null) {

            if (type.isInstance(temp.employee)) {

                list.add(temp.employee);
            }

            temp = temp.next;
        }

        return list;
    }

    // Clear list
    public void clear() {

        head = null;
        tail = null;
        current = null;
    }
}