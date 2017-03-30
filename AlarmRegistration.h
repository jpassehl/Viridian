//AlarmRegistration.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _AlarmRegistration
#define _AlarmRegistration

#include "CommandBase.h"
#include "AlarmManager.h"


class AlarmRegistration : public CommandBase
{
public:
	//pointers!
	//needs pointer to right manager to talk to
	AlarmManager* AlarmMgrPtr;
	//object that needs to be registered
	AlarmMarker* AlarmMarkerPtr;

	//constructors all in one place
	AlarmRegistration() = delete;
	~AlarmRegistration(){};
	AlarmRegistration(const AlarmRegistration&) = delete;
	AlarmRegistration operator=(const AlarmRegistration&) = delete;

	AlarmRegistration(AlarmManager* mgr, AlarmMarker* alarm);
	virtual void execute() override;


};
#endif _AlarmRegistration