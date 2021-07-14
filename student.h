//
//  student.h
//  roster2
//
//  Created by Stephen Bruen on 7/5/21.
//
#pragma once

#include "degree.h"
#include <string>
using std::string;

class Student
{
public:
    const static int daysToCompleteArraySize = 3;

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    DegreeProgram degreeProgram;
    int daysInCourse[daysToCompleteArraySize];

public:
    // Constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, DegreeProgram degreeProgram, int daysInCourse[]);

    //Accessors (Getters)
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    DegreeProgram getDegreeProgram();
    int* getDaysInCourse();

    //Mutators (Setters)
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setStudentAge(int studentAge);
    void setDegreeProgram(DegreeProgram degreeProgram);
    void setDaysInCourse(int daysInCourse[]);

    //Method to print
    void print();

    //Destructor
    ~Student();
};

