#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

class Entity
{
public:
    Entity(std::string string);
    ~Entity();
    std::string GetItemName();
    virtual void PrintName();
    virtual void ShowItem();
    virtual int GetWeight();
    virtual int GetHP();
private:
  std::string itemName;
};

#endif
