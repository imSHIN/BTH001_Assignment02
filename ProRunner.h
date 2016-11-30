#ifndef PRORUNNER_H
#define PRORUNNER_H
#include "Runner.h"
class ProRunner:public Runner
{
private:
	string club;
	string sponsor;
public:
	ProRunner(string name="?",int startNum=1,string club="?", string sponsor="?");
	virtual ~ProRunner();

	ProRunner(const ProRunner& origin);
	
	string getSponsor() const;
	string getClub() const;
	
	void changeSponsor(string newSponsor);
	
	virtual string toStringSpecial() const;
};
#endif // !PRORUNNER_H

