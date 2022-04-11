#pragma once
#include "person.h"
class Professor :
	public Person
{
public:
	Professor();
	Professor(string aSurmane, string aName, int aAge, int aExperience, string aPosition, string aPatronymic);
	void setPosition(string aPosition);
	void setPatronymic(string aPatronymic);
	string getPosition() const;
	string getPatronymic() const;
	void writeToStream(ostream&) override;
	void readProfessorFromConsole();
private:
	string position;
	string patronymic;

	friend ostream& operator << (ostream& os, const Professor& pp);
};