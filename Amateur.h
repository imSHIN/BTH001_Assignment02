#ifndef AMATEUR_H
#define AMATEUR_H
#include "Runner.h"

class Amateur:public Runner
{
private:
	int age;
public:
	Amateur(string name="?", int startNum=1, int age=0);
	virtual ~Amateur();

	Amateur(const Amateur& origin);

	int getAge() const;

	virtual string toStringSpecial() const;
};
#endif // !AMATEUR_H

