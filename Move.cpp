#include <cmath>
#include <sstream>
#include <stdio.h>      
#include <stdlib.h>
#include "Move.h"

using namespace std;

Move::Move(string commandString) : Move() {
    if (commandString == "")
    {
        isPass = true;
    }
    char firstLetter = commandString.at(0);
    // converts upper case letters to lower
    if (firstLetter >= 65)
    {
        firstLetter += 32;
    }
    if (firstLetter == 's')
    {
        isSave = true;
    }
    else if (firstLetter == 'q')
    {
        isQuit = true;
    }
    
    int elevatorNum = commandString.at(1);
    char secondLetter = commandString.at(2);
    // converts upper case letters to lower
    if (secondLetter >= 65)
    {
        secondLetter += 32;
    }
    if (secondLetter == 'p')
    {
        isPickup = true;
        elevatorId = elevatorNum;
    }
    else if (secondLetter == 'f')
    {
        elevatorId = elevatorNum;
        targetFloor = commandString.at(3);
    }
}

bool Move::isValidMove(Elevator elevators[NUM_ELEVATORS]) const {
    if (isPass || isSave || isQuit)
    {
        return true;
    }
    if (isPickup || (elevatorId != -1))
    {
        if ((elevatorId >= 0) && (elevatorId < NUM_ELEVATORS) && elevators[elevatorId].isServicing())
        {
            return true;
        }
    }
    return false;
}

void Move::setPeopleToPickup(const string& pickupList, const int currentFloor, const Floor& pickupFloor) {

    numPeopleToPickup = 0;
    totalSatisfaction = 0;
    
    for (int i = 0; i < pickupList.length(); i++) {
        int index = pickupList.at(i);
        peopleToPickup[i] += index;
        numPeopleToPickup++;
        
        Person person1 = pickupFloor.getPersonByIndex(index);
        int angerLevel = person1.getAngerLevel();
        totalSatisfaction += MAX_ANGER - angerLevel;
    }
    
    int furthestTravel = 0;
    
    for (int j = 0; j < numPeopleToPickup; j++){
        Person person = pickupFloor.getPersonByIndex(j);
        int targetFloor = person.getTargetFloor();
        int difference = 0;
        difference = abs(targetFloor - currentFloor);
        if (difference > furthestTravel){
            furthestTravel = difference;
        }
        setTargetFloor(furthestTravel);
    }
    
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Move::Move() {
    elevatorId = -1;
    targetFloor = -1;
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
	isPass = false;
    isPickup = false;
    isSave = false;
    isQuit = false;
}

bool Move::isPickupMove() const {
    return isPickup;
}

bool Move::isPassMove() const {
	return isPass;
}

bool Move::isSaveMove() const {
	return isSave;
}

bool Move::isQuitMove() const {
	return isQuit;
}

int Move::getElevatorId() const {
    return elevatorId;
}

int Move::getTargetFloor() const {
    return targetFloor;
}

int Move::getNumPeopleToPickup() const {
    return numPeopleToPickup;
}

int Move::getTotalSatisfaction() const {
    return totalSatisfaction;
}

void Move::setTargetFloor(int inTargetFloor) {
    targetFloor = inTargetFloor;
}

void Move::copyListOfPeopleToPickup(int newList[MAX_PEOPLE_PER_FLOOR]) const {
    for (int i = 0; i < numPeopleToPickup; ++i) {
        newList[i] = peopleToPickup[i];
    }
}
