 //Inputable.h
//Jacqueline Passehl Winter Quarter 2k16

/*
//
// 
//
*/


#ifndef _Inputable
#define _Inputable

#include "Keyboard.h"
#include "AzulCore.h"

class Inputable 
{
public:


	Inputable(){};
	virtual ~Inputable()
	{
		DebugMsg::out("\nInputable deconstructor called");
	};
	Inputable(const Inputable&) = delete;
	Inputable& operator=(const Inputable&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @defgroup Inputable Inputable
	/// @ingroup GameObject
	/// 
	/// @brief 
	/// 
	///  All GameObjects are derive from Inputable. This allows the game object to take user input  from the keyboard.
	///  There is an enum for key press vs key release.
	///  
	///  	 \par Example:
	/// The following example shows how you would set up keyboard events. This example shows spaceship move with the WASD keys.
	/// \code
	///		
	///		void SpaceShip::SceneEntry()
	///	{
	///     //...Other various registrations..
	///     
	///		KeyEventRegistration(AZUL_KEY::KEY_W, KEY_PRESS);
	///		KeyEventRegistration(AZUL_KEY::KEY_A, KEY_PRESS);
	///		KeyEventRegistration(AZUL_KEY::KEY_S, KEY_PRESS);
	///		KeyEventRegistration(AZUL_KEY::KEY_D, KEY_PRESS);
	///
	///		KeyEventRegistration(AZUL_KEY::KEY_W, KEY_RELEASE);
	///		KeyEventRegistration(AZUL_KEY::KEY_A, KEY_RELEASE);
	///		KeyEventRegistration(AZUL_KEY::KEY_S, KEY_RELEASE);
	///		KeyEventRegistration(AZUL_KEY::KEY_D, KEY_RELEASE);
	///
	///
	///	}
	///	void SpaceShip::SceneExit()
	///	{
	///		//...other various deregistrations...
	///
	///		KeyEventDeregistration(AZUL_KEY::KEY_W, KEY_RELEASE);
	///		KeyEventDeregistration(AZUL_KEY::KEY_A, KEY_RELEASE);
	///		KeyEventDeregistration(AZUL_KEY::KEY_S, KEY_RELEASE);
	///		KeyEventDeregistration(AZUL_KEY::KEY_D, KEY_RELEASE);
	///
	///		KeyEventDeregistration(AZUL_KEY::KEY_W, KEY_RELEASE);
	///		KeyEventDeregistration(AZUL_KEY::KEY_A, KEY_RELEASE);
	///		KeyEventDeregistration(AZUL_KEY::KEY_S, KEY_RELEASE);
	///		KeyEventDeregistration(AZUL_KEY::KEY_D, KEY_RELEASE);
	///
	///	}
	///	
	///	void SpaceShip::KeyPressed(AZUL_KEY k)
	///	{
	///	
	///		if (k == AZUL_KEY::KEY_W)
	///		{
	///			moveForward = true;
	///		}
	///		else if (k == AZUL_KEY::KEY_S)
	///		{
	///			moveBackward = true;
	///		}
	///
	///		else if (k == AZUL_KEY::KEY_A)
	///		{
	///			moveLeft = true;
	///		}
	///		else if (k == AZUL_KEY::KEY_D)
	///		{
	///			moveRight = true;
	///
	///		}
	///	}
	///	void SpaceShip::KeyReleased(AZUL_KEY k)
	///	{
	///		if (k == AZUL_KEY::KEY_W)
	///		{
	///			
	///			moveForward = false;
	///		}
	///		else if (k == AZUL_KEY::KEY_S)
	///		{
	///			
	///			moveBackward = false;
	///
	///		}
	///		else if (k == AZUL_KEY::KEY_A)
	///		{
	///			
	///			moveLeft = false;
	///
	///		}
	///		else if (k == AZUL_KEY::KEY_D)
	///		{
	///			
	///			moveRight = false;
	///
	///		}
	///
	///	}
	///	
	///	void SpaceShip::Update()
	///	{
	///		//set default position etc...
	///		
	///		if (moveForward)
	///		{
	///			//Math for moving forward
	///		}
	///		else if (moveBackward)
	///		{
	///			Math for moving backward
	///		}
	///		else if (moveLeft)
	///		{
	///			Math for moving left
	///		}
	///		else if (moveRight)
	///		{
	///			Math for moving right
	///		}
	///
	///	}
	///	
	///  \endcode
	///  
	///   \note Currently there is not a system for holding down a key, so you'll need to have booleans such as these to make an object keep moing as
	///   a key is held down.
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/** @{ */

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 	
	/// 	   Key Press: the key was up on the previous frame but is down now. Key Release: the key
	/// 	   was down on the previous frame but is up now."
	/// 	
	/// 	
	/// </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	enum INPUT_EVENT_TYPE { KEY_PRESS, KEY_RELEASE };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	callback method to be defined in the game object of what should happen when a specific key is pressed </summary>
	///
	/// <param name="k">	The AZUL_KEY to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void KeyPressed(AZUL_KEY k, bool shift, bool ctrl, bool alt){ AZUL_UNUSED(k); AZUL_UNUSED(shift); AZUL_UNUSED(ctrl); AZUL_UNUSED(alt); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	///  <summary>	callback method to be defined in the game object of what should happen when a specific key is released </summary>
	///
	/// <param name="k">	The AZUL_KEY to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void KeyReleased(AZUL_KEY k, bool shift, bool ctrl, bool alt){ AZUL_UNUSED(k); AZUL_UNUSED(shift); AZUL_UNUSED(ctrl); AZUL_UNUSED(alt); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Key event registration, goes inside SceneEntry() inside of the game object that has a keyboard event </summary>
	///
	/// <param name="k">	The AZUL_KEY to process. </param>
	/// <param name="e">	The INPUT_EVENT_TYPE to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void KeyEventRegistration(AZUL_KEY k, INPUT_EVENT_TYPE e);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Key event deregistration, goes inside SceneExit() inside of the game object that has a keyboard event </summary>
	///
	/// <param name="k">	The AZUL_KEY to process. </param>
	/// <param name="e">	The INPUT_EVENT_TYPE to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void KeyEventDeregistration(AZUL_KEY k, INPUT_EVENT_TYPE e);
	/** @} */

};

#endif _Inputable