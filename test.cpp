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
    Person guy;
    cout << guy << endl;
    Person dude = Person("3f4t8a1");
    cout << dude << endl;
}
