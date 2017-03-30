#ifndef _RenderCollisionVolumeCommand
#define _RenderCollisionVolumeCommand

#include "RenderCommand.h"
#include "CollisionVolume.h"


class RenderCollisionVolumeCommand : public RenderCommand, public Align16
{
public:
	RenderCollisionVolumeCommand() = delete;
	virtual ~RenderCollisionVolumeCommand(){};
	RenderCollisionVolumeCommand(const RenderCollisionVolumeCommand&) = delete;
	RenderCollisionVolumeCommand& operator=(const RenderCollisionVolumeCommand&) = delete;

	RenderCollisionVolumeCommand( CollisionVolume* _colVol, const Vect& color);
	virtual void execute();

private:
	 CollisionVolume* colVol;
	Vect targetColor;

};

#endif _RenderCollisionVolumeCommand