#include "Player.h"
#include "Game.h"

Player::Player()
{
  inventory = new Inventory();
  this->isDead = false;
  this->health = 100;
}

Player::~Player()
{
}

void Player::Start()
{
  Game::Print("\nW--Where am, I... Who am... I? Do you know what my name is?\n");
  std::getline(std::cin, name);
}

std::string Player::GetName()
{
  return name;
}

Room* Player::GetRoom()
{
  return currentRoom;
}

void Player::SetRoom(Room *room)
{
  currentRoom = room;
}

int Player::GetHealth()
{
  return health;
}

void Player::Damage(int hp)
{
  this->health -= hp;
  if (this->health < 0)
  {
    this->isDead = true;
  }
}


void Player::Heal(int hp)
{
  this->health += hp;
}


bool Player::IsAlive()
{
  return this->isDead;
}
