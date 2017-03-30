#ifndef _Listener
#define _Listener

#include "fmod.hpp"
#include "SoundManager.h"
#include "SceneManager.h"

class Listener
{
private:
	static Listener* instance;

	Listener(){};
	virtual ~Listener(){};

	static Listener& getInstance()
	{
		//if instance is null
		//make new instance with constructor
		if (instance == nullptr)
		{
			instance = new Listener();
		}

		return *instance;
	}

private:
	// its null if you dont do this
	//later I will need to set this in a method to the scene's curr sound test
	


	SoundManager *pSoundManager; 
	typedef FMOD::Sound* pFMOD_Sound;
	pFMOD_Sound sound;
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @defgroup Listener Listener
	///  @ingroup SoundSystem
	///	  @brief The Sound Loader, used for 3D sound to indicate where to listen to the sound from
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/** @{ */

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Positions the listener by taking in vectors to indicate position, forward and upward. </summary>
	///
	/// <param name="pos">	  	The position. </param>
	/// <param name="forward">	The forward. </param>
	/// <param name="upward"> 	[ The upward. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void PrivSetListener(Vect& pos, Vect& forward, Vect& upward);

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a listener- calls private method. </summary>
	///
	/// <param name="pos">	  	The position. </param>
	/// <param name="forward">	 The forward. </param>
	/// <param name="upward"> 	[The upward. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void setListener(Vect& pos, Vect& forward, Vect& upward);
	/** @} */
};


#endif _Sound