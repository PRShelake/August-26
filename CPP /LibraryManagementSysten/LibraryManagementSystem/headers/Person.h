#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

namespace LibrarySystem
{

class Person
{
protected:
    int id;
    std::string name;
    std::string phone;

public:

    Person()
    {
        id = 0;
        name = "";
        phone = "";
    }

    Person(int id, std::string name, std::string phone)
    {
        this->id = id;
        this->name = name;
        this->phone = phone;
    }

    virtual ~Person()
    {
    }

    int getId() const
    {
        return id;
    }

    std::string getName() const
    {
        return name;
    }

    std::string getPhone() const
    {
        return phone;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    void setPhone(std::string phone)
    {
        this->phone = phone;
    }

    virtual void displayInfo() const = 0;
};

}

#endif
