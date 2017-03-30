//Gameobject.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _GameObject
#define _GameObject

#include "Updatable.h"
#include "Drawable.h"
#include "Alarmable.h"
#include "Inputable.h"
#include "Collidable.h"
//#include "SceneManager.h"

#include "Scene.h"


class GameObject : public Updatable, public Drawable, public Drawable2D,public Alarmable, public Inputable, public Collidable
{
public:

	GameObject(){};
	virtual ~GameObject()
	{
		DebugMsg::out("Game Object deconstrucor called");
	};
	GameObject(const GameObject&) = delete;
	GameObject& operator=(const GameObject&) = delete;


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @defgroup GameObject GameObject
	/// @brief All game entities will be derived from GameObject.Each GameObject has access to various registration methods such as ones for
	///	  updating, drawing, registering for keyboard input, alarms, and collisions.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @defgroup DefaultEvents DefaultEvents
	///  @ingroup GameObject
	///	  @brief All GameObjects automatically has these default scene related methods, which are needed as gateways so they can register / deregister themselves for
	///	  certain events which you will want to use.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/** @{ */

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \brief Call necessary registration methods for scene entrance
	/// \details This is where you would put registration methods for what you want your game object to do.
	/// 
	/// \par Example:
	/// The following example shows what you would use this method for
	/// \code
	/// void YourGameObject::SceneEntry()
	///	{
	///		
	///		UpdateRegistration();
	///		DrawRegistration();
	///		
	///		//Optional setup for collision
	///		
	///		CollisionRegistration<YourGameObject>(this);
	///		
	///		//Optional setup for keyboard input
	///		
	///		KeyEventRegistration(AZUL_KEY::KEY_P, KEY_PRESS);
	///		
	///		//Optional setup for alarm
	///		
	///		AlarmRegistration(AlarmID_2, timeTilDeath);
	///	}
	/// \endcode
	/// 
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void SceneEntry(){};

	
	 
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \brief Call necessary registration methods for scene entrance
	/// \details This is where you would put corresponding deregistration methods
	/// 
	/// \par Example:
	/// The following example shows what you would use this method for
	/// \code
	/// void House::SceneExit()
	///	{
	///		UpdateDergistration();
	///		DrawDergistration();
	///		
	///		CollisionDeregistration<House>(this);
	///		KeyEventDeregistration(AZUL_KEY::KEY_P, KEY_PRESS);
	///		AlarmDeregistration();
	///	}
	///
	/// \endcode
	/// 
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void SceneExit(){};

	
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \brief Mark a GameObject for removal from the scene.
	/// \details This will remove the object from the scene in the next update tick
	/// 
	/// 
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void MarkForSceneExit()
	{
		//make sure sceneexit is only called once
		if (SceneManager::GetCurrentScene() != nullptr)
		{
			SceneManager::GetCurrentScene()->RemovefromScene(this);
		}
		
	};
	/** @} */
	float Pos;
	 
	void DrawCells(Vect& min, Vect& max)
	{
		SceneManager::GetCurrentTerrain()->DrawAllCells(min,max,this);
	}
private:


	Scene* currScenePtr;
	
};

#endif _GameObject