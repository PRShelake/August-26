//============================================================================
// Name        : 43.cpp
// Author      : praveenkumar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <iomanip>

using namespace std;


// ============================================================
// PART A : ABSTRACT DATA PROCESSOR
// ============================================================

class DataProcessor
{
public:

    // Pure virtual functions
    virtual void loadData(const string& source) = 0;

    virtual void processData() = 0;

    virtual void exportResult(const string& destination) = 0;

    virtual string processorType() const = 0;

    virtual int recordCount() const = 0;


    // Non-pure virtual function
    virtual void printSummary() const
    {
        cout << "Processor Type: "
             << processorType() << endl;

        cout << "Record Count: "
             << recordCount() << endl;
    }


    // Virtual destructor
    virtual ~DataProcessor() = default;
};


// ============================================================
// CSV PROCESSOR
// ============================================================

class CSVProcessor : public DataProcessor
{
private:
    vector<string> records;

public:

    // Load CSV data
    void loadData(const string& source) override
    {
        cout << "[CSV] Loading data from: "
             << source << endl;

        // Hard-coded sample CSV rows
        records.push_back("name,age,city");
        records.push_back("ramesh,25,hyderabad");
        records.push_back("suresh,30,mumbai");
        records.push_back("priya,28,bangalore");
        records.push_back("anil,35,delhi");
    }


    // Convert every record to uppercase
    void processData() override
    {
        for (string& record : records)
        {
            for (char& ch : record)
            {
                ch = static_cast<char>(
                    toupper(static_cast<unsigned char>(ch))
                );
            }
        }
    }


    // Export processed records
    void exportResult(const string& destination) override
    {
        cout << "[CSV EXPORT -> "
             << destination
             << "]"
             << endl;

        for (const string& record : records)
        {
            cout << record << endl;
        }
    }


    string processorType() const override
    {
        return "CSV Processor";
    }


    int recordCount() const override
    {
        return static_cast<int>(records.size());
    }


    void printSummary() const override
    {
        cout << "Processor Type: "
             << processorType()
             << endl;

        cout << "Records Loaded: "
             << recordCount()
             << endl;
    }
};


// ============================================================
// SENSOR STREAM PROCESSOR
// ============================================================

class SensorStreamProcessor : public DataProcessor
{
private:
    vector<double> readings;

    double mean = 0;
    double minimum = 0;
    double maximum = 0;

public:

    // Load sensor readings
    void loadData(const string& source) override
    {
        cout << "[Sensor] Loading data from: "
             << source << endl;

        readings = {
            23.4,
            21.8,
            25.1,
            24.6,
            22.9,
            26.3,
            23.7,
            24.2
        };
    }


    // Calculate mean, minimum and maximum
    void processData() override
    {
        if (readings.empty())
            return;

        double sum = 0;

        minimum = readings[0];
        maximum = readings[0];

        for (double value : readings)
        {
            sum += value;

            if (value < minimum)
                minimum = value;

            if (value > maximum)
                maximum = value;
        }

        mean = sum / readings.size();
    }


    // Print statistical result
    void exportResult(const string& destination) override
    {
        cout << "[SENSOR EXPORT -> "
             << destination
             << "]"
             << endl;

        cout << fixed << setprecision(2);

        cout << "Mean: "
             << mean << endl;

        cout << "Minimum: "
             << minimum << endl;

        cout << "Maximum: "
             << maximum << endl;
    }


    string processorType() const override
    {
        return "Sensor Stream Processor";
    }


    int recordCount() const override
    {
        return static_cast<int>(readings.size());
    }


    void printSummary() const override
    {
        cout << fixed << setprecision(2);

        cout << "Processor Type: "
             << processorType()
             << endl;

        cout << "Readings: "
             << recordCount()
             << endl;

        cout << "Mean: "
             << mean << endl;

        cout << "Minimum: "
             << minimum << endl;

        cout << "Maximum: "
             << maximum << endl;
    }
};


// ============================================================
// PART B : TEMPLATE DATA BUFFER
// ============================================================

/*
    IMPORTANT TEMPLATE NOTE:

    The entire DataBuffer<T> implementation is written in this
    same file.

    Template definitions normally need to be visible at the
    point where the compiler instantiates the template.

    Therefore, if the template implementation is placed in a
    separate .cpp file, the compiler may not have the definition
    available when it needs to generate DataBuffer<int>,
    DataBuffer<double>, DataBuffer<string>, etc.

    That is why template classes are normally placed entirely
    in a header file (.h), or written completely in one file.
*/

template <typename T>
class DataBuffer
{
private:

    T* data;

    int capacity;

    // Index of oldest element
    int head;

    // Index where next element is written
    int tail;

    // Number of current elements
    int count;


public:

