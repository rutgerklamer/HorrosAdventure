#include "Room.h"

#define up 0
#define down 1
#define left  2
#define right 3


Room::Room(std::string dis, std::string name, std::string fileloc)
{
  discription = dis;
  this->name = name;
  this->filelocation = fileloc;
  inventory = new Inventory();
}

Room::~Room()
{

}

void Room::showRoom()
{
  Textloader::loadText(this->filelocation);
}

std::string Room::getNeededKey()
{
  return this->neededKey;
}

void Room::setNeededKey(std::string key)
{
  this->neededKey = key;
}

bool Room::GetLocked()
{
  return this->locked;
}

void Room::SetLocked(bool locking)
{
  this->locked = locking;
}

void Room::SetNeighbours(std::string dir, Room* neighbour)
{
  neighbours[dir] = neighbour;
}

Room* Room::GetNeighbours(std::string dir)
{
  return neighbours[dir];
}

std::string Room::GetDirections()
{
  std::string directions;
  if (neighbours["up"] != NULL) { directions += "'up', "; }
  if (neighbours["down"] != NULL) { directions += "'down', "; }
  if (neighbours["left"] != NULL) { directions += "'left', "; }
  if (neighbours["right"] != NULL) { directions += "'right', "; }
  return directions;
}


std::string Room::GetDiscription()
{
  return discription;
}

std::string Room::GetName()
{
  return name;
}

Entity* Room::GetItem()
{
  return inventory->GetItem("");
}

void Room::SetItem(Entity* entity)
{
  if (entity != 0) {
    inventory->AddItem(entity->getItemName(), entity);
  } else {
    inventory->AddItem("", entity);
  }
}
