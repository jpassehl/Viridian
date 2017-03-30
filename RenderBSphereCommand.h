
#ifndef _RenderBSphereCommand
#define _RenderBSPhereCommand

#include "RenderCommand.h"
#include "BoundingSphere.h"


class RenderBSphereCommand : public RenderCommand, public Align16
{
public:
	RenderBSphereCommand() = delete;
	virtual ~RenderBSphereCommand(){};
	RenderBSphereCommand(const RenderBSphereCommand&) = delete;
	RenderBSphereCommand& operator=(const RenderBSphereCommand&) = delete;

	RenderBSphereCommand(Matrix& _world, const Vect& color);
	virtual void execute();

private:
	Matrix& world;
	Vect targetColor;

};

#endif _RenderBSphereCommand