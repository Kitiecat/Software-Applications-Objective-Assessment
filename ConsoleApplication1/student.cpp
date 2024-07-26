#include <iostream>
#include <vector>
#include <regex>
#include <string>
using namespace std;

#include "student.h"
#include "degree.h"

void Student::setstudentID(string str){
	this->studentID = str;
}

string Student::getstudentID() {
return this->studentID;
}

void Student::setFullName(string first, string last) {
	this->firstName = first;
	this->lastName = last;
}

string Student::getFullName() {
	return this->firstName + " " + this->lastName;
}

void Student::setEmail(string email) {
	this->emailAddress = email;
}

string Student::getEmail() {
	return emailAddress;
}

void Student::setAge(int a) {
	this->age = a;
}

int Student::getAge() {
	return age;
}

void Student::setdaysToComplete(vector<int> days) {
	this->daysToComplete = days;
}

vector<int> Student::getdaysToComplete() {
	return daysToComplete;
}

void Student::setdegreeProgram(DegreeProgram degree) {
	this->degreeProgram = degree;
}

DegreeProgram Student::getdegreeProgram() {
	return degreeProgram;
}

void Student::print() {


	int daysInCourse1 = this->daysToComplete.at(0);
	int daysInCourse2 = this->daysToComplete.at(1);
	int daysInCourse3 = this->daysToComplete.at(2);
	/// A1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse : {35, 40, 55} Degree Program : Security 

	cout << this->studentID << "\t" << "First Name : " << this->firstName << "\t"
		<< "Last Name : " << this->lastName << "\t" << "Email: " << this->emailAddress << "\t" << "Age : " << this->age << "\t"
		<< "daysInCourse : { " << daysInCourse1 << ", " << daysInCourse2 << ", " << daysInCourse3
		<< " } \t Degree Program : ";
	auto dp = static_cast<DegreeProgram>(degreeProgram);
	switch (dp) {
	case DegreeProgram::SOFTWARE: cout << "SOFTWARE" << endl; break;
	case DegreeProgram::SECURITY: cout << "SECURITY" << endl; break;
	case DegreeProgram::NETWORK: cout << "NETWORK" << endl; break;
	}
}

Student::Student(
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

	vector<int> dc(3);

	setstudentID(studentID);
	setFullName(firstName, lastName);
	setEmail(emailAddress);
	setAge(age);

	dc[0] = daysInCourse1;
	dc[1] = daysInCourse2;
	dc[2] = daysInCourse3;
	setdaysToComplete(dc);
	setdegreeProgram(degreeprogram);

}
Student::Student(string row) {
	size_t i = 0;
	string tmp;
	vector<string> columns = {};
	vector<int> dc(3);
	string delim = ",";
	DegreeProgram degree = DegreeProgram::SOFTWARE;

	/// Incoming Data:
	/// Student ID, First Name, Last Name, Email, Age, List of Days in Course (3), Degree Program
	while ((i = row.find(delim)) != std::string::npos){
		tmp = row.substr(0, i);
		columns.push_back(tmp);
		row.erase(0, i + delim.length());
	}
	columns.push_back(row);

	setstudentID(columns[0]);
	setFullName(columns[1], columns[2]);
	setEmail(columns[3]);
	setAge(stoi(columns[4]));
	int j = 0;
	for (i = 5; i < 8; i++) {
		dc[j] = stoi(columns[i]);
		j++;
	}
	setdaysToComplete(dc);
	if (columns[8] == "SECURITY") {
		degree = DegreeProgram::SECURITY;
	}
	else if (columns[8] == "NETWORK") {
		degree = DegreeProgram::NETWORK;
	}
	else if (columns[8] == "SOFTWARE") {
		degree = DegreeProgram::SOFTWARE;
	}
	setdegreeProgram(degree);

}