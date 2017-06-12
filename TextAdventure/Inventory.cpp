#include "Inventory.h"
#include "Game.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{

}

Entity* Inventory::GetItem(std::string item)
{
  return inventory[item];
}

void Inventory::AddItem(std::string item, Entity* entity)
{
  inventory[item] = entity;
}

std::string Inventory::GetItems()
{
   std::string items;
   if (inventory["Janitor keys"]) { items += "Janitor keys - "; }
   if (inventory["Shovel"]) { items += "Shovel"; }
   return items;
}
