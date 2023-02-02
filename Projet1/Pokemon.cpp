#include "Pokemon.h"
#include <iostream>
using namespace std;

Pokemon::Pokemon(std::string name, std::string description, int hp, Elements type) {
	mName = name;
	mDescription = description;
	mHealthPoints = hp;
	mType = type;
}

Pokemon::~Pokemon() {}

void Pokemon::Attack(Pokemon& target, int ability) {
	if (!CanAttack(ability)) {
		return;
	}
	float coefficient = 1 + ((rand() % 4) - 2) / 10.0;
	int damages = mAbilities[ability].GetDamages() * GetBonusResistance(target,ability) * coefficient;

	// DISPLAY BONUS RESISTANCE
	if (GetBonusResistance(target, ability) == 0.5) {
		cout << "Ce n'est pas tres efficace\n";
	}
	if (GetBonusResistance(target, ability) == 2) {
		cout << "C'est tres efficace\n";
	}

	mAbilities[ability].Use();
	cout << mName << " attaque " << target.mName << " avec " 
		 << mAbilities[ability].GetName() << endl
		 << "Il fait " << damages << " dommages.\n";
	target.TakeDamage(damages);
}

float Pokemon::GetBonusResistance(Pokemon& target, int ability) {
	return ResistanceMat[(int)mAbilities[ability].GetType()][(int)target.mType];
}


void Pokemon::TakeDamage(int damages) {
	mHealthPoints -= damages;
	if (mHealthPoints <= 0) {
		PassOut();
	}
	else {
		cout << mName << " a " << mHealthPoints << " hp\n";
	}
}

void Pokemon::Heal(int hp) {
	mHealthPoints += hp;
}

void Pokemon::PassOut() {
	cout << mName << " est epuise...\n";
}

void Pokemon::Display() {
	cout << mName << " est un pokemon qui est " << mDescription << " et qui a " << mHealthPoints << " points de vie\n";
}

void Pokemon::Learn(Ability ability, int place) {
	if (place < 0 || place > 3) {
		cerr << "L'emplacement" << place << "est invalide, donnez un chiffre entre 1 et 4" << endl;
		return;
	}
	mAbilities[place] = ability;
	cout << mName << " a appris la capacite " << ability.GetName() << " a l'emplacement " << place + 1 << endl;
}

bool Pokemon::Dead() {
	return (mHealthPoints <= 0);
}

void Pokemon::DisplayAttack() {
	for (int i = 0; i < 4; i++) {
		if (mAbilities[i].GetName() != "Default") {
			cout << i + 1 << " - " << mAbilities[i].GetName()
				<< "\t | Puissance -> " << mAbilities[i].GetDamages()
				<< "\t | PP -> " << mAbilities[i].GetPP() << " / " << mAbilities[i].GetPPMax()
				<< "\t | Type -> " << ElementsToStr(mAbilities[i].GetType())
				<< endl;
		}
		else {
			cout << i + 1 << " - " << "* \t" << "| Unassigned\n";
		}
	}
}

bool Pokemon::CanAttack(int ability) {
	if (ability < 0 || ability > 3
		|| mAbilities[ability].GetName() == "Default"
		|| mAbilities[ability].GetPP() <= 0) {
		cerr << mName << " n'a pas pu attaquer avec l'attaque " << ability+1 << endl;
		return false;
	}
	return true;
}

Elements Pokemon::GetType() {
	return mType;
}