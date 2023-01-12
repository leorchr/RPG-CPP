#include <string>
#pragma once

class Ability
{
private:
	std::string mName;
	std::string mDescription;
	int mDamages;

public:
	Ability();
	Ability(std::string name, std::string description, int hp);
	Ability(std::string name, int hp);
	~Ability();

	int GetDamages();

};

