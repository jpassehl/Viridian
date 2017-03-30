//KeyPressedRegistration.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _KeyPressedRegistration
#define _KeyPressedRegistration

#include "CommandBase.h"
#include "KeyboardEventManager.h"


class KeyPressedRegistration : public CommandBase
{
public:
	//pointers!
	//needs pointer to right manager to talk to
	KeyboardEventManager* KeyEventMgrPtr;
	//object that needs to be registered
	Inputable* InputablePtr;

	//constructors all in one place
	KeyPressedRegistration() = delete;
	~KeyPressedRegistration(){};
	KeyPressedRegistration(const KeyPressedRegistration&) = delete;
	KeyPressedRegistration operator=(const KeyPressedRegistration&) = delete;

	KeyPressedRegistration(KeyboardEventManager* mgr, Inputable* input,AZUL_KEY k);
	virtual void execute() override;


};
#endif _KeyPressedRegistration