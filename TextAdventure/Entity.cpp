#include "Entity.h"

Entity::Entity(std::string string)
{
  this->itemName = string;
}

Entity::~Entity()
{

}

int Entity::getHP()
{

}

int Entity::getWeight()
{

}

void Entity::PrintName()
{

}


std::string Entity::getItemName()
{
  return this->itemName;
}

void Entity::showItem()
{

}
