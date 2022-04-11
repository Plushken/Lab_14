#pragma once
#include "person.h"
#include <vector>
using namespace std;
class info
{
public:
    info();
    virtual ~info();
    void addPerson(Person* p);
    unsigned getpersonID() const;
    void print(ostream&);
private:
    vector <Person*> persons;
    static unsigned nextID;
    unsigned personID;
};