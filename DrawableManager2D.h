//DrawableManager2D.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _DrawableManager2D
#define _DrawableManager2D

#include <string>
#include <list>

#include "Drawable2D.h"
#include "AzulCore.h"

class DrawableManager2D
{
private:

	/*
	//------------------------------------------------------------
	// NOTES:
	//needs storage for who is being registered. Is a list enough?
	// - it IS enough! However;
	// - maps would provide uniqueness
	// - maps would have update order
	//
	// -list is okay for now- just barebones for basic purposes
	//-------------------------------------------------------------
	*/
	typedef std::list <Drawable2D*> Drawable2DList;
	Drawable2DList drawable2DList;

	friend class Scene;
	void ProcessElements(); /*
							//why private friendly?- anything not directly requested by user should be hidden
							*/
public:

	DrawableManager2D(){};
	virtual ~DrawableManager2D()
	{
		DebugMsg::out("\nDrawableManager 2D  deconstructor called");
	};
	DrawableManager2D(const DrawableManager2D&) = delete;
	DrawableManager2D& operator=(const DrawableManager2D&) = delete;

	void Register(Drawable2D* draw);
	void Deregister(Drawable2D* draw);

};

#endif _DrawableManager