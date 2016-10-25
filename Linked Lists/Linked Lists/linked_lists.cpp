#include <iostream>


using namespace std;


struct Record {
	int number;
	int grade;
	Record *next = NULL;
};
typedef Record *studentCollection;


void addRecord(studentCollection &sc, int number, int grade) {
	Record *r = new Record;
	r->number = number;
	r->grade = grade;
	r->next = sc;  // Link new node to old head
	sc = r;  // New record placed at head of collection
}


double averageGrade(studentCollection &sc) {
	if (sc == NULL) return 0;

	double sum = 0;
	int numRecords = 0;

	Record *currentRecord = sc;
	while (currentRecord != NULL) {
		sum += currentRecord->grade;
		numRecords++;
		currentRecord = currentRecord->next;
	}
	return sum / numRecords;
}


void printRecords(studentCollection &sc) {
	Record *currentRecord = sc;
	while (currentRecord != NULL) {
		cout << currentRecord->number << ' ' << currentRecord->grade << '\n';
		currentRecord = currentRecord->next;
	}
	cin.get();
}


void testRecord() {
	studentCollection sc = NULL;

	addRecord(sc, 1001, 78);
	addRecord(sc, 1012, 93);
	addRecord(sc, 1076, 85);

	printRecords(sc);
}

void testAverage() {
	studentCollection sc = NULL;

	addRecord(sc, 1001, 78);
	addRecord(sc, 1012, 93);
	addRecord(sc, 1076, 85);

	double avg = 0;
	avg = averageGrade(sc);
	cout << "average: " << avg << '\n';
	cin.get();
}


int main() {
	//testRecord();
	//testAverage();
	return 0;
}