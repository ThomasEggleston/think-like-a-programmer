#include "automobile.h"
#include "iostream"
#include "string"


using namespace std;


string Automobile::getManufacturerName()
{
	return _manufacturerName;
}


void Automobile::setManufacturerName(string newManufacturerName)
{
	_manufacturerName = newManufacturerName;
}


string Automobile::getModelName()
{
	return _modelName;
}


void Automobile::setModelName(string newModelName)
{
	_modelName = newModelName;
}


int Automobile::getModelYear()
{
	return _modelYear;
}


void Automobile::setModelYear(int newModelYear)
{
	_modelYear = newModelYear;
}


int main()
{
	return 0;
}