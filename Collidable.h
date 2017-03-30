//Collidable.h
//Jacqueline Passehl Winter Quarter 2k16

/*
// Class is not templated but the registration and deregistration methods
// are templated
//
*/

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @defgroup CollisionSystem CollisionSystem
/// @brief The Collision System has been updated so that it now handles collision with three different
/// collision volumes; an axis-aligned bounding box, and oriented bounding box, and a bounding sphere.
////////////////////////////////////////////////////////////////////////////////////////////////////




#ifndef _Collidable
#define _Collidable


#include "BoundingSphere.h"
#include "AxisAlignedBoundingBox.h"
#include "OrientedBoundingBox.h"
#include "TerrainCell.h"
#include "Terrain.h"
#include "SceneManager.h"

#include "CollisionVolume.h"
#include "CollisionVolumeTypes.h"

using namespace VolumeTypes;



class Collidable 
{
protected:
	//Bounding Sphere
	BoundingSphere *bSphere;

	//Model for Collision Tests
	const Model* pModel;

	CollisionVolume *colVolume;

	
public:


	Collidable(){};
	virtual ~Collidable()
	{
		DebugMsg::out("\nCollidable deconstructor called");
	};
	Collidable(const Collidable&) = delete;
	Collidable& operator=(const Collidable&) = delete;
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @defgroup Collidable Collidable
	///  @ingroup GameObject
	///  @ingroup CollisionSystem
	///	 @brief All GameObjects derive from Collidable which allows it to process Collision events with other game objects.
	///	 Each one has a bpshere and a collision volume. When collision checking, it first checks the bspheres before it tests the other volume
	///	 for optimization purposes.
	///	 
	///	 	 \par Example:
	/// The following example shows how you would go about setting collisions up.
	/// \code
	///void SceneDemo::Initalize()
	///{
	///			SetCollisionPair<SpaceShip,House>();
	///		
	///}
	///
	///void SpaceShip::SceneEntry()
	///{	
	///		//various registration methods...
	///		
	///		//individually register to collision group
	///		CollisionRegistration<SpaceShip>(this)
	///}
	/// void House::SceneEntry()
	///{
	///		// various registration methods...
	///		
	///		individually register to collision group
	///		CollisionRegistration<House>(this)
	///}
	/// void SpaceShip::Collision(House*)
	///{
	///		DebugMsg::out("Collision Spaceship with House");
	/// 
	///}
	///void House::Collision(SpaceShip*)
	///{
	///		DebugMsg::out("Collision House with SpaceShip");
	///
	/// }
	///  \endcode
	///	 
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/** @{ */

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 	This is the callback which  can be overloaded in the GameObject you'd like collisions for
	//
	/// </summary>
	///
	/// <param name="Collidable*">	The game object to be collided with </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Collision(Collidable*){};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	this is the callback for the collision with the bounding sphere. This makes the 
	/// 			collision more efficent because it checks for the bsphere collision before it checks for
	/// 			the collision with each game object's perspective volume </summary>
	///
	/// <typeparam name="Collidable*">	Type of the collidable. </typeparam>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void CollisionBSphere(Collidable*){};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 	Unlike the usual re/deregistration methods this one is tempalted in order to correctly
	/// 	indenfify the collsion group. This registers the collision event.
	/// </summary>
	///
	/// <typeparam name="C">	Type of the collidable. </typeparam>
	/// <param name="c">		The collidable. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	template<typename C>
	void CollisionRegistration(C* c)
	{
		SceneManager::GetCurrentScene()->CollisionRegister<C>(c);
	}
	template<typename C>

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 	Unlike the usual re/deregistration methods this one is tempalted in order to correctly
	/// 	indenfify the collsion group. This dergisters the collision event.
	/// </summary>
	///
	/// <typeparam name="C">	Type of the collidable. </typeparam>
	/// <param name="c">		The collidable. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void CollisionDeregistration(C* c)
	{
		SceneManager::GetCurrentScene()->CollisionDeregister<C>(c);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets object to be collided with. </summary>
	///
	/// <param name="model">	model object. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetColliderModel(Model* model)
	{
		pModel = model;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Set the two game objects that will need to have a collision event. </summary>
	///
	/// <param name="c1">	 the first collidable game object. </param>
	/// <param name="c2">	 the second collidable game object. </param>
	///
	/// <returns>	true if they are colliding , false if it not. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool CollisionTestPair(Collidable* c1, Collidable* c2)
	{
		//STATIC method
		//called by the collision test commands
		if (c1->colVolume->Intersect(c2->colVolume))
		{
			//if (c1->colVolume->Intersect(c2->colVolume))
			// if (c1->OBBox.Intersect(c2->bSphere))
			return true;
		}
		else
		{
			return false;
		}
		

	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Set the two game objects that will need to have a collision event using only their bspheres. </summary>
	///
	/// <param name="c1">	 the first collidable game object. </param>
	/// <param name="c2">	 the second collidable game object. </param>
	///
	/// <returns>	true if they are colliding , false if it not. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool CollisionTestPairBSphere(Collidable* c1, Collidable* c2)
	{
		//STATIC method
		//called by the collision test commands
		if (c1->bSphere->Intersect(c2->bSphere))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the game object and the terrain cell to be collided with. </summary>
	///
	/// <param name="cell">	 the TerrainCell. </param>
	/// <param name="c">	 the  collidable game object. </param>
	///
	/// <returns>	true if they are colliding , false if it not. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool CollisionTerrainCell(TerrainCell* cell, Collidable* c)
	{
		if (c->colVolume->Intersect(cell))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the game object's bsphere and the terrain cell to be collided with. </summary>
	///
	/// <param name="cell">	 the Terrain cell. </param>
	/// <param name="c">	 the  collidable game object. </param>
	///
	/// <returns>	true if they are colliding , false if it not. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool CollisionTerrainCellBsphere(TerrainCell* cell , Collidable* c)
	{
		if (c->bSphere->Intersect(cell))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Updates the collision data described by matrix. This updates the collision volume AND the bsphere's </summary>
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void UpdateCollisionData(Matrix& matrix)
	{
		bSphere->ComputeData(pModel, matrix);
		colVolume->ComputeData(pModel,matrix);

	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the collision volume of the game object </summary>
	///
	/// <param name="volType">	 The collsion volume that belongs to the game object </param>
	/// 
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void SetCollisionVolume(const CollisionVolumeTypes& volType)
	{
		bSphere = new BoundingSphere();

		if (volType == Type_BSphere)
		{
			colVolume = bSphere;
		}
		else if (volType == Type_AABBox)
		{
			colVolume = new AxisAlignedBoundingBox();
			colVolume->Initalize(pModel);
		}
		else if (volType == Type_OBBox)
		{
			colVolume = new OrientedBoundingBox();
			colVolume->Initalize(pModel);
			
			
		}

	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary> Return the bsphere that each Game Object has </summary>
	///
	/// <returns>	the bpshere </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	BoundingSphere* getBSphere()
	{
		return bSphere;
	}


};
#endif _Collidable
