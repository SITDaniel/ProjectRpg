#pragma once

class Enemy;

class Tile
{
public:
	enum TileType
	{
		GRASS,
		HOLE
	};

	Tile();
	Tile(const TileType& type);

	~Tile();

	void GenerateEnemies(int size);

	void SetType(const TileType& type);
	const TileType& GetType();

	int GetEnemiesSize();

	Enemy& operator[](int index);
	Enemy* GetEnemies();
    void ReduceEnemies(int i);
    

private:
	TileType type;

	Enemy* enemies;
	int enemies_size;
};
