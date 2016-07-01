#pragma once

class Health
{
public:
	Health();
	~Health();

	void LoseHealth(int value);

	void SetMinHealth(int amount);
	void SetMaxHealth(int amount);

	int GetCurrentHealth();
	int GetMinHealth();
	int GetMaxHealth();

	bool IsDead();

private:
	int current_health;

	int min_health;
	int max_health;

	bool is_dead;
};
