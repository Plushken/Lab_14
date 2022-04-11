#pragma once
#include <string>
#include <iostream>
using namespace std;
constexpr auto t1 = __LINE__;
enum class PersonType 
{
	STUDENT = 1,
	PROFESSOR,
	ASSISTANT
};
constexpr auto n_types = __LINE__ - t1 - 3;
class Person
{
public:
	virtual ~Person() {}
	Person(string aSurmane, string aName, int aAge, int aExperience);
	Person(const Person& other);
	void operator = (const Person& other);
	Person();
	void setSurmane(string aSurmane);
	void setName(string aName);
	void setAge(int aAge);
	void setYearExperience(int aExperience);
	string getSurmane() const;
	string  getName() const;
	int getYearExperience() const;
	int getAge() const;
	unsigned getID() const;
	virtual void readFromConsole();
	virtual void writeToStream(ostream&);
	static Person* createPerson(PersonType);
protected:
	unsigned ID;
	string surname;
	string name;
	int yearExperience;
	int age;
	void clone(const Person& other);
	static unsigned nextID;
	friend ostream& operator << (ostream& os, const Person& p);
};