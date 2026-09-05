//============================================================================
// Name        : 42.cpp
// Author      : praveenkumar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


// ============================================================
// BASE CLASS : Vehicle
// ============================================================

class Vehicle
{
protected:
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:

    // Constructor
    Vehicle(const string& reg,
            const string& owner,
            int year,
            double km)
    {
        registrationNo = reg;
        ownerName = owner;
        yearOfManufacture = year;
        kmDriven = km;

        cout << "[Vehicle Constructor] "
             << registrationNo << " : "
             << ownerName << endl;
    }

    // Pure virtual function
    virtual double fuelCost(double kmToTravel) const = 0;

    // Virtual function
    virtual void describe() const
    {
        cout << "Registration: " << registrationNo << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Year: " << yearOfManufacture << endl;
        cout << "KM Driven: " << kmDriven << endl;
    }

    // Pure virtual function
    virtual string vehicleType() const = 0;

    // Virtual destructor
    virtual ~Vehicle()
    {
        cout << "[Vehicle Destructor] "
             << registrationNo << endl;
    }

    double getKmDriven() const
    {
        return kmDriven;
    }

    string getRegNo() const
    {
        return registrationNo;
    }

    string getOwnerName() const
    {
        return ownerName;
    }
};


// ============================================================
// CAR : Vehicle
// ============================================================

class Car : public Vehicle
{
private:
    string fuelType;
    double mileageKmpl;

public:

    Car(const string& reg,
        const string& owner,
        int year,
        double km,
        const string& fuel,
        double mileage)
        : Vehicle(reg, owner, year, km)
    {
        fuelType = fuel;
        mileageKmpl = mileage;

        cout << "[Car Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        double fuelPrice;

        if (fuelType == "Petrol")
            fuelPrice = 106.00;
        else
            fuelPrice = 93.00;

        return (kmToTravel / mileageKmpl) * fuelPrice;
    }

    string vehicleType() const override
    {
        return "Car";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Fuel Type: " << fuelType << endl;
        cout << "Mileage: " << mileageKmpl << " km/l" << endl;
    }

    string getFuelType() const
    {
        return fuelType;
    }

    ~Car() override
    {
        cout << "[Car Destructor] "
             << registrationNo << endl;
    }
};


// ============================================================
// TRUCK : Vehicle
// ============================================================

class Truck : public Vehicle
{
protected:
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:

    Truck(const string& reg,
          const string& owner,
          int year,
          double km,
          double payload,
          double efficiency)
        : Vehicle(reg, owner, year, km)
    {
        payloadCapacityTons = payload;
        fuelEfficiencyKmpl = efficiency;

        cout << "[Truck Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        // Efficiency drops by 5% for every ton
        double effectiveEfficiency =
            fuelEfficiencyKmpl *
            (1.0 - (0.05 * payloadCapacityTons));

        // Prevent zero/negative efficiency
        if (effectiveEfficiency <= 0)
            return 0;

        double fuelUsed =
            kmToTravel / effectiveEfficiency;

        // Diesel price
        double dieselPrice = 93.00;

        return fuelUsed * dieselPrice;
    }

    string vehicleType() const override
    {
        return "Truck";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Payload Capacity: "
             << payloadCapacityTons
             << " tons" << endl;

        cout << "Fuel Efficiency: "
             << fuelEfficiencyKmpl
             << " km/l" << endl;
    }

    ~Truck() override
    {
        cout << "[Truck Destructor] "
             << registrationNo << endl;
    }
};


// ============================================================
// ELECTRIC TRUCK : Truck
// Multilevel Inheritance
// Vehicle -> Truck -> ElectricTruck
// ============================================================

class ElectricTruck : public Truck
{
private:
    double batteryCapacityKWh;
    double rangePerChargeKm;
    double batteryChargePercent;

public:

    ElectricTruck(const string& reg,
                  const string& owner,
                  int year,
                  double km,
                  double payload,
                  double efficiency,
                  double batteryCapacity,
                  double range,
                  double chargePercent)
        : Truck(reg, owner, year, km, payload, efficiency)
    {
        batteryCapacityKWh = batteryCapacity;
        rangePerChargeKm = range;
        batteryChargePercent = chargePercent;

        cout << "[ElectricTruck Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        double electricityCostPerUnit = 9.50;

        double energyUsed =
            (kmToTravel / rangePerChargeKm)
            * batteryCapacityKWh;

        return energyUsed * electricityCostPerUnit;
    }

    string vehicleType() const override
    {
        return "Electric Truck";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Payload Capacity: "
             << payloadCapacityTons
             << " tons" << endl;

        cout << "Battery Capacity: "
             << batteryCapacityKWh
             << " kWh" << endl;

        cout << "Range Per Charge: "
             << rangePerChargeKm
             << " km" << endl;

        cout << "Battery Charge: "
             << batteryChargePercent
             << "%" << endl;
    }

    double getBatteryCharge() const
    {
        return batteryChargePercent;
    }

    ~ElectricTruck() override
    {
        cout << "[ElectricTruck Destructor] "
             << registrationNo << endl;
    }
};


// ============================================================
// VAN : Vehicle
// Hierarchical Inheritance
// ============================================================

class Van : public Vehicle
{
private:
    int seatingCapacity;
    double mileageKmpl;

public:

