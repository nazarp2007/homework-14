#include "LivingSpace.h"

LivingSpace::LivingSpace() :Space(), livingArea(0), state("unknown") {}
LivingSpace::LivingSpace(int size, int rooms, string name, double price, int zone, double livArea, string state) :Space(size, rooms, name, price, zone), livingArea(livArea), state(state) {}

double LivingSpace::finalPrice() {
	double result = Space::finalPrice();

	if (state == "NoRepair")
		result;
	if (state == "Normal")
		result += livingArea * 15;
	if (state == "Lux")
		result += livingArea * 35;
	return result;
}

void LivingSpace::read(istream& is) {
	Space::read(is);
	is >> livingArea >> state;
}

void LivingSpace::write(ostream& os)const {
	Space::write(os);
	os << "\nLiving area: " << livingArea << "\nState: " << state << endl;
}