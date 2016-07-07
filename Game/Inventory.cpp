#include "Inventory.h"

Inventory::Inventory()
{
    inventory_size = 3;
}

Inventory::~Inventory()
{
}

int Inventory::GetInventorySize()
{
    return inventory_size;
}