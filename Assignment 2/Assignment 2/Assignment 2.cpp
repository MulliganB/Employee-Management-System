// Assignment 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

void createManagers(linkedList&);
void createStaff(linkedList&);
void getMenu(char&);
void listAllEmployees(linkedList&);
void addAnEmployee(linkedList&);
void removeEmployee(linkedList&);
void changeStaffsDepartment(linkedList&);
void displaySpecificManagersDetails(linkedList&);
void displaySpecificStaffDetails(linkedList&);
void listAllOfManagersStaff(linkedList&);
void displayHourlyRateAndWages(linkedList&);
char quit(char&, linkedList&);

int main()
{
	linkedList list;
	char command = ' ';
	createManagers(list);
	createStaff(list);

	while (command != 'Q')
	{
		getMenu(command);
		switch (command)
		{
		case '1': listAllEmployees(list);
			      break;
		case '2': addAnEmployee(list);
			      break;
		case '3': removeEmployee(list);
			      break;
		case '4': changeStaffsDepartment(list);
			      break;
		case '5': displaySpecificManagersDetails(list);
			      break;
		case '6': displaySpecificStaffDetails(list);
			      break;
		case '7': listAllOfManagersStaff(list);
			      break;
		case '8': displayHourlyRateAndWages(list);	
			      break;
		case '9': quit(command, list);
			      break;
		default:  break;
		}
	}
	system("pause");
	return 0;
}

void createManagers(linkedList& list)
{
	Manager* manager1 = new Manager("Ben Mulligan", "01/04/10", "A124", "Sales", 10000);
	Manager* manager2 = new Manager("Dave Smith", "17/07/06", "B345", "Accounting", 50000);
	Node* newNode = new Node;
	newNode->nodePtr = manager1;
	newNode->employeeType = 'M';
	list.addNode(newNode);
	newNode = new Node;
	newNode->nodePtr = manager2;
	newNode->employeeType = 'M';
	list.addNode(newNode);
}
void createStaff(linkedList& list)
{
	Staff* staff1 = new Staff("John Davis", "01/04/10", "A123", "Sales", 40, 6.00);
	Staff* staff2 = new Staff("Dave Smith", "17/07/06", "B346", "Accounting", 20, 6.76);
	Staff* staff3 = new Staff("James Phone", "02/08/10", "C123", "Sales", 35, 6.43);
	Staff* staff4 = new Staff("Hannah Mill", "01/01/12", "A987", "Sales", 45, 6.00);
	Staff* staff5 = new Staff("Dave Jones", "03/12/08", "B789", "Accounting", 40, 6.75);
	Node* newNode = new Node;
	newNode->nodePtr = staff1;
	newNode->employeeType = 'S';
	list.addNode(newNode);
	newNode = new Node;
	newNode->nodePtr = staff2;
	newNode->employeeType = 'S';
	list.addNode(newNode);
	newNode = new Node;
	newNode->nodePtr = staff3;
	newNode->employeeType = 'S';
	list.addNode(newNode);
	newNode = new Node;
	newNode->nodePtr = staff4;
	newNode->employeeType = 'S';
	list.addNode(newNode);
	newNode = new Node;
	newNode->nodePtr = staff5;
	newNode->employeeType = 'S';
	list.addNode(newNode);
}
void getMenu(char& command)
{
	cout << "1.List all employees.\n"
		<< "2.Add an employee(manager or staff member).\n"
		<< "3.Remove an employee.\n"
		<< "4.Change a staff member's department.\n"
		<< "5.Display a manager's details.\n"
		<< "6.Display a staff member's details.\n"
		<< "7.List all staff members under a specified manager.\n"
		<< "8.Display hourly pay rates and wages of all staff members.\n"
		<< "9.Quit.\n"
		<< "Enter the number of the option you want: ";
	cin >> command;
	cout << "\n";
}
char quit(char& command, linkedList& list)
{
	
	if (command == '9')
	{
		list.~linkedList();
		return (command ='Q');
	}
	else
	{
		return '0';
	}
}