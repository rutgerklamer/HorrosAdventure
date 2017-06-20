#ifndef KEYS_H
#define KEYS_H

#include <iostream>
#include "Entity.h"
#include "Textloader.h"

class Keys : public Entity
{
public:
    Keys(std::string string, std::string fileloc);
    ~Keys();
    std::string GetItemName();
    void PrintName();
    void ShowItem();
    int GetHP();
    int GetWeight();
private:
  int health = 100;
  int weight = 1;
  std::string itemName;
  std::string filelocation;
};

#endif
