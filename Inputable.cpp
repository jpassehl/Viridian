//Inputable.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "Inputable.h"


#include "SceneManager.h"


void Inputable::KeyEventRegistration(AZUL_KEY k, INPUT_EVENT_TYPE e)
{

	SceneManager::GetCurrentScene()->KeyRegister(this,k,e);

}
void Inputable::KeyEventDeregistration(AZUL_KEY k, INPUT_EVENT_TYPE e)
{
	SceneManager::GetCurrentScene()->KeyDeregister(this, k,e);
}