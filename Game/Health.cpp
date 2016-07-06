#include "Health.h"

Health::Health()
{
	is_dead = false;

	min_health = 0;
	max_health = 100;

	current_health = max_health;
}

Health::~Health()
{
}

bool Health::IsDead()
{
	return is_dead;
}

void Health::LoseHealth(int value)
{
	current_health -= value;

	if (current_health <= min_health)
	{
		current_health = min_health;

		is_dead = true;
	}
}

int Health::GetCurrentHealth()
{
	return current_health;
}

int Health::GetMinHealth()
{
	return min_health;
}

int Health::GetMaxHealth()
{
	return max_health;
}

void Health::SetMinHealth(int amount)
{
	min_health = amount;
}

void Health::SetMaxHealth(int amount)
{
	max_health = amount;
}

void Health::Heal(int healed_value)
{
    current_health += healed_value;

    if (current_health > max_health)
    {
        current_health = max_health;
    }
}