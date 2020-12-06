#include <iostream>
#include <fstream>
#include "Utility.h"
#include "Game.h"

using namespace std;

// write your test functions here
void test_Person();
void test_Elevator();
void test_Floor();
void test_Building();
void test_Move();

void start_tests() {
    test_Person();
    test_Elevator();
    test_Floor();
    test_Building();
    test_Move();
}

void test_Person()
{
    cout << "Now testing the Person class!" << endl;
    //Default Constuctor
    Person guy;
    cout << "Expected: f0t0a0, Actual: " << guy << endl;
    
    //Non-default Constructor
    Person dude = Person("3f4t8a1");
    cout << "Expected: f4t8a1, Actual: "<< dude << endl;
    cout << endl;
}

void test_Elevator()
{
    //Default COnstructor
    cout << "Now testing the Elevator class!" << endl;
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
    cout << endl;
}

void test_Floor()
{
    cout << "Now testing the Floor class!" << endl;
    Floor floor;
    Person p0 = Person("3f4t8a1");
    Person p1 = Person("5f4t2a4");
    Person p2 = Person("5f4t5a2");
    Person p3 = Person("5f4t7a5");
    Person p4 = Person("5f4t1a4");
    floor.addPerson(p0, 4);
    floor.addPerson(p1, -2);
    floor.addPerson(p2, 1);
    floor.addPerson(p3, 3);
    floor.addPerson(p4, -3);
    
    cout << "Expected:" << endl << p0 << endl << p1 << endl << p2 << endl
         << p3 << endl << p4 << endl << "Actual:" << endl;
    for (int i = 0; i < floor.getNumPeople(); i++)
    {
        cout << floor.getPersonByIndex(i) << endl;
    }
    int remove[3] = {0,2,4};
    floor.removePeople(remove, 3);
    cout << "Expected:" << endl << p1 << endl << p3 << endl
         << "Actual:" << endl;
    for (int i = 0; i < floor.getNumPeople(); i++)
    {
        cout << floor.getPersonByIndex(i) << endl;
    }
    cout << endl;
}

void test_Building()
{
    cout << "Now testing the Building class!" << endl;
    
    //Testing spawnPerson()
    Building building;
    Floor floor;
    Person p0 = Person("3f4t8a1");
    Person p1 = Person("5f4t2a4");
    Person p2 = Person("5f4t5a2");
    Person p3 = Person("5f4t7a5");
    Person p4 = Person("5f4t1a4");
    floor.addPerson(p0, 4);
    floor.addPerson(p1, -2);
    floor.addPerson(p2, 1);
    floor.addPerson(p3, 3);
    building.spawnPerson(p4);
    
    for (int i = 0; i < floor.getNumPeople(); i++)
    {
        cout << floor.getPersonByIndex(i) << endl;
    }
    cout << endl;
    
    
    
    
    
}
void test_Move()
{
    //Default Constructor
    cout << "Now testing the Move class!" << endl;
    Move move;
    cout << "Expected: -1-100, Actual: ";
    cout << move.getElevatorId() << move.getTargetFloor()
         << move.getNumPeopleToPickup() << move.getTotalSatisfaction() << endl;
}
