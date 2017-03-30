//AlarmDeregistration.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _AlarmDeregistration
#define _AlarmDeregistration

#include "CommandBase.h"
#include "AlarmManager.h"


class AlarmDeregistration : public CommandBase
{
public:
	//pointers!
	//needs pointer to right manager to talk to
	AlarmManager* AlarmMgrPtr;
	//object that needs to be registered
	AlarmMarker* AlarmMarkerPtr;

	//constructors all in one place
	AlarmDeregistration() = delete;
	~AlarmDeregistration(){};
	AlarmDeregistration(const AlarmDeregistration&) = delete;
	AlarmDeregistration operator=(const AlarmDeregistration&) = delete;

	AlarmDeregistration(AlarmManager* mgr, AlarmMarker* alarm);
	virtual void execute() override;


};
#endif _AlarmDeregistration