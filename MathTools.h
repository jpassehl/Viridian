//MathTools.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _MathTools
#define _MathTools

#include "AzulCore.h"
#include <cmath>

//forward declarations 
class BoundingSphere;
class AxisAlignedBoundingBox;
class OrientedBoundingBox;
class TerrainCell;


class MathTools
{

private:
	
	BoundingSphere* bSphere;
	 
public:
	
	MathTools(){};
	~MathTools(){};
	MathTools(const MathTools&){};
	MathTools operator=(const MathTools&) = delete;

	static bool IntersectSpheres(const BoundingSphere& bSphere1, const BoundingSphere& bSphere2);
	static bool IntersectAABBs(const AxisAlignedBoundingBox& AABBox1, const AxisAlignedBoundingBox& AABBox2);
	static bool IntersectOBBs(const OrientedBoundingBox& OBB1, const OrientedBoundingBox& OBB2);
	
	static bool IntersectSpherewithAABB(const BoundingSphere& bSphere, const AxisAlignedBoundingBox& AABBox);
	static bool IntesectOBBwithSphere(const OrientedBoundingBox& OBB, const BoundingSphere& bSphere);
	static bool IntersectOBBwithABB(const OrientedBoundingBox& OBB, const AxisAlignedBoundingBox& AABB);
	
	static bool IntersectCellwithSphere(TerrainCell& cell, BoundingSphere& bSphere);
	static bool IntersectCellwithAABBB(TerrainCell& cell, AxisAlignedBoundingBox& AABB);
	static bool IntersectCellwithOBB(TerrainCell& cell, OrientedBoundingBox& OBB);

	
	static bool pointInSphere(const Vect& point, const BoundingSphere& bSphere);
	static bool pointInAABB(const Vect& point, const AxisAlignedBoundingBox& AABBox);
	static bool pointinOBB(const Vect& point, const OrientedBoundingBox& OBB);

	static bool OverlapOBBwithABB(const OrientedBoundingBox& OBB, const AxisAlignedBoundingBox& AABB,const Vect& axis);
	static bool OverlapOBBS(const OrientedBoundingBox& OBB1, const OrientedBoundingBox& OBB2, const Vect& axis);
	static bool intervalOverlap(float a, float b, float c, float d);
	static bool isAnInterval(const Vect& point, const Vect& min, const Vect& max);
	static float ClampToInterval(const float v, float min, float max);
	
	static float minTwoFloats(float f1, float f2);
	static float maxTwoFloats(float f1, float f2);

	static Vect returnMaxVector(Vect& p1, Vect& p2);

	static float MaxOBBprojection(const OrientedBoundingBox& OBB, const Vect& v);
	static float MaxABBprojection(const AxisAlignedBoundingBox& ABB, const Vect& v);

	static float DistanceProjection(const Vect& p, const Vect& center1, const Vect& center2);

	//static float GetProjectionVector();




};
#endif _MathTools