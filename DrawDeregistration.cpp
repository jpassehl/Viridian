//DrawDeregistration.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "DrawDeregistration.h"

DrawDeregistration::DrawDeregistration(DrawableManager* mgr, Drawable* draw)
	:DrawableMgrPtr(mgr), DrawablePtr(draw)
{
	//just stores the manager and the update
}
void DrawDeregistration::execute()
{
	//needs to register the update
	//will be called when its ready to do it
	DrawableMgrPtr->Deregister(DrawablePtr);
}