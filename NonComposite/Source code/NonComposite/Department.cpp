#include "Department.h"

Department::Department(string name, string id)
{
	this->name = name;
	this->id = id;
}

Department::~Department()
{
	if (this->manager)
	{
		delete this->manager;
		this->manager = nullptr;
	}
	for (int i = this->listOfSection.size() - 1; i >= 0; i--)
	{
		if (this->listOfSection[i]) {
			delete this->listOfSection[i];
			this->listOfSection[i] = nullptr;
		}
	}
	this->listOfSection.clear();
}

void Department::addSection(Section* section)
{
	this->listOfSection.push_back(section);
}

bool Department::removeSection(string id)
{
	for (int i = 0; i < this->listOfSection.size(); i++)
	{
		if (this->listOfSection[i]->getID() == id)
		{
			delete this->listOfSection[i];
			this->listOfSection[i] = nullptr;
			this->listOfSection.erase(this->listOfSection.begin() + i);
			return true;
		}
	}
	return false;
}

bool Department::addStaff(Employee* staff)
{
	if (staff->getID().find("MNG") != string::npos)
	{
		this->manager = staff;
		return true;
	}
	for (auto se : listOfSection)
	{
		if (staff->getID().find(se->getID()) != string::npos)
		{
			se->addStaff(staff);
			return true;
		}
	}
	return false;
}

bool Department::removeStaff(string id)
{
	for (auto se : listOfSection)
	{
		if (id.find(se->getID()) != string::npos)
		{
			return se->removeStaff(id);
		}
	}
	return false;
}

string Department::getName()
{
	return this->name;
}

string Department::getID()
{
	return this->id;
}

int Department::getNumOfSection()
{
	return this->listOfSection.size();
}

int Department::getNumOfStaff()
{
	int num = 0;
	if (manager)
		num++;
	for (auto v : this->listOfSection)
	{
		num += v->getNumOfStaffs();
	}
	return num;
}

Section* Department::findSection(string id)
{
	for (auto v : this->listOfSection)
	{
		if (v->getID() == id)
			return v;
	}
	return nullptr;
}

Employee* Department::findEmployee(string id)
{
	for (auto v : this->listOfSection)
	{
		if (id.find(v->getID()) != string::npos)
			return v->findStaff(id);
	}
	return nullptr;
}

long Department::totalSalary()
{
	long total = 0;
	if (this->manager)
		total = this->manager->salary();
	for (auto st : this->listOfSection)
	{
		total += st->totalSalary();
	}
	return total;
}

long Department::averageSalary()
{
	return this->totalSalary() / this->getNumOfStaff();
}

Employee* Department::highestSalaryStaff()
{
	Employee* mS = this->manager;
	Employee* temp = nullptr;
	for (auto v : this->listOfSection)
	{
		temp = v->highestSalaryStaff();
		if (mS->salary() < temp->salary())
			mS = temp;
	}
	return mS;
}

void Department::outputDiagram(int level)
{
	outputTab(level);
	cout << "[" << this->id << "] " << this->name << endl;
	this->manager->outputDiagram(level + 1);
	for (auto st : this->listOfSection)
	{
		st->outputDiagram(level + 1);
	}
}

ostream& operator<<(ostream& out, const Department& department)
{
	out << "Department ID: " << department.id << endl;
	out << "Name: " << department.name << endl;
	out << "List of Section:\n";
	if (department.manager)
	{
		out << "\tManager: " << department.manager << endl;
	}
	for (auto st : department.listOfSection)
	{
		out << "\t" << *st << endl;
	}
	return out;
	// TODO: insert return statement here
}
