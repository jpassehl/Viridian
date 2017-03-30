//KeyRegistration.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _KeyRegistration
#define _KeyRegistration

#include "CommandBase.h"
#include "KeyboardEventManager.h"


class KeyRegistration : public CommandBase
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
	KeyRegistration() = delete;
	~KeyRegistration(){};
	KeyRegistration(const KeyRegistration&) = delete;
	KeyRegistration operator=(const KeyRegistration&) = delete;

	KeyRegistration(KeyboardEventManager* mgr, Inputable* input, AZUL_KEY k, Inputable::INPUT_EVENT_TYPE e);
	virtual void execute() override;


};
#endif _KeyRegistration