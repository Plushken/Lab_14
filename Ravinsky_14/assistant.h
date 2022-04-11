#pragma once
#include "person.h"
class Assistant :
    public Person
{
public:
    Assistant();
    Assistant(string aSurmane, string aName, int aAge, int aExperience, string aDepartment);
    void setDepartment(string aDepartment);
    string getDepartment() const;
    void readFromConsole() override;
    void writeToStream(ostream&) override;
    void readAssistantFromConsole();
private:
    string department;

    friend ostream& operator << (ostream& os, const Assistant& ap);
};