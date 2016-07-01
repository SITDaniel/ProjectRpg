#pragma once

class CharacterLevel
{
public:
	CharacterLevel();
	~CharacterLevel();

	int GetLevel();

	int GetCurrrentExperience();
	int GetNextExperience();

	void AddExperience(int amount);

private:
	int level;

	int currentExperience;
	int nextExperience;
};