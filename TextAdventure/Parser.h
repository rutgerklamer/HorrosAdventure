// parser.h

#ifndef PARSER_H
#define PARSER_H

#include "Commandwords.h"

class Parser
{
public:
	Parser();
	virtual ~Parser();

	std::string getCommand(CommandWords* commands);
	void showCommands() { commands.showAll(); }

private:
	CommandWords commands;
};

#endif /* PARSER_H */
