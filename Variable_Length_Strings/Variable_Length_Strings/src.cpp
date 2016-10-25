#include "iostream"
#include "string"
#include "variable_length_strings.h";


using namespace std;


int main()
{/*
	string str1 = string("hello");
	string str2 = string("world");

	vl_string *s1 = new vl_string(str1);
	vl_string *s2 = new vl_string(str2);

	s1->append(' ');

	s1->concatenate(*s2);

	s1->append('!');

	s1->print();

	delete s1;*/

	vl_string vl = vl_string();
	vl.append('a');
	vl.print();

	return 0;
}