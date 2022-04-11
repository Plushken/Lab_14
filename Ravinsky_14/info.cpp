#include "info.h"
unsigned info::nextID = 0;
info::info() : personID(nextID++)
{

}

info::~info()
{
	cout << endl << "THE END..." << endl;
	for (auto x : persons)
		delete x;
}

void info::addPerson(Person* p)
{
		persons.push_back(p);
}

unsigned info::getpersonID() const
{
	return personID;
}

void info::print(ostream& os)
{
	for (int i = 0; i < persons.size(); i++)
		persons[i]->writeToStream(os);
}

