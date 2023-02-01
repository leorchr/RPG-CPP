#include "Ability.h"
#include <iostream>
using namespace std;

Ability::Ability(std::string name, std::string description, int damages, int ppmax, Elements type) {
	mName = name;
	mDescription = description;
	mDamages = damages;
	mPP = ppmax;
	mPPMax = ppmax;
	mType = type;
}

Ability::Ability(std::string name, int damages, int ppmax, Elements type) {
	mName = name;
	mDescription = "Description manquante";
	mDamages = damages;
	mPP = ppmax;
	mPPMax = ppmax;
	mType = type;
}

Ability::Ability() {
	mName = "Default";
	mDescription = "Description manquante";
	mDamages = 0;
	mPP = 0;
	mPPMax = 0;
	mType = Elements::Normal;
}


Ability::~Ability() {}

int Ability::GetDamages() {
	return mDamages;
}

string Ability::GetName() {
	return mName;
}

int Ability::GetPP() {
	return mPP;
}

int Ability::GetPPMax() {
	return mPPMax;
}

Elements Ability::GetType() {
	return mType;
}

void Ability::Use() {
	mPP--;
}

void Ability::Reset() {
	mPP = mPPMax;
}