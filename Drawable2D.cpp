//Drawable.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "Drawable2D.h"
#include "SceneManager.h"

void Drawable2D::Draw2DRegistration()
{
	SceneManager::GetCurrentScene()->DrawRegister2D(this);
}
void Drawable2D::Draw2DDergistration()
{
	SceneManager::GetCurrentScene()->DrawDeregister2D(this);
}