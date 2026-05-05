#pragma once
#include <string>
#include <iostream>

using namespace std;

class Space
{
protected:
    int size;
    int rooms;
    string name;
    double price;
    int zone;

public:
    Space();
    Space(int size, int rooms, string name, double price, int zone);
    Space(const Space& other);
    virtual ~Space();

    int getSize() const;
    int getRooms() const;
    string getName() const;
    double getPrice() const;
    int getZone() const;

    void setSize(int z);
    void setRooms(int z);
    void setName(const string& z);
    void setPrice(double z);
    void setZone(int z);

    virtual double finalPrice();

    virtual void read(istream& is);
    virtual void write(ostream& os) const;
    string finalRecord() const;

    bool operator<(const Space& other) const;

    friend ostream& operator<<(ostream& out, const Space& a);
    friend istream& operator>>(istream& in, Space& a);

    Space& operator=(const Space& other);
};
