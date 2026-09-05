#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <utility>

using namespace std;

class LedgerEntry
{
private:
    string description;
    double* amounts;
    int days;

    static int totalEntries;

public:

    // Constructor
    LedgerEntry(const string& desc, int days)
    {
        description = desc;
        this->days = days;

        if (days > 0)
            amounts = new double[days]();
        else
            amounts = nullptr;

        totalEntries++;

        cout << "[LedgerEntry Created] "
             << description << " (" << days << " days)" << endl;
    }

    // Copy Constructor - Deep Copy
    LedgerEntry(const LedgerEntry& other)
    {
        description = other.description;
        days = other.days;

        if (days > 0 && other.amounts != nullptr)
        {
            amounts = new double[days];

            for (int i = 0; i < days; i++)
            {
                amounts[i] = other.amounts[i];
            }
        }
        else
        {
            amounts = nullptr;
        }

        totalEntries++;

        cout << "[Copy Constructor] Copied: "
             << description << endl;
    }

    // Move Constructor - Transfer Ownership
    LedgerEntry(LedgerEntry&& other) noexcept
    {
        description = move(other.description);
        amounts = other.amounts;
        days = other.days;

        cout << "[Move Constructor] Ownership transferred from: "
             << description << endl;

        // Make source empty
        other.amounts = nullptr;
        other.days = 0;
        other.description = "";

        totalEntries++;
    }

    // Copy Assignment Operator
    LedgerEntry& operator=(const LedgerEntry& other)
    {
        if (this != &other)
        {
            // Delete existing memory
            delete[] amounts;

            description = other.description;
            days = other.days;

            if (days > 0 && other.amounts != nullptr)
            {
                amounts = new double[days];

                for (int i = 0; i < days; i++)
                {
                    amounts[i] = other.amounts[i];
                }
            }
            else
            {
                amounts = nullptr;
            }
        }

        return *this;
    }

    // Move Assignment Operator
    LedgerEntry& operator=(LedgerEntry&& other) noexcept
    {
        if (this != &other)
        {
            // Delete current memory
            delete[] amounts;

            // Transfer ownership
            description = move(other.description);
            amounts = other.amounts;
            days = other.days;

            cout << "[Move Assignment] Ownership transferred from: "
                 << description << endl;

            // Make source empty
            other.amounts = nullptr;
            other.days = 0;
            other.description = "";
        }

        return *this;
    }

    // Destructor
    ~LedgerEntry()
    {
        delete[] amounts;
        totalEntries--;
    }

    // Addition Operator
    LedgerEntry operator+(const LedgerEntry& other) const
    {
        // Both ledgers should have same number of days
        if (days != other.days)
        {
            throw invalid_argument(
                "Cannot add ledgers with different number of days"
            );
        }

        LedgerEntry result(
            description + " + " + other.description,
            days
        );

        for (int i = 0; i < days; i++)
        {
            result.amounts[i] = amounts[i] + other.amounts[i];
        }

        return result;
    }

    // Equality Operator
    bool operator==(const LedgerEntry& other) const
    {
        if (days != other.days)
            return false;

        for (int i = 0; i < days; i++)
        {
            if (amounts[i] != other.amounts[i])
                return false;
        }

        return true;
    }

    // Greater Than Operator
    bool operator>(const LedgerEntry& other) const
    {
        double sum1 = 0;
        double sum2 = 0;

        for (int i = 0; i < days; i++)
        {
            sum1 += amounts[i];
        }

        for (int i = 0; i < other.days; i++)
        {
            sum2 += other.amounts[i];
        }

        return sum1 > sum2;
    }

    // Subscript Operator - Non-const
    double& operator[](int index)
    {
        if (index < 0 || index >= days)
        {
            throw out_of_range("Index out of range");
        }

        return amounts[index];
    }

    // Subscript Operator - Const
    const double& operator[](int index) const
    {
        if (index < 0 || index >= days)
        {
            throw out_of_range("Index out of range");
        }

        return amounts[index];
    }

    // Friend output operator
    friend ostream& operator<<(ostream& out,
                               const LedgerEntry& entry);

    // Friend input operator
    friend istream& operator>>(istream& in,
                               LedgerEntry& entry);

    // Static member function
    static int getTotalEntries()
    {
        return totalEntries;
    }
};


// Definition of static member
int LedgerEntry::totalEntries = 0;


// Output operator <<
ostream& operator<<(ostream& out, const LedgerEntry& entry)
{
    out << entry.description << " : [";

    double total = 0;

    for (int i = 0; i < entry.days; i++)
    {
        out << fixed << setprecision(2)
            << entry.amounts[i];

        total += entry.amounts[i];

        if (i < entry.days - 1)
        {
            out << ", ";
        }
    }

    out << "] Total: "
        << fixed << setprecision(2)
        << total;

    return out;
}


// Input operator >>
istream& operator>>(istream& in, LedgerEntry& entry)
{
    for (int i = 0; i < entry.days; i++)
    {
        in >> entry.amounts[i];
    }

    return in;
}


// Main function
int main()
{
    // Objective 1 - Constructor & deep copy

    LedgerEntry jan("January Sales", 5);

    jan[0] = 1200.50;
    jan[1] = 3400.00;
    jan[2] = 800.75;
    jan[3] = 2100.00;
    jan[4] = 650.25;


    LedgerEntry feb("February Sales", 5);

    feb[0] = 900.00;
    feb[1] = 2200.50;
    feb[2] = 1750.00;
    feb[3] = 3000.00;
    feb[4] = 475.50;


    cout << jan << endl;
    cout << feb << endl;


    // Objective 2 - Operator +
    LedgerEntry combined = jan + feb;

    cout << "Combined : "
         << combined << endl;


    // Objective 3 - Relational operators

    cout << "Jan == Feb : "
         << (jan == feb ? "Yes" : "No")
         << endl;

    cout << "Jan > Feb : "
         << (jan > feb ? "Yes" : "No")
         << endl;


    // Objective 4 - Move Constructor

    LedgerEntry moved = move(jan);

    cout << "After move, jan.amounts is null: "
         << (jan[0] /* this would throw! */)
         << endl;

    cout << "Moved entry : "
         << moved << endl;


    // Objective 5 - Move Assignment

    LedgerEntry q1("Q1 Total", 5);

    q1 = move(feb);

    cout << "Q1 (moved from feb) : "
         << q1 << endl;


    // Objective 6 - Static member

    cout << "Live LedgerEntry objects: "
         << LedgerEntry::getTotalEntries()
         << endl;


    return 0;
}
