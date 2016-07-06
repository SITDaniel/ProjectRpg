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

	bool HasLeveled();

private:
	int level;
	int previous_level;

	int currentExperience;
	int nextExperience;

	
};