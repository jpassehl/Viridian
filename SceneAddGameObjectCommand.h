//SceneAddGameObjectCommand.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _SceneAddGameObjectCommand
#define _SceneAddGameObjectCommand

#include "CommandBase.h"
#include "GameObject.h"


class SceneAddGameObjectCommand : public CommandBase
{
public:
	//pointers!

	//needs pointer to right manager to talk to
	//Scene* ScenePtr;

	//object that needs to be registered
	GameObject* gameObjPtr;

	//constructors all in one place
	SceneAddGameObjectCommand() = delete;
	~SceneAddGameObjectCommand(){};
	SceneAddGameObjectCommand(const SceneAddGameObjectCommand&) = delete;
	SceneAddGameObjectCommand operator=(const SceneAddGameObjectCommand&) = delete;

	SceneAddGameObjectCommand( GameObject* gameObject);
	virtual void execute() override;


};
#endif _SceneAddGameObjectCommand