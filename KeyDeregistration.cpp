//KeyDeregistration.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "KeyDeregistration.h"

KeyDeregistration::KeyDeregistration(KeyboardEventManager* mgr, Inputable* input, AZUL_KEY k, Inputable::INPUT_EVENT_TYPE e)
:KeyEventMgrPtr(mgr), InputablePtr(input), key(k),eventType(e)
{
	//just stores the manager and the update
}
void KeyDeregistration::execute()
{
	//needs to register the update
	//will be called when its ready to do it
	KeyEventMgrPtr->Deregister(key, InputablePtr,eventType);
}