#include <iostream>
#include <random>
#include "Pokemon.h"

using namespace std;

int mAnswer;

int main()
{
	srand(time(NULL));
	cout << (rand() % 10) << endl;
	cout << "Let's play Pokemon!\n";
	cout << "======================\n";
	Pokemon Pikachu("Pikachu", "jaune", 15, Elements::Electric);
	Pokemon Reshiram("Reshiram", "charismatique", 300, Elements::Dragon);
	Ability Eclair("Eclair", 10, 20, Elements::Electric);
	Ability ViveAttaque("Vive Attaque", 15, 15, Elements::Normal);
	Ability BouleElek("Boule Elek", 20, 5, Elements::Electric);
	Ability FlammeCroix("Flamme Croix", 50,10, Elements::Fire);
	Ability DracoChoc("Draco-Choc", 85, 5, Elements::Dragon);
	Ability Charge("Charge", 5, 50, Elements::Normal);

	Reshiram.Learn(FlammeCroix, 0);
	Reshiram.Learn(DracoChoc, 1);
	Reshiram.Learn(Charge, 2);
	Pikachu.Learn(Eclair, 0);
	Pikachu.Learn(ViveAttaque, 1);
	Pikachu.Learn(BouleElek, 2);

	while (!Pikachu.Dead() && !Reshiram.Dead()) {
		cout << "\nDresseur 1 :" << endl;
		cout << "\nQuelle attaque veux-tu utiliser ?" << endl;
		Pikachu.DisplayAttack();
		do {
			cin >> mAnswer;
			mAnswer--;
		} while (!Pikachu.CanAttack(mAnswer));
		Pikachu.Attack(Reshiram, mAnswer);
		if (Pikachu.Dead()) {
			break;
		}
		cout << "==========================================\n";
		cout << "\nDresseur 2 :" << endl;
		cout << "\nQuelle attaque veux-tu utiliser ?" << endl;
		Reshiram.DisplayAttack();
		do {
			cin >> mAnswer;
			mAnswer--;
		} while (!Reshiram.CanAttack(mAnswer));
		Reshiram.Attack(Pikachu, mAnswer);
		cout << "==========================================\n";
	}
}