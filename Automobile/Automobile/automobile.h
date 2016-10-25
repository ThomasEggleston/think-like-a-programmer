#include "iostream"


using namespace std;


class Automobile
{
public:
	string getManufacturerName();
	void setManufacturerName(string newManufacturerName);
	string getModelName();
	void setModelName(string newModelName);
	int getModelYear();
	void setModelYear(int newYear);
private:
	string _manufacturerName;
	string _modelName;
	int _modelYear;
};