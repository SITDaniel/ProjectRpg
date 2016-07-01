#pragma once

class Damage
{
public:
	Damage();
	Damage(int min, int max);

	~Damage();

	void SetMinDamage(int min);
	void SetMaxDamage(int max);

	int GetMinDamage();
	int GetMaxDamage();

private:
	int minDamage;
	int maxDamage;
};
