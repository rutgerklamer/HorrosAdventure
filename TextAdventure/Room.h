#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <map>
#include "Entity.h"
#include "Textloader.h"
#include "Inventory.h"

class Room
{
public:
    Room(std::string dis, std::string name, std::string fileloc);
    ~Room();
    void SetNeighbours(std::string dir, Room* neighbour);
    Room* GetNeighbours(std::string dir);
    std::string GetDiscription();
    std::string GetName();
    std::string GetDirections();
    bool GetLocked();
    void SetLocked(bool locking);
    std::string GetNeededKey();
    void SetNeededKey(std::string key);
    void ShowRoom();
    Inventory* inventory;
private:
  std::string discription;
  std::string name;
  std::string neededKey;
  std::string filelocation;
  std::map<std::string, Room*> neighbours;
  bool locked;
};

#endif
