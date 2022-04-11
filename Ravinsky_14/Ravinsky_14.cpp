#include <iostream>
#include <windows.h>	
#include "person.h"
#include "assistant.h"
#include "professor.h"
#include "student.h"
#include "info.h"
#include <vector>

using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	info info;
	info.addPerson(Person::createPerson(PersonType::STUDENT));
	info.addPerson(Person::createPerson(PersonType::PROFESSOR));
	info.addPerson(Person::createPerson(PersonType::ASSISTANT));
	info.print(cout);
	return 0;
}
