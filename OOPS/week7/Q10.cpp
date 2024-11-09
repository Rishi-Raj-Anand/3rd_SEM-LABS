#include <iostream>
using namespace std;

// Base class for all vehicles
class Vehicle {
public:
    void basicFeatures() {
        cout << "Basic vehicle features" << endl;
    }
};

// Single Inheritance
class Car : virtual public Vehicle {
public:
    void carFeatures() {
        cout << "Car-specific features" << endl;
    }
};

// Multilevel Inheritance
class SportsCar : public Car {
public:
    void sportsCarFeatures() {
        cout << "SportsCar-specific features" << endl;
    }
};

// Hierarchical Inheritance
class Truck : public Car {
public:
    void truckFeatures() {
        cout << "Truck-specific features" << endl;
    }
};

// Multiple Inheritance using virtual inheritance to avoid ambiguity
class ElectricVehicle : public virtual Vehicle {
public:
    void electricFeatures() {
        cout << "Electric vehicle features" << endl;
    }
};

class FuelVehicle : public virtual Vehicle {
public:
    void fuelFeatures() {
        cout << "Fuel vehicle features" << endl;
    }
};

// Multiple inheritance 
class HybridCar : public ElectricVehicle, public FuelVehicle {
public:
    void hybridFeatures() {
        cout << "Hybrid vehicle features (electric + fuel)" << endl;
    }
};

// Hybrid Inheritance
class SportsHybridCar : public SportsCar, public HybridCar {
public:
    void sportsHybridFeatures() {
        cout << "Sports Hybrid Car features" << endl;
    }
};

int main() {
    SportsHybridCar myCar;
    myCar.basicFeatures();       
    myCar.carFeatures();         
    myCar.sportsCarFeatures();   
    myCar.electricFeatures();    
    myCar.fuelFeatures();        
    myCar.hybridFeatures();      
    myCar.sportsHybridFeatures();

    return 0;
}
