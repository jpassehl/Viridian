/*
// We have collision groups and as many
// as the user wishes.
// 
//
// Scene-Level Manager- not singleton
//
// Two Jobs
// 1. Holds all test commands
// A Broker!
//
// 2.Each Call to Process Collision Tests will 
// execute all the test commands every frame
*/

//CollisionManager.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _CollisionManager
#define _CollisionManager

#include "CollisionTestCommandBase.h"
#include "CollisionGroupCommandBase.h"
#include "CommandRegistrationBroker.h"
#include "CollisionGroupDeleteCommand.h"
#include "CollisionGroupTestCommand.h"
#include <list>


class CollisionManager
{
private:
	CommandRegistrationBroker commandRegistrationBroker;

	typedef std::list<CollisionTestCommandBase*> CollisionTestCommands;
	CollisionTestCommands collisionTestCommandList;

	typedef std::list<CollisionGroupCommandBase*> CollisionGroupTestCommands;
	CollisionGroupTestCommands collisionGroupTestCommandList;

	typedef std::list<CollisionGroupCommandBase*> CollisionDeleteCommands;
	CollisionDeleteCommands collisionDeleteCommandList;


public:


	CollisionManager(){};
	~CollisionManager()
	{
		DebugMsg::out("\nCollision Manager Deconstructor called");
		ExecuteDeleteCommands();

	};
	CollisionManager(const CollisionManager&) = delete;
	CollisionManager& operator=(const CollisionManager&) = delete;


	template <typename C> 
	void AddCollisionGroupDeleteCommand()
	{
		//commandRegistrationBroker.addCommand(new CollisionGroupDeleteCommand<C>());
		collisionDeleteCommandList.push_front(new CollisionGroupDeleteCommand<C>());
	}
	template <typename C1, typename C2> 
	void SetCollisionPair()
		//each call to Set CollisionSelf/Pair adds another test to the Manager's collection.
	{
		collisionTestCommandList.push_front(new CollisionTestPairCommand<C1, C2>());
	}
	template <typename C1>
	void SetCollisionSelf()
	{
		collisionTestCommandList.push_front(new CollisionTestSelfCommand<C1>());
		//collisionTestCommandList.push_front<C1>();
	}
	template <typename C1>
	void AddCollisionGroupTest()
	{
		collisionGroupTestCommandList.push_front( new CollisionGroupTestCommand<C1>());
	}

	void ProcessCollisionTests()
		/*Call to process the job to call the collisions- execute all the test commands*/
		//go through all commands and execute them, dont delete them though
		// not like the others.
	{
		for (std::list<CollisionGroupCommandBase*>::iterator it = collisionGroupTestCommandList.begin(); it != collisionGroupTestCommandList.end(); ++it)
		{
			(*it)->execute();
		}
		for (std::list<CollisionTestCommandBase*>::iterator it = collisionTestCommandList.begin(); it != collisionTestCommandList.end(); ++it)
		{
			(*it)->execute();
		}
		//dont delete these you want to keep.
	}
	 void ExecuteDeleteCommands()
		/*Call to process the job to delete collision groups*/
	{
		for (std::list<CollisionGroupCommandBase*>::iterator it = collisionDeleteCommandList.begin(); it != collisionDeleteCommandList.end(); ++it)
		{
			(*it)->execute();
		}
		collisionDeleteCommandList.clear();

	}



};

#endif _CollisionManager