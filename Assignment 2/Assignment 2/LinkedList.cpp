#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "LinkedList.h"
using namespace std;

linkedList::linkedList()
{

}
linkedList::linkedList(const linkedList& list)
{
	
}
linkedList::~linkedList()
{
	Node* current = head;
	while (current != NULL) {
		Node* next = current->next;
		current->nodePtr->~Employee();
		delete current;
		current = next;
	}
	head = NULL;
}
void linkedList::addNode(Node* newNode)
{
	newNode->next = head;
	head = newNode;
}
bool linkedList::deleteNode(string searchName)
{
	Node* previousNode = head;
	Node* thisNode = head;
	bool found = false;

	while ((thisNode != NULL) && !found)
	{
		if (thisNode->nodePtr->getEmpNo() == searchName)
		{
			found = true;
		}
		else
		{
			previousNode = thisNode;
			thisNode = thisNode->next;
		}
	}
	if (found)
	{
		if (thisNode == head)
		{
			Node* oldhead = head;
			head = head->next;
			thisNode->nodePtr->~Employee();
			delete oldhead;
		}
		else
		{
			previousNode->next = thisNode->next;
			thisNode->nodePtr->~Employee();
			delete thisNode;
			
		}
		return true;
	}
	return false;
}
Node* linkedList::getPerson(string searchName)
{
	Node* previousNode = head;
	Node* thisNode = head;
	bool found = false;
	if (searchName == " ")
	{
		return thisNode;
	}
	while (thisNode != NULL)
	{
		if (thisNode->nodePtr->getEmpNo() == searchName)
		{
			found = true;
			return thisNode;
		}
		else
		{
			previousNode = thisNode;
			thisNode = thisNode->next;
		}
	}
	
	if (!found)
	{
		return nullptr;
	}

}
void linkedList::displayList()
{
	Node* nodeptr = head;
	cout.width(20);
	cout << left << "Employee Type";
	cout.width(20);
	cout << left << "Name";
	cout.width(20);
	cout << left << "Employee Number\n";
	cout << "\n";
	
	while (nodeptr != nullptr)
	{
		
		if (nodeptr->employeeType == 'M')
		{
			cout.width(20);
			cout << left << "Manager";
			cout.width(20);
			cout << left << nodeptr->nodePtr->getName();
			cout.width(20);
			cout << left << nodeptr->nodePtr->getEmpNo() 
				<< "\n";
			nodeptr = nodeptr->next;
		}
		else
		{
			cout.width(20);
			cout << left << "Staff";
			cout.width(20);
			cout << left << nodeptr->nodePtr->getName();
			cout.width(20);
			cout << left << nodeptr->nodePtr->getEmpNo() 
				<< "\n";
			nodeptr = nodeptr->next;
		}
	}
	cout << "\n";
}
void listAllEmployees(linkedList& list)
{
	list.displayList();
	
}
void addAnEmployee(linkedList& list)
{
	Node* newNode = new Node;
	string option = "";
	string newName = "";
	string newStartDate = "";
	string newEmpNo = "";
	string newDept = "";
	double salary = 0;
	double newHourlyRate = 0;
	double newHoursPerWeek = 0;

	cout << "Is the employee a manager or staff member?: ";
	cin.ignore();
	getline(cin, option);

	cout << "Employee Number: ";
	getline(cin, newEmpNo);
	if (list.getPerson(newEmpNo) == nullptr)
	{
		cout << "Employee name: ";
		getline(cin, newName);
		cout << "Employee start date: ";
		getline(cin, newStartDate);
		cout << "Employee Department: ";
		getline(cin, newDept);

		if (option == "manager")
		{
			cout << "Managers Salary: ";
			cin >> salary;
			Manager* manager1 = new Manager(newName, newStartDate, 
				newEmpNo, newDept, salary);
			newNode->nodePtr = manager1;
			newNode->employeeType = 'M';
			list.addNode(newNode);
		}
		else if (option == "staff")
		{
			cout << "Staff members hourly rate: ";
			cin >> newHourlyRate;
			cout << "Staff members hours per week: ";
			cin >> newHoursPerWeek;

			Staff* staff1 = new Staff(newName, newStartDate, 
				newEmpNo, newDept, newHoursPerWeek, newHourlyRate);
			newNode->nodePtr = staff1;
			newNode->employeeType = 'S';
			list.addNode(newNode);
		}
	}
	else
	{
		cout << "Employee number already exists\n\n";
	}
	
}
void removeEmployee(linkedList& list)
{
	string searchName = "";

	cout << "Enter Employee number: ";
	cin.ignore();
	getline(cin, searchName);

	if (list.deleteNode(searchName))
	{
		cout << "Employee Removed\n";
	}
	else
	{
		cout << "Employee Does Not Exist\n";
	}
	cout << "\n";
}
void changeStaffsDepartment(linkedList& list)
{
	char type = 'S';
	bool found = false;
	bool empty = false;
	string searchName = "";
	string newDept = "";
	Node* nodeptr = list.getPerson(" ");

	cout << "Enter Employee number: ";
	cin.ignore();
	getline(cin, searchName);
	cout << "Enter Employee's new department: ";
	cin >> newDept;

	while (!found && !empty)
	{
		if (nodeptr != nullptr)
		{
			if (nodeptr->nodePtr->getDept() == newDept)
			{
				found = true;
			}
			else
			{
				nodeptr = nodeptr->next;
			}
		}
		else
			empty = true;
	}
	if (!found && empty)
	{
		cout << "Department does not exist\n";
	}
	else
	{
		Staff* staffMember = (Staff*)(list.getPerson(searchName)->nodePtr);
		staffMember->setDept(newDept);
	}
	cout << "\n";
}
void displaySpecificManagersDetails(linkedList& list)
{
	bool found = false;
	string searchName = "";
	char type = 'M';

	cout << "Enter Employee number: ";
	cin.ignore();
	getline(cin, searchName);

	Manager* manager = (Manager*)(list.getPerson(searchName)->nodePtr);

	while (!found)
	{
		Node* staffType = list.getPerson(searchName);
		if (manager == nullptr)
		{
			cout << "Employee not found!\n";
			found = true;

		}
		else if (staffType->employeeType == 'M')
		{
			cout.width(20);
			cout << left << "Name";
			cout.width(20);
			cout << left << "Department";
			cout.width(20);
			cout << left << "Salary\n";
			cout << "\n";
			cout.width(20);
			cout << left << manager->getName();
			cout.width(20);
			cout << left << manager->getDept();
			cout.width(10);
			cout << left << manager->getSalary() << "\n";
			found = true;
		}
	}
	cout << "\n";
}
void displaySpecificStaffDetails(linkedList& list)
{
	bool found = false;
	char type = 'S';
	string searchName = "";

	cout << "Enter Employee number: ";
	cin.ignore();
	getline(cin, searchName);

	Staff* staffMemberA = (Staff*)(list.getPerson(searchName)->nodePtr);

	while (!found)
	{
		Node* staffMember = list.getPerson(searchName);
		if (staffMember == nullptr)
		{
			cout << "Employee not found!\n";
			found = true;
		}
		else if (staffMember->employeeType == 'S')
		{
			cout.width(20);
			cout << left << "Name";
			cout.width(20);
			cout << left << "Department";
			cout.width(10);
			cout << left << "Wage\n";
			cout << "\n";
			cout.width(20);
			cout << left << staffMemberA->getName();
			cout.width(20);
			cout << left << staffMemberA->getDept();
			cout.width(10);
			cout << left << setprecision(2) << fixed << staffMemberA->getWage()
				<< "\n";
			found = true;
		}
		if (staffMember->employeeType == 'M')
		{
			cout << "The employee you have requested is a manager\n";
			found = true;
		}
	}
	if (!found)
	{
		cout << "The person you are looking for does not exist\n";
	}
	cout << "\n";
}
void listAllOfManagersStaff(linkedList& list)
{
	char type = 'M';
	int multipleCounter = 0;
	string searchName = "";

	cout << "Enter Employee number of Manager: ";
	cin.ignore();
	getline(cin, searchName);

	Node* specificManager = list.getPerson(searchName);
	type = 'S';
	Node* nodeptr = list.getPerson(" ");

	cout.width(20);
	cout << left << "Name";
	cout.width(20);
	cout << left << "Employee Number";
	cout << "\n";

	while (nodeptr != nullptr)
	{
		Node* staffMember = list.getPerson(nodeptr->nodePtr->getEmpNo());
		if (staffMember == nullptr)
		{
			cout << "Employee not found!\n";
		}
		if (staffMember->employeeType == 'S' &&
			staffMember->nodePtr->getDept() == specificManager->nodePtr->getDept())
		{
			if (staffMember->nodePtr->getName() == specificManager->nodePtr->getName() &&
				multipleCounter == 0)
			{
				cout.width(20);
				cout << left << staffMember->nodePtr->getName();
				cout.width(20);
				cout << left << staffMember->nodePtr->getEmpNo() << "\n";
				nodeptr = nodeptr->next;
				multipleCounter = 1;
			}
			else if (staffMember->nodePtr->getName() != specificManager->nodePtr->getName())
			{
				cout.width(20);
				cout << left << staffMember->nodePtr->getName();
				cout.width(20);
				cout << left << staffMember->nodePtr->getEmpNo() << "\n";
				nodeptr = nodeptr->next;
			}
			else
			{
				nodeptr = nodeptr->next;
			}
		}
		else
		{
			nodeptr = nodeptr->next;
		}
	}
	cout << "\n";
}
void displayHourlyRateAndWages(linkedList& list)
{
	Node* staffMemberA = list.getPerson(" ");
	Staff* staffMember = (Staff*)(list.getPerson((staffMemberA->nodePtr->getEmpNo()))->nodePtr);

	cout.width(20);
	cout << left << "Employee Number";
	cout.width(20);
	cout << left << "Wage";
	cout.width(20);
	cout << left << "Hourly Rate\n";
	cout << "\n";

	while (staffMemberA != nullptr)
	{
		if (staffMemberA->employeeType == 'S')
		{
			cout.width(20);
			cout << left << staffMemberA->nodePtr->getEmpNo();
			cout.width(20);
			cout << left << setprecision(2) << fixed << staffMember->getWage();
			cout.width(20);
			cout << left << staffMember->getRate() << "\n";
		}
		staffMemberA = staffMemberA->next;
		if (staffMemberA != nullptr)
			staffMember = (Staff*)(list.getPerson((staffMemberA->nodePtr->getEmpNo()))->nodePtr);
		
	}
	cout << "\n";
}