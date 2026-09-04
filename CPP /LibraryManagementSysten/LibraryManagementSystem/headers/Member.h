#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"
#include "LibraryException.h"
#include <iostream>
#include <string>

namespace LibrarySystem
{

class Member : public Person
{
private:
    int issuedCount;
    int* issuedBookIds;
    int capacity;

    static const int MAX_BOOKS = 3;

public:

    Member()
        : Person()
    {
        issuedCount = 0;
        capacity = MAX_BOOKS;
        issuedBookIds = new int[capacity];
    }

    Member(int id, std::string name, std::string phone)
        : Person(id, name, phone)
    {
        issuedCount = 0;
        capacity = MAX_BOOKS;
        issuedBookIds = new int[capacity];
    }

    // Copy constructor - Deep Copy
    Member(const Member& other)
        : Person(other.id, other.name, other.phone)
    {
        issuedCount = other.issuedCount;
        capacity = other.capacity;

        issuedBookIds = new int[capacity];

        for (int i = 0; i < issuedCount; i++)
        {
            issuedBookIds[i] = other.issuedBookIds[i];
        }
    }

    // Destructor
    ~Member() override
    {
        delete[] issuedBookIds;
    }

    // Assignment operator
    Member& operator=(const Member& other)
    {
        if (this != &other)
        {
            id = other.id;
            name = other.name;
            phone = other.phone;

            delete[] issuedBookIds;

            capacity = other.capacity;
            issuedCount = other.issuedCount;

            issuedBookIds = new int[capacity];

            for (int i = 0; i < issuedCount; i++)
            {
                issuedBookIds[i] = other.issuedBookIds[i];
            }
        }

        return *this;
    }

    void addBook(int bookId)
    {
        if (issuedCount >= MAX_BOOKS)
        {
            throw MaxBooksExceededException(
                "Member cannot issue more than 3 books",
                __FUNCTION__,
                __LINE__);
        }

        issuedBookIds[issuedCount] = bookId;
        issuedCount++;
    }

    bool removeBook(int bookId)
    {
        for (int i = 0; i < issuedCount; i++)
        {
            if (issuedBookIds[i] == bookId)
            {
                for (int j = i; j < issuedCount - 1; j++)
                {
                    issuedBookIds[j] = issuedBookIds[j + 1];
                }

                issuedCount--;
                return true;
            }
        }

        return false;
    }

    bool hasBook(int bookId) const
    {
        for (int i = 0; i < issuedCount; i++)
        {
            if (issuedBookIds[i] == bookId)
                return true;
        }

        return false;
    }

    int getIssuedCount() const
    {
        return issuedCount;
    }

    int getIssuedBook(int index) const
    {
        if (index >= 0 && index < issuedCount)
            return issuedBookIds[index];

        return -1;
    }

    void displayInfo() const override
    {
        std::cout << "\nMember ID     : " << id;
        std::cout << "\nName          : " << name;
        std::cout << "\nPhone         : " << phone;
        std::cout << "\nBooks Issued  : " << issuedCount;

        if (issuedCount > 0)
        {
            std::cout << "\nBook IDs      : ";

            for (int i = 0; i < issuedCount; i++)
            {
                std::cout << issuedBookIds[i] << " ";
            }
        }

        std::cout << "\n";
    }

    // == operator
    bool operator==(const Member& other) const
    {
        return id == other.id;
    }

    // << operator
    friend std::ostream& operator<<(std::ostream& out,
                                    const Member& member)
    {
        out << member.id << " "
            << member.name << " "
            << member.phone;

        return out;
    }

    // >> operator
    friend std::istream& operator>>(std::istream& in,
                                    Member& member)
    {
        in >> member.id
           >> member.name
           >> member.phone;

        return in;
    }
};

}

#endif
