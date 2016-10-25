#include "iostream"
#include "string"
#include "student.h"
#include "student_collection.h"


using namespace std;


void testStudentCollection()
{/*
	StudentCollection s = StudentCollection();
	s.addRecord(StudentRecord(84, 1152, "Sue"));
	s.addRecord(StudentRecord(75, 4875, "Ed"));
	s.addRecord(StudentRecord(98, 2938, "Todd"));

	cout << s.recordWithNumber(75).getGrade() << '\n';
	cin.get();*/

	StudentCollection s = StudentCollection();
	StudentRecord s1(84, 1152, "Sue");
	StudentRecord s2(75, 4875, "Ed");
	StudentRecord s3(98, 2938, "Todd");
	
	s.addRecord(s1);
	s.addRecord(s2);
	s.addRecord(s3);

	cout << s.recordWithNumber(1152).getName() << '\n';
	cout << s.recordWithNumber(4875).getName() << '\n';
	cout << s.recordWithNumber(2938).getName() << '\n';
	cin.get();
}


int main()
{
	testStudentCollection();

	return 0;
}