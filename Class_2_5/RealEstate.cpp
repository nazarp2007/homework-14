#include "RealEstate.h"
#include <fstream>
#include "Exception.h"

RealEstate::RealEstate(string n) :agencyName(n), count(0), properties{ nullptr } {}

RealEstate::~RealEstate() {
	for (int i = 0; i < count; i++)
		delete properties[i];
}

void RealEstate::add(Space* s)
{
	if (count < 50)
		properties[count++] = s;
	else
		cout << "No more space.";
}

void RealEstate::load() {
	ifstream fin("text.txt");
	try {
		if (!(fin.is_open()))
			throw Exception("File corrupt");
	}
	catch (const Exception& e) {
		cout << "Problem with .txt file: ";
	}

	char type;
	while (fin >> type) {
		
			Space* s = nullptr;
		try {
			if (type == 'L')
				s = new LivingSpace();
			else if (type == 'C')
				s = new CommercialSpace();
			else
				throw Exception("Unknown type");
			if (s) {
				s->read(fin);
				add(s);
			}
		}
		catch (Exception& e) {
			cout << "Object couldn't be loaded" << e.what();
			delete s;
		}
	}
	fin.close();
}

void RealEstate::print() {
	cout << "Agency: " << agencyName;
	for (int i = 0;i < count;i++)
		properties[i]->write(cout);
	cout << endl;
}

void RealEstate::findAbsolutes() {
	int min = 0, max = 0;

	for (int i = 0;i < count;i++) {
		if (properties[i]->getSize() < properties[min]->getSize())
			min = i;
		if (properties[i]->getSize() > properties[max]->getSize())
			max = i;
	}
	cout << "Minimal size: " << properties[min]->getSize() << endl;
	cout << "Maximal size: " << properties[max]->getSize() << endl;
}

void RealEstate::findBigOwners() {
	int b = 0;
	for (int i = 0; i < count; i++) {
		string current = properties[i]->getName();
		bool alreadyDone = false;
		for (int k = 0; k < i; k++) {
			if (properties[k]->getName() == current)
			{
				alreadyDone = true;
				break;
			}
		}
		if (alreadyDone) continue;

		int total = 0;
		for (int j = 0; j < count; j++) {
			if (properties[j]->getName() == current) total++;
		}
		if (total > 2) cout << current << ": " << total << " objects" << endl;
		total = b;
	}
	if (b <= 2)
		cout << "No such owners.";
}

double RealEstate::totalSum() {
	double sum = 0;
	for (int i = 0;i < count;i++)
		sum += properties[i]->getPrice();
	return sum;
}

void RealEstate::sort() {
	for (int i = 0;i < count - 1;i++) {
		for (int j = 0;j < count - 1;j++) {
			if (*properties[j + 1] < *properties[j]) {
				Space* temp = properties[j];
				properties[j] = properties[j + 1];
				properties[j + 1] = temp;
			}
		}
	}
}

void RealEstate::split(Space**& m1, int& s1, Space**& m2, int& s2) {
	s1 = 0;
	s2 = 0;

	for (int i = 0; i < count; i++) {
		if (dynamic_cast<LivingSpace*>(properties[i])) s1++;
		else if (dynamic_cast<CommercialSpace*>(properties[i])) s2++;
	}

	m1 = new Space * [s1];
	m2 = new Space * [s2];

	int i1 = 0, i2 = 0;
	for (int i = 0; i < count; i++) {
		if (dynamic_cast<LivingSpace*>(properties[i])) {
			m1[i1++] = properties[i];
		}
		else if (dynamic_cast<CommercialSpace*>(properties[i])) {
			m2[i2++] = properties[i];
		}
	}
	cout << endl;
}