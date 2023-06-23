#include "Company.h"

Company::Company(string name)
{
	this->name = name;
}

Company::~Company()
{
	if (this->ceo)
	{
		delete this->ceo;
		this->ceo = nullptr;
	}
	for (int i = this->listOfDepartment.size() - 1; i >= 0; i--)
	{
		if (this->listOfDepartment[i]) {
			delete this->listOfDepartment[i];
			this->listOfDepartment[i] = nullptr;
		}
	}
	this->listOfDepartment.clear();
}

void Company::addDepartment(Department* department)
{
	this->listOfDepartment.push_back(department);
}

bool Company::removeDepartment(string id)
{

	for (int i = 0; i < this->listOfDepartment.size(); i++)
	{
		if (this->listOfDepartment[i]->getID() == id)
		{
			delete this->listOfDepartment[i];
			this->listOfDepartment[i] = nullptr;
			this->listOfDepartment.erase(this->listOfDepartment.begin() + i);
			return true;
		}
	}
	return false;
}

bool Company::addSection(Section* section)
{
	for (auto dm : listOfDepartment)
	{
		if (section->getID().find(dm->getID()) != string::npos)
		{
			dm->addSection(section);
			return true;
		}
	}
	return false;
}

bool Company::removeSection(string id)
{
	for (auto dm : listOfDepartment)
	{
		if (id.find(dm->getID()) != string::npos)
		{
			return dm->removeSection(id);
		}
	}
	return false;
}

bool Company::addStaff(Employee* staff)
{
	if (staff->getID().find("CEO") != string::npos)
	{
		this->ceo = staff;
		return true;
	}
	for (auto dm : listOfDepartment)
	{
		if (staff->getID().find(dm->getID()) != string::npos)
		{
			return dm->addStaff(staff);
		}
	}
	return false;
}

bool Company::removeStaff(string id)
{
	for (auto dm : listOfDepartment)
	{
		if (id.find(dm->getID()) != string::npos)
		{
			return dm->removeStaff(id);
		}
	}
	return false;
}

string Company::getName()
{
	return this->name;
}

string Company::getProduct()
{
	return this->product;
}

void Company::setProduct(string product)
{
	this->product = product;
}

int Company::getNumOfDepartment()
{
	return this->listOfDepartment.size();
}

int Company::getNumOfSection()
{
	int num = 0;
	for (auto v : this->listOfDepartment)
	{
		num += v->getNumOfSection();
	}
	return num;
}

int Company::getNumOfStaff()
{
	int num = 0;
	if (ceo)
		num++;
	for (auto v : this->listOfDepartment)
	{
		num += v->getNumOfStaff();
	}
	return num;
}

long Company::totalSalary()
{
	long total = 0;
	if (this->ceo)
		total = this->ceo->salary();
	for (auto st : this->listOfDepartment)
	{
		total += st->totalSalary();
	}
	return total;
}

long Company::averageSalary()
{
	return this->totalSalary() / this->getNumOfStaff();
}

Department* Company::findDepartment(string id)
{
	for (auto v : this->listOfDepartment)
	{
		if (v->getID() == id)
			return v;
	}
	return nullptr;
}

Section* Company::findSection(string id)
{
	for (auto v : this->listOfDepartment)
	{
		if (id.find(v->getID()) != string::npos)
			return v->findSection(id);
	}
	return nullptr;
}

Employee* Company::findEmployee(string id)
{
	for (auto v : this->listOfDepartment)
	{
		if (id.find(v->getID()) != string::npos)
			return v->findEmployee(id);
	}
	return nullptr;
}

Employee* Company::highestSalaryStaff()
{
	Employee* mS = this->ceo;
	Employee* temp = nullptr;
	for (auto v : this->listOfDepartment)
	{
		temp = v->highestSalaryStaff();
		if (mS->salary() < temp->salary())
			mS = temp;
	}
	return mS;
}

void Company::outputDiagram(int level)
{
	cout << this->name << " - Product: " << this->product << endl;
	cout << this->getNumOfDepartment() << " departments, " << this->getNumOfSection() << " sections, " << this->getNumOfStaff() << " staffs\n";
	this->ceo->outputDiagram(level + 1);
	for (auto st : this->listOfDepartment)
	{
		st->outputDiagram(level + 1);
	}
}

ostream& operator<<(ostream& out, const Company& company)
{
	out << "Name: " << company.name << endl;
	out << "Product: " << company.product << endl;
	out << "List of Section:\n";
	if (company.ceo)
	{
		out << "\tCEO: " << company.ceo << endl;
	}
	for (auto st : company.listOfDepartment)
	{
		out << "\t" << *st << endl;
	}
	return out;
	// TODO: insert return statement here
}
