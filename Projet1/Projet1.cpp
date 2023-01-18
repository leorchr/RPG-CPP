#include <iostream>
#include <random>
#include "Pokemon.h"

using namespace std;

int main()
{
	cout << "Let's play Pokemon!\n";

	Pokemon Pikachu("Pikachu", "jaune", 15);
	Pokemon Reshiram("Reshiram", "charismatique", 300);
	Ability Eclair("Eclair", 10, 20);
	Ability ViveAttaque("Vive Atttaque", 15, 15);
	Ability FlammeCroix("Flamme Croix", 50,10);
	Ability DracoChoc("Draco-Choc",85, 5);

	Reshiram.Learn(FlammeCroix, 0);
	Reshiram.Learn(DracoChoc, 1);
	Pikachu.Learn(Eclair, 0);
	Pikachu.Learn(ViveAttaque,1);
	Pikachu.Display();
	Reshiram.Display();
	Pikachu.Attack(Reshiram, 0);
	Pikachu.Attack(Reshiram, 1);
	Reshiram.Attack(Pikachu, 0);
}