//CollisionTestCommandBase.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _CollisionTestCommandBase
#define _CollisionTestCommandBase

#include "CommandBase.h"

class CollisionTestCommandBase :public CommandBase
{
public:
	virtual void execute() = 0;
};
#endif _CollisionTestCommandBase