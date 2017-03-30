
#include "RenderOBBCommand.h"
#include "Visualizer.h"
#include "OrientedBoundingBox.h"

RenderOBBCommand::RenderOBBCommand(Matrix& _world, const Vect& color)
: world(_world), targetColor(color)
{
}
void RenderOBBCommand::execute()
{
	Visualizer::getInstance().privRenderOBB(world, targetColor);
}