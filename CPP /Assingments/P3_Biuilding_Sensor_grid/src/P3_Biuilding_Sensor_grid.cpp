#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double temperature[3][3];

    // Read temperatures
    cout << "Enter temperature for 9 rooms:\n";

    for (int floor = 0; floor < 3; floor++)
    {
        for (int room = 0; room < 3; room++)
        {
            cout << "Floor " << floor + 1
                 << ", Room " << room + 1 << ": ";
            cin >> temperature[floor][room];
        }
    }

    // Display readings in table
    cout << "\n\tRoom1\tRoom2\tRoom3\n";

    for (int floor = 0; floor < 3; floor++)
    {
        cout << "Floor " << floor + 1 << "\t";

        for (int room = 0; room < 3; room++)
        {
            cout << fixed << setprecision(1)
                 << temperature[floor][room] << "\t";
        }

        cout << endl;
    }

    // Find hottest room
    double hottest = temperature[0][0];
    int hottestFloor = 0;
    int hottestRoom = 0;

    for (int floor = 0; floor < 3; floor++)
    {
        for (int room = 0; room < 3; room++)
        {
            if (temperature[floor][room] > hottest)
            {
                hottest = temperature[floor][room];
                hottestFloor = floor;
                hottestRoom = room;
            }
        }
    }

    // Find floor with highest average
    double highestAverage = 0;
    int hottestFloorNumber = 0;

    for (int floor = 0; floor < 3; floor++)
    {
        double sum = 0;

        for (int room = 0; room < 3; room++)
        {
            sum += temperature[floor][room];
        }

        double average = sum / 3;

        if (floor == 0 || average > highestAverage)
        {
            highestAverage = average;
            hottestFloorNumber = floor;
        }
    }

    // Count rooms at or above WARNING threshold
    int warningCount = 0;

    for (int floor = 0; floor < 3; floor++)
    {
        for (int room = 0; room < 3; room++)
        {
            if (temperature[floor][room] >= 30)
            {
                warningCount++;
            }
        }
    }

    // Display results
    cout << "\nHottest Room : Floor " << hottestFloor + 1
         << ", Room " << hottestRoom + 1
         << " -> " << fixed << setprecision(1)
         << hottest << "°C" << endl;

    cout << "Hottest Floor : Floor " << hottestFloorNumber + 1
         << " (avg " << fixed << setprecision(2)
         << highestAverage << "°C)" << endl;

    cout << "Rooms at WARNING or above : "
         << warningCount << endl;

    return 0;
}
