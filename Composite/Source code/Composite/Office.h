#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "HR.h"

using namespace std;

// composite
class Office : public HR
{
	vector<HR*> List;
public:
	Office();
	Office(string, string, int, Date);
	~Office();
	void add(HR*) override;
	void add(HR*, string) override;
	void remove(string) override;
	void setEmployee() override
	{
		return;
	}
	long long getSalary() override;
	int countEmployee() override;
	double avgSalary() override;
	//string getPosition() override;
	HR* maxSalary() override;
	HR* findHR(string) override;
	void printHRInfo(string) override;
};
