#include <string>
#pragma once

class Ability
{
private:
	std::string mName;
	std::string mDescription;
	int mDamages;
	int mPP;
	int mPPMax;

public:
	Ability();
	Ability(std::string name, std::string description, int hp, int mPPMax);
	Ability(std::string name, int hp, int PPMax);
	~Ability();

	std::string GetName();
	int GetDamages();
	int GetPP();
	int GetPPMax();
	void Use();
};

