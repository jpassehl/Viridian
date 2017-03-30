//DrawDeregistration.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _DrawDeregistration
#define _DrawDeregistration

#include "CommandBase.h"
#include "DrawableManager.h"


class DrawDeregistration : public CommandBase
{
public:
	//pointers!
	//needs pointer to right manager to talk to
	DrawableManager* DrawableMgrPtr;
	//object that needs to be registered
	Drawable* DrawablePtr;

	//constructors all in one place
	DrawDeregistration() = delete;
	~DrawDeregistration(){};
	DrawDeregistration(const DrawDeregistration&) = delete;
	DrawDeregistration operator=(const DrawDeregistration&) = delete;

	DrawDeregistration(DrawableManager* mgr, Drawable* draw);
	virtual void execute() override;


};
#endif _DrawDeregistration