#pragma once
#include "student.h"
#include "degree.h"

class Roster {
public:
	void add(
		std::string studentID,
		std::string firstName,
		std::string lastName,
		std::string emailAddress,
		int age, 
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeprogram
	);

	void addByRow(string row);
	void addToRoster(Student* student);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
	std::vector<Student*> getRoster();
private:
	std::vector<Student*> classRosterArray;
};