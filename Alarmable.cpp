//Alarmable.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "Alarmable.h"
#include "SceneManager.h"

#include "Viridian.h"
#include "TimeManager.h"


void Alarmable::AlarmRegistration(AlarmID id,float t)
{ 
	AlarmMarker* temp = new AlarmMarker(this,id);
	temp->triggerTime = t + TimeManager::TimeInSeconds();

	SceneManager::GetCurrentScene()->AlarmRegister(temp);
}
void Alarmable::AlarmDeregistration()
{
	SceneManager::GetCurrentScene()->AlarmDeregister(alarmMarkerPtr);
}	