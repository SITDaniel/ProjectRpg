#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

Health& Enemy::GetHp()
{
	return hp;
}

Damage& Enemy::GetDmg()
{
	return dmg;
}