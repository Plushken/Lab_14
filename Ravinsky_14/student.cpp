#include "student.h"

ostream& operator<<(ostream& os, const Student& sp)
{
	os << (const Person&)sp << "Student course: " << sp.course << " Student average score: " << sp.average << "\n";
	return os;
}

Student::Student() : Person()
{
	readStudentFromConsole();
}

Student::Student(string aSurmane, string aName, int aAge, int aExperience, double aAverage_score, int aCourse) :
	Person(aSurmane, aName, aAge, aExperience)
{
	setAverage_score(aAverage_score);
	setCourse(aCourse);
}


void Student::setAverage_score(double aAverage_score)
{
	if (aAverage_score < 1 || aAverage_score > 11)
		throw exception("setPages: invalid pages count!");
	average = aAverage_score;
}

void Student::setCourse(int aCourse)
{
	if (aCourse <= 0 || aCourse > 6)
		throw exception("setCourse: invalid course count!");
	course = aCourse;
}

double Student::getAverage_score() const
{
	return average;
}

int Student::getCourse() const
{
	return course;
}

void Student::writeToStream(ostream& os)
{
	os << (const Person&)*this << "Student course: " << course << " Student average score: " << average << "\n";
}

void Student::readStudentFromConsole()
{
	double t;
	int q;
	cout << "Введите средний балл студента: ";
	while (true) 
	{
		cin >> t;
		if (t>10 || t<1)
			cout << "Вы ошиблись, повторите ввод!\n";
		else 
		{
			try 
			{
				setAverage_score(t);
			}
			catch (exception& ex)
			{
				cout << ex.what();
			}
			break;
		}
	}
	cout << "Введите курс студента: ";
	while (true) 
	{
		cin >> q;
		if (q > 6 || q <= 0)
			cout << "Вы ошиблись, повторите ввод!\n";
		else
		{
			try 
			{
				setCourse(q	);
			}
			catch (exception& ex)
			{
				cout << ex.what();
			}
			break;
		}
	}
	cin.ignore();
}