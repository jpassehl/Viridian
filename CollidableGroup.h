 //CollidableGroup.h
//Jacqueline Passehl Winter Quarter 2k16

/*
// Point is to know which bucket pair we're interested in
// Collidables must be grouped by user type.
// Different because we need access to things that dont exist, you dont know what
// object u wanna create with the engine.
//
//
//
// Templated to a specific Collidabe-derived class C
//	All there is to it: nothing more than our standard managers, a bucket, a list
// that you can register/deregister from. Templatized means bucket collection will be templateized
// to a map, list, whatever.
//
// Set up as a SINGLETON for easy access
*/


#ifndef _CollidableGroup
#define _CollidableGroup

#include<set>
#include "SceneManager.h"
#include "CollisionManager.h"
#include "Visualizer.h"
#include "AxisAlignedBoundingBox.h"
#include "Align16.h"

class Collidable;
class BoundingSphere;
class MathTools;

template<typename C> 
class CollidableGroup : public Align16
{
private:
	MathTools* mathTools;
	AxisAlignedBoundingBox* AABB;
	Collidable* collidable;

	CollidableGroup()
	{
		AABB = new AxisAlignedBoundingBox();
		SceneManager::GetCurrentScene()->AddCollisionGroupDelete<C>();
		SceneManager::GetCurrentScene()->AddCollidableGroupABB<C>();
	};
	~CollidableGroup()
	{	
		collidableCollection.clear();
		DebugMsg::out("\nCollidable Group deconstructor called");
	};
	CollidableGroup(const CollidableGroup&){};
	CollidableGroup operator=(const CollidableGroup&){};

	static CollidableGroup<C>* instance;

	static CollidableGroup<C>& getInstance() 
	{
		//if instance is null
		//make new instance with constructor
		if (instance == nullptr)
		{
			instance = new CollidableGroup<C>();
		}

		return *instance;
	}

	//maintains a collectin of type C pointers


	CollidableGroup<C>& Instance();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @defgroup CollidableGroup CollidableGroup
	///  @ingroup CollisionSystem
	///	  @brief The Collision Group for tiered collision. So that an object can test for collision with a group of 
	///	  objects!
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/** @{ */
	
	
	/// <summary> deletes the gorups. </summary>
	static void PrivDelete()
	{
		//iterate through the list and delete
		
		delete instance;
		instance = nullptr;
	}

	 /// <summary>	 creates group AABB. </summary>
	 void privCreateGroupABB()
	 {
		 AABB->CreateGroupABB(collidableCollection);
	 }

	 ////////////////////////////////////////////////////////////////////////////////////////////////////
	 /// <summary>	Intersects the group AABBS of each objects </summary>
	 ///
	 /// <param name="AABB">	the ABB  </param>
	 ///
	 /// <returns>	true if it succeeds, false if it fails. </returns>
	 ////////////////////////////////////////////////////////////////////////////////////////////////////

	 bool privIntersectGroupABBs(AxisAlignedBoundingBox* AABB)
	 {
		 return mathTools->IntersectAABBs((*this->AABB), *AABB);
	 }

	 ////////////////////////////////////////////////////////////////////////////////////////////////////
	 /// <summary>	Priv intersect AABB v bsphere. </summary>
	 ///
	 /// <param name="bSphere">	the sphere. </param>
	 ///
	 /// <returns>	true if it succeeds, false if it fails. </returns>
	 ////////////////////////////////////////////////////////////////////////////////////////////////////

	 bool privIntersectABBvBsphere(BoundingSphere* bSphere)
	 {
		 return mathTools->IntersectSpherewithAABB(*bSphere, (*this->AABB));
	 }
	 /** @} */
public:
	typedef std::set<C*> CollidableCollection;
	CollidableCollection collidableCollection;



	static void Delete()
	{
		getInstance().PrivDelete();
	}
	static void Register(C* collidable_C)
	{
		//DebugMsg::out("Register Collidable Group Called");
		getInstance().collidableCollection.insert(collidable_C);
		//GetColliderCollection();
	}
	static void Deregister(C* collidable_C)
	{
		//DebugMsg::out("Deregister Collidable Group Called");
		getInstance().collidableCollection.erase(collidable_C);
	}
	static CollidableCollection& GetColliderCollection()
	{
		return getInstance().collidableCollection;
	}
	static void CreateGroupABB()
	{
		return getInstance().privCreateGroupABB();
	}
	static bool IntersectGroupABBs(AxisAlignedBoundingBox* AABB)
	{
		return getInstance().privIntersectGroupABBs(AABB);
	}
	static bool IntersectABBvBsphere(BoundingSphere* bSphere)
	{
		return getInstance().privIntersectABBvBsphere(bSphere);
	}
	static AxisAlignedBoundingBox* getAABB()
	{
		return getInstance().AABB;
	}
	static void RenderThis(Vect &color)
	{
		Visualizer::ShowCollisionAABB(getInstance().AABB,color);
	}
	
};
template<typename C>
CollidableGroup<C>* CollidableGroup<C>::instance = nullptr;

#endif _CollidableGroup
