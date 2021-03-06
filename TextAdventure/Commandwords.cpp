// commandwords.cpp

#include "Commandwords.h"
#include "Game.h"

CommandWords::CommandWords()
{
	validCommands.push_back("look");
	validCommands.push_back("quit");
	validCommands.push_back("help");
	validCommands.push_back("currentroom");
	validCommands.push_back("inventory");
	validCommands.push_back("yes");
	validCommands.push_back("no");
	validCommands.push_back("go");
	validCommands.push_back("east");
	validCommands.push_back("west");
	validCommands.push_back("north");
	validCommands.push_back("south");
  validCommands.push_back("dig");
  validCommands.push_back("unlock");
  validCommands.push_back("drop");
  validCommands.push_back("grab");
}

CommandWords::~CommandWords()
{

}

std::string CommandWords::GetCommands()
{
	std::string string;
	for (int i = 0; i < validCommands.size(); i++)
	{
		string += validCommands[i];
		if (i != validCommands.size() - 1) {
			string += " - ";
		}
	}
	return string;
}

void CommandWords::PushCommand(std::string command)
{
	validCommands.push_back(command);
}

void CommandWords::RemoveCommand(int i)
{
	validCommands.erase(validCommands.begin() + i);
}

int CommandWords::GetLength()
{
	return validCommands.size();
}


bool CommandWords::IsCommand(std::string str)
{
	for (size_t i = 0; i < validCommands.size(); i++) {
		if (validCommands[i].compare(str) == 0) {
			return true;
		}
	}
	return false;
}
