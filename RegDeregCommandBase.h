//RegDregCommandBase.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _RegDregCommandBase
#define _RegDregCommandBase

#include "CommandBase.h"

class RegDregCommandBase :public CommandBase
{
public:
	virtual void execute() = 0;
};
#endif _RegDregCommandBase