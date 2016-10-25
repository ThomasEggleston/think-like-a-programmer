#include "iostream"


struct Node
{
	char c;
	Node *next = NULL;
};
typedef Node *linkedListString;


int length(linkedListString s)
{
	int len = 0;
	Node *currentNode = s;
	while (currentNode != NULL)
	{
		len++;
		currentNode = currentNode->next;
	}
	return len;
}


char characterAt(linkedListString s, int pos)
{
	Node *currentNode = s;

	int i = 0;
	for (i = 0; i < pos; i++)
	{
		currentNode = currentNode->next;
	}
	return currentNode->c;
}


void append(linkedListString &s, char appendC)
{
	Node *newNode = new Node;
	newNode->c = appendC;
	newNode->next = NULL;

	if (s == NULL)
	{
		s = newNode;
	}
	else
	{
		Node *currentNode = s;
	
		while (currentNode->next != NULL)  // iterate to last node in list
		{
			currentNode = currentNode->next;
		}

		currentNode->next = newNode;
	}

}


void concatenate(linkedListString &s1, linkedListString &s2)
{
	Node *s1Node = s1;
	Node *s2Node = s2;

	while (s1Node->next != NULL)  // get last node of first string
	{
		s1Node = s1Node->next;
	}

	while (s2Node != NULL)  // add new character for each one in second string
	{
		append(s1Node, s2Node->c);
		s1Node = s1Node->next;
		s2Node = s2Node->next;
	}
}


void printll(linkedListString &s)
{
	Node *currentNode = s;

	while (currentNode != NULL)
	{
		std::cout << currentNode->c;
		currentNode = currentNode->next;
	}
	std::cout << '\n';
}


void removeChars(linkedListString &s, int pos, int len)
{
	if (len > 0)
	{
		Node *leftNode = s;
		Node *rightNode = NULL;
		Node *temp = NULL;

		int i = 0;

		if (pos > 0)
		{
			for (i = 0; i < pos - 1; i++)
			{
				leftNode = leftNode->next;
			}

			temp = leftNode->next;

			for (i = 0; i < len && temp != NULL; i++)
			{
				rightNode = temp->next;
				delete temp;
				temp = rightNode;
			}

			leftNode->next = rightNode;
		}
		else if (pos == 0)
		{
			for (i = 0; i < len && leftNode != NULL; i++)
			{
				temp = leftNode;
				leftNode = leftNode->next;
				delete temp;
			}

			s = leftNode;
		}
	}
}