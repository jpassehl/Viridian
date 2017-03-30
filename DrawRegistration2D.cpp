//DrawRegistration2D.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "DrawRegistration2D.h"

DrawRegistration2D::DrawRegistration2D(DrawableManager2D* mgr, Drawable2D* draw)
:DrawableMgrPtr2D(mgr), DrawablePtr2D(draw)
{
	//just stores the manager and the update
}
void DrawRegistration2D::execute()
{
	//needs to register the update
	//will be called when its ready to do it
	DrawableMgrPtr2D->Register(DrawablePtr2D);
}