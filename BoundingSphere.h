//BoundingSphere.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _BoundingSphere
#define _BoundingSphere

#include "AzulCore.h"
#include "MathTools.h"
#include "CollisionVolume.h"
#include "TerrainCell.h"

class Visualizer;
class TerrainCell;

class BoundingSphere : public CollisionVolume, public Align16
{
private:
	Vect center;
	float radius;
	Visualizer* visualizeHelper;

	MathTools mathTools;

	Matrix Scale;
	Matrix Trans;
	Matrix world;
public:

	BoundingSphere(){};
	~BoundingSphere(){};
	BoundingSphere& operator=(const BoundingSphere&) = delete;
	BoundingSphere(const BoundingSphere&) = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @defgroup BoundingSphere BoundingSphere
	///  @ingroup CollisionSystem
	///	  @brief The BoundingSphere (BSphere) Collision Volume
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/** @{ */

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Calculates the data. </summary>
	///
	/// <param name="model"> 	The model. </param>
	/// <param name="matrix">	The matrix. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void ComputeData(const Model* model, const Matrix &matrix);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the center. </summary>
	///
	/// <returns>	The center. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	const Vect GetCenter();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the radius. </summary>
	///
	/// <returns>	The radius. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	const float GetRadius();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Intersects another Bsphere </summary>
	///
	/// <param name="other">	The other bsphere to be collided with. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Intersect( BoundingSphere* other);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Intersects the given AABB. </summary>
	///
	/// <param name="AABBox">	The other AABB to be collided with</param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Intersect( AxisAlignedBoundingBox* AABBox);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Intersects the given OBB. </summary>
	///
	/// <param name="AABBox">	The other OBB to be collided with</param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Intersect( OrientedBoundingBox* AABBox);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Intersects the given collision volume. </summary>
	///
	/// <param name="other">	the other volume to be collided with. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Intersect(CollisionVolume* other);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Intersects the given TerrainCell. </summary>
	///
	/// <param name="other">	The terrain cell to be collided with. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Intersect(TerrainCell* other);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Renders this described by color. </summary>
	///
	/// <param name="color">	The color. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void RenderThis(const Vect& color);
	/** @} */
};
#endif _BoundingSphere