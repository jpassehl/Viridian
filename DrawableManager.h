//DrawableManager.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _DrawableManager
#define _DrawableManager

#include <string>
#include <list>

#include "Drawable.h"
#include "AzulCore.h"

class DrawableManager
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
	typedef std::list <Drawable*> DrawableList;
	DrawableList drawableList;

	friend class Scene;
	void ProcessElements(); /*
							//why private friendly?- anything not directly requested by user should be hidden
							*/
public:

	DrawableManager(){};
	virtual ~DrawableManager()
	{
		DebugMsg::out("\nDrawable Manager deconstructor called");
	};
	DrawableManager(const DrawableManager&) = delete;
	DrawableManager& operator=(const DrawableManager&) = delete;

	void Register(Drawable* up);
	void Deregister(Drawable* up);

};

#endif _DrawableManager