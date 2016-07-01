#pragma once

#include "Damage.h"
#include "Health.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	Health& GetHp();
	Damage& GetDmg();

private:
	Health hp;
	Damage dmg;
};