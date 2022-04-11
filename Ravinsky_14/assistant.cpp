#include "assistant.h"

ostream& operator<<(ostream& os, const Assistant& ap)
{
	os << (const Person&)ap << "Assistant department: " << ap.department <<"\n";
	return os;
}

Assistant::Assistant() : Person()
{
	readAssistantFromConsole();
}

Assistant::Assistant(string aSurmane, string aName, int aAge, int aExperience, string aDepartment) :
	Person(aSurmane, aName, aAge, aExperience)
{
	void setDepartment(string aDepartment);
}

void Assistant::setDepartment(string aDepartment)
{
	department = aDepartment;
}

string Assistant::getDepartment() const
{
	return department;
}

void Assistant::readFromConsole()
{
	Person::readFromConsole();
	readAssistantFromConsole();
}

void Assistant::writeToStream(ostream& os)
{
	os << (const Person&)*this << "Assistant department: " << department << "\n";

}

void Assistant::readAssistantFromConsole()
{
	cin.ignore();
	string s;
	cout << "Введите кафедру лаборанта: ";
	getline(cin, s);
	setDepartment(s);
	cin.ignore();
}