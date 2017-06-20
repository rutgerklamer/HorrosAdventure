#include "Shovel.h"

Shovel::Shovel(std::string string, std::string fileloc) : Entity::Entity(string)
{
  this->itemName = string;
  this->filelocation = fileloc;
}

Shovel::~Shovel()
{

}

void Shovel::PrintName()
{
  std::cout << "Shovel" << std::endl;
}

std::string Shovel::getItemName()
{
  return this->itemName;
}

void Shovel::showItem()
{
  Textloader::loadText(this->filelocation);
}

int Shovel::getHP()
{
  return this->health;
}

int Shovel::getWeight()
{
  return this->weight;
}
