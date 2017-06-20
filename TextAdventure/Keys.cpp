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

std::string Keys::GetItemName()
{
  return this->itemName;
}

void Keys::ShowItem()
{
  Textloader::LoadText(this->filelocation);
}

int Keys::GetHP()
{
  return this->health;
}

int Keys::GetWeight()
{
  return this->weight;
}
