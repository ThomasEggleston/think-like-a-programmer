#ifndef STUDENT_H
#define STUDENT_H


#include "iostream"


using namespace std;


class StudentRecord
{
public:
	StudentRecord();

	StudentRecord(int newGrade, int newID, string newName);

	int getGrade();

	void setGrade(int newGrade);

	int getStudentID();

	void setStudentID(int newID);

	string getName();

	void setName(string newName);

	string letterGrade();

private:
	string _name;
	int _studentID;
	int _grade;

	bool StudentRecord::isValidGrade(int grade);
};

#endif