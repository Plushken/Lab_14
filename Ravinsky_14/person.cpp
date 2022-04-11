#include "person.h"
#include "assistant.h"
#include "professor.h"
#include "student.h"
#include <cassert>
unsigned Person::nextID = 0;

Person* Person::createPerson(PersonType pt)
{
	Person* p = nullptr;
	switch (pt) {
	case PersonType::STUDENT:
		p = new Student();
		break;
	case PersonType::PROFESSOR:
		p = new Professor();
		break;
	case PersonType::ASSISTANT:
		p = new Assistant();
		break;
	default:
		assert(false);
	}
	return p;
}

Person::Person(string aSurmane, string aName, int aAge, int aExperience) : ID(nextID++)
{
	setName(aName);
	setSurmane(aSurmane);
	setAge(aAge);
	setYearExperience(aExperience);
}

void Person::setSurmane(string aSurmane)
{
	surname = aSurmane;
}

void Person::setName(string aName)
{
	name = aName;
}

void Person::setAge(int aAge)
{
	if (aAge < 1920 || aAge > 2005)
		throw exception("setAge: invalid age year!");
	age = aAge;
}

void Person::setYearExperience(int aExperience)
{
	if (aExperience <= 0 || aExperience > 70)
		throw exception("setYearRelease: invalid experience year!");
	yearExperience = aExperience;
}

string Person::getSurmane() const
{
	return surname;
}

string Person::getName() const
{
	return name;
}

int Person::getYearExperience() const
{
	return yearExperience;
}

int Person::getAge() const
{
	return age;
}

Person::Person(const Person& other) : ID(nextID++)
{
	clone(other);
}

void Person::operator=(const Person& other)
{
	clone(other);
}

Person::Person() : ID(nextID++)
{
	readFromConsole();
}

unsigned Person::getID() const
{
	return ID;
}

void Person::readFromConsole()
{
	int t;
	string s;
	cout << "Введите фамилию: ";

	getline(cin, s);
	setSurmane(s);
	cout << "Введите имя: ";
	getline(cin, s);
	setName(s);
	cout << "Введите год рождения: ";
	while (true) 
	{
		cin >> t;
		if (t > 2005 || t <1920)
			cout << "Вы ошиблись, повторите ввод!\n";
		else
		{
			try
			{
				setAge(t);

			}
			catch (exception& ex)
			{
				cout << ex.what();
			}
			break;
		}
			
	}
	cout << "Введите стаж работы: ";
	while (true)
	{
		cin >> t;
		if (t > 70 || t <= 0)
			cout << "Вы ошиблись, повторите ввод!\n";
		else
		{
			try
			{
				setYearExperience(t);

			}
			catch (exception& ex)
			{
				cout << ex.what();
			}
			break;
		}
	}
}

void Person::writeToStream(ostream& os)
{
	os << *this;
}

void Person::clone(const Person& other)
{
	name = other.name;
	surname = other.surname;
	age = other.age;
	yearExperience = other.yearExperience;
}

ostream& operator<<(ostream& os, const Person& p)
{
	os << "Person ID: " << p.ID << " Surname: " << p.surname << " Name: " << p.name << " Year of Experience: " << p.yearExperience << " Year of birth: " << p.age << "\n";
	return os;
}