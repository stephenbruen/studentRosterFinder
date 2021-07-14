//  Created by Stephen Bruen on 7/4/21.
//
#include "roster.h"
#include "student.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

Roster::Roster(int sizeOfArray, string studentData[])
{
    this->sizeOfArray = sizeOfArray;
    this->numberOfStudents = sizeOfArray;
    this->classRosterArray = new Student * [sizeOfArray];

    int index = 0;
    while (index < sizeOfArray)
    {
        vector<string> fields;
        stringstream streamInput(studentData[index]);
        string field;
        while (getline(streamInput, field, ','))
        {
            fields.push_back(field);
        }
        DegreeProgram program = DegreeProgram::SECURITY;
        if (fields[8] == "SECURITY")
            program = DegreeProgram::SECURITY;
        else if (fields[8] == "NETWORK")
            program = DegreeProgram::NETWORK;
        else if (fields[8] == "SOFTWARE")
            program = DegreeProgram::SOFTWARE;

        int days[3] = { stoi(fields[5]), stoi(fields[6]), stoi(fields[7]) };
        classRosterArray[index] = new Student(
            fields[0],
            fields[1],
            fields[2],
            fields[3],
            stoi(fields[4]),
            DegreeProgram::SECURITY,
            days
        );
    }
}



void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
    int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
    int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[sizeOfArray] = new Student(studentID, firstName, lastName, emailAddress, age, degreeprogram, days);
    numberOfStudents++;
}

void Roster::remove(string studentID)
{
    bool IDexists = false;
    for (int index = 0; index < numberOfStudents; index++) {
        if (this->classRosterArray[index]->getStudentID() == studentID) {
            IDexists = true;
            classRosterArray[index] = classRosterArray[numberOfStudents - 1];
            numberOfStudents--;
            cout << "Student ID " << studentID << " has been removed." << endl;
        }
    }
    if (!IDexists)
    {
        cout << "Student not found." << endl;
    }

}

void Roster::printAverageDaysInCourse(string studentID)
{
    bool IDexists = false;
    for (int index = 0; index < numberOfStudents; index++) {
        if (this->classRosterArray[index]->getStudentID() == studentID) {
            IDexists = true;
            int* days = classRosterArray[index]->getDaysInCourse();
            int average = (days[0] + days[1] + days[2]) / 3;
            cout << "Student ID " << studentID << " spent an average of" << average << " days in each course." << endl;
        }
    }
    if (!IDexists)
    {
        cout << "Student not found." << endl;
    }

}

void Roster::printAll()
{
    cout << "Printing";
    for (int index = 0; index < numberOfStudents; index++)
    {
        classRosterArray[index]->print();
    }
}

void Roster::printInvalidEmails()
{
    bool invalidFound = false;
    for (int index = 0; index < numberOfStudents; index++)
    {
        string emailAddress = this->classRosterArray[index]->getEmailAddress();
        if (emailAddress.find('@') == string::npos)
        {
            cout << "The email: " << emailAddress << " is invalid" << endl;
            cout << "It is missing an '@' character." << endl;
            invalidFound = true;
        }
        else if (emailAddress.find('.') == string::npos)
        {
            cout << "The email: " << emailAddress << " is invalid" << endl;
            cout << "It is missing a '.' character." << endl;
            invalidFound = true;
        }
        else if (emailAddress.find(' ') != string::npos)
        {
            cout << "The email: " << emailAddress << " is invalid" << endl;
            cout << "Emails cannot have ' ' characters." << endl;
            invalidFound = true;
        }
    }
    if (!invalidFound)
    {
        cout << "No invalid emails found.";
    }

}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    bool degreeFound = false;
    for (int index = 0; index < numberOfStudents; index++)
    {
        if (classRosterArray[index]->getDegreeProgram() == degreeProgram)
        {
            classRosterArray[index]->print();
            degreeFound = true;
        }
    }


}

Roster::~Roster()
{
    delete[] classRosterArray;
}
