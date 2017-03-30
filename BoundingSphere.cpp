// BoundingSphere.cpp
//Jacqueline Passehl Winter Quarter 2k16


#include "BoundingSphere.h"
#include "Visualizer.h"
#include <cmath>

void BoundingSphere::ComputeData( const Model* model, const Matrix &matrix)
{	

	//Multipy center it by the matrix
	center = *(model->center) * matrix;	
	//insert radius into one axis of a vect-
	//radius and a bunch of zeroes)- multiply it by matrix
	Vect tempRadius = Vect(0, 0, model->radius, 0) * matrix;
	//take the float and get it by the magnitude
	radius = tempRadius.mag();
}
const Vect BoundingSphere::GetCenter()
{
	return center;
}
const float BoundingSphere::GetRadius()
{
	return radius;
}
bool BoundingSphere::Intersect( BoundingSphere* other)
{
	return mathTools.IntersectSpheres(*this,*other);
}
bool BoundingSphere::Intersect( AxisAlignedBoundingBox* AABBox)
{
	return mathTools.IntersectSpherewithAABB(*this, *AABBox);
}
bool BoundingSphere::Intersect( OrientedBoundingBox* OBB)
{
	return mathTools.IntesectOBBwithSphere(*OBB, *this);
}
bool BoundingSphere::Intersect(CollisionVolume* other)
{
	return other->Intersect(this);
}
bool BoundingSphere::Intersect(TerrainCell* other)
{
	return mathTools.IntersectCellwithSphere(*other, *this);
}
void BoundingSphere::RenderThis(const Vect& color)
{

	//move the wireframe sphere to have proper center and size- to put it in the right place
	Scale.set(SCALE, radius, radius, radius);
	Trans.set(TRANS, center);
	world = Scale * Trans;

	visualizeHelper->RenderBSphere(world,color);
}