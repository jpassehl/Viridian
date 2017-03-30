//AxisAlignedBoundingBox.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _AxisAlignedBoundingBox
#define _AxisAlignedBoundingBox

#include "MathTools.h"
#include "AzulCore.h"
#include "CollisionVolume.h"
#include "TerrainCell.h"
#include <set>


class Visualizer;
class TerrainCell;


class AxisAlignedBoundingBox :public CollisionVolume, public Align16
{
private:
	
	//data points:
	//min on x/y/z
	Vect min;
	//max on x/y/z
	Vect max;

	Vect center;
	Matrix world;
	Matrix Trans;
	Matrix Scale;
	Vect halfDiagonal;
	float SquaredScaleFactor;

	MathTools mathTools;
	Visualizer* visualizeHelper;
	

public:

	float minX;
	float minY;
	float minZ;
	float maxX;
	float maxY;
	float maxZ;

	AxisAlignedBoundingBox();
	~AxisAlignedBoundingBox(){};
	AxisAlignedBoundingBox& operator=(const AxisAlignedBoundingBox&) = delete;
	AxisAlignedBoundingBox(const AxisAlignedBoundingBox&) = delete;

	//scan all vertices of the model, for each vertex apply world transform
	
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @defgroup AxisAlignedBoundingBox AxisAlignedBoundingBox
	///  @ingroup CollisionSystem
	///	  @brief The AxisAlignedBoundingBox (AABB) Collision Volume
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/** @{ */

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Computes the data. </summary>
	///
	/// <param name="model"> 	The model. </param>
	/// <param name="matrix">	The matrix. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void ComputeData(const Model* model, const Matrix &matrix);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Intersects the given AABB. </summary>
	///
	/// <param name="AABBox2">	the other ABB to be collided with </param>
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Intersect( AxisAlignedBoundingBox* AABBox2);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Intersects the AABB with the OBB </summary>
	///
	/// <param name="OBB">	the OBB to be collided with </param>
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Intersect(OrientedBoundingBox* OBB);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Intersects the AABB with the BSphere. </summary>
	///
	/// <param name="bSphere">	the bsphere. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Intersect(BoundingSphere* bSphere);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Intersects the AABB with the volume. </summary>
	///
	/// <param name="other">	the the collision volume to be collided with. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Intersect(CollisionVolume* other);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Intersects the Terrain Cell. </summary>
	///
	/// <param name="other">	the cell to be collided with. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Intersect(TerrainCell* other);

	template <typename C>

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Creates a AABB that surrounds a group of colliables. </summary>
	///
	/// <param name="> "collidableCollection">	 collection of >collidables. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void CreateGroupABB(std::set<C*>collidableCollection)
	{
		//make an ABB that surronds all the objects
		{
			//get biggest max and biggest min of all the models

			//every model has pre-caclulated bsphere radius
			//given a sphere, what is the ABB out of the sphere??
			//we can get min and max around the sphere

			//Given two AABBS, how do you find the enclosing AABB?
			//max of the max and the min of the min

			if (collidableCollection.size() > 0)
			{
				//intialize shit here
				float radius = (*collidableCollection.begin())->getBSphere()->GetRadius();

				max = (*collidableCollection.begin())->getBSphere()->GetCenter();
				max.X() += radius;
				max.Y() += radius;
				max.Z() += radius;

				min = (*collidableCollection.begin())->getBSphere()->GetCenter();
				min.X() -= radius;
				min.Y() -= radius;
				min.Z() -= radius;

			}


			for (auto it = collidableCollection.begin(); it != collidableCollection.end(); it++)
			{
				//get the maximum point from the center
				Vect TempMaxPoint = (*it)->getBSphere()->GetCenter();
				//you have to add the radiuses to get the max point
				TempMaxPoint.X() += (*it)->getBSphere()->GetRadius();
				TempMaxPoint.Y() += (*it)->getBSphere()->GetRadius();
				TempMaxPoint.Z() += (*it)->getBSphere()->GetRadius();

				//get the minimum point from the center
				Vect TempMinPoint = (*it)->getBSphere()->GetCenter();
				//you have to add the radiuses to get the max point
				TempMinPoint.X() -= (*it)->getBSphere()->GetRadius();
				TempMinPoint.Y() -= (*it)->getBSphere()->GetRadius();
				TempMinPoint.Z() -= (*it)->getBSphere()->GetRadius();

				max = MathTools::returnMaxVector(max, TempMaxPoint);
				min = MathTools::returnMaxVector(min, TempMinPoint);

			}
			maxX = max.X();
			maxY = max.Y();
			maxZ = max.Z();

			minX = min.X();
			minY = min.Y();
			minZ = min.Z();

			//create translation matrix for scaling
			Scale.set(SCALE, max - min);
			Vect translate = max + min;
			Trans.set(TRANS, translate.X() / 2.0f, translate.Y() / 2.0f, translate.Z() / 2.0f);
			world = Scale * Trans;
		}

	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Initalizes the given model. </summary>
	///
	/// <param name="model">	The model. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void Initalize(const Model* model);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Renders this AABB. </summary>
	///
	/// <param name="color">	The color. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void RenderThis(const Vect& color);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets world matrix. </summary>
	///
	/// <returns>	The world matrix. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Matrix GetWorldMatrix();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets half diagonal. </summary>
	///
	/// <returns>	The half diagonal. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Vect GetHalfDiagonal();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the center. </summary>
	///
	/// <returns>	The center. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Vect GetCenter();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets squared scale factor. </summary>
	///
	/// <returns>	The squared scale factor. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	float GetSquaredScaleFactor();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the minimum. </summary>
	///
	/// <returns>	The calculated minimum. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Vect GetMin();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the maximum. </summary>
	///
	/// <returns>	The calculated maximum. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Vect GetMax();
	/** @} */
};
#endif _AxisAlignedBoundingBox