    // Constructor
    DataBuffer(int capacity)
    {
        if (capacity <= 0)
        {
            throw invalid_argument(
                "Capacity must be greater than zero"
            );
        }

        this->capacity = capacity;

        data = new T[capacity];

        head = 0;
        tail = 0;
        count = 0;
    }


    // Destructor
    ~DataBuffer()
    {
        delete[] data;
    }


    // Add element
    // If full, overwrite oldest element
    void push(const T& value)
    {
        data[tail] = value;

        // Move tail circularly
        tail = (tail + 1) % capacity;


        if (count < capacity)
        {
            // Buffer was not full
            count++;
        }
        else
        {
            // Buffer was full.
            // Oldest element is overwritten,
            // so move head forward.
            head = (head + 1) % capacity;
        }
    }


    // Remove and return oldest element
    T pop()
    {
        if (isEmpty())
        {
            throw underflow_error(
                "Buffer is empty"
            );
        }

        T value = data[head];

        head = (head + 1) % capacity;

        count--;

        return value;
    }


    // View oldest element without removing
    T peek() const
    {
        if (isEmpty())
        {
            throw underflow_error(
                "Buffer is empty"
            );
        }

        return data[head];
    }


    // Check whether buffer is empty
    bool isEmpty() const
    {
        return count == 0;
    }


    // Check whether buffer is full
    bool isFull() const
    {
        return count == capacity;
    }


    // Return number of elements
    int size() const
    {
        return count;
    }


    // Friend template operator
    template <typename U>
    friend ostream& operator<<(
        ostream& out,
        const DataBuffer<U>& buf
    );
};


// ============================================================
// TEMPLATE FRIEND OUTPUT OPERATOR
// ============================================================

template <typename U>
ostream& operator<<(
    ostream& out,
    const DataBuffer<U>& buf)
{
    out << "[";

    for (int i = 0; i < buf.count; i++)
    {
        int index =
            (buf.head + i) % buf.capacity;

        out << buf.data[index];

        if (i < buf.count - 1)
        {
            out << ", ";
        }
    }

    out << "]";

    return out;
}


// ============================================================
// MAIN
// ============================================================

int main()
{
    // ========================================================
    // PART A : POLYMORPHIC DATA PROCESSING PIPELINE
    // ========================================================

    cout << "===== DATA PROCESSING PIPELINE ====="
         << endl;

    vector<DataProcessor*> pipeline;


    pipeline.push_back(new CSVProcessor());

    pipeline.push_back(new SensorStreamProcessor());


    for (auto* p : pipeline)
    {
        cout << endl;

        p->loadData("source_data");

        p->processData();

        p->printSummary();

        p->exportResult("output_dir");

        cout << "---" << endl;
    }


    // ========================================================
    // ABSTRACT CLASS TEST
    // ========================================================

    /*
        DataProcessor dp;

        ERROR:
        Cannot instantiate an abstract class because
        DataProcessor contains pure virtual functions.
    */


    // ========================================================
    // CLEANUP PIPELINE
    // ========================================================

    for (auto* p : pipeline)
    {
        delete p;
    }

    pipeline.clear();


    // ========================================================
    // PART B : INTEGER BUFFER
    // ========================================================

    cout << endl;

    cout << "===== INTEGER BUFFER ====="
         << endl;

    DataBuffer<int> tickBuffer(5);


    for (int i = 1; i <= 7; i++)
    {
        tickBuffer.push(i * 10);
    }


    cout << "Tick Buffer: "
         << tickBuffer
         << endl;


    // ========================================================
    // DOUBLE BUFFER
    // ========================================================

    cout << endl;

    cout << "===== DOUBLE BUFFER ====="
         << endl;

    DataBuffer<double> tempBuffer(4);


    tempBuffer.push(36.6);
    tempBuffer.push(37.1);
    tempBuffer.push(38.2);
    tempBuffer.push(36.9);


    cout << fixed << setprecision(1);

    cout << "Before pop: "
         << tempBuffer
         << endl;


    cout << "Popped: "
         << tempBuffer.pop()
         << endl;


    cout << "After pop: "
         << tempBuffer
         << endl;


    // ========================================================
    // STRING BUFFER
    // ========================================================

    cout << endl;

    cout << "===== STRING BUFFER ====="
         << endl;

    DataBuffer<string> logBuffer(3);


    logBuffer.push(
        "INFO: Server started"
    );

    logBuffer.push(
        "WARN: High memory usage"
    );

    logBuffer.push(
        "ERROR: DB connection timeout"
    );

    // Overwrites oldest element
    logBuffer.push(
        "INFO: Retry successful"
    );


    cout << "Log Buffer: "
         << logBuffer
         << endl;


    // ========================================================
    // RETURN
    // ========================================================

    return 0;
}
