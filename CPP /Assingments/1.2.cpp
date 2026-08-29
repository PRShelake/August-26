//============================================================================
// Name        :1.2.cpp
// Author      : praveenkumar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N;

    // 1. Accept N
    cout << "Enter number of readings: ";
    cin >> N;

    double readings[100];

    // Read N temperature values
    for (int i = 0; i < N; i++)
    {
        cin >> readings[i];
    }

    // 2. Print valid readings and skip errors using continue
    cout << "Valid readings : ";

    int skipped = 0;

    for (int i = 0; i < N; i++)
    {
        if (readings[i] < 0)
        {
            skipped++;
            continue;
        }

        cout << readings[i] << " ";
    }

    cout << endl;
    cout << "Skipped (errors) : " << skipped << endl;


    // 3. Find first reading >= 45 using break
    bool foundCritical = false;

    for (int i = 0; i < N; i++)
    {
        if (readings[i] < 0)
        {
            continue;
        }

        if (readings[i] >= 45)
        {
            cout << "First CRITICAL : Index " << i
                 << " -> " << readings[i] << "°C" << endl;

            foundCritical = true;
            break;
        }
    }

    if (!foundCritical)
    {
        cout << "First CRITICAL : Not found" << endl;
    }


    // 4 & 5. Min, Max, Average and category counting
    double minTemp = 0;
    double maxTemp = 0;
    double sum = 0;

    int validCount = 0;

    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    // Single loop pass for min, max, average and categories
    for (int i = 0; i < N; i++)
    {
        if (readings[i] < 0)
        {
            continue;
        }

        // First valid reading initializes min and max
        if (validCount == 0)
        {
            minTemp = readings[i];
            maxTemp = readings[i];
        }

        // Min
        if (readings[i] < minTemp)
        {
            minTemp = readings[i];
        }

        // Max
        if (readings[i] > maxTemp)
        {
            maxTemp = readings[i];
        }

        // Sum
        sum += readings[i];
        validCount++;

        // Categories
        if (readings[i] < 30)
        {
            normal++;
        }
        else if (readings[i] < 45)
        {
            warning++;
        }
        else if (readings[i] < 60)
        {
            critical++;
        }
        else
        {
            shutdown++;
        }
    }


    // Average
    double average = sum / validCount;

    cout << fixed << setprecision(2);

    cout << "Min : " << minTemp << "°C ";
    cout << "Max : " << maxTemp << "°C ";
    cout << "Avg : " << average << "°C" << endl;

    cout << "Normal:" << normal
         << " Warning:" << warning
         << " Critical:" << critical
         << " Shutdown:" << shutdown << endl;

    return 0;
}
