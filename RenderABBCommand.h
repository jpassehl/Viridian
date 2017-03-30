
#ifndef _RenderABBCommand
#define _RenderABBCommand

#include "RenderCommand.h"
#include "AxisAlignedBoundingBox.h"


class RenderABBCommand : public RenderCommand,public Align16
{
public:
	RenderABBCommand() = delete;
	virtual ~RenderABBCommand(){};
	RenderABBCommand(const RenderABBCommand&) = delete;
	RenderABBCommand& operator=(const RenderABBCommand&) = delete;

	RenderABBCommand(Matrix& _world, const Vect& color);
	virtual void execute();

private:
	Matrix& world;
	Vect targetColor;

};

#endif _RenderABBCommand