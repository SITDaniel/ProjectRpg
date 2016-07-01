#include "Map.h"
#include "Character.h"
#include "Tile.h"
#include "Enemy.h"

Map::Map()
{
    map_name = "unnamed map";

    width = 0;
    height = 0;

	fightStarted = false;
}

Map::Map(int width, int height)
{
	this->width = width;
	this->height = height;

	GenerateMap();

	fightStarted = false;
}

Map::~Map()
{
    for (int i = 0; i < width; i++)
    {
        delete[] tiles[i];
    }
}

void Map::operator()(const string& map_name)
{
    this->map_name = map_name;
}

void Map::operator()(int width, int height)
{
    srand((unsigned int)time(0));

    this->width = width;
    this->height = height;

	GenerateMap();
}

void Map::Display()
{
	cout << "\n========================================\n" << endl;

    cout << "Map name: " << map_name <<"\n" << endl;

	character->DisplayHealth();
	character->DisplayLevel();

	if (!fightStarted)
	{
		character->DisplayPosition();

		DisplayMap();
	}

	bool is_dead = character->GetHealth().IsDead();

	if (!is_dead)
	{
		GetInput();
	}
	else
	{
		cout << "\nYou have died\n" << endl;
	}
}

void Map::GetInput()
{
	cout << "\nInstructions:\n" << endl;

	if (!fightStarted)
	{
		cout << "Movement\n" << endl;

		cout << "Left: l\n";
		cout << "Right: r\n";
		cout << "Down: d\n";
		cout << "Up: u\n" << endl;
	}

	cout << "Fighting\n" << endl;

	cout << "Fight: f\n" << endl;

	char i;
	cout << "Your choice: ";
    cin >> i;

    if (i == 'r')
    {
        GoRight();
    }
    else if (i == 'l')
    {
        GoLeft();
    }
    else if (i == 'u')
    {
        GoUp();
    }
    else if (i == 'd')
    {
        GoDown();
    }
	else if (i == 'f')
	{
		if (tiles[character->GetPositionX()][character->GetPositionY()].GetEnemiesSize() > 0)
		{
			Fight();
		}
		else
		{
			cout << "You do not have any enemies here" << endl;
		}
	}

    Display();
}

void Map::GoRight()
{
    int next = character->GetPositionY() + 1;

    if (next < height)
    {
		Move(character->GetPositionX(), next);

		character->IncrementPositionY();
    }
    else
    {
        cout << "\nYou've hit a wall\n";
    }
}

void Map::GoLeft()
{
    int previous = character->GetPositionY() - 1;

    if (previous >= 0)
    {
		Move(character->GetPositionX(), previous);

		character->DecrementPositionY();
    }
    else
    {
        cout << "\nYou've hit a wall\n";
    }
}

void Map::GoUp()
{
    int previous = character->GetPositionX() - 1;

    if (previous >= 0)
    {
		Move(previous, character->GetPositionY());

		character->DecrementPositionX();
    }
    else
    {
        cout << "\nYou've hit a wall\n";
    }
}

void Map::GoDown()
{
    int next = character->GetPositionX() + 1;
    
    if (next < width)
    {
		Move(next, character->GetPositionY());

		character->IncrementPositionX();
    }
    else
    {
        cout << "\nYou've hit a wall\n";
    }
}

void Map::SetCharacter(Character* character)
{
	this->character = character;
}

void Map::GenerateMap()
{
	tiles = new Tile*[width];

	for (int i = 0; i < width; i++)
	{
		tiles[i] = new Tile[height];
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int tile_rand = rand() % 6 + 1;

			if (tile_rand == 3)
			{
				tiles[i][j].SetType(Tile::HOLE);
			}
			else
			{
				tiles[i][j].SetType(Tile::GRASS);

				int enemies_rand = rand() % 10 + 1;

				if (enemies_rand > 5)
				{
					int enemies_size = rand() % 3 + 1;

					tiles[i][j].GenerateEnemies(enemies_size);
				}
			}
		}
	}
}

void Map::Move(int next_x, int next_y)
{
	if (tiles[next_x][next_y].GetType() == Tile::HOLE)
	{
		int lost_life = (rand() % 15 + 1) + 4;

		character->GetHealth().LoseHealth(lost_life);

		cout << "\nHole warning!\nYou have lost: " << lost_life << " life points\n";
	}
}

char Map::DisplayTile(Tile& tile)
{
	if (tile.GetType() == Tile::GRASS)
	{
		return 'g';
	}
	else if (tile.GetType() == Tile::HOLE)
	{
		return 'h';
	}

	return 'u';
}

void Map::Fight()
{
	cout << "Fight started" << endl;

	fightStarted = true;

	Tile& tile = tiles[character->GetPositionX()][character->GetPositionY()];

	for (int i = 0; i < tile.GetEnemiesSize(); i++)
	{
		Enemy& enemy = tile.GetEnemies()[i];

		if (!enemy.GetHp().IsDead())
		{
			// player turn
			int damage = character->GetDamage().GetMaxDamage();

			enemy.GetHp().LoseHealth(damage);

			if (!enemy.GetHp().IsDead())
			{
				// enemy turn
				int enemy_dmg = enemy.GetDmg().GetMinDamage();

				character->GetHealth().LoseHealth(enemy_dmg);
			}
			else
			{
				character->GetLevel().AddExperience(rand() % 50 + 30);
			}

			break;
		}
	}
}

void Map::DisplayMap()
{
	if (width > 0 && height > 0)
	{
		Tile& tile = tiles[character->GetPositionX()][character->GetPositionY()];

		cout << "\nEnemies: " << tile.GetEnemiesSize() << endl;

		for (int i = 0; i < width; i++)
		{
			cout << "\n";

			for (int j = 0; j < height; j++)
			{
				if (character->GetPositionX() == i &&
					character->GetPositionY() == j)
				{
					cout << 'p' << " ";
				}
				else
				{
					if (j < height - 1)
					{
						cout << DisplayTile(tiles[i][j]) << " ";
					}
					else
					{
						cout << DisplayTile(tiles[i][j]);
					}
				}
			}
		}

		cout << "\n\n";
	}
}
