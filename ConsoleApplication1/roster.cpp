#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <regex>
#include "student.h"
#include "roster.h"
#include "degree.h"

using namespace std;


Roster::~Roster() {
	for (Student* student : this->classRosterArray) {
		delete student;
	}
	this->classRosterArray.clear();
}
void Roster::addByRow(string row) {
	Student* student = new Student(row);
	///this->classRosterArray.push_back(student);
	this->addToRoster(student);
}

void Roster::add(
	std::string studentID, 
	std::string firstName,
	std::string lastName,
	std::string emailAddress,
	int age, 
	int daysInCourse1, 
	int daysInCourse2, 
	int daysInCourse3, 
	DegreeProgram degreeprogram
	) {
	Student* student = new Student(
		studentID,
		firstName,
		lastName,
		emailAddress,
		age,
		daysInCourse1,
		daysInCourse2,
		daysInCourse3,
		degreeprogram
	);
	///this->classRosterArray.push_back(student);
	addToRoster(student);
}

void Roster::addToRoster(Student* student) {
	classRosterArray.push_back(student);
}

void Roster::remove(string studentID) {

	int i = 0;
	for (i = 0; i < classRosterArray.size(); i++) {
		Student* student = classRosterArray.at(i);
		if ( ( studentID.compare( student->getstudentID() ) ) == 0) {
			for (i = i; i < classRosterArray.size(); i++) {
				if (i + 1 < classRosterArray.size()) {
					classRosterArray.at(i) = classRosterArray.at(i + 1);
				}
				else classRosterArray.pop_back();
			}
			cout << "Successfully removed Student: " << studentID << endl;
			return;
		}
	}
	cout << "Unable to find student with ID: " << studentID << endl;
}

vector<Student*> Roster::getRoster() {
	return classRosterArray;
}

void Roster::printAll() {
	int i = 0;
	for (i = 0; i < classRosterArray.size(); i++) {
		Student* student = classRosterArray.at(i);
		student->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int i = 0;
	for (i = 0;  i < classRosterArray.size(); i++) {
		Student* student = classRosterArray.at(i);
		if (student->getstudentID() == studentID) {
			int j = 0;
			int accumulator = 0;
			vector<int> dc = student->getdaysToComplete();
			for (j = 0; j < dc.size(); j++) {
				accumulator = accumulator + dc.at(j);
			}
			cout << "Average Days to complete course for " << student->getFullName() << ": " << (accumulator / dc.size()) << endl;
			return;
		}
	}
	cout << "Unable to find student with ID: " << studentID << endl;	
}

void Roster::printInvalidEmails() {
	int i = 0;
	for (i = 0; i < classRosterArray.size(); i++) {
		Student* student = classRosterArray.at(i);
		string email = student->getEmail();
		if (email.find("@") == string::npos) {
			cout << "Invalid email address: does not contain a @ Student: " << student->getFullName() << " Email:" << email << endl;
			continue;
		}
		else if (email.find(".") == string::npos) {
			cout << "Invalid email address: does not contain a . for Student: " << student->getFullName() << " Email: " << email <<  endl;
			continue;
		}

		int j = 0;
		char space = ' ';
		for (j = 0; j < email.length(); j++) {
			
			if (space == email[j]) {
				cout << "Invalid email address: must not contain spaces for Student: " << student->getFullName() << " Email: " << email << endl;
				break;
			}
		}

	}
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	int i = 0;
	for (i = 0; i < classRosterArray.size(); i++) {
		Student* student = classRosterArray.at(i);
		if (student->getdegreeProgram() == degreeProgram) {
			student->print();
		}
	}
}