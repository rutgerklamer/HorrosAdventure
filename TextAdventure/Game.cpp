#include "Game.h"
#include <stdio.h>

Game::Game() {
  Textloader::loadText("../TextArt/Loading.txt");
  SetTextColor(10);
  commandword = new CommandWords();
  parser = new Parser();
  SpawnRooms();
  player = new Player();
  Intro();
  player->Start();
  player->SetRoom(main);
  Print("\nHello: " + player->getName() + " Use the help command if you are uncertain what to do");
  i = 2;
  MainLoop();
}

Game::~Game() {
  delete player;
  delete janitorRoom;
  delete commandword;
  delete parser;
  delete canteen;
  delete main;
  delete exitDoor;
  delete classRoom;
}

void Game::Sleep(float time)
{
  clock_t time_end;
  time_end = clock() + time * CLOCKS_PER_SEC/1000;
  while (clock() < time_end) {}
}

void Game::MainLoop() {
  SpawnInfo();
  Print("What do you want to do now?\n");
  std::string returnedString;
  returnedString = parser->getCommand(commandword);
  int temp = i;
  if (returnedString == "quit") {
    Quit();
  } else if (returnedString == "help") {
    PrintHelp(i);
  } else if (returnedString == "currentroom") {
    ShowRoom();
  } else if (returnedString == "look") {
    Look();
  } else if (returnedString == "grab" && i == 3 && player->GetRoom()->GetItem()) {
    Grab();
  } else if (returnedString == "dig") {
    Dig();
    return;
  } else if (returnedString == "unlock") {
    Unlock();
  } else if (returnedString == "north" || returnedString == "east" || returnedString == "south" || returnedString == "west") {
    WalkDirection(returnedString);
  } else {
      Print("I don't know that command! \n Use 'help' If you are stuck!");
  }
  MainLoop();
}

void Game::SpawnInfo()
{
  Print("Items: " + player->inventory->GetItems());
  std::cout << player->GetHealth() << std::endl;
}

void Game::WalkDirection(std::string dir) {
  if (player->GetRoom()->GetNeighbours(dir) != 0 && !player->GetRoom()->GetNeighbours(dir)->GetLocked()) {
    player->SetRoom(player->GetRoom()->GetNeighbours(dir));
    Print("You have gone " + dir + " to the: " + player->GetRoom()->GetName());
    player->setHealth(10);
    if (player->isAlive())
    {
      Print("Oh no you have died");
      Sleep(1000);
      Game::Exit(this);
    }
  } else   if (player->GetRoom()->GetNeighbours(dir) != 0 && player->GetRoom()->GetNeighbours(dir)->GetLocked()) {
    Textloader::loadText("../TextArt/LockedDoor.txt");
  }
}

void Game::Intro() {
//  Textloader::loadText("../TextArt/Intro.txt");
  i = 1;
  GetAge();
}

void Game::Print(std::string text) {
  std::cout << text << std::endl;
}

void Game::SpawnRooms() {
  main = new Room("Your start place. It's theh main hall, connected to every room",
                  "The main hall", "../TextArt/MainRoom.txt");
  janitorRoom = new Room("this is the janitor room, I wonder what is in here.",
                         "The janitor's room", "../TextArt/MainRoom.txt");
  canteen = new Room("This is the canteen's kitchen", "The canteen's kitchen", "../TextArt/Kitchen.txt");
  exitDoor =
      new Room("This it the exit, It's looks like it's locked!", "The exit", "../TextArt/MainRoom.txt");
  classRoom = new Room("this is the classroom of Ms Puff", "The classroom", "../TextArt/MainRoom.txt");

  main->SetNeighbours("north", exitDoor);
  main->SetNeighbours("south", classRoom);
  main->SetNeighbours("west", canteen);
  main->SetNeighbours("east", janitorRoom);

  janitorRoom->SetNeighbours("west", main);
  canteen->SetNeighbours("east", main);
  exitDoor->SetNeighbours("south", main);
  classRoom->SetNeighbours("north", main);

  janitorKeys = new Keys("Janitor keys", "../TextArt/Keys.txt");
  main->SetItem(janitorKeys);
  shovel = new Shovel("Shovel", "../TextArt/Shovel.txt");
  janitorRoom->SetItem(shovel);

  janitorRoom->SetLocked(true);
  janitorRoom->setNeededKey("Janitor keys");
}

void Game::PrintHelp(int i) {
  std::cout << "DId it help?" << std::endl;
}

void Game::SetTextColor(int colors)
{
  rlutil::setColor(colors);
}

void Game::Exit(Game* game) {
  delete game;
}

void Game::GetAge() {
  std::getline(std::cin, answer);
  if (answer == "help") {
    PrintHelp(i);
    GetAge();
    return;
  }
  if ((float)atoi(answer.c_str()) == 0) {
    Print("You're either not alive or you're entering letters \nTry again!\n");
    GetAge();
    return;
  }
  if (atoi(answer.c_str()) < 18) {
    SetTextColor(12);
    Print("Sorry you are too young to play!\n");
    Sleep(3000);
    Exit(this);
  }
}

Game* Game::GetGame() {
  return this;
}

void Game::Dig()
{
  Print("Digging now, I hope I get free!");
  Print("Digging");
  for (int j = 0; j < 100; j++) {
      Sleep(10);
      std::cout << "." << std::flush;
  }
  std::cout << "quiting" << std::endl;
  Sleep(1000);
  std::cout << "quiting2" << std::endl;
  if (player->GetRoom()->GetName() == "The exit") {
    std::cout << "quiting3" << std::endl;
    Print("I'm free!");
    Sleep(2000);
    Exit(this);
  } else {
    Print("Too bad the shovel is now damaged, It's" + player->inventory->GetItem("Shovel")->getHP());
  }
}

void Game::ShowRoom()
{
  player->GetRoom()->showRoom();
  Print(player->GetRoom()->GetDiscription());
}

void Game::Look()
{
  if (player->GetRoom()->GetItem() != nullptr) {
    commandword->pushCommand("grab");
    if (!player->inventory->GetItem("Shovel")) { i = 3; }
    player->GetRoom()->GetItem()->showItem();
  } else {
   Print("There's nothing here.");
  }
}

void Game::Unlock()
{
  Print("What direction do you want to unlock?");
  std::string returnedString = parser->getCommand(commandword);
  if (returnedString != "No command found" ) {
    if (returnedString == "north" || returnedString == "east" || returnedString == "south" || returnedString == "west") {
      player->GetRoom()->GetNeighbours(returnedString)->SetLocked(false);
      player->inventory->AddItem("Janitor keys", NULL);
      Textloader::loadText("../TextArt/UnlockedDoor.txt");
    }
  }
}

void Game::Grab()
{
  if (player->GetRoom()->GetItem()->getItemName() == "Shovel") {
    commandword->pushCommand("dig");
  } else if (player->GetRoom()->GetItem()->getItemName() == "Janitor keys") {
    commandword->pushCommand("unlock");
  }
  player->GetRoom()->GetItem()->showItem();
  Print("I got it it looks to be : " + player->GetRoom()->GetItem()->getItemName());
  player->inventory->AddItem(player->GetRoom()->GetItem()->getItemName(), player->GetRoom()->GetItem());
  player->GetRoom()->SetItem(0);
}

void Game::Quit()
{
  i = 0;
  Print("Are you sure you want to quit?\n");
  std::string returnedString = parser->getCommand(commandword);
  if (returnedString == "help") {
    PrintHelp(i);
    Quit();
  } else if (returnedString == "yes") {
    Exit(this);
  } else {
    MainLoop();
  }
}