    Van(const string& reg,
        const string& owner,
        int year,
        double km,
        int seating,
        double mileage)
        : Vehicle(reg, owner, year, km)
    {
        seatingCapacity = seating;
        mileageKmpl = mileage;

        cout << "[Van Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        double petrolPrice = 106.00;

        return (kmToTravel / mileageKmpl)
               * petrolPrice;
    }

    string vehicleType() const override
    {
        return "Van";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Seating Capacity: "
             << seatingCapacity << endl;

        cout << "Mileage: "
             << mileageKmpl
             << " km/l" << endl;
    }

    ~Van() override
    {
        cout << "[Van Destructor] "
             << registrationNo << endl;
    }
};


// ============================================================
// FLEET REPORT FUNCTION
// ============================================================

void printFleetReport(const vector<Vehicle*>& fleet,
                      double tripKm)
{
    cout << endl;
    cout << "============================================================"
         << endl;

    cout << "===== FLEET REPORT - Trip Distance: "
         << tripKm << " km ====="
         << endl;

    cout << "============================================================"
         << endl;

    cout << left
         << setw(15) << "Registration"
         << setw(20) << "Type"
         << setw(25) << "Owner"
         << setw(15) << "KM Driven"
         << endl;

    cout << "------------------------------------------------------------"
         << endl;


    // Variables for most efficient vehicle
    Vehicle* mostEfficient = nullptr;
    double lowestCost = 0;


    // Loop through base class pointers
    for (Vehicle* vehicle : fleet)
    {
        cout << left
             << setw(15) << vehicle->getRegNo()
             << setw(20) << vehicle->vehicleType()
             << setw(25) << vehicle->getOwnerName()
             << setw(15) << fixed
             << setprecision(0)
             << vehicle->getKmDriven()
             << endl;


        // Runtime polymorphism
        double cost = vehicle->fuelCost(tripKm);

        if (mostEfficient == nullptr ||
            cost < lowestCost)
        {
            mostEfficient = vehicle;
            lowestCost = cost;
        }
    }


    // ========================================================
    // COST SECTION
    // ========================================================

    cout << endl;

    cout << "===== FUEL / CHARGE COST ESTIMATE ====="
         << endl;

    cout << fixed << setprecision(2);


    for (Vehicle* vehicle : fleet)
    {
        double cost = vehicle->fuelCost(tripKm);

        cout << vehicle->getRegNo()
             << " (" << vehicle->vehicleType()
             << ") : Rs. "
             << cost;


        // Check whether vehicle is an ElectricTruck
        ElectricTruck* electricTruck =
            dynamic_cast<ElectricTruck*>(vehicle);

        if (electricTruck != nullptr)
        {
            cout << " [Battery: "
                 << electricTruck->getBatteryCharge()
                 << "% charged]";
        }

        else
        {
            // Check if vehicle is Car
            Car* car =
                dynamic_cast<Car*>(vehicle);

            if (car != nullptr)
            {
                cout << " ("
                     << car->getFuelType()
                     << ")";
            }
        }

        cout << endl;
    }


    // ========================================================
    // MOST EFFICIENT VEHICLE
    // ========================================================

    cout << endl;

    cout << "Most Efficient Vehicle: "
         << mostEfficient->getRegNo()
         << " (" << mostEfficient->vehicleType()
         << ") - Rs. "
         << lowestCost
         << " for "
         << tripKm
         << " km"
         << endl;
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    // ========================================================
    // PART B
    // Constructor / Destructor Execution Order
    // ========================================================

    cout << "===== CONSTRUCTION / DESTRUCTION DEMO ====="
         << endl;

    {
        ElectricTruck electricTruck(
            "V-ET001",
            "Green Logistics",
            2025,
            50000,
            10,
            6,
            85,
            400,
            85
        );

        cout << endl;
        cout << "ElectricTruck object is inside scope..."
             << endl;
    }

    cout << "Scope ended."
         << endl;


    // ========================================================
    // PART C
    // CREATE FLEET
    // ========================================================

    cout << endl;

    cout << "===== CREATING FLEET ====="
         << endl;


    vector<Vehicle*> fleet;


    // 1. Car
    fleet.push_back(
        new Car(
            "KA01AA001",
            "Ramesh Kumar",
            2020,
            45200,
            "Petrol",
            12.0
        )
    );


    // 2. Truck
    fleet.push_back(
        new Truck(
            "MH04BB002",
            "Shyam Logistics",
            2018,
            123500,
            8,
            5.0
        )
    );


    // 3. Electric Truck
    fleet.push_back(
        new ElectricTruck(
            "GJ07CC003",
            "Green Fleet Co",
            2024,
            89000,
            6,
            5.5,
            85,
            400,
            85
        )
    );


    // 4. Van
    fleet.push_back(
        new Van(
            "TS09DD004",
            "City Delivery",
            2022,
            67000,
            8,
            14.0
        )
    );


    // 5. Another Car
    fleet.push_back(
        new Car(
            "DL05EE005",
            "Anil Sharma",
            2021,
            32000,
            "Diesel",
            16.0
        )
    );


    // ========================================================
    // PRINT FLEET REPORT
    // ========================================================

    printFleetReport(fleet, 200);


    // ========================================================
    // CLEANUP
    // ========================================================

    cout << endl;

    cout << "===== CLEANUP ====="
         << endl;

    for (Vehicle* vehicle : fleet)
    {
        delete vehicle;
    }

    fleet.clear();


    cout << "All vehicles deleted."
         << endl;

    return 0;
}
