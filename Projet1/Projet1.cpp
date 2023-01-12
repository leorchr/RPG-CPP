#include <iostream>
#include <random>
#include "Pokemon.h"

using namespace std;

int main()
{
	cout << "Let's play Pokemon!\n";

	Pokemon Pikachu("Pikachu", "jaune", 15);
	Pokemon Reshiram("Reshiram", "charismatique", 300);
	Ability Eclair("Eclair", 15);
	Ability ViveAttaque("Vive Atttaque",15);

	Pikachu.Display();
	Reshiram.Display();
	Pikachu.Attack(Reshiram, Eclair);
	Pikachu.Display();
	Reshiram.Display();
}