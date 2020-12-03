#include <iostream>
#include <fstream>
#include "Utility.h"
#include "Game.h"

using namespace std;

// write your test functions here
void test_Person();

void start_tests() {
    test_Person();
}

void test_Person()
{
    //Default Constuctor
    Person guy;
    cout << guy << endl;
}
