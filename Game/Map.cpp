#include "Map.h"
#include "Character.h"
#include "Tile.h"
#include "Enemy.h"
#include "World.h"
#include <conio.h>




Map::Map()
{
    map_name = "unnamed map";

    width = 0;
    height = 0;

	fightStarted = false;
	hasKilled = false;
    hasTransitioned = false;
    
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
        cout << "Up: u\n";
        cout << "Start fight: f\n";
        cout << "Show stats : ?\n"<<endl;
	}

	else
	{
		if (!hasKilled)
		{

			cout << "Fighting\n" << endl;

			cout << "Fight: f\n" << endl;
		}
		else
		{
			cout << "Fighting\n" << endl;

			cout << "Fight: f\n";
			cout << "Run: r\n" << endl;
		}
	}

	char i;
	cout << "Your choice: ";
    cin >> i;

    i = tolower(i); // converts possible uppercase input into lowercase

	if (!fightStarted)
	{
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
	}

	if (i == 'f')
	{
		if (tiles[character->GetPositionX()][character->GetPositionY()].GetEnemiesSize() > 0)
		{
			hasKilled = false;
            fightStarted = true;
			Fight();
            
		}
		else
		{
            fightStarted = false;
			cout << "You do not have any enemies here." << endl;
		}
	}

	else if (i == 'r' && hasKilled == true)
	{
		fightStarted = false;
		
	}

    else if (i == '?')
    {
        
        character->DisplayStats();
        cout << "\nPress any key to go back.\n";
        getch();
    }

	else
	{
		cout << "Invalid command! \n";
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

        tiles[0][5].SetType(Tile::TRANSITION); // [0][5] in next map will be [last][5];
	}
}

void Map::Move(int next_x, int next_y)
{
	if (tiles[next_x][next_y].GetType() == Tile::HOLE)
	{
		int lost_life = (rand() % 15 + 1) + 4;

		character->GetHealth().LoseHealth(lost_life);

		cout << "\n\nHole warning!\nYou have lost: " << lost_life << " life points\n";
	}

    if (tiles[next_x][next_y].GetType() == Tile::TRANSITION)
    {
        cout << "You've found a cave leading to another area. Would you like to go to it? Y/N\n";
        char i;
        cin >> i;

        i = tolower(i);

        if (i == 'y')
        {
            character->SetPositionX(9);
            
            
          //  World::GetInstance().SetMapIndex(1);
            World::GetInstance().SetCurrentMap(1);
            // map transition needs to be here
            tiles[character->GetPositionX()][character->GetPositionY()+1].SetType(Tile::TRANSITION);
            
        }
        
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

    else if (tile.GetType() == Tile::TRANSITION)
    {
        return 'x';
    }

	return 'u';
}

void Map::Fight()
{
	cout << "Fight started" << endl;

    
    
	
    

	Tile& tile = tiles[character->GetPositionX()][character->GetPositionY()];

    

    if (tile.GetEnemiesSize() > 0)
    {
        for (int i = tile.GetEnemiesSize(); i >= 0; i--)
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
                    cout << "You have killed an enemy!\n";
					hasKilled = true;
                    tile.ReduceEnemies(1);              
                    character->SetKills(character->GetKills()+1);



					if (character->GetLevel().HasLeveled())
					{
						character->GetHealth().Heal(character->GetHealth().GetMaxHealth());
					}

                    if (tile.GetEnemiesSize() == 0)
                    {
                        cout << "Fight has ended.\n";
                        fightStarted = false;
                        hasKilled = false;
                        Display();
                    }





                }


                break;


            }
            else
                continue;

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
