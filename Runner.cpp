#include "Runner.h"
#include <sstream>

Runner::Runner(string name, int startNum)
{
	this->name = name;
	this->startNum = startNum;
}

Runner::~Runner()
{
}

void Runner::setName(string name)
{
	this->name = name;
}

void Runner::setStartNum(int startNum)
{
	this->startNum = startNum;
}

string Runner::getName() const
{
	return this->name;
}

int Runner::getStartNum() const
{
	return this->startNum;
}

string Runner::toString() const
{
	stringstream converter;
	converter << "Name: " << this->name << " StartNumber: " << this->startNum<<this->toStringSpecial();
	return converter.str();
}
