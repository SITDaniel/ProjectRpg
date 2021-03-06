#include "CharacterLevel.h"
#include "Character.h"


CharacterLevel::CharacterLevel()
{
	
	level = 1;
	previous_level = level - 1;

	currentExperience = 0;
	nextExperience = 100;
}

CharacterLevel::~CharacterLevel()
{
}

int CharacterLevel::GetLevel()
{
	return level;
}

int CharacterLevel::GetCurrrentExperience()
{
	return currentExperience;
}

int CharacterLevel::GetNextExperience()
{
	return nextExperience;
}

void CharacterLevel::AddExperience(int amount)
{
	currentExperience += amount;

	if (currentExperience >= nextExperience)
	{
		currentExperience -= nextExperience;

		nextExperience += (int)((float)nextExperience * 0.25f);

		level++;

		
        
	}
}

bool CharacterLevel::HasLeveled()
{
	if (level > previous_level + 1)
		return true;
	else
		return false;
}