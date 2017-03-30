//AlarmManager.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "AlarmManager.h"
#include "Viridian.h"
#include "TimeManager.h"


void AlarmManager::Register(AlarmMarker* alarm)
{
	float time = alarm->getTime();
	alarmMap[time] = alarm;
}
void AlarmManager::Deregister(AlarmMarker* alarm)
{
	alarmMap.erase(alarm->getTime());
}
void AlarmManager::ProcessAlarms()
{
	AlarmMap::iterator it = alarmMap.begin();

	if (it != alarmMap.end())
	{
		if (TimeManager::TimeInSeconds() >= it->first)
		{
			it->second->CallEvent();
		}

	}
}