#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>
#include "Entity.h"

class Inventory
{
public:
    Inventory();
    ~Inventory();
    Entity* GetItem(std::string item);
    void AddItem(std::string item, Entity* entity) ;
    void RemoveItem(std::string item);
    std::string GetItems();
private:
  std::map<std::string, Entity*> inventory;
  int weightLimit;
  int currentWeight;
};

#endif
