//KeyRegistration.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "KeyRegistration.h"

KeyRegistration::KeyRegistration(KeyboardEventManager* mgr, Inputable* input, AZUL_KEY k, Inputable::INPUT_EVENT_TYPE e)
:KeyEventMgrPtr(mgr), InputablePtr(input), key(k), eventType(e)
{
	//just stores the manager and the update
}
void KeyRegistration::execute()
{
	//needs to register the update
	//will be called when its ready to do it
	KeyEventMgrPtr->Register(key, InputablePtr,eventType);
}