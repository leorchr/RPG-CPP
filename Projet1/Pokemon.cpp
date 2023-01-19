#include "Pokemon.h"
#include <iostream>
using namespace std;

Pokemon::Pokemon(std::string name, std::string description, int hp) {
	mName = name;
	mDescription = description;
	mHealthPoints = hp;
}

Pokemon::~Pokemon() {}

void Pokemon::Attack(Pokemon& target, int ability) {
	if (!CanAttack(ability)) {
		return;
	}
	float coefficient = 1 + ((rand() % 4) - 2) / 10.0;
	int damages = mAbilities[ability].GetDamages() * coefficient;

	mAbilities[ability].Use();

	cout << mName << " attaque " << target.mName << " avec " 
		 << mAbilities[ability].GetName() << endl
		 << "Il fait " << damages << " dommages.\n";
	target.TakeDamage(damages);
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
		cout << i+1 << " - " << mAbilities[i].GetName()
			 << " Puissance -> " << mAbilities[i].GetDamages()
			 << " PP -> " << mAbilities[i].GetPP() << endl;
	}

}

bool Pokemon::CanAttack(int ability) {
	if (ability < 0 || ability > 3
		|| mAbilities[ability].GetName() == "Default"
		|| mAbilities[ability].GetPP() <= 0) {
		cerr << mName << " n'a pas pu attaquer avec l'attaque " << ability << endl;
		return false;
	}
	return true;
}