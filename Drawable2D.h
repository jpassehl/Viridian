//Drawable2D.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _Drawable2D
#define _Drawable2D
#include "AzulCore.h"
class Drawable2D
{
public:

	Drawable2D(){};
	virtual ~Drawable2D()
	{
		DebugMsg::out("\nDrawable2D deconstructor called");
	};
	Drawable2D(const Drawable2D&) = delete;
	Drawable2D& operator=(const Drawable2D&) = delete;
	
	virtual void Draw2D(){}

	void Draw2DRegistration();
	void Draw2DDergistration();

};

#endif _Drawable2D