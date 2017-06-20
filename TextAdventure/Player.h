#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Room.h"
#include "Inventory.h"

class Player
{
public:
    Player();
    ~Player();
    Room* GetRoom();
    void SetRoom(Room* room);
    void Start();
    int GetHealth();
    bool IsAlive();
    void SetHealth(int hp);
    std::string GetName();
    Inventory* inventory;
private:
  std::string name;
  Room* currentRoom;
  int health;
  bool isDead;
};

#endif
