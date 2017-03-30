
#include "RenderCollisionVolumeCommand.h"
#include "Visualizer.h"


RenderCollisionVolumeCommand::RenderCollisionVolumeCommand( CollisionVolume* _colVol, const Vect& color)
: colVol(_colVol), targetColor(color)
{
}
void RenderCollisionVolumeCommand::execute()
{
	Visualizer::getInstance().privRenderCollisionVolume(colVol, targetColor);
}