
#ifndef _RenderLineCommand
#define _RenderLineCommand

#include "RenderCommand.h"
#include "AxisAlignedBoundingBox.h"


class RenderLineCommand : public RenderCommand, public Align16
{
public:
	RenderLineCommand() = delete;
	virtual ~RenderLineCommand(){};
	RenderLineCommand(const RenderLineCommand&) = delete;
	RenderLineCommand& operator=(const RenderLineCommand&) = delete;

	RenderLineCommand(const Vect& _p1, const Vect& _p2, const Vect& col);
	virtual void execute();

private:
	const Vect p1;
	const Vect p2;
	Vect targetColor;


};

#endif _RenderABBCommand