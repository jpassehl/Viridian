
#include "RenderABBCommand.h"
#include "Visualizer.h"


RenderABBCommand::RenderABBCommand(Matrix& _world, const Vect& color)
: world(_world), targetColor(color)
{
}
void RenderABBCommand::execute()
{
	Visualizer::getInstance().privRenderABB(world, targetColor);
}