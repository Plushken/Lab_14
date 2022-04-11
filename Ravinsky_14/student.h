#pragma once
#include "person.h"
class Student :
    public Person
{
public:
    Student();
    Student(string  aSurmane, string aName, int aAge, int aExperience, double aAverage_score, int aCourse);
    void setAverage_score(double aAverage_score);
    void setCourse(int aCourse);
    double getAverage_score() const;
    int getCourse() const;
    void writeToStream(ostream&) override; 
    void readStudentFromConsole();
private:
    int course;
    double average;

    friend ostream& operator << (ostream& os, const Student& sp);
};