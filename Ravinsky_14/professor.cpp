#include "professor.h"

ostream& operator<<(ostream& os, const Professor& pp)
{
	os << (const Person&)pp << " Professor Patronymic: " << pp.patronymic <<  " Professor position: " << pp.position << "\n";
	return os;
}

Professor::Professor() : Person()
{
	readProfessorFromConsole();
}

Professor::Professor(string aSurmane, string aName, int aAge, int aExperience, string aPosition, string aPatronymic) :
	Person(aSurmane,aName,aAge, aExperience)
{
	setPosition(aPosition);
	setPatronymic(aPatronymic);
}

void Professor::setPosition(string aPosition)
{
	position = aPosition;
}

void Professor::setPatronymic(string aPatronymic)
{
	patronymic = aPatronymic;
}

string Professor::getPosition() const
{
	return position;
}

string Professor::getPatronymic() const
{
	return patronymic;
}

void Professor::writeToStream(ostream& os)
{
	os << (const Person&)*this << " Professor Patronymic: " << patronymic  << " Professor position:  " << position << "\n";

}

void Professor::readProfessorFromConsole()
{
	cin.ignore();
	string s;
	cout << "Введите Отчество преподавателя: ";
	getline(cin, s);
	setPatronymic(s);
	cout << "Введите должность преподавателя: ";
	getline(cin, s);
	setPosition(s);
	cin.ignore();
}