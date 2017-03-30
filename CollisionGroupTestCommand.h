//CollisionGroupTestCommand.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _CollisionGroupTestCommand
#define _CollisionGroupTestCommand

#include "CollisionGroupCommandBase.h"
#include "CollidableGroup.h"
#include "Collidable.h"


template<typename C>
class CollisionGroupTestCommand : public CollisionGroupCommandBase
{
public:
	//pointers!
	//needs pointer to right manager to talk to
	//CollisionManager* CollisionMgr; DONT NEED IT
	//object that needs to be registered
	C* CollidablePtr;

	//constructors all in one place
	CollisionGroupTestCommand(){};
	~CollisionGroupTestCommand(){};
	CollisionGroupTestCommand(const CollisionGroupTestCommand&) = delete;
	CollisionGroupTestCommand operator=(const CollisionGroupTestCommand&) = delete;

	CollisionGroupTestCommand(C* c)
		:CollidablePtr(c)
	{
		//just stores the manager and the update
	}
	virtual void execute()
	{
		//needs to register the update
		//will be called when its ready to do it

		CollidableGroup<C>::CreateGroupABB();
	}


};
#endif _CollisionGroupTestCommand