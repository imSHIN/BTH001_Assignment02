#include "ProRunner.h"
#include <sstream>



ProRunner::ProRunner(string name, int startNum, string club, string sponsor) :Runner(name, startNum)
{
	this->club = club;
	this->sponsor = sponsor;
};

ProRunner::~ProRunner()
{
}

ProRunner::ProRunner(const ProRunner & origin):Runner(origin)
{
	this->club = origin.club;
	this->sponsor = origin.sponsor;
}


string ProRunner::getSponsor() const
{
	return this->sponsor;
}

string ProRunner::getClub() const
{
	return this->club;
}

void ProRunner::changeSponsor(string newSponsor)
{
	this->sponsor = newSponsor;
}

string ProRunner::toStringSpecial() const
{
	stringstream converter;
	converter << " Club: " << this->club << " Sponsor: " << this->sponsor << "\n";
	return converter.str();
}








