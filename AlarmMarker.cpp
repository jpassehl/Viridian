//AlarmMarker.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "AlarmMarker.h"
#include "SceneManager.h"

AlarmMarker::AlarmMarker(Alarmable* alarm, Alarmable::AlarmID id)
{
	ptrAlarmable = alarm;
	alarmID = id;
}
void AlarmMarker::CallEvent()
{
	switch (alarmID)
	{
		case Alarmable::AlarmID_0:
			ptrAlarmable->Alarm0();
			break;
		case Alarmable:: AlarmID_1:
			ptrAlarmable->Alarm1();
			break;
		case Alarmable::AlarmID_2:
			ptrAlarmable->Alarm2();
			break;
		default:
			break;	
	}
}
float AlarmMarker::getTime()
{
	return triggerTime;
}
