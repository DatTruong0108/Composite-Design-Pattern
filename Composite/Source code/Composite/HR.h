#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Date.h"

using namespace std;

// components
class HR
{
protected:
	string name;
	string id;
	int startYear;
	Date dateOfBirth;
public:
	HR();
	virtual void add(HR*) = 0;
	virtual void add(HR*, string) = 0;
	virtual void remove(string) = 0;
	virtual void setEmployee() = 0;
	virtual bool isLeaf()
	{
		return false;
	}
	virtual string getID()
	{
		return id;
	}
	virtual long long getSalary() = 0;
	virtual int countEmployee() = 0;
	//virtual string getPosition() = 0;
	virtual HR* maxSalary() = 0;
	virtual HR* findHR(string) = 0;
	virtual void printHRInfo(string) = 0;
	virtual double avgSalary() = 0;
};