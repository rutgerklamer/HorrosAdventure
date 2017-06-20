#include "Inventory.h"
#include "Game.h"

Inventory::Inventory()
{
  this->weightLimit = 4;
}

Inventory::~Inventory()
{

}

void Inventory::RemoveItem(std::string item)
{
  inventory[item] = NULL;
}

Entity* Inventory::GetItem(std::string item)
{
  if (item == "")
  {
    std::map<std::string, Entity*>::iterator it = inventory.begin();
    while (it != inventory.end()) {
      Entity* entity = inventory[it->first];
      if (entity != nullptr) {
        it = inventory.end();
        return entity;
      }
      it++;
    }
  }
  return inventory[item];
}

void Inventory::AddItem(std::string item, Entity* entity)
{
  if (currentWeight + entity->getWeight() <= weightLimit) {
    inventory[item] = entity;
  }
  else {
    Game::Print("Your inventory is full!");
  }
}

std::string Inventory::GetItems()
{
   std::string items;
   std::map<std::string, Entity*>::iterator it = inventory.begin();
   while (it != inventory.end()) {
     Entity* entity = inventory[it->first];
     if (entity != nullptr) {
       items += " " + entity->getItemName() + " \n";
     }
     it++;
   }
   return items;
}
