#include "Tile.h"
#include "Enemy.h"

#include <stdlib.h>
#include <time.h>

Tile::Tile()
{
	enemies_size = 0;
}

Tile::Tile(const Tile::TileType& type)
{
	this->type = type;
}

Tile::~Tile()
{
}

void Tile::SetType(const TileType& type)
{
	this->type = type;
}

const Tile::TileType& Tile::GetType()
{
	return type;
}

void Tile::GenerateEnemies(int size)
{
	if (size > 0)
	{
		enemies_size = size;
		enemies = new Enemy[enemies_size];

		for (int i = 0; i < enemies_size; i++)
		{
			int min_dmg = rand() % 10 + 1;
			int max_dmg = min_dmg + rand() % 10 + 1;

			Damage& dmg = enemies[i].GetDmg();

			dmg.SetMinDamage(min_dmg);
			dmg.SetMaxDamage(max_dmg);

			Health& hp = enemies[i].GetHp();

			int full_health = rand() % 40 + 10;

			hp.SetMaxHealth(full_health);
		}
	}
}

Enemy* Tile::GetEnemies()
{
	return enemies;
}

Enemy& Tile::operator[](int index)
{
	return enemies[index];
}

int Tile::GetEnemiesSize()
{
	return enemies_size;
}