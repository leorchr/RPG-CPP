#include "Ability.h"
#include <iostream>
using namespace std;

Ability::Ability(std::string name, std::string description, int damages) {
	mName = name;
	mDescription = description;
	mDamages = damages;
}

Ability::Ability(std::string name, int damages) {
	mName = name;
	mDescription = "Description manquante";
	mDamages = damages;
}

Ability::Ability() {
	mName = "Default";
	mDescription = "Description manquante";
	mDamages = 0;
}


Ability::~Ability() {}

int Ability::GetDamages() {
	return mDamages;
}