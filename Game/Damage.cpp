#include "Damage.h"

Damage::Damage()
{
}

Damage::Damage(int min, int max)
{
	minDamage = min;
	maxDamage = max;
}

int Damage::GetMinDamage()
{
	return minDamage;
}

int Damage::GetMaxDamage()
{
	return maxDamage;
}

void Damage::SetMinDamage(int min)
{
	minDamage = min;
}

void Damage::SetMaxDamage(int max)
{
	maxDamage = max;
}

Damage::~Damage()
{
}