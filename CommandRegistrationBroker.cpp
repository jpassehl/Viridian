//CommandRegistrationBroker.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "CommandRegistrationBroker.h"

void CommandRegistrationBroker::addCommand(CommandBase* command)
{
	commandList.push_back(command);
}
void CommandRegistrationBroker::executeCommand()
{
	for (std::list<CommandBase*>::iterator it = commandList.begin(); it != commandList.end(); ++it)
	{
		(*it)->execute();
	}
	commandList.clear();

}