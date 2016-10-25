#include "student_collection.h"
#include "string"


StudentCollection::StudentCollection()
{
	_listHead = NULL;
}


void StudentCollection::addRecord(StudentRecord newStudent)
{
	studentNode *newNode = new studentNode;
	newNode->studentData = newStudent;
	newNode->next = _listHead;
	_listHead = newNode;
}


StudentRecord StudentCollection::recordWithNumber(int studentID)
{
	studentNode *currentNode = _listHead;

	while (currentNode != NULL && currentNode->studentData.getStudentID() != studentID)
		currentNode = currentNode->next;

	if (currentNode == NULL)  // return a dummy record if not found or list empty
	{
		StudentRecord dummyRecord = StudentRecord(-1, -1, "");
		return dummyRecord;
	}
	else
		return currentNode->studentData;
}


void StudentCollection::removeRecord(int studentID)
{
	studentNode *previousNode = NULL;
	studentNode *currentNode = _listHead;

	if (currentNode->studentData.getStudentID() == studentID)  // if record to remove is at head
	{
		_listHead = currentNode->next;
		delete currentNode;
	}
	else
	{
		while (currentNode != NULL && currentNode->studentData.getStudentID() != studentID)  // find record
		{
			previousNode = currentNode;  // store previous record, to link past target record
			currentNode = currentNode->next;
		}
		if (currentNode != NULL)  // record has been found
		{
			previousNode->next = currentNode->next;
			delete currentNode;
		}
	}
}


void StudentCollection::deleteList(studentList &listPtr)
{
	while (listPtr != NULL)
	{
		studentList *temp = &listPtr;
		listPtr = listPtr->next;
		delete temp;
	}
}


// Class destructor
StudentCollection::~StudentCollection()
{
	deleteList(_listHead);
}


StudentCollection::studentList
StudentCollection::copiedList(const studentList original)
{
	if (original == NULL)
		return NULL;

	studentList newList = new studentNode;
	newList->studentData = original->studentData;

	studentNode *oldListPtr = original->next;
	studentNode *newListPtr = newList;

	while (oldListPtr != NULL)
	{
		newListPtr->next = new studentNode;
		newListPtr = newListPtr->next;
		newListPtr->studentData = oldListPtr->studentData;
		oldListPtr = oldListPtr->next;
	}
	newListPtr->next = NULL;

	return newList;
}


// Operator overloading
StudentCollection& StudentCollection::operator=(const StudentCollection &rhs)
{
	if (this != &rhs)
	{
		deleteList(_listHead);
		_listHead = copiedList(rhs._listHead);
	}
	return *this;
}


// Copy constructor
StudentCollection::StudentCollection(const StudentCollection &original)
{
	_listHead = copiedList(original._listHead);
}
