
#ifndef COMMANDWORDS_H
#define COMMANDWORDS_H

#include <iostream>
#include <vector>
#include <string>
class CommandWords
{
public:
	CommandWords();
	virtual ~CommandWords();
	void PushCommand(std::string command);
	void RemoveCommand(int i);
	int GetLength();
	std::string GetCommands();
	bool IsCommand(std::string);
	void ShowAll() {
        for(int i = 0; i < validCommands.size(); i++) {
            std::cout << validCommands[i] << " ";
        }
        std::cout << std::endl;
    }

private:
	std::vector<std::string> validCommands;
};

#endif /* COMMANDWORDS_H */
