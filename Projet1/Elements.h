#pragma once
enum class Elements {
	Normal,
	Fire,
	Water,
	Grass,
	Flying,
	Fighting,
	Poison,
	Electric,
	Ground,
	Rock,
	Psychic,
	Ice,
	Bug,
	Ghost,
	Steel,
	Dragon,
	Dark,
	Fairy
};

std::string ElementsToStr(Elements element) {
	switch (element)
	{
	case Elements::Normal:
		return "Normal";
		break;
	case Elements::Fire:
		return "Fire";
		break;
	case Elements::Water:
		return "Water";
		break;
	case Elements::Grass:
		return "Grass";
		break;
	case Elements::Flying:
		return "Flying";
		break;
	case Elements::Fighting:
		return "Fighting";
		break;
	case Elements::Poison:
		return "Poison";
		break;
	case Elements::Electric:
		return "Electric";
		break;
	case Elements::Ground:
		return "Ground";
		break;
	case Elements::Rock:
		return "Rock";
		break;
	case Elements::Psychic:
		return "Psychic";
		break;
	case Elements::Ice:
		return "Ice";
		break;
	case Elements::Bug:
		return "Bug";
		break;
	case Elements::Ghost:
		return "Ghost";
		break;
	case Elements::Steel:
		return "Steel";
		break;
	case Elements::Dragon:
		return "Dragon";
		break;
	case Elements::Dark:
		return "Dark";
		break;
	case Elements::Fairy:
		return "Fairy";
		break;
	default:
		return "Normal";
		break;
	}
}