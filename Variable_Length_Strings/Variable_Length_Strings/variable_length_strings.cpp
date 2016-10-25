#include "iostream"
#include "variable_length_strings.h"


int str_length(std::string s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
} 


vl_string::vl_string()
{
	_root = NULL;
}


vl_string::vl_string(const std::string s)
{
	_root = NULL;

	int len = str_length(s);

	if (len > 0)
	{
		vl_node *new_node = new vl_node();
		new_node->c = s[0];
		new_node->next = NULL;

		_root = new_node;

		vl_node *node_ptr = _root;

		int i = 1;
		for (i = 1; i < len; i++)
		{
			vl_node *new_node = new vl_node();
			new_node->c = s[i];
			new_node->next = NULL;
			node_ptr->next = new_node;
			node_ptr = node_ptr->next;
		}
	}
}


vl_string::~vl_string()
{
	vl_node *node_ptr = _root;
	vl_node *temp = NULL;

	while (node_ptr != NULL)
	{
		temp = node_ptr;
		node_ptr = node_ptr->next;
		delete temp;
	}
}


char vl_string::characterAt(int pos)
{
	vl_node *str_ptr = _root;
	int i = 0;

	for (i = 0; i < pos; i++)
	{
		if (str_ptr == NULL)
			return -1;
		str_ptr = str_ptr->next;
	}
	return str_ptr->c;
}


int vl_string::length()
{
	vl_node *str_ptr = _root;
	int i = 0;

	while (str_ptr != NULL)
	{
		str_ptr = str_ptr->next;
		i++;
	}
	return i;
}


void vl_string::append(char c)
{
	vl_node *new_node = new vl_node;
	new_node->c = c;
	new_node->next = NULL;

	if (_root == NULL)
	{
		_root = new_node;
	}
	else
	{
		vl_node *str_ptr = _root;

		while (str_ptr->next != NULL)
			str_ptr = str_ptr->next;
		str_ptr->next = new_node;
	}
}


void vl_string::concatenate(const vl_string &s)
{
	vl_node *ptr1 = _root;
	vl_node *ptr2 = s._root;

	while (ptr1->next != NULL)
		ptr1 = ptr1->next;

	while (ptr2 != NULL)
	{
		vl_node *new_node = new vl_node;
		new_node->c = ptr2->c;
		new_node->next = NULL;

		ptr1->next = new_node;
		ptr2 = ptr2->next;
		ptr1 = ptr1->next;
	}
}


void vl_string::removeChars(int post, int len)
{

}


void vl_string::print()
{
	vl_node *node_ptr = _root;

	while (node_ptr != NULL)
	{
		std::cout << node_ptr->c;
		node_ptr = node_ptr->next;
	}
	std::cout << '\n';
	std::cin.get();
}
