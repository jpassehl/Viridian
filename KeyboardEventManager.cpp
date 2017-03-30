//SingleKeyEventManager.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "KeyboardEventManager.h"


void KeyboardEventManager::Register(AZUL_KEY k, Inputable* input, Inputable::INPUT_EVENT_TYPE e)
{

	//check if a manager for requested key exists
		//iterator types pointing to elements (of type value_type).
	auto search = singleKeyMgrMap.find(k);
	//IF it was found
	if (search != singleKeyMgrMap.end())
	{
		//pass it in
		singleKeyMgrMap[k]->Register(input,e);

	}
	//IF it was not found 
	else
	{
		//create one for that key then pass it in 

		singleKeyMgrMap[k] = new SingleKeyEventManager(k);
		singleKeyMgrMap[k]->Register(input,e);
	}

}
void KeyboardEventManager::Deregister(AZUL_KEY k, Inputable* input, Inputable::INPUT_EVENT_TYPE e)
{
	//check if a manager for requested key exists
	//iterator types pointing to elements (of type value_type).
	auto search = singleKeyMgrMap.find(k);
	//IF it was found
	if (search != singleKeyMgrMap.end())
	{
		//pass it in
		singleKeyMgrMap[k]->Deregister(input,e);

	}
	//IF it was not found 
	else
	{
		//create one for that key then pass it in 

		singleKeyMgrMap[k] = new SingleKeyEventManager(k);
		singleKeyMgrMap[k]->Deregister(input,e);
	}

}

void KeyboardEventManager::ProcessKeys()
//Is this like process elements in Drawable/UpdatableManager?
{

	for (std::map<AZUL_KEY, SingleKeyEventManager*>::iterator it = singleKeyMgrMap.begin(); it != singleKeyMgrMap.end(); it++)
	{
		it->second->CheckKeyState();
	}

	//singleKeyEventMgr.CheckKeyState();
}

