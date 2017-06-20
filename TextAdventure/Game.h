#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdlib.h>
#include <cstddef>
#include <time.h>
#include "Player.h"
#include "Room.h"
#include "rlutil.h"
#include "Commandwords.h"
#include "Parser.h"
#include "Entity.h"
#include "Shovel.h"
#include "Keys.h"
#include "Textloader.h"

class Game
{
public:
    Game();
    ~Game();
    static void Print(std::string text);
    void PrintHelp(int i);
    static void Exit(Game* game);
    void GetAge();
    void Intro();
    void MainLoop();
    void SpawnRooms();
    void WalkDirection(std::string dir);
    static void SetTextColor( int colors);
    void SpawnInfo();
    static void Sleep(float time);
    void Dig();
    void ShowRoom();
    void Look();
    void Unlock();
    void Grab();
    void Quit();
    void showInventory();
    void Drop();
    Game* GetGame();
private:
    Player* player;
    std::string answer;
    int i;
    Room* main;
    Room* janitorRoom;
    Room* canteen;
    Room* exitDoor;
    Room* classRoom;
    Room* parkingLot;
    Room* basement;
  //  Command* command;
    CommandWords* commandword;
    Parser* parser;
    Shovel* shovel;
    Keys* janitorKeys;
    Keys* carKeys;

};

#endif
