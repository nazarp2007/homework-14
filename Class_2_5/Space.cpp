#include "Space.h"
#include <string>
#include <cmath>
#include "Exception.h"
using namespace std;

Space::Space(): size(0), rooms(0), name("nobody"), price(0), zone(0){}

Space::Space(int size, int rooms, string name, double price, int zone) : size(size), rooms(rooms), name(name), price(price), zone(zone) {}

Space::Space(const Space& other): size(other.size),rooms(other.rooms),name(other.name),price(other.price),zone(other.zone){}

int Space::getSize() const {
    return size;
}

int Space::getRooms() const {
    return rooms;
}

string Space::getName() const {
    return name;
}

double Space::getPrice() const {
    return price;
}

int Space::getZone() const {
    return zone;
}

void Space::setSize(int z) {
    size = z;
}

void Space::setRooms(int z) {
    rooms = z;
}

void Space::setName(const string& z) {
    name = z;
}

void Space::setPrice(double z) {
    price = z;
}

void Space::setZone(int z) {
    zone = z;
}


double Space::finalPrice()
{
    double fP;
   /* if (zone == 1)
        price *= 1.2;
    else if (zone == 2)
        price *= 1.1;*/
    if (size > 150)
        fP = price * size - ((price * size) * 0.05);
    else
        fP = price * size;
    if (zone == 1)
        fP = price * 1.2;
    else if (zone == 2)
        fP = price * 1.1;
    else if (zone == 3)
        fP = price * 1.3;
    else if (zone == 4) {
        fP = price;
    }
    return fP;
}

string Space::finalRecord() const
{
    string a;

    a = "Name: " + name;
    a += ", rooms: " + to_string(rooms);
    a += ", price: " + to_string(price);
    a += ", zone: " + to_string(zone);

    return a;
}

istream& operator>>(istream& in, Space& a)
{
    a.read(in);
    return in;
}

ostream& operator<<(ostream& out, const Space& a)
{
    a.write(out);
    return out;
}

bool Space::operator<(const Space& other) const
{
    return size < other.size;
}

Space& Space::operator=(const Space& other)
{
    if (this != &other) 
    {
        size = other.size;
        rooms = other.rooms;
        name = other.name;
        price = other.price;
        zone = other.zone;
    }
    return *this;
}

void Space::read(istream& is) {
    try {
        is >> size >> rooms >> name >> price >> zone;
        if (size <= 0)
            throw Exception("Size is too small");
    }
    catch (Exception& e) {
        cout << "Couldn't enter file element: " << e.what();
    }
}

void Space::write(ostream& os)const {
    os << "Name: " << name
        << "\nSize: " << size
        << "\nRooms: " << rooms
        << "\nPrice: " << price
        << "\nZone: " << zone;
}

Space::~Space() {};