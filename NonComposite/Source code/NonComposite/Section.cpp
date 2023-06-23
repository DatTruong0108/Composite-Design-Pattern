#include "Section.h"

Section::Section(string name, string id)
{
	this->name = name;
	this->id = id;
}

Section::~Section()
{
	for (int i = this->staff.size() - 1; i >= 0; i--)
	{
		if (this->staff[i]) {
			delete this->staff[i];
			this->staff[i] = nullptr;
		}
	}
	this->staff.clear();
}

void Section::addStaff(Employee* staff)
{
	this->staff.push_back(staff);
}

bool Section::removeStaff(string id)
{
	for (int i = 0; i < this->staff.size(); i++)
	{
		if (this->staff[i]->getID() == id)
		{
			delete this->staff[i];
			this->staff[i] = nullptr;
			this->staff.erase(this->staff.begin() + i);
			return true;
		}
	}
	return false;
}

long Section::totalSalary()
{
	long total = 0;
	for (auto st : this->staff)
	{
		total += st->salary();
	}
	return total;
}

string Section::getName()
{
	return this->name;
}

string Section::getID()
{
	return this->id;
}

int Section::getNumOfStaffs()
{
	return this->staff.size();
}

long Section::averageSalary()
{
	return this->totalSalary() / this->staff.size();
}

Employee* Section::findStaff(string id)
{
	for (auto v : this->staff)
	{
		if (v->getID() == id)
			return v;
	}
	return nullptr;
}

Employee* Section::highestSalaryStaff()
{
	if (this->staff.size() == 0)
		return nullptr;

	Employee* mS = this->staff[0];
	for (auto v : this->staff)
	{
		if (mS->salary() < v->salary())
			mS = v;
	}
	return mS;
}

void Section::outputDiagram(int level)
{
	outputTab(level);
	cout << "[" << this->id << "] " << this->name << endl;
	for (auto st : this->staff)
	{
		st->outputDiagram(level + 1);
	}
}

ostream& operator<<(ostream& out, const Section& section)
{
	out << "Section ID: " << section.id << endl;
	out << "Name: " << section.name << endl;
	out << "List of Employee:\n";
	for (auto st : section.staff)
	{
		out << "\t" << *st << endl;
	}
	return out;
	// TODO: insert return statement here
}
