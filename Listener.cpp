#include "Listener.h"

Listener* Listener::instance = nullptr;

void Listener::PrivSetListener(Vect& pos, Vect& forward, Vect& upward) 
{
	SceneManager::GetSoundManager()->setListener(pos, forward, upward);
}
void Listener:: setListener(Vect& pos, Vect& forward, Vect& upward)
{
	getInstance().PrivSetListener(pos, forward, upward);
}