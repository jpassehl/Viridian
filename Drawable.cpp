//Drawable.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "Drawable.h"
#include "SceneManager.h"

void Drawable::DrawRegistration()
{
	SceneManager::GetCurrentScene()->DrawRegister(this);
}
void Drawable::DrawDergistration()
{
	SceneManager::GetCurrentScene()->DrawDeregister(this);
}