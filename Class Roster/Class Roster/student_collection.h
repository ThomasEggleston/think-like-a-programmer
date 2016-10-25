#ifndef STUDENT_COLLECTION_H
#define STUDENT_COLLECTION_H


#include "student.h"


class StudentCollection
{
private:
	struct studentNode
	{
		StudentRecord studentData;
		studentNode *next;
	};

public:
	StudentCollection();

	~StudentCollection();

	void addRecord(StudentRecord newStudent);

	StudentRecord recordWithNumber(int studentID);

	void removeRecord(int studentID);

	StudentCollection& operator=(const StudentCollection &rhs);

	StudentCollection(const StudentCollection &original);

private:
	typedef studentNode *studentList;
	studentList _listHead;

	void deleteList(studentList &listPtr);

	studentList copiedList(const studentList original);
};

#endif