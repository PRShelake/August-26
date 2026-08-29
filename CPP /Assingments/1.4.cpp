//============================================================================
// Name        : 1.4.cpp
// Author      : praveenkumar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[])
{
    // Check if all 3 arguments are provided
    if (argc != 4)
    {
        cout << "Usage : ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>" << endl;
        cout << "Error : Missing arguments." << endl;
        return 1;
    }

    // Convert command-line arguments from string to integer
    int warn = atoi(argv[1]);
    int critical = atoi(argv[2]);
    int num_readings = atoi(argv[3]);

    // Validate thresholds
    if (warn >= critical)
    {
        cout << "Error : Warn threshold must be less than critical threshold." << endl;
        return 1;
    }

    // Validate number of readings
    if (num_readings < 1 || num_readings > 500)
    {
        cout << "Error : Number of readings must be between 1 and 500." << endl;
        return 1;
    }

    cout << "Config : Warn=" << warn
         << "°C Critical=" << critical
         << "°C Readings=" << num_readings << endl;

    int normal = 0;
    int warning = 0;
    int criticalCount = 0;
    int shutdown = 0;

    // Generate random temperature values
    srand(time(0));

    for (int i = 0; i < num_readings; i++)
    {
        int temperature = rand() % 70;

        if (temperature < warn)
        {
            normal++;
        }
        else if (temperature < critical)
        {
            warning++;
        }
        else if (temperature < 60)
        {
            criticalCount++;
        }
        else
        {
            shutdown++;
        }
    }

    // Print summary
    cout << "Results : Normal:" << normal
         << " Warning:" << warning
         << " Critical:" << criticalCount
         << " Shutdown:" << shutdown << endl;

    return 0;
}
