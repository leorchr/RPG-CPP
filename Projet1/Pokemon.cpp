#include "Pokemon.h"
#include <iostream>
using namespace std;

Pokemon::Pokemon(std::string name, std::string description, int hp) {
	mName = name;
	mDescription = description;
	mHealthPoints = hp;
}

Pokemon::~Pokemon() {}

void Pokemon::Attack(Pokemon& target,Ability competence) {
	cout << mName << " attaque " << target.mName << " avec " << competence.GetDamages() << " dommages.\n";
	target.TakeDamage(competence.GetDamages());
}

void Pokemon::TakeDamage(int damages) {
	mHealthPoints -= damages;
	if (mHealthPoints <= 0) {
		PassOut();
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