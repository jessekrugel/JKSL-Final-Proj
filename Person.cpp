#include "Person.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

Person::Person(string input_string) : Person() {
    //TODO: Implement non-default constructor
    string input = input_string;
    stringstream ss(input);
    
    char f;
    char t;
    char a;
    
    ss >> turn;
    ss >> f;
    ss >> currentFloor;
    ss >> t;
    ss >> targetFloor;
    ss >> a;
    ss >> angerLevel;
}

bool Person::tick(int currentTime) {
    if (currentTime % TICKS_PER_ANGER_INCREASE == 0)
    {
        angerLevel++;
    }
    return angerLevel >= MAX_ANGER;
}

void Person::print(ostream &outs) {
    outs << "f" << currentFloor << "t" << targetFloor << "a" << angerLevel;
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Person::Person() {
    turn = 0;
    currentFloor = 0;
    targetFloor = 0;
    angerLevel = 0;
}

int Person::getTurn() const {
    return turn;
}

int Person::getCurrentFloor() const {    
    return currentFloor;
}

int Person::getTargetFloor() const {    
    return targetFloor;
}

int Person::getAngerLevel() const {    
    return angerLevel;
}

ostream& operator<< (ostream& outs, Person p)
{
    p.print(outs);
    return outs;
}
