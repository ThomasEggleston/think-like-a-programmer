#include "student.h"


StudentRecord::StudentRecord()
{
	setGrade(0);
	setStudentID(-1);
	setName("");
}


StudentRecord::StudentRecord(int newGrade, int newID, string newName)
{
	setGrade(newGrade);
	setStudentID(newID);
	setName(newName);
}


bool StudentRecord::isValidGrade(int grade)
{
	if ((grade >= 0) && (grade <= 100))
		return true;
	else
		return false;
}


int StudentRecord::getGrade()
{
	return _grade;
}


void StudentRecord::setGrade(int newGrade)
{
	if (isValidGrade(newGrade))
		_grade = newGrade;
}


int StudentRecord::getStudentID()
{
	return _studentID;
}


void StudentRecord::setStudentID(int newID)
{
	_studentID = newID;
}


string StudentRecord::getName()
{
	return _name;
}


void StudentRecord::setName(string newName)
{
	_name = newName;
}


string StudentRecord::letterGrade()
{
	if (!isValidGrade(_grade))
		return "ERROR";

	const int NUMBER_CATEGORIES = 11;

	const string GRADE_LETTER[] = { "F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A", "A+" };
	const int LOWEST_GRADE_SCORE[] = { 0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93 };
	
	int category = 0;

	while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
		category++;

	return GRADE_LETTER[category - 1];
}