#include <iostream>
#include "Space.h"

#pragma once
using namespace std;

class LivingSpace:public Space
{
private:
	double livingArea;
	string state;
public:
	LivingSpace();
	LivingSpace(int size, int rooms, string name, double price, int zone, double livingArea, string state);

	double finalPrice()override;

	void read(istream& is) override;
	void write(ostream& os)const override;

	
};

