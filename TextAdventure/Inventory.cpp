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
  if (item == "")
  {
    Entity* entity;
    std::map<std::string, Entity*>::iterator it = inventory.begin();
    while (it != inventory.end()) {
      if (inventory[it->first] != nullptr) {
        entity = inventory[it->first];
        it = inventory.end();
      }
      return entity;
    }
  }
  return inventory[item];
}

void Inventory::AddItem(std::string item, Entity* entity)
{
  std::cout << "Why am i getting called" << std::endl;

  inventory[item] = entity;
}

std::string Inventory::GetItems()
{
   std::string items;
   std::map<std::string, Entity*>::iterator it = inventory.begin();
   while (it != inventory.end()) {
     Entity* entity = inventory[it->first];
     items += " " + entity->getItemName() + " ";
     ++it;
   }
   return items;
}
