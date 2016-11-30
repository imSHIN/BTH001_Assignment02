#include "RunnerRegister.h"

void RunnerRegister::expand()
{
	this->capacity += 5;
	Runner* *temp = new Runner*[this->capacity];
	for (int i = 0; i <this->nrOfRunners; i++)
	{
		temp[i] = this->runners[i];
	}
	delete[] this->runners;
	this->runners = temp;
	for (int i = this->nrOfRunners; i < this->capacity; i++)
	{
		this->runners[i] = nullptr;
	}
}

void RunnerRegister::freeMemory()
{
	for (int i = 0; i < this->nrOfRunners; i++)
	{
		delete this->runners[i];
	}
	delete[] this->runners;
}

RunnerRegister::RunnerRegister(int capacity)
{
	this->capacity = capacity;
	this->nrOfRunners = 0;
	this->runners = new Runner*[this->capacity];
	for (int i = 0; i < this->capacity; i++)
	{
		this->runners[i] = nullptr;
	}
}

RunnerRegister::~RunnerRegister()
{
	this->freeMemory();
}

RunnerRegister::RunnerRegister(const RunnerRegister & origin)
{
	this->capacity = origin.capacity;
	this->nrOfRunners = origin.nrOfRunners;

	this->runners = new Runner*[this->capacity];
	for (int i = 0; i < this->nrOfRunners; i++)
	{
		ProRunner* prorunnerptr = dynamic_cast<ProRunner*>(origin.runners[i]);
		if (prorunnerptr!=nullptr)
		{
			this->runners[i] = new ProRunner(*prorunnerptr);
		}
		else
		{
			Amateur* amateurptr = dynamic_cast<Amateur*>(origin.runners[i]);
			if (amateurptr!=nullptr)
			{
				this->runners[i] = new Amateur(*amateurptr);
			}
		}
	}

	for (int i = this->nrOfRunners; i < this->capacity; i++)
	{
		this->runners[i] = nullptr;
	}
}

void RunnerRegister::operator=(const RunnerRegister & origin)
{
	if (this!=&origin)
	{
		this->freeMemory();

		this->capacity = origin.capacity;
		this->nrOfRunners = origin.nrOfRunners;

		this->runners = new Runner*[this->capacity];
		for (int i = 0; i < this->nrOfRunners; i++)
		{
			ProRunner* prorunnerptr = dynamic_cast<ProRunner*>(origin.runners[i]);
			if (prorunnerptr != nullptr)
			{
				this->runners[i] = new ProRunner(*prorunnerptr);
			}
			else
			{
				Amateur* amateurptr = dynamic_cast<Amateur*>(origin.runners[i]);
				if (amateurptr != nullptr)
				{
					this->runners[i] = new Amateur(*amateurptr);
				}
			}
		}

		for (int i = this->nrOfRunners; i < this->capacity; i++)
		{
			this->runners[i] = nullptr;
		}
	}
}

void RunnerRegister::addProRunner(string name, int startNum, string club, string sponsor)
{
	if (this->nrOfRunners == this->capacity)
	{
		expand();
	}
	this->runners[this->nrOfRunners++] = new ProRunner(name, startNum, club, sponsor);
}

void RunnerRegister::addAmateur(string name, int startNum, int age)
{
	if (this->nrOfRunners==this->capacity)
	{
		expand();
	}
	this->runners[this->nrOfRunners++] = new Amateur(name, startNum, age);
}

bool RunnerRegister::removeArunner(int startNum)
{
	bool exist = false;
	int index = 0;
	if (index< this->nrOfRunners && this->runners[index]->getStartNum() !=startNum)
	{
		index++;
	}
	if (index<this->nrOfRunners)
	{
		exist = true;
		delete this->runners[index];
		this->runners[index] = this->runners[--this->nrOfRunners];
		this->runners[this->nrOfRunners] = nullptr;
	}
	return exist;

}

int RunnerRegister::getNrOfRunners() const
{
	return this->nrOfRunners;
}

int RunnerRegister::getNrOfProRunners() const
{
	int nrOfProRun = 0;
	for (int i = 0; i < this->nrOfRunners; i++)
	{
		if (dynamic_cast<ProRunner*>(runners[i])!=nullptr)
		{
			nrOfProRun++;
		}
	}
	return nrOfProRun;
}

int RunnerRegister::getNrOfAmateurs() const
{
	int nrOfAma=0;
	for (int i = 0; i < this->nrOfRunners; i++)
	{
		if (dynamic_cast<Amateur*>(runners[i])!=nullptr)
		{
			nrOfAma++;
		}
	}
	return nrOfAma;
}

bool RunnerRegister::getAllRunners(string run[], int size) const
{
	bool allRunnersIncluded = true;
	int nrOfRunnersAsStrings = this->nrOfRunners;
	if (size<this->nrOfRunners)
	{
		allRunnersIncluded = false;
		nrOfRunnersAsStrings = size;
	}
	for (int i = 0; i < nrOfRunnersAsStrings; i++)
	{
		run[i] = this->runners[i]->toString();
	}
	return allRunnersIncluded;
}

bool RunnerRegister::getAllProRunners(string prorun[], int size) const
{
	bool allProRunnersIncluded = true;
	int nrOfProRunnersAsStrings = this->getNrOfProRunners();
	if (size<nrOfProRunnersAsStrings)
	{
		allProRunnersIncluded = false;
		nrOfProRunnersAsStrings = size;
	}
	int index = 0;
	for (int i = 0; i < this->nrOfRunners; i++)
	{
		if (dynamic_cast<ProRunner*>(this->runners[i])!=nullptr)
		{
			prorun[index++] = this->runners[i]->toString();
		}
	}
	return allProRunnersIncluded;
}

bool RunnerRegister::getAllAmateurs(string ama[], int size) const
{
	bool allAmateursIncluded = true;
	int nrOfAmateursAsStrings = this->getNrOfAmateurs();
	if (size<nrOfAmateursAsStrings)
	{
		allAmateursIncluded = false;
		nrOfAmateursAsStrings = size;
	}
	int index = 0;
	for (int i = 0; i < this->nrOfRunners; i++)
	{
		if (dynamic_cast<Amateur*>(this->runners[i]) != nullptr)
		{
			ama[index++] = this->runners[i]->toString();
		}
	}
	return allAmateursIncluded;
}

bool RunnerRegister::changeSponsor(string sponsor, int startNum)
{
	int pos = -1;
	for (int i = 0; i < this->nrOfRunners&&pos==-1; i++)
	{
		if (this->runners[i]->getStartNum()==startNum)
		{
			pos = i;
		}
	}

	bool sponsorChanged = false;
	if (pos!=-1)
	{
		ProRunner *prorunner = dynamic_cast<ProRunner*>(this->runners[pos]);
		if (prorunner!=nullptr)
		{
			prorunner->changeSponsor(sponsor);
			sponsorChanged = true;
		}
	}
	return sponsorChanged;
}

bool RunnerRegister::getSpecificAmateurs(string spAma[], int lowAge, int upAge)
{
	bool spAmateursIncluded = false;
	
	int index = 0;
	for (int i = 0; i <this->nrOfRunners ; i++)
	{
		Amateur *amateur = dynamic_cast<Amateur*>(this->runners[i]);
		if (amateur!=nullptr)
		{
			if (amateur->getAge()>=lowAge&&amateur->getAge()<=upAge)
			{
				spAma[index++] = this->runners[i]->toString();
				spAmateursIncluded = true;
			}
		}
	}
	for (int i = index; i < this->getNrOfAmateurs(); i++)
	{
		spAma[i] = nullptr;
	}
	return spAmateursIncluded;
}






