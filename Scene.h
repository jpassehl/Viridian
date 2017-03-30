 //Scene.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _Scene
#define _Scene

#include "UpdatableManager.h"
#include "DrawableManager.h"
#include "DrawableManager2D.h"
#include "AlarmManager.h"
#include "KeyboardEventManager.h"
#include "CameraManager.h"
#include "CollisionManager.h"
#include "CameraManager.h"



#include "CommandRegistrationBroker.h"

#include "CollisionRegistrationCommand.h"
#include "CollisionDeregistrationCommand.h"

#include "CollisionTestSelfCommand.h"
#include "CollisionTestPairCommand.h"

#include "CollisionGroupDeleteCommand.h"

#include "AzulCore.h"
#include "SoundManager.h"
#include "Terrain.h"

class GameObject;


////////////////////////////////////////////////////////////////////////////////////////////////////
/// @defgroup Scene Scene
/// @brief The place were GameObjects exist...
////////////////////////////////////////////////////////////////////////////////////////////////////

class Scene
{
public:
	Scene(){}
	virtual ~Scene()
	{
		DebugMsg::out("\nScene deconstructor called");
	};
	Scene(const Scene&) = delete;
	Scene& operator= (const Scene&) = delete;

	CameraManager cameraManager;

private:
	Terrain* currTerrain;
	SoundManager soundManager;
	UpdatableManager updatableManager;
	DrawableManager drawableManager;
	DrawableManager2D drawableManager2D;
	AlarmManager alarmManger;
	KeyboardEventManager keyboardEventManager;
	CollisionManager collisionManager;
	//CameraManager cameraManager;

	

	CommandRegistrationBroker commandRegistrationBroker;





protected:
	friend class SceneManager;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @ingroup Scene
	/// \brief Initalizes the Scene
	/// \details  user defined, for each scene created this is where you would go about add objects to them, and registering for collision
	/// 
	///	 \par Example:
	/// 
	/// \code			
	/// void SceneTest::Initalize()
	///	{
	///
	///		gObjWorldPlane = new WorldPlane();
	///		gObjSpaceShipTextured = new SpaceShip();
	///		gObjCottage = new Cottage();
	///		
	///		AddToScene(gObjWorldPlane);
	///		AddToScene(gObjSpaceShip);
	///		AddToScene(gObjCottage);
	///
	///		SetCollisionPair<SpaceShipTextured, Cottage>();
	///
	///	}
	///	}
	///  \endcode
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Initalize() = 0; //force user to tell scene what to look like
	virtual void SceneEnd(){};

	//Temporarliy user specified//

	//virtual void Update(){};-became not virtual update now implemented in the scene!
	//virtual void Draw(){};

	void Update();
	void Draw();

	friend class GameObject;
	//------------Game Object Life Cycle- Sprint 4----------
	void AddToScene(GameObject* gameObj);


	//------------Game Object Life Cycle- Sprint 4----------
	void RemovefromScene(GameObject* gameObj);

public:


	//For registration
	void UpdateRegister(Updatable* up);
	void UpdateDeregister(Updatable* up);

	void DrawRegister(Drawable* draw);
	void DrawDeregister(Drawable* draw);

	void DrawRegister2D(Drawable2D* draw);
	void DrawDeregister2D(Drawable2D* draw);

	void AlarmRegister(AlarmMarker* alarm);
	void AlarmDeregister(AlarmMarker* alarm);

	void KeyRegister(Inputable* input, AZUL_KEY key, Inputable::INPUT_EVENT_TYPE e);
	void KeyDeregister(Inputable* input, AZUL_KEY key, Inputable::INPUT_EVENT_TYPE e);

	Terrain* SetSceneTerrain(const std::string key);
	Terrain* GetTerrain();

	template<typename C> 
	void CollisionRegister(C* c)
	{
		commandRegistrationBroker.addCommand(new CollisionRegistrationCommand<C>(c));
	}
	template<typename C>
	void CollisionDeregister(C* c)
	{
		commandRegistrationBroker.addCommand(new CollisionDeregistrationCommand<C>(c));
	}
	template <typename C> 
	void AddCollisionGroupDelete()
	{
		collisionManager.AddCollisionGroupDeleteCommand<C>();
	}
	template <typename C>
	void AddCollidableGroupABB()
	{
		collisionManager.AddCollisionGroupTest<C>();
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @ingroup Scene
	/// \brief Sets collision self
	/// \details  Specify here if you want to have collision with one game object colliding with another game object that is the same.
	//
	///	 \par Example:
	/// 
	/// \code			
	/// void SceneTest::Initalize()
	///	{
	///
	///		//..addd your objects to the scene...
	///		
	///		//would mean cottages colliding with other cottages
	///		SetCollisionPair<Cottage>();
	///
	///	}
	///	\endcode
	////////////////////////////////////////////////////////////////////////////////////////////////////

	template<typename C>
	void SetCollisionSelf()
	{
		collisionManager.SetCollisionSelf<C>();
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @ingroup Scene
	/// \brief Sets collision pair
	/// \details  Specify here which pairwise test your game will need for collision
	///
	/// <typeparam name="C1">	Type of the first collidable game object. </typeparam>
	/// <typeparam name="C2">	TType of the second collidable game object. </typeparam>
	/// 
	/// 
	///	 \par Example:
	/// 
	/// \code			
	/// void SceneTest::Initalize()
	///	{
	///
	///		//..addd your objects to the scene...
	///		
	///		SetCollisionPair<SpaceShip, Cottage>();
	///
	///	}
	///	\endcode
	////////////////////////////////////////////////////////////////////////////////////////////////////

	template<typename C1, typename C2>
	void SetCollisionPair()
	{
		collisionManager.SetCollisionPair<C1, C2>();
	}
	CameraManager* Scene::GetCameraManager();
	SoundManager* Scene::GetSoundManager();
	


};
#endif _Scene