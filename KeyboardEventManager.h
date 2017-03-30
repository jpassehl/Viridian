/*
// NOT a singleton, part of the scene and treat it as the rest
// Creates single-key event manager as necessary
// Called by the scene
//  Triggers the key state test in each single-key managers
*/

//SingleKeyEventManager.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _KeyboardEventManager
#define _KeyboardEventManager

#include "SingleKeyEventManager.h"
#include "Keyboard.h"
#include <map>


class KeyboardEventManager
{
private:

	SingleKeyEventManager singleKeyEventMgr;

	/* A Map to store the SingleKeyEventManagers that have been created
	// Why a map? Because it prevents duplicate keys.
	*/
	typedef std::map <AZUL_KEY, SingleKeyEventManager*> SingleKeyMgrMap;
	SingleKeyMgrMap singleKeyMgrMap;



public:


	KeyboardEventManager(){};
	virtual ~KeyboardEventManager()
	{
		DebugMsg::out("\nKeyboardEventManager deconstructor called");
	};
	KeyboardEventManager(const KeyboardEventManager&) = delete;
	KeyboardEventManager& operator=(const KeyboardEventManager&) = delete;

	//manage registration/deregistartion requests
	void Register(AZUL_KEY k, Inputable* input, Inputable::INPUT_EVENT_TYPE e);
	void Deregister(AZUL_KEY k, Inputable* input, Inputable::INPUT_EVENT_TYPE e);

	//trigger key-state test in each SingleKeyEventManagers
	//void TriggerKeyTest(AZUL_KEY k);

	void ProcessKeys();

};

#endif _KeyboardEventManager