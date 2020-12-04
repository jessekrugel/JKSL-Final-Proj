#include <iostream>
#include <fstream>
#include "Utility.h"
#include "Game.h"

using namespace std;

// write your test functions here
void test_Person();
void test_Elevator();
void test_Floor();

void start_tests() {
    test_Person();
    test_Elevator();
    test_Floor();
}

void test_Person()
{
    //Default Constuctor
    Person guy;
    cout << "Expected: f0t0a0, Actual: " << guy << endl;
    
    //Non-default Constructor
    Person dude = Person("3f4t8a1");
    cout << "Expected: f4t8a1, Actual: "<< dude << endl;
}

void test_Elevator()
{
    //Default COnstructor
    Elevator Elevator1;
    cout << "Expected: 000, Actual: ";
    cout << Elevator1.getCurrentFloor() << Elevator1.isServicing()
         << Elevator1.getTargetFloor() << endl;
    
    //Tick
    Elevator1.setCurrentFloor(3);
    Elevator1.serviceRequest(0);
    Elevator1.isServicing();
    Elevator1.tick(4);
    cout << "Expected: 21, Actual: " << Elevator1.getCurrentFloor()
        << Elevator1.isServicing() << endl;
    
    
    
}

void test_Floor()
{
    
}
