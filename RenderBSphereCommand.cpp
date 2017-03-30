
#include "RenderBSphereCommand.h"
#include "Visualizer.h"
#include "BoundingSphere.h"

RenderBSphereCommand::RenderBSphereCommand(Matrix& _world, const Vect& color)
: world(_world), targetColor(color)
{
}
void RenderBSphereCommand::execute()
{
	Visualizer::getInstance().privRenderBSphere(world, targetColor);
}