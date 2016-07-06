#pragma once

#include "Health.h"
#include "Inventory.h"
#include "Damage.h"
#include "CharacterLevel.h"

#include <iostream>

using namespace std;

class Character
{
public:
	Character();
	~Character();

	int GetPositionX();
	int GetPositionY();

	void SetPositionX(int x);
	void SetPositionY(int y);

	void IncrementPositionX();
	void IncrementPositionY();

	void DecrementPositionX();
	void DecrementPositionY();

	Health& GetHealth();
	Damage& GetDamage();

	Inventory& GetBag();
	CharacterLevel& GetLevel();

	void DisplayHealth();
	void DisplayLevel();
	void DisplayPosition();

    int GetKills();
    void SetKills(int kills);

    

private:
	Health hp;
	Damage dmg;
	Inventory bag;
	CharacterLevel level;
    int kills;
    
	int position_x;
	int position_y;
};