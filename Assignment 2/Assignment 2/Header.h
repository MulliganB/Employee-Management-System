#include "stdafx.h"
#include <string>
using namespace std;

class Employee
{
protected:
	string name;
	string startDate;
	string empNumber;
	string dept;
public:
	Employee();
	Employee(string, string, string, string);
	string getName();
	string getStartDate();
	string getEmpNo();
	string getDept();
	void setName(string);
	virtual ~Employee();
};

class Manager : public Employee
{
private:
	double salary;
public:
	Manager();
	Manager(string, string, string, string, double);
	double getSalary();
	void setSalary(double);
	~Manager();
};

class Staff : public Employee
{
private:
	double hoursPerWeek;
	double hourlyRate;
public:
	Staff();
	Staff(string, string, string, string, double, double);
	void setHours(double);
	void setRate(double);
	double getWage();
	double getRate();
	void setDept(string);
	~Staff();
};