//
//  student.cpp
//  roster2
//
//  Created by Stephen Bruen on 7/5/21.
#include "student.h"
#include <iostream>
using std::cout;
using std::endl;

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, DegreeProgram degreeProgram, int daysInCourse[])
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->degreeProgram = degreeProgram;
    for (int index = 0; index < daysToCompleteArraySize; index++) {
        this->daysInCourse[index] = daysInCourse[index];
    }
}

Student::~Student()
{

}

//Accessors (Getters)
string Student::getStudentID()
{
    return studentID;
}

string Student::getFirstName()
{
    return firstName;
}

string Student::getLastName()
{
    return lastName;
}

string Student::getEmailAddress()
{
    return emailAddress;
}

int Student::getAge()
{
    return age;
}

DegreeProgram Student::getDegreeProgram()
{
    return degreeProgram;
}

int* Student::getDaysInCourse()
{
    return  daysInCourse;
}


//Mutators (Setters)
void Student::setStudentID(string studentID)
{
    this->studentID = studentID;
}
void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}
void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress)
{
    this->emailAddress = emailAddress;
}
void Student::setStudentAge(int studentAge)
{
    this->age = age;
}
void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
    this->degreeProgram = degreeProgram;
}
void Student::setDaysInCourse(int daysInCourse[])
{
    for (int index = 0; index < daysToCompleteArraySize; index++)
    {
        this->daysInCourse[index] = daysInCourse[index];
    }
}

//Method to print
void Student::print()
{
    cout << studentID << "\t";
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Age: " << age << "\t";
    cout << "daysInCourse: {";
    cout << daysInCourse[1] << ", ";
    cout << daysInCourse[2] << ", ";
    cout << daysInCourse[1] << "}\t";
    cout << "Degree Program: ";
    switch (degreeProgram)
    {
    case DegreeProgram::SECURITY:
        cout << "Security";
        break;
    case DegreeProgram::NETWORK:
        cout << "Network";
        break;
    case DegreeProgram::SOFTWARE:
        cout << "Software";
        break;
    }
    cout << endl;
}
