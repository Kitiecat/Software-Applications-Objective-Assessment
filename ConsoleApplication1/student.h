#pragma once
#include "degree.h"
#include <iostream>
#include <vector>
#include <regex>
#include <string>

class Student {
	public:
		string getstudentID();
		string getFullName();
		string getEmail();
		int getAge();
		vector<int> getdaysToComplete();
		DegreeProgram getdegreeProgram();

		void setstudentID(string str);
		void setFullName(string first, string second);
		void setEmail(string email);
		void setAge(int a);
		void setdaysToComplete(vector<int> days );
		void setdegreeProgram(DegreeProgram degree);

		void print();

		Student(string row);
		Student(
			std::string studentID,
			std::string firstName,
			std::string lastName,
			std::string emailAddress,
			int age,
			int daysInCourse1,
			int daysInCourse2,
			int daysInCourse3,
			DegreeProgram degreeprogram);

	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		vector<int> daysToComplete;
		DegreeProgram degreeProgram;
};

