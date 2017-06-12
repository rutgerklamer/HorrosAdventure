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
    std::string getItemName();
    void PrintName();
    void showItem();
private:
  std::string itemName;
  std::string filelocation;
};

#endif
