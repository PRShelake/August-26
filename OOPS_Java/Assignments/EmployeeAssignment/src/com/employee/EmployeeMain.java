package com.employee;

import java.io.*;
import java.util.*;

public class EmployeeMain {

    static Scanner sc = new Scanner(System.in);

    static EmployeeDoublyLinkedList list =
            new EmployeeDoublyLinkedList();

    static final String FILE_NAME = "employees.dat";
1

    public static void main(String[] args) {

        while (true) {

            System.out.println("\n==============================");
            System.out.println(" EMPLOYEE MANAGEMENT SYSTEM");
            System.out.println("==============================");

            System.out.println("1. Add an Employee");
            System.out.println("2. Display");
            System.out.println("3. Sort");
            System.out.println("4. Save to File");
            System.out.println("5. Load from File");
            System.out.println("6. Exit");

            System.out.print("Enter your choice: ");

            int choice = Integer.parseInt(sc.nextLine());

            switch (choice) {

                case 1:
                    addEmployeeMenu();
                    break;

                case 2:
                    displayMenu();
                    break;

                case 3:
                    sortMenu();
                    break;

                case 4:
                    saveToFile();
                    break;

                case 5:
                    loadFromFile();
                    break;

                case 6:
                    System.out.println("Program exited.");
                    return;

                default:
                    System.out.println("Invalid choice.");
            }
        }
    }


    // =========================================
    // 1. ADD EMPLOYEE MENU
    // =========================================

    static void addEmployeeMenu() {

        while (true) {

            System.out.println("\n------ ADD EMPLOYEE ------");

            System.out.println("a. Manager");
            System.out.println("b. Engineer");
            System.out.println("c. Sales Person");
            System.out.println("d. Exit to Main Menu");

            System.out.print("Enter choice: ");

            String choice = sc.nextLine();

            switch (choice.toLowerCase()) {

                case "a":
                    addManager();
                    break;

                case "b":
                    addEngineer();
                    break;

                case "c":
                    addSalesPerson();
                    break;

                case "d":
                    return;

                default:
                    System.out.println("Invalid choice.");
            }
        }
    }


    // Add Manager

    static void addManager() {

        System.out.print("Enter Manager name: ");
        String name = sc.nextLine();

        System.out.print("Enter salary: ");
        double salary = Double.parseDouble(sc.nextLine());

        System.out.print("Enter department: ");
        String department = sc.nextLine();

        Manager manager =
                new Manager(name, salary, department);

        list.add(manager);

        System.out.println("Manager added successfully.");
    }


    // Add Engineer

    static void addEngineer() {

        System.out.print("Enter Engineer name: ");
        String name = sc.nextLine();

        System.out.print("Enter salary: ");
        double salary = Double.parseDouble(sc.nextLine());

        System.out.print("Enter technology: ");
        String technology = sc.nextLine();

        Engineer engineer =
                new Engineer(name, salary, technology);

        list.add(engineer);

        System.out.println("Engineer added successfully.");
    }


    // Add Sales Person

    static void addSalesPerson() {

        System.out.print("Enter Sales Person name: ");
        String name = sc.nextLine();

        System.out.print("Enter salary: ");
        double salary = Double.parseDouble(sc.nextLine());

        System.out.print("Enter sales area: ");
        String area = sc.nextLine();

        SalesPerson salesPerson =
                new SalesPerson(name, salary, area);

        list.add(salesPerson);

        System.out.println("Sales Person added successfully.");
    }


    // =========================================
    // 2. DISPLAY MENU
    // =========================================

    static void displayMenu() {

        while (true) {

            System.out.println("\n------ DISPLAY ------");

            System.out.println("a. All Employees");
            System.out.println("b. First Employee");
            System.out.println("c. Next Employee");
            System.out.println("d. Previous Employee");
            System.out.println("e. Last Employee");
            System.out.println("f. Exit to Main Menu");

            System.out.print("Enter choice: ");

            String choice = sc.nextLine();

            switch (choice.toLowerCase()) {

                case "a":
                    displayAll();
                    break;

                case "b":
                    displayOne(list.first());
                    break;

                case "c":
                    displayOne(list.next());
                    break;

                case "d":
                    displayOne(list.previous());
                    break;

                case "e":
                    displayOne(list.last());
                    break;

                case "f":
                    return;

                default:
                    System.out.println("Invalid choice.");
            }
        }
    }


