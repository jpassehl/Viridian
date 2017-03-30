//CollisionGroupCommandBase.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _CollisionGroupCommandBase
#define _CollisionGroupCommandBase

#include "CommandBase.h"

class CollisionGroupCommandBase :public CommandBase
{
public:
	virtual void execute() = 0;
};
#endif _CollisionGroupCommandBase