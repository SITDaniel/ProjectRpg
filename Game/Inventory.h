#pragma once

class Inventory
{
public:
	Inventory();
	~Inventory();

    int GetInventorySize();

private:
    int inventory_size;
};
