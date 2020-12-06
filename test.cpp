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
    //test_Person();
    //test_Elevator();
    test_Floor();
    //test_Building();
    //test_Move();
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
    Floor floor2;
    floor2.addPerson(p0, 4);
    floor2.addPerson(p1, -2);
    floor2.addPerson(p2, 1);
    floor2.addPerson(p3, 3);
    floor2.addPerson(p4, -3);
    int remove2[3] = {0,4,2};
    floor2.removePeople(remove2, 3);
    cout << "Testing non-sorted" << endl;
    cout << "Expected:" << endl << p1 << endl << p3 << endl
         << "Actual:" << endl;
    for (int i = 0; i < floor2.getNumPeople(); i++)
    {
        cout << floor2.getPersonByIndex(i) << endl;
    }
    cout << endl;
    
    Person p10 = Person("3f4t8a0");
    Person p11 = Person("5f4t2a1");
    Person p12 = Person("5f4t5a2");
    Person p13 = Person("5f4t7a3");
    Person p14 = Person("5f4t1a4");
    Person p15 = Person("5f4t1a5");
    Person p16 = Person("5f4t1a6");
    Person p17 = Person("5f4t1a7");
    Person p18 = Person("5f4t1a8");
    Floor floor3;
    floor3.addPerson(p10, 4);
    floor3.addPerson(p11, -2);
    floor3.addPerson(p12, 1);
    floor3.addPerson(p13, 3);
    floor3.addPerson(p14, -3);
    floor3.addPerson(p15, -3);
    floor3.addPerson(p16, -3);
    floor3.addPerson(p17, -3);
    floor3.addPerson(p18, -3);
    //int remove3[4] = {0,3,7,8};
    int remove6[4] = {3,2,1,5};
    floor3.removePeople(remove6, 4);
    cout << "Testing blocks" << endl;
    for (int i = 0; i < floor3.getNumPeople(); i++)
    {
        cout << floor3.getPersonByIndex(i) << endl;
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
    
    Move move1 = Move("e1f3");
    cout << "Expected: 13, Actual: ";
    cout << move1.getElevatorId() << move1.getTargetFloor() << endl;
    
    Move move2 = Move("e3p");
    cout << "Expected: 31, Actual: ";
    cout << move2.getElevatorId() << move2.isPickupMove() << endl;
    
    Move move3 = Move("E5p");
    cout << "Expected: 51, Actual: ";
    cout << move3.getElevatorId() << move3.isPickupMove() << endl;
    
    Move move4 = Move("S");
    cout << "Expected: 1, Actual: ";
    cout << move4.isSaveMove() << endl;
    
    Move move5 = Move("Q");
    cout << "Expected: 1, Actual: ";
    cout << move5.isQuitMove() << endl;
    
    Move move6 = Move("s");
    cout << "Expected: 1, Actual: ";
    cout << move6.isSaveMove() << endl;
    
    Elevator ele1 = Elevator();
    ele1.setCurrentFloor(1);
    Elevator ele2 = Elevator();
    ele2.setCurrentFloor(2);
    Elevator elevators[] = {ele1, ele2};
    cout << move1.isValidMove(elevators) << endl;
}
