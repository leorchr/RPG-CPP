#pragma once
enum class Elements {
	Normal,
	Fire,
	Water,
	Grass,
	Electric,
	Dragon
};

float static ResistanceMat[6][6]{ 
	{1,1,1,1,1,1},
	{1,2,0.5,0.5,1,0.5},
	{1,0.5,0.5,2,1,0.5},
	{1,0.5,2,0.5,1,0.5},
	{1,0.5,1,2,0.5,0.5},
	{1,1,1,1,1,1} };

std::string static ElementsToStr(Elements element) {
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
	case Elements::Electric:
		return "Electric";
		break;
	case Elements::Dragon:
		return "Dragon";
		break;
	default:
		return "Normal";
		break;
	}
}