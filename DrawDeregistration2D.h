//DrawDeregistration2D.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _DrawDeregistration2D
#define _DrawDeregistration2D

#include "CommandBase.h"
#include "DrawableManager2D.h"


class DrawDeregistration2D : public CommandBase
{
public:
	//pointers!
	//needs pointer to right manager to talk to
	DrawableManager2D* DrawableMgrPtr2D;
	//object that needs to be registered
	Drawable2D* DrawablePtr2D;

	//constructors all in one place
	DrawDeregistration2D() = delete;
	~DrawDeregistration2D(){};
	DrawDeregistration2D(const DrawDeregistration2D&) = delete;
	DrawDeregistration2D operator=(const DrawDeregistration2D&) = delete;

	DrawDeregistration2D(DrawableManager2D* mgr, Drawable2D* draw);
	virtual void execute() override;


};
#endif _DrawDeregistration2D