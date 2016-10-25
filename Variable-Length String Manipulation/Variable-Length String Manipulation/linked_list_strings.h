struct Node
{
	char c;
	Node *next = NULL;
};

typedef Node *linkedListString;

int length(linkedListString s);

char characterAt(linkedListString s, int pos);

void append(linkedListString &s, char appendC);

void concatenate(linkedListString &s1, linkedListString &s2);

void removeChars(linkedListString &s, int pos, int len);

void printll(linkedListString &s);