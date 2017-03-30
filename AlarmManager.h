//AlarmManager.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _AlarmManager
#define _AlarmManager

#include <string>
#include <map>
#include "AzulCore.h"

#include "AlarmMarker.h"

class AlarmManager
{
private:
	/*
	//Manage the Markers!- just a pair of time to trigger in future and alarmable!
	// in charge of keeping a list/data structure of markers
	//command pattern wher commands are executed based on current time
	*/

	//typedef std::list<Alarmable*> AlarmList;
	//AlarmList alarmList;

	
	typedef std::map <float, AlarmMarker*> AlarmMap;
	AlarmMap alarmMap;


public:

	AlarmManager(){};
	~AlarmManager(){ DebugMsg::out("\nAlarm Manager Deconstructor called"); };
	AlarmManager(const AlarmManager&) = delete;
	AlarmManager& operator=(const AlarmManager&) = delete;

	void Register(AlarmMarker* alarm);
	void Deregister(AlarmMarker* alarm);
	void ProcessAlarms();

};

#endif _AlarmManager