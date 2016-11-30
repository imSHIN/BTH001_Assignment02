#ifndef RUNNER_H
#define RUNNER_H
#include <string>
using namespace std;

class Runner
{
private:
	string name;
	int startNum;
public:
	Runner(string name="?", int startNum=1);
	virtual ~Runner();
	
	void setName(string name);
	void setStartNum(int startNum);
	
	string getName() const;
	int getStartNum() const;
	
	virtual string toString() const;
	virtual string toStringSpecial() const=0;
	
};

#endif // !RUNNER_H

