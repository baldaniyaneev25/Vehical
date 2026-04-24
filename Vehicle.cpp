#include <iostream>
#include <cstring>
using namespace std;

// Base Class
class Vehicle {
protected:
    int vehicleID;
    char manufacturer[50];
    char model[50];
    int year;

    static int totalVehicles;

public:
    Vehicle() {
        vehicleID = 0;
        strcpy(manufacturer, "");
        strcpy(model, "");
        year = 0;
        totalVehicles++;
    }

    ~Vehicle() {
        totalVehicles--;
    }

    void inputVehicle() {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;
        cout << "Enter Manufacturer: ";
        cin >> manufacturer;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Year: ";
        cin >> year;
    }

    void displayVehicle() {
        cout << "ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }

    int getID() {
        return vehicleID;
    }
};

int Vehicle::totalVehicles = 0;

// Single Inheritance
class Car : public Vehicle {
protected:
    char fuelType[20];

public:
    void inputCar() {
        inputVehicle();
        cout << "Enter Fuel Type: ";
        cin >> fuelType;
    }

    void displayCar() {
        displayVehicle();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// Multilevel Inheritance
class ElectricCar : public Car {
protected:
    int batteryCapacity;

public:
    void inputElectricCar() {
        inputCar();
        cout << "Enter Battery Capacity: ";
        cin >> batteryCapacity;
    }

    void displayElectricCar() {
        displayCar();
        cout << "Battery: " << batteryCapacity << " kWh" << endl;
    }
};

// Another Base Class (for Multiple Inheritance)
class Aircraft {
protected:
    int flightRange;

public:
    void inputAircraft() {
        cout << "Enter Flight Range: ";
        cin >> flightRange;
    }

    void displayAircraft() {
        cout << "Flight Range: " << flightRange << endl;
    }
};

// Multiple Inheritance
class FlyingCar : public Car, public Aircraft {
public:
    void inputFlyingCar() {
        inputCar();
        inputAircraft();
    }

    void displayFlyingCar() {
        displayCar();
        displayAircraft();
    }
};

// Multilevel (again)
class SportsCar : public ElectricCar {
    int topSpeed;

public:
    void inputSportsCar() {
        inputElectricCar();
        cout << "Enter Top Speed: ";
        cin >> topSpeed;
    }

    void displaySportsCar() {
        displayElectricCar();
        cout << "Top Speed: " << topSpeed << endl;
    }
};

// Hierarchical
class Sedan : public Car {
public:
    void inputSedan() {
        inputCar();
    }

    void displaySedan() {
        displayCar();
    }
};

class SUV : public Car {
public:
    void inputSUV() {
        inputCar();
    }

    void displaySUV() {
        displayCar();
    }
};

// Main
int main() {
    int choice;

    // Objects
    Car car;
    ElectricCar ecar;
    FlyingCar fcar;
    SportsCar scar;
    Sedan sedan;
    SUV suv;

    do {
        cout << "\n--- Vehicle Registry Menu ---\n";
        cout << "1. Car\n2. Electric Car\n3. Flying Car\n4. Sports Car\n5. Sedan\n6. SUV\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            car.inputCar();
            car.displayCar();
            break;
        case 2:
            ecar.inputElectricCar();
            ecar.displayElectricCar();
            break;
        case 3:
            fcar.inputFlyingCar();
            fcar.displayFlyingCar();
            break;
        case 4:
            scar.inputSportsCar();
            scar.displaySportsCar();
            break;
        case 5:
            sedan.inputSedan();
            sedan.displaySedan();
            break;
        case 6:
            suv.inputSUV();
            suv.displaySUV();
            break;
        case 7:
            cout << "Exit...\n";
            break;
        default:
            cout << "Invalid!\n";
        }

    } while (choice != 7);

    return 0;
}