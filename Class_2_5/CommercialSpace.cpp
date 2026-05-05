#include "CommercialSpace.h"

CommercialSpace::CommercialSpace() :Space(), purpose("unknown") {}
CommercialSpace::CommercialSpace(int size, int rooms, string name, double price, int zone, string purpose) :Space(size,rooms,name,price,zone), purpose(purpose) {}

double CommercialSpace::finalPrice() {
	double result = Space::finalPrice();
	if (purpose == "Office")
		result *= 1.05;
	if (purpose == "Warehouse")
		result *= 1.03;
	if (purpose == "Store")
		result *= 1.13;
	if (purpose == "Industrial")
		result *= 1.17;
	return result;
}

void CommercialSpace::read(istream& is) {
	Space::read(is);
	is >> purpose;
}

void CommercialSpace::write(ostream& os)const {
	Space::write(os);
	os << "\nPurpose: " << purpose;
	cout << endl;
}