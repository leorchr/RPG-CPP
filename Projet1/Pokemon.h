#include <string>
#include <random>
#include "Ability.h"
#include "Elements.h"
#pragma once

class Pokemon
{
private :
	std::string mName;
	std::string mDescription;
	int mHealthPoints;
	Ability mAbilities[4];
	void PassOut();
	Elements mType;

public :
	Pokemon(std::string name, std::string description, int hp, Elements type);
	~Pokemon();

	void Attack(Pokemon& target, int ability);
	bool CanAttack(int ability);
	void Learn(Ability ability,int place);
	void TakeDamage(int damages);
	void Heal(int quantity);
	void Display();
	bool Dead();
	void DisplayAttack();
	Elements GetType();
};

