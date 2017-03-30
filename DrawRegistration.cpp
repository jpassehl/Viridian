//DrawRegistration.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "DrawRegistration.h"

DrawRegistration::DrawRegistration(DrawableManager* mgr, Drawable* draw)
	:DrawableMgrPtr(mgr), DrawablePtr(draw)
{
	//just stores the manager and the update
}
void DrawRegistration::execute()
{
	//needs to register the update
	//will be called when its ready to do it
	DrawableMgrPtr->Register(DrawablePtr);
}