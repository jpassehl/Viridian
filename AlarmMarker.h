//AlarmMarker.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _AlarmMarker
#define _AlarmMarker

#include "Alarmable.h"
#include "AzulCore.h"

class AlarmMarker
{
private:

	//time in which you wanna trigger
	float triggerTime;
	Alarmable* ptrAlarmable;
	Alarmable::AlarmID alarmID;


	friend class Alarmable;

public:
	AlarmMarker()
	{
	};
	~AlarmMarker()
	{
		DebugMsg::out("\nAlarm Marker Deconstructor called");
	}
	AlarmMarker(Alarmable* alarm, Alarmable::AlarmID id);
	AlarmMarker(const AlarmMarker&) = delete;
	AlarmMarker& operator=(const AlarmMarker&) = delete;

	void CallEvent();
	float getTime();

};
#endif _AlarmMarker