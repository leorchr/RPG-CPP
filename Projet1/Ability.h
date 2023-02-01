#include <string>
#include "Elements.h"
#pragma once

class Ability
{
private:
	std::string mName;
	std::string mDescription;
	int mDamages;
	int mPP;
	int mPPMax;
	Elements mType;

public:
	Ability();
	Ability(std::string name, std::string description, int hp, int mPPMax, Elements type);
	Ability(std::string name, int hp, int PPMax, Elements type);
	~Ability();

	std::string GetName();
	int GetDamages();
	int GetPP();
	int GetPPMax();
	Elements GetType();
	void Use();
	void Reset();
};

