//
//  main.cpp
//  roster2
//
//  Created by Stephen Bruen on 7/4/21.
//
#include <iostream>
#include "student.h"
#include "roster.h"

using namespace std;
// main function in main.cpp
int main()
{
    // studentData Table with personal information
    string studentData[] = {
                        // student rosters
                        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                        "A5,Stephen,Bruen,sbruen@wgu.edu,25,35,45,35,SOFTWARE"
                };
    // F1 Print out to screen
    cout << "C867 - Scripting & Programming: Applications" << endl;
       cout << "Language - C++" << endl;
       cout << "Student ID - #######" << endl;
       cout << "Name - Stephen Bruen" << endl;
       cout << endl;
    // F2 / F3 Class roster call
    Roster* classRoster = new Roster(5, studentData);
    
    // F4 print rosters
    classRoster->printAll();
    classRoster->printInvalidEmails();
    // prints students by degree
    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    // prints average days in course by student id
    classRoster->printAverageDaysInCourse("A1");
    classRoster->printAverageDaysInCourse("A2");
    classRoster->printAverageDaysInCourse("A3");
    classRoster->printAverageDaysInCourse("A4");
    classRoster->printAverageDaysInCourse("A5");
    // removal of students
    classRoster->remove("A3");
}
