#include <iostream>
#include "Space.h"
#pragma once
using namespace std;

class CommercialSpace:public Space
{
private:
	string purpose;
public:
	CommercialSpace();
	CommercialSpace(int size, int rooms, string name, double price, int zone, string purpose);
	double finalPrice()override;

	void read(istream& is) override;
	void write(ostream& os)const override;
};

