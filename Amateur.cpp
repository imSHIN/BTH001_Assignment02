#include "Amateur.h"
#include <sstream>



Amateur::Amateur(string name, int startNum, int age):Runner(name,startNum)
{
	this->age = age;
}

Amateur::~Amateur()
{
}

Amateur::Amateur(const Amateur & origin):Runner(origin)
{
	this->age = origin.age;
}


int Amateur::getAge() const
{
	return this->age;
}

string Amateur::toStringSpecial() const
{
	stringstream converter;
	converter << " Age: " << this->age << "\n";
	return converter.str();
}


