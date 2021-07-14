//
//  roster.h
//  roster2
//
//  Created by Stephen Bruen on 7/5/21.
#pragma once
#include <string>
#include <iostream>
#include "student.h"

class Roster
{
private:
    int sizeOfArray;
    int numberOfStudents;
    Student** classRosterArray;
public:
    Roster(int sizeOfArray, string studentData[]);
    ~Roster();


    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};

