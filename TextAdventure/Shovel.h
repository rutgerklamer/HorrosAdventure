#ifndef SHOVEL_H
#define SHOVEL_H

#include <iostream>
#include "Entity.h"
#include "Textloader.h"

class Shovel : public Entity
{
public:
    Shovel(std::string string, std::string fileloc);
    ~Shovel();
    std::string getItemName();
    void PrintName();
    void ShowItem();
    int GetHP();
    int GetWeight();
private:
  int health = 100;
  int weight = 2;
  std::string itemName;
  std::string filelocation;
};

#endif
