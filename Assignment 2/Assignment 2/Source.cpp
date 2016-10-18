#include "stdafx.h"
#include "Header.h"
#include <iostream>
using namespace std;

Employee::Employee()
{

}
Employee::Employee(string newName, string newStartDate, 
	string newEmpNo, string newDept)
{
	name = newName;
	startDate = newStartDate;
	empNumber = newEmpNo;
	dept = newDept;
}
string Employee::getName()
{
	return name;
}
string Employee::getStartDate()
{
	return startDate;
}
string Employee::getEmpNo()
{
	return empNumber;
}
string Employee::getDept()
{
	return dept;
}
void Employee::setName(string newName)
{
	name = newName;
}
Employee::~Employee()
{
	cout << "~" << empNumber << "\n";
}

Manager::Manager()
{

}
Manager::Manager(string newName, string newStartDate, 
	string newEmpNo, string newDept, double newSalary)
{
	salary = newSalary;
	name = newName;
	startDate = newStartDate;
	empNumber = newEmpNo;
	dept = newDept;
}
double Manager::getSalary()
{
	return salary;
}
void Manager::setSalary(double newSalary)
{
	salary = newSalary;
}
Manager::~Manager()
{
	cout << "~Manager\n";
}

Staff::Staff()
{

}
Staff::Staff(string newName, string newStartDate, string newEmpNo, 
	string newDept, double newHours, double newRate)
{
	hoursPerWeek = newHours;
	hourlyRate = newRate;
	name = newName;
	startDate = newStartDate;
	empNumber = newEmpNo;
	dept = newDept;
}
void Staff::setHours(double newHours)
{
	hoursPerWeek = newHours;
}
void Staff::setRate(double newRate)
{
	hourlyRate = newRate;
}
double Staff::getWage()
{
	return (hoursPerWeek*hourlyRate);
}
double Staff::getRate()
{
	return (hourlyRate);
}
void Staff::setDept(string newDept)
{
	dept = newDept;
}
Staff::~Staff()
{
	cout << "~Staff Member\n";
}
