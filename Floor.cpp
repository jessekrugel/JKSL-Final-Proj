#include "Floor.h"
#include <algorithm>

using namespace std;

int Floor::tick(int currentTime) {
    int exploded[numPeople];
    int index = 0;
    for (int i = 0; i < numPeople; i++)
    {
        if (people[i].tick(currentTime))
        {
            exploded[index] = i;
            index++;
        }
    }
    removePeople(exploded, index);
    return index;
}

void Floor::addPerson(Person p, int request) {
    if (numPeople < MAX_PEOPLE_PER_FLOOR) {
            people[numPeople] = p;
            numPeople++;
    }
    if (request > 0){
        hasUpRequest = true;
        hasDownRequest = false;
    }
    else if (request < 0){
        hasDownRequest = true;
        hasUpRequest = false;
    }
}

void Floor::removePeople(int indicesToRemove[MAX_PEOPLE_PER_FLOOR],
                         int numPeopleToRemove) {
    for (int i = 0; i < numPeopleToRemove-1; i++)
    {
        if (indicesToRemove[i] > indicesToRemove[i+1])
        {
            int temp = indicesToRemove[i];
            indicesToRemove[i] = indicesToRemove[i+1];
            indicesToRemove[i+1] = temp;
        }
    }
    int removeCounter = 0;
    for (int i = 0; i < numPeopleToRemove-1; i++)
    {
        int personToRemove = indicesToRemove[i];
        for (int j = personToRemove - removeCounter; j < numPeople - 1; j++)
        {
            people[j] = people[j + 1];
        }
        removeCounter++;
        numPeople--;
    }
    resetRequests();
}

void Floor::resetRequests() {
    for (int i = 0; i < numPeople; i++) {
        if (people[i].getTargetFloor() - people[i].getCurrentFloor() > 0) {
            hasUpRequest = true;
            hasDownRequest = false;
        }
        else if (people[i].getTargetFloor() - people[i].getCurrentFloor() < 0) {
            hasDownRequest = true;
            hasUpRequest = false;
        }
    }

}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Floor::Floor() {
    hasDownRequest = false;
    hasUpRequest = false;
    numPeople = 0;
}

void Floor::prettyPrintFloorLine1(ostream& outs) const {
	string up = "U";
	outs << (hasUpRequest ? up : " ") << " ";
	for (int i = 0; i < numPeople; ++i){
		outs << people[i].getAngerLevel();
		outs << ((people[i].getAngerLevel() < MAX_ANGER) ? "   " : "  ");
	}
	outs << endl;
}

void Floor::prettyPrintFloorLine2(ostream& outs) const {
	string down = "D";
	outs << (hasDownRequest ? down : " ") << " ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "o   ";
	}
	outs << endl;
}

void Floor::printFloorPickupMenu(ostream& outs) const {
	cout << endl;
	outs << "Select People to Load by Index" << endl;
	outs << "All people must be going in same direction!";
	/*  O   O
	// -|- -|-
	//  |   |
	// / \ / \  */
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " O   ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "-|-  ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " |   ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "/ \\  ";
	}
	outs << endl << "INDEX:        ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << i << "   ";
	}
	outs << endl << "ANGER:        ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << people[i].getAngerLevel() << "   ";
	}
	outs << endl << "TARGET FLOOR: ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << people[i].getTargetFloor() << "   ";
	}
}

void Floor::setHasUpRequest(bool hasRequest) {
    hasUpRequest = hasRequest;
}

bool Floor::getHasUpRequest() const {
	return hasUpRequest;
}

void Floor::setHasDownRequest(bool hasRequest) {
    hasDownRequest = hasRequest;
}

bool Floor::getHasDownRequest() const {
	return hasDownRequest;
}

int Floor::getNumPeople() const {
    return numPeople;
}

Person Floor::getPersonByIndex(int index) const {
    return people[index];
}
