// AxisAlignedBoundingBox.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "MathTools.h"
#include "AxisAlignedBoundingBox.h"
#include "Visualizer.h"
#include <cmath>

AxisAlignedBoundingBox::AxisAlignedBoundingBox()
{
	


}
void AxisAlignedBoundingBox::Initalize(const Model* model)
{
	model;
}
void AxisAlignedBoundingBox::ComputeData(const Model* model, const Matrix &matrix)
{

	//for each vertex
	//apply world transform
	//keep track of lowest of min/max values on 3 axes (x,y,z)

	//get first value
	Vect v = const_cast<Model*>(model)->getVectList()[0];

	//first times it by world matrix!
	v *= matrix;

	 minX = v.X();
	 minY = v.Y();
	 minZ = v.Z();
	 maxX = v.X();
	 maxY = v.Y();
	 maxZ = v.Z();


	//for loop, scan through all the points (all verticecs)-numVerts?
	for (int i = 1; i < model->numVerts; i++)
	{
		Vect v = const_cast<Model*>(model)->getVectList()[i];
		//transform the point first--
		//multiply by world matrix!
		v *= matrix;
		//do magic here to find min and max
		minX = mathTools.minTwoFloats(v.X(), minX);
		minY = mathTools.minTwoFloats(v.Y(), minY);
		minZ = mathTools.minTwoFloats(v.Z(), minZ);
		maxX = mathTools.maxTwoFloats(v.X(), maxX);
		maxY = mathTools.maxTwoFloats(v.Y(), maxY);
		maxZ = mathTools.maxTwoFloats(v.Z(), maxZ);
	}

	max = GetMax();
	min = GetMin();

	world = Matrix(SCALE,1,1,1);
	//max *= world.getInv();
	//min *= world.getInv();
	center = ((min + max))*0.5f;
	halfDiagonal = ((max - min))*0.5f;
	SquaredScaleFactor = 1;
	
}
Vect AxisAlignedBoundingBox::GetMax()
{
	max.X() = maxX;
	max.Y() = maxY;
	max.Z() = maxZ;

	return max;
}
Vect AxisAlignedBoundingBox::GetMin()
{
	min.X() = minX;
	min.Y() = minY;
	min.Z() = minZ;

	return min;
}
Matrix AxisAlignedBoundingBox::GetWorldMatrix()
{
	return world;
}
Vect AxisAlignedBoundingBox::GetHalfDiagonal()
{
	return halfDiagonal;
}
Vect AxisAlignedBoundingBox::GetCenter()
{
	return center;
}
float AxisAlignedBoundingBox::GetSquaredScaleFactor()
{
	return SquaredScaleFactor;
}
bool AxisAlignedBoundingBox::Intersect(AxisAlignedBoundingBox* AABBox2)
{
	return mathTools.IntersectAABBs(*this, *AABBox2);
}
bool AxisAlignedBoundingBox::Intersect(OrientedBoundingBox* OBB)
{
	return mathTools.IntersectOBBwithABB(*OBB, *this);
}
bool AxisAlignedBoundingBox::Intersect(BoundingSphere* bSphere)
{
	return mathTools.IntersectSpherewithAABB(*bSphere, *this);
}
bool AxisAlignedBoundingBox::Intersect(CollisionVolume* other)
{
	return other->Intersect(this);
}
bool AxisAlignedBoundingBox::Intersect(TerrainCell* other)
{
	return mathTools.IntersectCellwithAABBB(*other,*this);
}
void AxisAlignedBoundingBox::RenderThis(const Vect& color)
{

	Scale.set(SCALE, max - min);


	Vect translate = max + min;
	Trans.set(TRANS, translate.X() / 2.0f, translate.Y() / 2.0f, translate.Z() / 2.0f);
	world = Scale * Trans;

	visualizeHelper->RenderABB(world, color);
}