#include "Character.h"

Character::Character()
{
	position_x = 0;
	position_y = 0;
    kills = 0;
    
}

Character::~Character()
{
}

int Character::GetPositionX()
{
	return position_x;
}

int Character::GetPositionY()
{
	return position_y;
}

void Character::SetPositionX(int x)
{
	position_x = x;
}

void Character::SetPositionY(int y)
{
	position_y = y;
}

void Character::IncrementPositionX()
{
	++position_x;
}

void Character::IncrementPositionY()
{
	++position_y;
}

void Character::DecrementPositionX()
{
	--position_x;
}

void Character::DecrementPositionY()
{
	--position_y;
}

Health & Character::GetHealth()
{
	return hp;
}

Inventory& Character::GetBag()
{
	return bag;
}

Damage& Character::GetDamage()
{
	return dmg;
}

CharacterLevel& Character::GetLevel()
{
	return level;
}

void Character::DisplayHealth()
{	
    cout << "Player current health: " << hp.GetCurrentHealth() << " / " << hp.GetMaxHealth() << endl;
}



void Character::DisplayPosition()
{
	cout << "\nPlayer position: " << position_x << " " << position_y << endl;
}

int Character::GetKills()
{
    return kills;
}

void Character::SetKills(int kills)
{
    this->kills = kills;
}

void Character::DisplayStats()
{
    cout << "Player kills :" << GetKills() << endl;
    cout << "Player Level :" << level.GetLevel() <<  endl;  
    cout << "Player current experience: " << level.GetCurrrentExperience() << endl;
    cout << "Player next experience: " << level.GetNextExperience() << endl;
    cout << "Inventory space: " << bag.GetInventorySize();

    //More stats to be added here
}

void Character::SetMapIndex(int map_index)
{
    this->map_index = map_index;
}

int Character::GetMapIndex()
{
    return map_index;
}
