
#include "RenderLineCommand.h"
#include "Visualizer.h"


RenderLineCommand::RenderLineCommand(const Vect& _p1, const Vect& _p2, const Vect& col)
: p1(_p1), p2(_p2),targetColor(col)
{
}
void RenderLineCommand::execute()
{
	Visualizer::getInstance().privRenderLine(p1,p2,targetColor);
}