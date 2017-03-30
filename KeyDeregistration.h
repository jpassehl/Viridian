//KeyDeregistration.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _KeyDeregistration
#define _KeyDeregistration

#include "CommandBase.h"
#include "KeyboardEventManager.h"


class KeyDeregistration : public CommandBase
{
public:
	//pointers!
	//needs pointer to right manager to talk to
	KeyboardEventManager* KeyEventMgrPtr;
	//object that needs to be registered
	Inputable* InputablePtr;
	AZUL_KEY key;
	Inputable::INPUT_EVENT_TYPE eventType;

	//constructors all in one place
	KeyDeregistration() = delete;
	~KeyDeregistration(){};
	KeyDeregistration(const KeyDeregistration&) = delete;
	KeyDeregistration operator=(const KeyDeregistration&) = delete;

	KeyDeregistration(KeyboardEventManager* mgr, Inputable* input, AZUL_KEY k, Inputable::INPUT_EVENT_TYPE e);
	virtual void execute() override;


};
#endif _KeyDeregistration