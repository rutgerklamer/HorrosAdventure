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

void Shovel::ShowItem()
{
  Textloader::LoadText(this->filelocation);
}

int Shovel::GetHP()
{
  return this->health;
}

int Shovel::GetWeight()
{
  return this->weight;
}
