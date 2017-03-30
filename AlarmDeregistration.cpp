//AlarmDeregistration.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "AlarmDeregistration.h"

AlarmDeregistration::AlarmDeregistration(AlarmManager* mgr, AlarmMarker* alarm)
:AlarmMgrPtr(mgr), AlarmMarkerPtr(alarm)
{
	//just stores the manager and the update
}
void AlarmDeregistration::execute()
{
	//needs to register the update
	//will be called when its ready to do it
	AlarmMgrPtr->Deregister(AlarmMarkerPtr);
}