#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

class Entity
{
public:
    Entity(std::string string);
    ~Entity();
    std::string getItemName();
    virtual void PrintName();
    virtual void showItem();
    virtual int getHP();
private:
  std::string itemName;
};

#endif
