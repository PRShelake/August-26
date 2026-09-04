#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <string>

namespace LibrarySystem
{

template <class T>
class Container
{
private:
    T* data;
    int size;
    int capacity;

    void resize()
    {
        capacity *= 2;

        T* newData = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
    }

public:

    Container(int initialCapacity = 10)
    {
        size = 0;
        capacity = initialCapacity;

        data = new T[capacity];
    }

    // Copy constructor
    Container(const Container& other)
    {
        size = other.size;
        capacity = other.capacity;

        data = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    // Assignment operator
    Container& operator=(const Container& other)
    {
        if (this != &other)
        {
            delete[] data;

            size = other.size;
            capacity = other.capacity;

            data = new T[capacity];

            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }

        return *this;
    }

    // Destructor
    ~Container()
    {
        delete[] data;
    }

    void add(const T& item)
    {
        if (size >= capacity)
        {
            resize();
        }

        data[size] = item;
        size++;
    }

    bool removeById(int id)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i].getId() == id)
            {
                for (int j = i; j < size - 1; j++)
                {
                    data[j] = data[j + 1];
                }

                size--;
                return true;
            }
        }

        return false;
    }

    // find() by ID
    T* find(int id)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i].getId() == id)
            {
                return &data[i];
            }
        }

        return nullptr;
    }

    // find() by name
    T* find(const std::string& name)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i].getName() == name)
            {
                return &data[i];
            }
        }

        return nullptr;
    }

    T& operator[](int index)
    {
        return data[index];
    }

    const T& operator[](int index) const
    {
        return data[index];
    }

    int getSize() const
    {
        return size;
    }

    void displayAll() const
    {
        for (int i = 0; i < size; i++)
        {
            data[i].displayInfo();
        }
    }
};

}

#endif
