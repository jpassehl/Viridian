//CommandRegistrationBroker.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _CommandRegistrationBroker
#define _CommandRegistrationBroker

#include "CommandBase.h"
#include <list>

class CommandRegistrationBroker
{
private:
	typedef std::list<CommandBase*> CommandList;
	CommandList commandList;

public:
	CommandRegistrationBroker(){};
	~CommandRegistrationBroker(){};
	CommandRegistrationBroker(const CommandRegistrationBroker&) = delete;
	CommandRegistrationBroker& operator = (const CommandRegistrationBroker&) = delete;

	void addCommand(CommandBase* command);
	void executeCommand();
};

#endif _CommandRegistrationBroker