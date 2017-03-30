//Alarmable.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _Alarmable
#define _Alarmable

#include "AzulCore.h"

class AlarmMarker;

class Alarmable 
{
private:

	AlarmMarker* alarmMarkerPtr;


	friend class AlarmMarker;

public:


	Alarmable(){};
	~Alarmable()
	{
		DebugMsg::out("\nAlarmable Deconstructor called");
	}
	//AlarmMarker(Alarmable* AlarmPtr,float t);
	Alarmable(const Alarmable&) = delete;
	Alarmable& operator=(const Alarmable&) = delete;
	
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @defgroup Alarmable Alarmable
	/// @ingroup GameObject
	/// 
	/// @brief 
	/// 
	///  All GameObjects are derive from Alarmable. Alarms are a nice countdown application to control time - based events. In this Engine
	///	there are currently 3 alarms all encapsulated into an enum labeld AlarmID, starting at 0 up to 2. Each also has their own callback method.
	///	 
	///	 \par Example:
	/// The following example shows how you might use alarms. timeTilDeath would be the (time as a float) until you want that alarm to go off.
	/// \code
	/// void SpaceShip::Alarm2()
	///		{
	///			DebugMsg::out("SpaceShip exploding...!\n");
	///			MarkForSceneExit();
	///
	///		}
	/// void SpaceShip::SceneEntry()
	///		{
	///			//...Other various registration methods...
	///		
	///			AlarmRegistration(AlarmID_2, timeTilDeath);
	///		}
	///	void SpaceShip::SceneExit()
	///		{
	///			//...Other various deregistration methods...
	///
	///			AlarmDeregistration();
	///		}
	///  \endcode
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/** @{ */
	
	enum AlarmID{ AlarmID_0, AlarmID_1, AlarmID_2 };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \brief Alarm 0 callback method
	/// \details  Define this in your game object's class to specify what happens when this alarm
	/// 			goes off
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Alarm0(){};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \brief Alarm 1 callback method
	/// \details  Define this in your game object's class to specify what happens when this alarm
	/// 			goes off
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Alarm1(){};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \brief Alarm 2 callback method
	/// \details  Define this in your game object's class to specify what happens when this alarm
	/// 			goes off
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Alarm2(){};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \brief Registers the Alarm specified by the id number, and the time. Like the usual registration
	/// methods this would go inside SceneEntry() inside of the game object you'd like to have an alarm for.
	///
	///
	/// <param name="id">	The Alarm ID. </param>
	/// <param name="t"> 	the time it takes until alarm goes off </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void AlarmRegistration(AlarmID id,float t);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \brief Deregisters the Alarm specified by the id number, and the time. Like the usual deregistration
	/// methods this would go inside SceneExit() inside of the game object you'd like to have an alarm for.
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void AlarmDeregistration();
	/** @} */


};
#endif _Alarmable