    // Display all

    static void displayAll() {

        List<Employee> employees = list.getAll();

        if (employees.isEmpty()) {

            System.out.println("No employees available.");

            return;
        }

        System.out.println("\n------ ALL EMPLOYEES ------");

        for (Employee employee : employees) {

            System.out.println(employee);
        }
    }


    // Display one employee

    static void displayOne(Employee employee) {

        if (employee == null) {

            System.out.println("Employee not available.");

        } else {

            System.out.println(employee);
        }
    }


    // =========================================
    // 3. SORT MENU
    // =========================================

    static void sortMenu() {

        while (true) {

            System.out.println("\n------ SORT ------");

            System.out.println("a. All Managers");
            System.out.println("b. All Engineers");
            System.out.println("c. All Sales Person");
            System.out.println("d. All Employees Alphabetic order ascending");
            System.out.println("e. All Employees Alphabetic order descending");
            System.out.println("f. Exit to Main Menu");

            System.out.print("Enter choice: ");

            String choice = sc.nextLine();

            switch (choice.toLowerCase()) {

                case "a":
                    displayList(
                        list.getByType(Manager.class)
                    );
                    break;

                case "b":
                    displayList(
                        list.getByType(Engineer.class)
                    );
                    break;

                case "c":
                    displayList(
                        list.getByType(SalesPerson.class)
                    );
                    break;

                case "d":
                    sortAscending();
                    break;

                case "e":
                    sortDescending();
                    break;

                case "f":
                    return;

                default:
                    System.out.println("Invalid choice.");
            }
        }
    }


    // Display selected list

    static void displayList(List<Employee> employees) {

        if (employees.isEmpty()) {

            System.out.println("No employees found.");

            return;
        }

        for (Employee employee : employees) {

            System.out.println(employee);
        }
    }


    // Alphabetical ascending

    static void sortAscending() {

        List<Employee> employees = list.getAll();

        employees.sort(
            Comparator.comparing(
                Employee::getName,
                String.CASE_INSENSITIVE_ORDER
            )
        );

        System.out.println("\n--- Ascending Order ---");

        displayList(employees);
    }


    // Alphabetical descending

    static void sortDescending() {

        List<Employee> employees = list.getAll();

        employees.sort(
            Comparator.comparing(
                Employee::getName,
                String.CASE_INSENSITIVE_ORDER
            ).reversed()
        );

        System.out.println("\n--- Descending Order ---");

        displayList(employees);
    }


    // =========================================
    // 4. SAVE TO FILE
    // =========================================

    static void saveToFile() {

        try {

            ObjectOutputStream out =
                new ObjectOutputStream(
                    new FileOutputStream(FILE_NAME)
                );

            out.writeObject(list.getAll());

            out.close();

            System.out.println(
                "Employees saved successfully."
            );

        } catch (IOException e) {

            System.out.println(
                "Error while saving file."
            );
        }
    }


    // =========================================
    // 5. LOAD FROM FILE
    // =========================================

    static void loadFromFile() {

        try {

            ObjectInputStream in =
                new ObjectInputStream(
                    new FileInputStream(FILE_NAME)
                );

            List<Employee> employees =
                (List<Employee>) in.readObject();

            in.close();

            list.clear();

            for (Employee employee : employees) {

                list.add(employee);
            }

            System.out.println(
                "Employees loaded successfully."
            );

        } catch (FileNotFoundException e) {

            System.out.println(
                "File not found. Save employees first."
            );

        } catch (IOException | ClassNotFoundException e) {

            System.out.println(
                "Error while loading file."
            );
        }
    }
}