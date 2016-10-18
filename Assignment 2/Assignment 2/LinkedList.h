#include "stdafx.h"
#include <string>
#include "Header.h"
using namespace std;

struct Node 
{
	Employee* nodePtr;
	char employeeType;
	Node* next;
	Node* previous;
};

class linkedList
{
private:
	Node* head;
public:
	linkedList();
	linkedList(const linkedList&);
	void addNode( Node*);
	bool deleteNode(string);
	Node* getPerson(string);
	void displayList();
	~linkedList();
};