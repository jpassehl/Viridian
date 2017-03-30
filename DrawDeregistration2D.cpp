//DrawDeregistration2D.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "DrawDeregistration2D.h"

DrawDeregistration2D::DrawDeregistration2D(DrawableManager2D* mgr, Drawable2D* draw)
:DrawableMgrPtr2D(mgr), DrawablePtr2D(draw)
{
	//just stores the manager and the update
}
void DrawDeregistration2D::execute()
{
	//needs to register the update
	//will be called when its ready to do it
	DrawableMgrPtr2D->Deregister(DrawablePtr2D);
}