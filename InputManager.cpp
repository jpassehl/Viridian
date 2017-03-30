//InputManager.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "InputManager.h"
#include "Viridian.h"
#include "SingleKeyEventManager.h"



void InputManager::Register(Inputable* input)
{
	inputatableList.push_front(input);
}
void InputManager::Deregister(Inputable* input)
{
	inputatableList.remove(input);
}
void InputManager::ProcessInputs()
{
	for (std::list<Inputable*>::iterator it = inputatableList.begin(); it != inputatableList.end(); ++it)
	{
		(*it)->SingleKeyEventManager::ActivateCallBack();
	}
}