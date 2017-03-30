//InputManager.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _InputManager
#define _InputManager

#include <string>
#include <list>

#include "Inputable.h"


class InputManager
{
private:

	typedef std::list <Inputable*> InputableList;
	InputableList inputatableList;

	friend class Scene;
	void ProcessInputs();

public:

	InputManager(){};
	virtual ~InputManager(){};
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;

	void Register(Inputable* input);
	void Deregister(Inputable* input);
;

};

#endif _InputManager