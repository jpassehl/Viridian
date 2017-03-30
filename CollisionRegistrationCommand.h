//CollisionRegistrationCommand.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _CollisionRegistrationCommand
#define _CollisionRegistrationCommand

#include "RegDeregCommandBase.h"
#include "CollidableGroup.h"
#include "Collidable.h"
//#include "CollisionManager.h"

template<typename C>
class CollisionRegistrationCommand : public RegDregCommandBase
{
public:
	//pointers!
	//needs pointer to right manager to talk to
	//CollisionManager* CollisionMgr; DONT NEED IT
	//object that needs to be registered
	C* CollidablePtr;

	//constructors all in one place
	CollisionRegistrationCommand(){};
	~CollisionRegistrationCommand(){};
	CollisionRegistrationCommand(const CollisionRegistrationCommand&) = delete;
	CollisionRegistrationCommand operator=(const CollisionRegistrationCommand&) = delete;

	CollisionRegistrationCommand(C* c)
		:CollidablePtr(c)
	{
		//just stores the manager and the update
	}
	virtual void execute()
	{
		//needs to register the update
		//will be called when its ready to do it
		CollidableGroup<C>::Register(CollidablePtr);
	}


};
#endif _CollisionRegistrationCommand