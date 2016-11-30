#ifndef RUNNERREGISTER_H
#define RUNNERREGISTER_H
#include "ProRunner.h"
#include "Amateur.h"

class RunnerRegister
{
private:
	int nrOfRunners;
	int capacity;
	Runner* *runners;

	void expand();
	void freeMemory();

public:
	RunnerRegister(int capacity = 5);
	virtual ~RunnerRegister();
	
	RunnerRegister(const RunnerRegister&origin);
	void operator=(const RunnerRegister&origin);

	void addProRunner(string name, int startNum, string club, string sponsor);
	void addAmateur(string name, int startNum, int age);
	bool removeArunner(int startNum);

	int getNrOfRunners() const;
	int getNrOfProRunners() const;
	int getNrOfAmateurs() const;

	bool getAllRunners(string run[],int size) const;
	bool getAllProRunners(string prorun[],int size) const;
	bool getAllAmateurs(string ama[],int size) const;
	bool changeSponsor(string sponsor,int startNum);
	bool getSpecificAmateurs(string spAma[],int lowAge, int upAge);
};
#endif // !RUNNERREGISTER_H

