#include "Game.h"
#include <stdio.h>

Game::Game() {
  Textloader::LoadText("../TextArt/Loading.txt");
  SetTextColor(10);
  commandword = new CommandWords();
  parser = new Parser();
  SpawnRooms();
  player = new Player();
  Intro();
  player->Start();
  player->SetRoom(main);
  Print("\nHello: " + player->GetName() + " Use the help command if you are uncertain what to do");
  i = 2;
  MainLoop();
}

Game::~Game() {
  delete player;
  delete janitorRoom;
  delete commandword;
  delete parser;
  delete canteen;
  delete parkingLot;
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
  returnedString = parser->GetCommand(commandword);
  int temp = i;
  if (returnedString == "quit") {
    Quit();
  } else if (returnedString == "help") {
    PrintHelp(i);
  } else if (returnedString == "currentroom") {
    ShowRoom();
  } else if (returnedString == "look") {
    Look();
  } else if (returnedString == "grab" && player->GetRoom()->inventory->GetItem("")) {
    Grab();
  } else if (returnedString == "dig") {
    Dig();
  } else if (returnedString == "drop") {
    Drop();
  } else if (returnedString == "unlock") {
    Unlock();
  } else if (returnedString == "inventory" ){
    ShowInventory();
  } else if (returnedString == "north" || returnedString == "east" || returnedString == "south" || returnedString == "west" || returnedString == "up") {
    WalkDirection(returnedString);
  } else {
    Print("I don't know that command! \n Use 'help' If you are stuck!");
  }
  MainLoop();
}

void Game::SpawnInfo()
{
  if (player->IsAlive())
  {
    Print("Oh no you have died");
    Sleep(1000);
    Game::Exit(this);
  }
  Print("Items: " + player->inventory->GetItems());
  std::cout << player->GetHealth() << std::endl;
}

void Game::WalkDirection(std::string dir) {
  if (player->GetRoom()->GetNeighbours(dir)->GetName() == "The janitor's room" && dir == "east")
  {
    player->SetRoom(basement);
    player->Damage(20);
    Print("You have gone to the basement but have fallen down!");
    Print("You have hit your head on the ground and you are bleeding even more now!");
  }
  if (player->GetRoom()->GetNeighbours(dir) != 0 && !player->GetRoom()->GetNeighbours(dir)->GetLocked()) {
    player->SetRoom(player->GetRoom()->GetNeighbours(dir));
    Print("You have gone " + dir + " to the: " + player->GetRoom()->GetName());
    player->Damage(10);
  } else if (player->GetRoom()->GetNeighbours(dir) != 0 && player->GetRoom()->GetNeighbours(dir)->GetLocked()) {
    Textloader::LoadText("../TextArt/LockedDoor.txt");
  }
}

void Game::Intro() {
  Textloader::LoadText("../TextArt/Intro.txt");
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
  parkingLot = new Room("This is the parking lot, it's surrounder by fences", "The parking lot", "../TextArt/MainRoom.txt");
  basement = new Room("This is the basement, it's very dark and stinky in here", "The basement", "../TextArt/MainRoom.txt");

  main->SetNeighbours("north", exitDoor);
  main->SetNeighbours("south", classRoom);
  main->SetNeighbours("west", canteen);
  main->SetNeighbours("east", janitorRoom);
  basement->SetNeighbours("up", janitorRoom);
  parkingLot->SetNeighbours("east", exitDoor);
  parkingLot->SetNeighbours("south", canteen);

  janitorRoom->SetNeighbours("west", main);
  janitorRoom->SetNeighbours("down", basement);

  canteen->SetNeighbours("east", main);
  canteen->SetNeighbours("north", parkingLot);
  exitDoor->SetNeighbours("south", main);
  exitDoor->SetNeighbours("west", parkingLot);
  classRoom->SetNeighbours("north", main);

  janitorKeys = new Keys("Janitor keys", "../TextArt/Keys.txt");
  main->inventory->AddItem(janitorKeys->GetItemName(), janitorKeys);
  shovel = new Shovel("Shovel", "../TextArt/Shovel.txt");
  janitorRoom->inventory->AddItem(shovel->GetItemName(), shovel);

  carKeys = new Keys("Car Keys", "../TextArt/Keys.txt");
  main->inventory->AddItem(carKeys->GetItemName(), carKeys);

  janitorRoom->SetLocked(true);
  janitorRoom->SetNeededKey("Janitor keys");
}

void Game::PrintHelp(int i) {
  std::cout << commandword->GetCommands() << std::endl;
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
  Print("Digging now, I hope I Get free!");
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
    Print("Too bad the shovel is now damaged, It's" + player->inventory->GetItem("Shovel")->GetHP());
  }
}

void Game::ShowRoom()
{
  player->GetRoom()->ShowRoom();
  Print(player->GetRoom()->GetDiscription());
}

void Game::Look()
{
  if (player->GetRoom()->inventory->GetItem("") != nullptr) {
    commandword->PushCommand("grab");
    if (!player->inventory->GetItem("Shovel")) { i = 3; }
    player->GetRoom()->inventory->GetItem("")->ShowItem();
  } else {
   Print("There's nothing here.");
  }
}

void Game::Unlock()
{
  Print("What direction do you want to unlock?");
  std::string returnedString = parser->GetCommand(commandword);
  if (returnedString != "No command found" ) {
    if (returnedString == "north" || returnedString == "east" || returnedString == "south" || returnedString == "west") {
      if (player->GetRoom()->GetNeighbours(returnedString)->GetLocked()) {
        std::string neededKey = player->GetRoom()->GetNeighbours(returnedString)->GetNeededKey();
        if (player->inventory->GetItem(neededKey) != 0) {
          player->GetRoom()->GetNeighbours(returnedString)->SetLocked(false);
          Textloader::LoadText("../TextArt/UnlockedDoor.txt");
        }
      } else {
        Print("This room isn't locked.");
      }
    }
  }
}

void Game::Grab()
{
  //player->GetRoom()->GetItem()->ShowItem();
  Print("I got it it looks to be : " + player->GetRoom()->inventory->GetItem("")->GetItemName());
  player->inventory->AddItem(player->GetRoom()->inventory->GetItem("")->GetItemName(), player->GetRoom()->inventory->GetItem(""));
  Entity* entity = player->GetRoom()->inventory->GetItem("");
  player->GetRoom()->inventory->RemoveItem(entity->GetItemName());
}

void Game::Quit()
{
  i = 0;
  Print("Are you sure you want to quit?\n");
  std::string returnedString = parser->GetCommand(commandword);
  if (returnedString == "help") {
    PrintHelp(i);
    Quit();
  } else if (returnedString == "yes") {
    Exit(this);
  } else {
    MainLoop();
  }
}

void Game::ShowInventory()
{
  Print(player->inventory->GetItems());
}

void Game::Drop()
{
  Print("What item do you want to drop?");
  std::string returnedString;
  std::getline(std::cin, returnedString);
  if (player->inventory->GetItem(returnedString) != NULL) {
    player->GetRoom()->inventory->AddItem(player->inventory->GetItem(returnedString)->GetItemName(), player->inventory->GetItem(returnedString));
    player->inventory->RemoveItem(returnedString);
    Print(returnedString + "Has now been dropped");
  } else {
    Print("This item isn't in your inventory");
  }
}
