#include "Entity.h"

Entity::Entity(std::string string)
{
  this->itemName = string;
}

Entity::~Entity()
{

}

int Entity::GetHP()
{

}

int Entity::GetWeight()
{

}

void Entity::PrintName()
{

}


std::string Entity::GetItemName()
{
  return this->itemName;
}

void Entity::ShowItem()
{

}
