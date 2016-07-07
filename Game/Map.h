#pragma once

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class World;
class Character;
class Tile;

class Map
{
public:
    Map();
	Map(int width, int height);

    ~Map();

    void operator()(const string& map_name);
    void operator()(int width, int height);

	void SetCharacter(Character* character);

    void Display();
	void DisplayMap();

	void GenerateMap();

	void Move(int next_x, int next_y);
	void Fight();
   
    void GetInput();
    void GoRight();
    void GoLeft();
    void GoUp();
    void GoDown();


private:
	char DisplayTile(Tile& tile);

	Character* character;

	Tile** tiles;
    string map_name;

	bool fightStarted;
	bool hasKilled;

    int width;
    int height;

    bool hasTransitioned;

   

    
};