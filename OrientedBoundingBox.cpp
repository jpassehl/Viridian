// OrientedBoundingBox.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "MathTools.h"
#include "OrientedBoundingBox.h"
#include "TerrainCell.h"
#include <cmath>
#include <math.h>
#include "Visualizer.h"


OrientedBoundingBox::OrientedBoundingBox()
{

}
void OrientedBoundingBox::Initalize(const Model* model)
{
	//these needs to be set so that it doesn't change every frame?
	min = *model->minPointAABB;
	max = *model->maxPointAABB;
	halfDiagonal = 0.5f*(max - min);
	halfDiagonal.W() = 0;
	center = (min + max) * 0.5f;
}
void OrientedBoundingBox::ComputeData(const Model* model, const Matrix &matrix)
{

	world = matrix;

	//apply world transform
	*model->maxPointAABB*matrix;
	*model->minPointAABB*matrix;
	
	//min and max points
	min = *model->minPointAABB;
	max = *model->maxPointAABB;
	//halfDiagonal = 0.5f*(max - min);

	center = (min + max)*matrix;

	SquaredScaleFactor = (Vect(1, 0, 0, 0)*matrix).magSqr();

}
Vect OrientedBoundingBox::GetMax()
{
	return max;
}
Vect OrientedBoundingBox::GetMin()
{
	return min;
}
Matrix OrientedBoundingBox::GetWorldMatrix()
{
	return world;
}
Vect OrientedBoundingBox::GetHalfDiagonal()
{
	return halfDiagonal;
}
Vect OrientedBoundingBox::GetCenter()
{
	return center;
}
float OrientedBoundingBox::GetSquaredScaleFactor()
{
	return SquaredScaleFactor;
}
bool OrientedBoundingBox::Intersect(OrientedBoundingBox* OBB2)
{
	return mathTools.IntersectOBBs(*(this), *(OBB2));
}
bool OrientedBoundingBox::Intersect(BoundingSphere* bSphere)
{
	return mathTools.IntesectOBBwithSphere(*this, *bSphere);
}
bool OrientedBoundingBox::Intersect(AxisAlignedBoundingBox* AABB)
{
	return mathTools.IntersectOBBwithABB(*this, *AABB);
}
bool OrientedBoundingBox::Intersect(CollisionVolume* other)
{
	return other->Intersect(this);
}
bool OrientedBoundingBox::Intersect(TerrainCell* other)
{
	return mathTools.IntersectCellwithOBB(*other, *this);
}
void OrientedBoundingBox::RenderThis(const Vect& color)
{

	/*unit box has sides of length 1, centered on origin!*/

	Matrix Scale;
	Matrix Trans;


	//Vect min = const_cast<OrientedBoundingBox&>(bBox).GetMin();
	//Vect max = const_cast<OrientedBoundingBox&>(bBox).GetMax();

	Matrix worldSpace =world;


	//move the wireframe sphere to have proper center and size- to put it in the right place
	Scale.set(SCALE, max - min);


	Vect translate = max + min;
	Trans.set(TRANS, translate.X() / 2.0f, translate.Y() / 2.0f, translate.Z() / 2.0f);
	world = Scale * Trans;
	world = world * worldSpace;

	 visualizeHelper->RenderOBB(world,color);

}
