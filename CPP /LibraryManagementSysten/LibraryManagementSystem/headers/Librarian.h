#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Person.h"
#include <iostream>

namespace LibrarySystem
{

class Librarian : public Person
{
private:
    int employeeId;
    double salary;

public:

    Librarian()
        : Person()
    {
        employeeId = 0;
        salary = 0;
    }

    Librarian(int id,
              std::string name,
              std::string phone,
              int employeeId,
              double salary)
        : Person(id, name, phone)
    {
        this->employeeId = employeeId;
        this->salary = salary;
    }

    int getEmployeeId() const
    {
        return employeeId;
    }

    double getSalary() const
    {
        return salary;
    }

    void displayInfo() const override
    {
        std::cout << "\nLibrarian ID : " << id;
        std::cout << "\nName         : " << name;
        std::cout << "\nPhone        : " << phone;
        std::cout << "\nEmployee ID   : " << employeeId;
        std::cout << "\nSalary        : " << salary;
        std::cout << "\n";
    }
};

}

#endif
