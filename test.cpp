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
    cout << "Now testing the Person class!" << endl;
    //Default Constuctor
    Person guy;
    cout << "Expected: f0t0a0, Actual: " << guy << endl;
    
    //Non-default Constructor
    Person dude = Person("3f4t8a1");
    cout << "Expected: f4t8a1, Actual: "<< dude << endl;
}

void test_Elevator()
{
    
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
}
