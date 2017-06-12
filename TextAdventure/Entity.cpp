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

void Entity::PrintName()
{
  std::cout << "Entity" << std::endl;
}


std::string Entity::getItemName()
{
  return this->itemName;
}

void Entity::showItem()
{

}
