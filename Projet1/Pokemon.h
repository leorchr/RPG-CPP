#include <string>
#include "Ability.h"

#pragma once
class Pokemon
{
private :
	std::string mName;
	std::string mDescription;
	int mHealthPoints;
	std::string mAbilities[4];
	void PassOut();

public :
	Pokemon(std::string name, std::string description, int hp);
	~Pokemon();

	void Attack(Pokemon& target, Ability competence);
	void TakeDamage(int damages);
	void Heal(int quantity);
	void Display();
};

