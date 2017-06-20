#include "Keys.h"

Keys::Keys(std::string string, std::string fileloc) : Entity::Entity(string)
{
  this->itemName = string;
  this->filelocation = fileloc;
}

Keys::~Keys()
{

}

void Keys::PrintName()
{
  std::cout << "Keys" << std::endl;
}

std::string Keys::getItemName()
{
  return this->itemName;
}

void Keys::showItem()
{
  Textloader::loadText(this->filelocation);
}

int Keys::getHP()
{
  return this->health;
}

int Keys::getWeight()
{
  return this->weight;
}
