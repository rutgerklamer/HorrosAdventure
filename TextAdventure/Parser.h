// parser.h

#ifndef PARSER_H
#define PARSER_H

#include "Commandwords.h"

class Parser
{
public:
	Parser();
	virtual ~Parser();

	std::string GetCommand(CommandWords* commands);
	void ShowCommands() { commands.ShowAll(); }

private:
	CommandWords commands;
};

#endif /* PARSER_H */
