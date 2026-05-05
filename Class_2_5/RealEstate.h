#include <iostream>
#include <string>
#include <stdexcept>
#include "Space.h"
#include "LivingSpace.h"
#include "CommercialSpace.h"
#pragma once
using namespace std;

class RealEstate {
private:
    string agencyName;
    Space* properties[50] = { nullptr };
    int count;
public:
    RealEstate(string name);
    ~RealEstate();

    void add(Space* s);
    void load();
    void print();

    void findAbsolutes();
    void findBigOwners();
    double totalSum();

    void sort();
    void split(Space**& m1, int& s1, Space**& m2, int& s2);
};

