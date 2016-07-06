#include "World.h"
#include "Map.h"
#include "Damage.h"

World::World()
{
}

World::~World()
{
	if (maps)
	{
		delete[] maps;
	}
}

Map& World::operator[] (int i)
{
    return maps[i];
}

void World::ShowMaps()
{
    for (int i = 0; i < size; i++)
    {
        maps[i].Display();
    }
}

Character& World::GetPlayer()
{
	return player;
}

void World::CreateMaps(int size)
{
	maps = new Map[size];

	this->size = size;
}

World& World::GetInstance()
{
	static World instance;

	return instance;
}

void World::InitCharacter()
{
	Damage& dmg = player.GetDamage();

	dmg.SetMinDamage(6);
	dmg.SetMaxDamage(12);
}