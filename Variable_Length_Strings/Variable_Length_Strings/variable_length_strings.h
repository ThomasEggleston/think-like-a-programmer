#include "iostream"


class vl_string
{
private:
	struct vl_node
	{
		char c;
		vl_node *next;
	};
public:
	vl_string();
	vl_string(const std::string s);
	~vl_string();
	void append(char c);
	void concatenate(const vl_string &s);
	char characterAt(int pos);
	void removeChars(int pos, int len);
	int length();
	void print();
protected:
	typedef vl_node *vl_list;
	vl_list _root;
};