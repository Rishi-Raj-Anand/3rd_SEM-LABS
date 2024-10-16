#include<iostream>
using namespace std;

// Single Inheritance
class Animal {
    
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking..." << endl;
    }
};

// Multiple Inheritance
class Flyer {
public:
    void fly() {
        cout << "Flying..." << endl;
    }
};

class Bird : public Animal, public Flyer {
public:
    void chirp() {
        cout << "Chirping..." << endl;
    }
};

// Multilevel Inheritance
class Mammal : public Animal {
public:
    void walk() {
        cout << "Walking..." << endl;
    }
};

class Human : public Mammal {
public:
    void talk() {
        cout << "Talking..." << endl;
    }
};

// Hierarchical Inheritance
class Vehicle {
public:
    void move() {
        cout << "Moving..." << endl;
    }
};

class Car : public Vehicle {
public:
    void drive() {
        cout << "Driving..." << endl;
    }
};

class Truck : public Vehicle {
public:
    void haul() {
        cout << "Hauling..." << endl;
    }
};

int main() {

    cout<<"Dog"<<endl;
    Dog dog;
    dog.eat();
    dog.bark();
    cout<<endl;

    cout<<"Bird "<<endl;
    Bird bird;
    bird.eat();
    bird.fly();
    bird.chirp();
    cout<<endl;
    
    cout<<"Human"<<endl;
    Human human;
    human.eat();
    human.walk();
    human.talk();
    cout<<endl;

    cout<<"Car"<<endl;
    Car car;
    car.move();
    car.drive();
    cout<<endl;

    cout<<"Truck"<<endl;
    Truck truck;
    truck.move();
    truck.haul();
    cout<<endl;

    return 0;
}
