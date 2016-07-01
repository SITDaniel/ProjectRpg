#pragma once

#include "Character.h"

class Map;

class World
{
public:
	Character& GetPlayer();

    Map& operator[] (int i);
	
    void ShowMaps();
	void CreateMaps(int size);
	void InitCharacter();

	static World& GetInstance();

private:
	World();
	~World();

	Map* maps;

	Character player;
    int size;
};