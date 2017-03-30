#include "MathTools.h"
#include "BoundingSphere.h"
#include "AxisAlignedBoundingBox.h"
#include "OrientedBoundingBox.h"
#include "Visualizer.h"

#include <float.h>
#include <math.h>


bool MathTools:: IntersectSpheres(const BoundingSphere& bSphere1, const BoundingSphere& bSphere2)
{
	float radius1 = const_cast<BoundingSphere&>(bSphere1).GetRadius();
	Vect center1 = const_cast<BoundingSphere&>(bSphere1).GetCenter();

	float radius2 = const_cast<BoundingSphere&>(bSphere2).GetRadius();
	Vect center2 = const_cast<BoundingSphere&>(bSphere2).GetCenter();

	float raidusSum = radius1 + radius2;
	if ((center1 - center2).magSqr() < std::pow(raidusSum, 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool MathTools::IntersectAABBs(const AxisAlignedBoundingBox& AABBox1, const AxisAlignedBoundingBox& AABBox2)
{

	//check if two AABBs are colliding 
	//test axis interval on all 3 sides
	//test 3 axis things

	bool retFlag = true;

	// x axis
	if (!intervalOverlap(AABBox1.minX, AABBox1.maxX, AABBox2.minX, AABBox2.maxX))
	{
		retFlag= false;
	}
	// y axis
	if (!intervalOverlap(AABBox1.minY, AABBox1.maxY, AABBox2.minY, AABBox2.maxY))
	{
		retFlag = false;
	}
	//z axis
	if (!intervalOverlap(AABBox1.minZ, AABBox1.maxZ, AABBox2.minZ, AABBox2.maxZ))
	{
		retFlag = false;
	}

	return retFlag;


}
bool MathTools:: IntersectOBBs(const OrientedBoundingBox& OBB1, const OrientedBoundingBox& OBB2) 
{
	Matrix world1 = const_cast<OrientedBoundingBox&>(OBB1).GetWorldMatrix();
	Matrix world2 = const_cast<OrientedBoundingBox&>(OBB2).GetWorldMatrix();

	if ((OverlapOBBS(OBB1, OBB2, world1.get(ROW_0))) &&
		(OverlapOBBS(OBB1, OBB2, world1.get(ROW_1))) &&
		(OverlapOBBS(OBB1, OBB2, world1.get(ROW_2))) &&

		(OverlapOBBS(OBB1, OBB2, world2.get(ROW_0))) &&
		(OverlapOBBS(OBB1, OBB2, world2.get(ROW_1))) &&
		(OverlapOBBS(OBB1, OBB2, world2.get(ROW_2))) &&

		(OverlapOBBS(OBB1, OBB2, world2.get(ROW_0).cross(world1.get(ROW_0)))) &&
		(OverlapOBBS(OBB1, OBB2, world2.get(ROW_1).cross(world1.get(ROW_0)))) &&
		(OverlapOBBS(OBB1, OBB2, world2.get(ROW_2).cross(world1.get(ROW_0)))) &&

		(OverlapOBBS(OBB1, OBB2, world2.get(ROW_0).cross(world1.get(ROW_1)))) &&
		(OverlapOBBS(OBB1, OBB2, world2.get(ROW_1).cross(world1.get(ROW_1)))) &&
		(OverlapOBBS(OBB1, OBB2, world2.get(ROW_2).cross(world1.get(ROW_1)))) &&

		(OverlapOBBS(OBB1, OBB2, world2.get(ROW_0).cross(world1.get(ROW_2)))) &&
		(OverlapOBBS(OBB1, OBB2, world2.get(ROW_1).cross(world1.get(ROW_2)))) &&
		(OverlapOBBS(OBB1, OBB2, world2.get(ROW_2).cross(world1.get(ROW_2)))))
	{
		return true;
	}

	return false;


}
bool MathTools::IntersectSpherewithAABB(const BoundingSphere& bSphere, const AxisAlignedBoundingBox& AABBox)
{
	//for this collision test, clamp the center of the sphere to the AABB on all three axes
	Vect clampedPoint = const_cast<BoundingSphere&>(bSphere).GetCenter();
	
	Vect max = const_cast<AxisAlignedBoundingBox&>(AABBox).GetMax();
	Vect min = const_cast<AxisAlignedBoundingBox&>(AABBox).GetMin();


	//clamp center to x axis
	clampedPoint.X() =ClampToInterval(clampedPoint.X(), min.X(), max.X());
	//clamp center to y axis
	clampedPoint.Y() = ClampToInterval(clampedPoint.Y(), min.Y(), max.Y());
	//clamp center to z axis
	clampedPoint.Z() = ClampToInterval(clampedPoint.Z(), min.Z(), max.Z());

	if (pointInSphere(clampedPoint, bSphere))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool MathTools::IntesectOBBwithSphere(const OrientedBoundingBox& OBB, const BoundingSphere& bSphere)
{
	//for this collision test, clamp the center of the sphere to the AABB on all three axes
	Vect clampedPoint = const_cast<BoundingSphere&>(bSphere).GetCenter();

	Vect max = const_cast<OrientedBoundingBox&>(OBB).GetMax();
	Vect min = const_cast<OrientedBoundingBox&>(OBB).GetMin();

	//convert the point to a LOCAL one
	Matrix worldMatrix = const_cast<OrientedBoundingBox&>(OBB).GetWorldMatrix();
	Vect localClamp = clampedPoint * worldMatrix.getInv();


	//clamp center to x axis
	localClamp.X() = ClampToInterval(localClamp.X(), min.X(), max.X());
	//clamp center to y axis
	localClamp.Y() = ClampToInterval(localClamp.Y(), min.Y(), max.Y());
	//clamp center to z axis
	localClamp.Z() = ClampToInterval(localClamp.Z(), min.Z(), max.Z());

	localClamp *= worldMatrix;


	if (pointInSphere(localClamp, bSphere))
	{
		return true;
	}
	else
	{
		return false;
	} 
}
bool MathTools::IntersectOBBwithABB(const OrientedBoundingBox& OBB, const AxisAlignedBoundingBox& AABB)
{
	Matrix world1 = const_cast<OrientedBoundingBox&>(OBB).GetWorldMatrix();
	Matrix world2 = const_cast<AxisAlignedBoundingBox&>(AABB).GetWorldMatrix();

	if ((OverlapOBBwithABB(OBB, AABB, world1.get(ROW_0))) &&
		(OverlapOBBwithABB(OBB, AABB, world1.get(ROW_1))) &&
		(OverlapOBBwithABB(OBB, AABB, world1.get(ROW_2))) &&

		(OverlapOBBwithABB(OBB, AABB, world2.get(ROW_0))) &&
		(OverlapOBBwithABB(OBB, AABB, world2.get(ROW_1))) &&
		(OverlapOBBwithABB(OBB, AABB, world2.get(ROW_2))) &&

		(OverlapOBBwithABB(OBB, AABB, world2.get(ROW_0).cross(world1.get(ROW_0)))) &&
		(OverlapOBBwithABB(OBB, AABB, world2.get(ROW_1).cross(world1.get(ROW_0)))) &&
		(OverlapOBBwithABB(OBB, AABB, world2.get(ROW_2).cross(world1.get(ROW_0)))) &&

		(OverlapOBBwithABB(OBB, AABB, world2.get(ROW_0).cross(world1.get(ROW_1)))) &&
		(OverlapOBBwithABB(OBB, AABB, world2.get(ROW_1).cross(world1.get(ROW_1)))) &&
		(OverlapOBBwithABB(OBB, AABB, world2.get(ROW_2).cross(world1.get(ROW_1)))) &&

		(OverlapOBBwithABB(OBB, AABB, world2.get(ROW_0).cross(world1.get(ROW_2)))) &&
		(OverlapOBBwithABB(OBB, AABB, world2.get(ROW_1).cross(world1.get(ROW_2)))) &&
		(OverlapOBBwithABB(OBB, AABB, world2.get(ROW_2).cross(world1.get(ROW_2)))))
	{
		return true;
	}

	return false;


}
 float MathTools::minTwoFloats(float f1, float f2)
{
	if (f1 < f2)
	{
		return f1;
	}
	else
	{
		return f2;
	}
}
float MathTools::maxTwoFloats(float f1, float f2)
{
	if (f1 > f2)
	{
		return f1;
	}
	else
	{
		return f2;
	}
}
Vect MathTools:: returnMaxVector(Vect& p1, Vect& p2)
{
	Vect temp;

	temp.X() = (maxTwoFloats(p1.X(), p2.X()));
	temp.Y() = (maxTwoFloats(p1.Y(), p2.Y()));
	temp.Z() = (maxTwoFloats(p1.Z(), p2.Z()));

	return temp;

}
bool MathTools::pointInSphere(const Vect& point, const BoundingSphere& bSphere)
{
	//first get the distance between the point and the center
	//center minus point cause youre taking distance from center
	//to the point

	float radius = const_cast<BoundingSphere&>(bSphere).GetRadius();
	Vect center = const_cast<BoundingSphere&>(bSphere).GetCenter();

	if ((center - point).magSqr() < pow(radius, 2.0f))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool MathTools::pointInAABB(const Vect&point, const AxisAlignedBoundingBox& AABBox)
{
	//is point inside the AABB?
	//look at every x,y,z value of the point, is 
	//it betweeen the x,y,z value of the min and max of the box?
	//if yes on ALL 3 then you're inside. Cant be missing one

	Vect max = const_cast<AxisAlignedBoundingBox&>(AABBox).GetMax();
	Vect min = const_cast<AxisAlignedBoundingBox&>(AABBox).GetMin();


	if (isAnInterval(point, min, max))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool MathTools::pointinOBB(const Vect& point, const OrientedBoundingBox& OBB)
{
	//take the point and multiply it by the intervese of the world transform to get local space
	Matrix worldMatrix = const_cast<OrientedBoundingBox&>(OBB).GetWorldMatrix();
	Vect localPoint = point * worldMatrix.getInv();

	//get max and mind
	Vect max = const_cast<OrientedBoundingBox&>(OBB).GetMax();
	Vect min = const_cast<OrientedBoundingBox&>(OBB).GetMin();


	if (isAnInterval(localPoint, min, max))
	{
		return true;
	}
	else
	{
		return false;
	}


}
bool MathTools::OverlapOBBS(const OrientedBoundingBox& OBB1, const OrientedBoundingBox& OBB2, const Vect& axis)
{

	if (axis.magSqr() > FLT_EPSILON)
	{
		Vect localAxis = axis;
		localAxis.W() = 0;

		Vect OBB1center = const_cast<OrientedBoundingBox&>(OBB1).GetCenter();
		Vect OBB2center = const_cast<OrientedBoundingBox&>(OBB2).GetCenter();

		//comptue projection length of OBB1Center-OBB2Center along axis
		//Vect difference = OBB1center - OBB2center;
		//difference.W() = 0.0f;

		float difference = DistanceProjection(localAxis, OBB1center, OBB2center);
		

		//compute OBB1 and OBB2 projection lengths along axis
		float OBB1projection = MaxOBBprojection(OBB1, localAxis);
		float OBB2projection = MaxOBBprojection(OBB2, localAxis);

		if (difference > OBB1projection + OBB2projection)
		{
			return false;
		}
	}
	
	return true;
	

}
bool MathTools::OverlapOBBwithABB(const OrientedBoundingBox& OBB, const AxisAlignedBoundingBox& AABB, const Vect& axis)
{
	if (axis.magSqr() > FLT_EPSILON)
	{
		Vect localAxis = axis;
		localAxis.W() = 0;

		Vect OBBcenter = const_cast<OrientedBoundingBox&>(OBB).GetCenter();
		Vect ABBcenter = const_cast<AxisAlignedBoundingBox&>(AABB).GetCenter();

		//comptue projection length of OBB1Center-OBB2Center along axis
		//Vect difference = OBB1center - OBB2center;
		//difference.W() = 0.0f;

		float difference = DistanceProjection(localAxis, OBBcenter, ABBcenter);


		//compute OBB1 and OBB2 projection lengths along axis
		float OBBprojection = MaxOBBprojection(OBB, localAxis);
		float ABBprojection = MaxABBprojection(AABB, localAxis);

		if (difference > OBBprojection + ABBprojection)
		{
			return false;
		}
	}

	return true;



}
float MathTools::MaxOBBprojection(const OrientedBoundingBox& OBB, const Vect& v)
{
	//move v to local space
	//take the point and multiply it by the intervese of the world transform to get local space
	Matrix worldMatrix = const_cast<OrientedBoundingBox&>(OBB).GetWorldMatrix();
	Vect localPoint = v * worldMatrix.getInv();
	//pure vector- set it W to zero
	localPoint.W() = 0.0f;

	Vect halfDiagonal = const_cast<OrientedBoundingBox&>(OBB).GetHalfDiagonal();
	//get max projection using half diagonal
	float MaxProjection = abs(localPoint.X()*halfDiagonal.X()) + abs(localPoint.Y()*halfDiagonal.Y()) + abs(localPoint.Z()*halfDiagonal.Z());

	float scaleSquared = const_cast<OrientedBoundingBox&>(OBB).GetSquaredScaleFactor();
	return scaleSquared*(MaxProjection / v.mag());

}
float MathTools::MaxABBprojection(const AxisAlignedBoundingBox& ABB, const Vect& v)
{
	//move v to local space
	//take the point and multiply it by the intervese of the world transform to get local space
	Matrix worldMatrix = const_cast<AxisAlignedBoundingBox&>(ABB).GetWorldMatrix();
	Vect localPoint = v * worldMatrix.getInv();
	//pure vector- set it W to zero
	localPoint.W() = 0.0f;

	Vect halfDiagonal = const_cast<AxisAlignedBoundingBox&>(ABB).GetHalfDiagonal();
	//get max projection using half diagonal
	float MaxProjection = abs(localPoint.X()*halfDiagonal.X()) + abs(localPoint.Y()*halfDiagonal.Y()) + abs(localPoint.Z()*halfDiagonal.Z());

	float scaleSquared = const_cast<AxisAlignedBoundingBox&>(ABB).GetSquaredScaleFactor();
	return scaleSquared*(MaxProjection / v.mag());

}
bool MathTools::intervalOverlap(float a, float b, float c, float d)
{
	//how do you test if two intervals overlap?
	//there is 5 cases

	if ((b < c) || (d < a))
	{
		return false;
	}
	else
	{
		return true;
	}

}
bool MathTools::isAnInterval(const Vect& point, const Vect& min, const Vect& max)
{
	//test if value is an interval
	
	bool retFlag = false;

	if ((point.X() > min.X()) && (point.X() < max.X()))
	{
		retFlag = true;
	}
	if ((point.Y() > min.Y()) && (point.Y() < max.Y()))
	{
		retFlag = true;
	}
	if ((point.Z() > min.Z()) && (point.Z() < max.Z()))
	{
		retFlag = true;
	}

	return retFlag;
}
float MathTools::ClampToInterval(const float v, float min, float max)
{
	if (v < min)
	{
		return min;
	}
	else if(v > max)
	{
		return max;
	}
	else
	{
		return v;
	}
}
float MathTools::DistanceProjection(const Vect& p, const Vect& center1, const Vect& center2)
{

	Vect distanceCenters = center2;
	Vect center1Projection = (p.dot(distanceCenters) / abs(p.magSqr()))*p;

	distanceCenters = center1;
	Vect center2Projection = (p.dot(distanceCenters) / abs(p.magSqr()))*p;

	Visualizer::RenderLine(center1Projection, center2Projection, Vect(1, 0, 0));
	//above is for visualizer---

	distanceCenters = center1 - center2;
	return((p.dot(distanceCenters) / (p.magSqr()))*p).mag();


}
bool MathTools:: IntersectCellwithSphere(TerrainCell& cell, BoundingSphere& bSphere)
{
	//for this collision test, clamp the center of the sphere to the AABB on all three axes
	Vect clampedPoint = const_cast<BoundingSphere&>(bSphere).GetCenter();

	Vect max = const_cast<TerrainCell&>(cell).getMax();
	Vect min = const_cast<TerrainCell&>(cell).getMin();


	//clamp center to x axis
	clampedPoint.X() = ClampToInterval(clampedPoint.X(), min.X(), max.X());
	//clamp center to y axis
	clampedPoint.Y() = ClampToInterval(clampedPoint.Y(), min.Y(), max.Y());
	//clamp center to z axis
	clampedPoint.Z() = ClampToInterval(clampedPoint.Z(), min.Z(), max.Z());

	if (pointInSphere(clampedPoint, bSphere))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool MathTools:: IntersectCellwithAABBB(TerrainCell& cell, AxisAlignedBoundingBox& AABB)
{

	Vect cellMax = const_cast<TerrainCell&>(cell).getMax();
	Vect cellMin = const_cast<TerrainCell&>(cell).getMin();

	bool retFlag = true;

	// x axis
	if (!intervalOverlap(cellMin.X(), cellMax.X(), AABB.minX, AABB.maxX))
	{
		retFlag = false;
	}
	// y axis
	if (!intervalOverlap(cellMin.Y(), cellMax.Y(), AABB.minY, AABB.maxY))
	{
		retFlag = false;
	}
	//z axis
	if (!intervalOverlap(cellMin.Z(), cellMax.Z(), AABB.minZ, AABB.maxZ))
	{
		retFlag = false;
	}

	return retFlag;
}
bool MathTools:: IntersectCellwithOBB(TerrainCell& cell, OrientedBoundingBox& OBB)
{
	cell;
	OBB;
	return 0;
}