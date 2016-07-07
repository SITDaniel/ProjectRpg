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

    void SetMapIndex(int map_index);
    int GetMapIndex();

	static World& GetInstance();

    Character& GetCharacter();

private:
	World();
	~World();

	Map* maps;

	Character player;
    int size;
    int map_index;
};