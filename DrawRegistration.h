//DrawRegistration.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _DrawRegistration
#define _DrawRegistration

#include "CommandBase.h"
#include "DrawableManager.h"


class DrawRegistration : public CommandBase
{
public:
	//pointers!
	//needs pointer to right manager to talk to
	DrawableManager* DrawableMgrPtr;
	//object that needs to be registered
	Drawable* DrawablePtr;

	//constructors all in one place
	DrawRegistration() = delete;
	~DrawRegistration(){};
	DrawRegistration(const DrawRegistration&) = delete;
	DrawRegistration operator=(const DrawRegistration&) = delete;

	DrawRegistration(DrawableManager* mgr, Drawable* draw);
	virtual void execute() override;


};
#endif _DrawRegistration