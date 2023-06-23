#include "Office.h"

Office::Office()
{
	return;
}

Office::Office(string name, string id, int year, Date bd)
{
	this->name = name;
	this->id = id;
	this->startYear = year;
	this->dateOfBirth = bd;
}

Office::~Office()
{
	for (int i = 0; i < (int)List.size(); ++i)
	{
		delete List[i];
		List[i] = nullptr;
	}
}

void Office::add(HR* addHR)
{
	this->List.push_back(addHR);
}

void Office::add(HR* addingHR, string deptID)
{
	if (this->id == deptID)
	{
		add(addingHR);
	}
	else
	{
		for (int i = 0; i < (int)this->List.size(); ++i)
		{
			List[i]->add(addingHR, deptID);
		}
	}
}

void Office::remove(string removeID)
{
	for (int i = 0; i < (int)this->List.size(); ++i)
	{
		if (List[i]->isLeaf())
		{
			if (List[i]->getID() == removeID)
			{
				List.erase(List.begin() + i);
			}
		}
		else
		{
			List[i]->remove(removeID);
		}
	}
}

long long Office::getSalary()
{
	long long sumSalary = 0;
	for (int i = 0; i < (int)List.size(); ++i)
	{
		sumSalary += List[i]->getSalary();
	}
	return sumSalary;
}

int Office::countEmployee()
{
	int cnt = 0;
	for (int i = 0; i < (int)this->List.size(); ++i)
	{
		cnt += List[i]->countEmployee();
	}
	return cnt;
}

double Office::avgSalary()
{
	return 1.0 * this->getSalary() / this->countEmployee();
}

HR* Office::maxSalary()
{
	HR* maxS = new Employee;
	for (int i = 0; i < (int)this->List.size(); ++i)
	{
		HR* curMax = List[i]->maxSalary();
		if ((*maxS).getSalary() < (*curMax).getSalary())
		{
			maxS = curMax;
		}
	}
	return maxS;
}

HR* Office::findHR(string str)
{
	HR* strHR = new Employee;
	for (int i = 0; i < (int)this->List.size(); ++i)
	{
		strHR = List[i]->findHR(str);
		if (strHR != nullptr)
		{
			return strHR;
		}
	}
	return nullptr;
}

void Office::printHRInfo(string tab)
{
	if (tab != "")
	{
		cout << tab << "Subdepartment:\n";
	}
	cout << tab << "Dep. Name: " << name << '\n';
	cout << tab << "Dep. ID: " << id << '\n';
	cout << tab << "Dep. Starting year: " << startYear << '\n';
	cout << tab << "Establishment Day: "; dateOfBirth.printDate(); cout << '\n';
	if (!List.empty())
	{
		cout << tab << "Include:\n";
	}
	tab += '\t';
	for (int i = 0; i < (int)List.size(); ++i)
	{
		List[i]->printHRInfo(tab);
	}
}