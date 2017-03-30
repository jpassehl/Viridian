
#ifndef _RenderCommand
#define _RenderCommand

#include "CommandBase.h"

class RenderCommand : public CommandBase
{
public:
	RenderCommand() {};
	virtual ~RenderCommand() {};
	RenderCommand(const RenderCommand&) = delete;
	RenderCommand& operator=(const RenderCommand&) = delete;

	virtual void execute() = 0;

private:

};

#endif _RenderCommand