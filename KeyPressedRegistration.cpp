//KeyRegistration.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "KeyPressedRegistration.h"

KeyPressedRegistration::KeyPressedRegistration(KeyboardEventManager* mgr, Inputable* input)
	:KeyEventMgrPtr(mgr), InputablePtr(input)
{
	//just stores the manager and the update
}
void KeyPressedRegistration::execute()
{
	//needs to register the update
	//will be called when its ready to do it
	KeyEventMgrPtr->Register(InputablePtr);
}