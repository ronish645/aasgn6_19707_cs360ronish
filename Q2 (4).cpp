#include <iostream>
#include <vector>
#include <memory> // for std::unique_ptr
#include <string>
using namespace std;

// Abstract class
class CarbonFootprint {
public:
    virtual double getCarbonFootprint() const = 0; // Pure virtual function
    virtual string getInfo() const = 0; // Pure virtual function
    virtual ~CarbonFootprint() = default; // Virtual destructor
};

class Building : public CarbonFootprint {
public:
    Building(double area, double energyConsumption) : area(area), energyConsumption(energyConsumption) {}

    double getCarbonFootprint() const override {
        // Carbon footprint calculation for buildings
        return area * energyConsumption * 0.5; // Dummy calculation, replace with actual formula
    }

    string getInfo() const override {
        return "Building (Area: " + to_string(area) + " sq.ft, Energy Consumption: " + to_string(energyConsumption) + " kWh)";
    }

private:
    double area; // in square feet
    double energyConsumption; // in kWh per year
};

class Car : public CarbonFootprint {
public:
    Car(double mileage, double fuelConsumption) : mileage(mileage), fuelConsumption(fuelConsumption) {}

    double getCarbonFootprint() const override {
        // Carbon footprint calculation for cars
        return mileage * fuelConsumption * 0.1; // Dummy calculation, replace with actual formula
    }

    string getInfo() const override {
        return "Car (Mileage: " + to_string(mileage) + " miles/gallon, Fuel Consumption: " + to_string(fuelConsumption) + " gallons/year)";
    }

private:
    double mileage; // in miles per gallon
    double fuelConsumption; // in gallons per year
};

class Bicycle : public CarbonFootprint {
public:
    Bicycle(double distanceTraveled) : distanceTraveled(distanceTraveled) {}

    double getCarbonFootprint() const override {
        // Carbon footprint calculation for bicycles (usually negligible)
        return 0.0;
    }

    string getInfo() const override {
        return "Bicycle (Distance Traveled: " + to_string(distanceTraveled) + " miles)";
    }

private:
    double distanceTraveled; // in miles
};

int main() {
    // Create objects of each class
    Building building(2000, 10000); // 2000 sq.ft area, 10000 kWh/year energy consumption
    Car car(25, 500); // 25 miles/gallon mileage, 500 gallons/year fuel consumption
    Bicycle bicycle(100); // 100 miles traveled

    // Create a vector of CarbonFootprint pointers
    vector<unique_ptr<CarbonFootprint>> carbonFootprints;

    // Add pointers to objects to the vector
    carbonFootprints.push_back(make_unique<Building>(building));
    carbonFootprints.push_back(make_unique<Car>(car));
    carbonFootprints.push_back(make_unique<Bicycle>(bicycle));

    // Iterate through the vector, polymorphically invoking each object's getCarbonFootprint method
    for (const auto& obj : carbonFootprints) {
        cout << obj->getInfo() << " - Carbon Footprint: " << obj->getCarbonFootprint() << " tons/year" << endl;
    }

    return 0;
}
