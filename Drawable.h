//Drawable.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _Drawable
#define _Drawable
#include "AzulCore.h"

class Drawable
{
public:

	Drawable(){};
	virtual ~Drawable()
	{
		DebugMsg::out("\nDrawable deconstructor called");
	};
	Drawable(const Drawable&) = delete;
	Drawable& operator=(const Drawable&) = delete;
	/** @defgroup Drawable Drawable
	*  @ingroup GameObject
	*  @brief All GameObjects derive from Drawable which allows it to be drawn once per frame.
	*/
	/** @{ */


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \brief Called once per frame on all GameObjects in the current scene.
	/// \details GameObjects that are registered to the current scene will trigger this method once per frame. Objects
	/// will appear on screen by using the GraphicsObject's Render method.
	/// 
	/// \note This does nothing by default, you will have to fill in here what youd like to be drawn.
	/// 
	/// \par Example:
	/// What you'd want to put inside of Draw():
	/// \code
	/// //pGObj_House is a graphics object pointer defined inside the House GameObject's header file
	/// 	pGObj_House->Render(SceneManager::GetCurrentCamera());
	/// \endcode
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Draw(){}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \brief  Registers the GameObject to be drawn
	/// \details You will need to put this in your SceneEntry() method so that your game object will be able to be drawn.
	/// 
	/// 
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void DrawRegistration();
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \brief  Deregisters the GameObject to be drawn
	/// \details You will need to put this in your SceneEntry() method so that your game object will be able to be drawn.
	/// 
	/// 
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void DrawDergistration();
	/** @} */
};

#endif _Drawable