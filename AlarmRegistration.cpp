//AlarmRegistration.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "AlarmRegistration.h"

AlarmRegistration::AlarmRegistration(AlarmManager* mgr, AlarmMarker* alarm)
:AlarmMgrPtr(mgr), AlarmMarkerPtr(alarm)
{
	//just stores the manager and the update
}
void AlarmRegistration::execute()
{
	//needs to register the update
	//will be called when its ready to do it
	AlarmMgrPtr->Register(AlarmMarkerPtr);
}