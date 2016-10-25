#include "iostream"
#include "array_strings.h"
#include "linked_list_strings.h"


void testArrayString()
{
	arrayString s1 = new char[6];
	s1[0] = 'h';
	s1[1] = 'e';
	s1[2] = 'l';
	s1[3] = 'l';
	s1[4] = 'o';
	s1[5] = 0;

	arrayString s2 = new char[6];
	s2[0] = 'w';
	s2[1] = 'o';
	s2[2] = 'r';
	s2[3] = 'l';
	s2[4] = 'd';
	s2[5] = 0;

	append(s1, ' ');
	concatenate(s1, s2);
	append(s1, '!');

	std::cout << s1 << '\n';
	std::cin.get();
}


void testArraySubstring()
{
	arrayString s1 = new char[6];
	s1[0] = 'h';
	s1[1] = 'e';
	s1[2] = 'l';
	s1[3] = 'l';
	s1[4] = 'o';
	s1[5] = 0;

	arrayString s = nullptr;
	s = substring(s1, 1, 2);

	std::cout << s << '\n';
	std::cin.get();
}

void testArrayReplaceString()
{
	arrayString s = new char[8];
	s[0] = 'a';
	s[1] = 'a';
	s[2] = 'a';
	s[3] = 'b';
	s[4] = 'a';
	s[5] = 'a';
	s[6] = 'b';
	s[7] = 0;

	arrayString t = new char[2];
	t[0] = 'b';
	t[1] = 0;

	arrayString r = new char[4];
	r[0] = 'c';
	r[1] = 'c';
	r[2] = 'c';
	r[3] = 0;


	std::cout << "replacing " << t << " with: " << r << '\n';
	std::cout << "before: " << s << '\n';

	arrayString replacedString = replaceString(s, t, r);

	std::cout << "after: " << replacedString << '\n';
	std::cin.get();
}


void testLinkedListAppend()
{
	linkedListString s;
	char c1 = 'h';
	char c2 = 'e';
	char c3 = 'l';
	char c4 = 'l';
	char c5 = 'o';
	
	append(s, c1);
	append(s, c2);
	append(s, c3);
	append(s, c4);
	append(s, c5);
	

	printll(s);
	std::cin.get();
}


void testLinkedListCharacterAt()
{
	linkedListString s;
	Node *c1 = new Node; c1->c = 'h';
	char c2 = 'e';
	char c3 = 'l';
	char c4 = 'l';
	char c5 = 'o';

	s = c1;
	append(s, c2);
	append(s, c3);
	append(s, c4);
	append(s, c5);


	std::cout << characterAt(s, 0) << '\n';
	std::cout << characterAt(s, 1) << '\n';
	std::cout << characterAt(s, 2) << '\n';
	std::cout << characterAt(s, 3) << '\n';
	std::cout << characterAt(s, 4) << '\n';

	std::cin.get();
}


void testLinkedListConcatenate()
{
	linkedListString s1 = NULL;

	append(s1, 'h');
	append(s1, 'e');
	append(s1, 'l');
	append(s1, 'l');
	append(s1, 'o');
	append(s1, ' ');

	linkedListString s2 = NULL;

	append(s2, 'w');
	append(s2, 'o');
	append(s2, 'r');
	append(s2, 'l');
	append(s2, 'd');
	append(s2, '!');

	concatenate(s1, s2);

	printll(s1);
	std::cin.get();
}


void testLinkedListRemoveChars()
{
	linkedListString s1 = NULL;

	append(s1, 'h');
	append(s1, 'e');
	append(s1, 'l');
	append(s1, 'l');
	append(s1, 'o');
	append(s1, ' ');
	append(s1, 'w');
	append(s1, 'o');
	append(s1, 'r');
	append(s1, 'l');
	append(s1, 'd');
	append(s1, '!');

	removeChars(s1, 0, 2);
	printll(s1);
	std::cin.get();
}


int main()
{
	testLinkedListRemoveChars();
	return 0;
}