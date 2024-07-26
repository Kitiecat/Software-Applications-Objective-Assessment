// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;
int main()
{
    cout << "This program was created using C++ by Kylie Taylor (Student ID: 001329025) for SCRIPTING AND PROGRAMMING - APPLICATIONS - C867" << endl;
    Roster classRoster;
    const vector<string> studentData =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Kylie,Taylor,stay535@wgu.edu,27,60,34,40,SOFTWARE" };

    cout << "Creating student roster" << endl;
    int i = 0;
    for (i = 0; i < studentData.size(); i++) {
        classRoster.addByRow(studentData.at(i));
    }

    cout << "Printing student roster." << endl;
    classRoster.printAll();

    cout << "Checking for invalid emails." << endl;
    classRoster.printInvalidEmails();

    cout << "Printing average days in course for all students." << endl;
    vector<Student*> classRosterArray = classRoster.getRoster();
    for (i = 0; i < classRosterArray.size(); i++) {
        Student* student = classRosterArray.at(i);
        classRoster.printAverageDaysInCourse(student->getstudentID());
    }
    
    DegreeProgram degree = DegreeProgram::SOFTWARE;
    cout << "Finding all students with Degree Program: SOFTWARE" << endl;
    classRoster.printByDegreeProgram(degree);
    
    cout << "Attempting to remove student with ID A3" << endl;
    classRoster.remove("A3");
    cout << "Printing student roster." << endl;
    classRoster.printAll();
    cout << "Attempting to remove student with ID A3" << endl;
    classRoster.remove("A3");

    classRoster.~Roster();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
