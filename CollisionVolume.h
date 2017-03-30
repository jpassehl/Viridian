//CollisionVolume.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _CollisionVolume
#define _CollisionVolume

#include "AzulCore.h"
#include <cmath>


class BoundingSphere;
class AxisAlignedBoundingBox;
class OrientedBoundingBox;
class TerrainCell;

//like "Instructions"



class CollisionVolume
{

private:



public:

	CollisionVolume(){};
	~CollisionVolume(){};
	CollisionVolume(const CollisionVolume&){};
	CollisionVolume operator=(const CollisionVolume&) = delete;
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @defgroup CollisionVolume CollisionVolume
	///  @ingroup CollisionSystem
	///	  @brief All Collisoin Volumes inheirt from this base class. This uses the visitor pattern so we can 
	///	  get double dispatch. None of the methods in this class should be called as they are all implemented in their
	///	  derived classes
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/** @{ */


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Base Intersection with volume. </summary>
	///
	/// <param name="other">	other volume to be collided with </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual bool Intersect( CollisionVolume* other)
	{ 
		DebugMsg::out("Calling Collision Volume Base Class");
		other;
		return false; 
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Base Intersection with bsphere. </summary>
	///
	/// <param name="other">	other bsphere to be collided with </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual bool Intersect( BoundingSphere* other)
	{
		DebugMsg::out("Calling Collision Volume Base Class");
		other;
		return false; 
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Base Intersection with AABB. </summary>
	///
	/// <param name="other">	other ABB to be collided with </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual bool Intersect( AxisAlignedBoundingBox* other)
	{ 
		DebugMsg::out("Calling Collision Volume Base Class");
		other;
		return false; 
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Base Intersection with OBB. </summary>
	///
	/// <param name="other">	other OBB to be collided with </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual bool Intersect(OrientedBoundingBox* other)
	{
		DebugMsg::out("Calling Collision Volume Base Class");
		other;
		return false;
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Base Intersection with TerrainCell. </summary>
	///
	/// <param name="other">	other TerainCell to be collided with </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual bool Intersect(TerrainCell* other)
	{
		DebugMsg::out("Calling Collision Volume Base Class");
		other;
		return false;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Calculates the data for each perspective volume. </summary>
	///
	/// <param name="model"> 	The model. </param>
	/// <param name="matrix">	The matrix. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void ComputeData(const Model* model, const Matrix &matrix)
	{
		DebugMsg::out("Calling Collision Volume Base Class");
		model;
		matrix;
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets collision volume. </summary>
	///
	/// <returns>	the collsion volume. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual CollisionVolume* GetCollisionVolume()
	{
		return this;
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Renders the collision volume. </summary>
	///
	/// <param name="color">	The color. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void RenderThis(const Vect& color)
	{
		DebugMsg::out("Calling Collision Volume Base Class");
		color;

	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Initalizes the volume data. </summary>
	///
	/// <param name="model">	The model. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Initalize(const Model* model)
	{
		DebugMsg::out("Calling Collision Volume Base Class");
		model;

	};
	/** @} */

};
#endif _CollisionVolume