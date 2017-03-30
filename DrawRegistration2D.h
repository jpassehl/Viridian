//DrawRegistration2D.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _DrawRegistration2D
#define _DrawRegistration2D

#include "CommandBase.h"
#include "DrawableManager2D.h"


class DrawRegistration2D : public CommandBase
{
public:
	//pointers!
	//needs pointer to right manager to talk to
	DrawableManager2D* DrawableMgrPtr2D;
	//object that needs to be registered
	Drawable2D* DrawablePtr2D;

	//constructors all in one place
	DrawRegistration2D() = delete;
	~DrawRegistration2D(){};
	DrawRegistration2D(const DrawRegistration2D&) = delete;
	DrawRegistration2D operator=(const DrawRegistration2D&) = delete;

	DrawRegistration2D(DrawableManager2D* mgr, Drawable2D* draw);
	virtual void execute() override;


};
#endif _DrawRegistration2D