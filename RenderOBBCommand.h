
#ifndef _RenderOBBCommand
#define _RenderOBBCommand

#include "RenderCommand.h"
#include "OrientedBoundingBox.h"


class RenderOBBCommand : public RenderCommand, public Align16
{
public:
	RenderOBBCommand() = delete;
	virtual ~RenderOBBCommand(){};
	RenderOBBCommand(const RenderOBBCommand&) = delete;
	RenderOBBCommand& operator=(const RenderOBBCommand&) = delete;

	RenderOBBCommand(Matrix& _world, const Vect& color);
	virtual void execute();

private:
	Matrix& world;
	Vect targetColor;

};

#endif _RenderOBBCommand