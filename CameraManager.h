//CameraManager.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _CameraManager
#define _CameraManager

#include "Camera.h"

class CameraManager
{
private:
	//singleton stuff


	//static CameraManager* instance;

	//static CameraManager& getInstance()
	//{
	//	//if instance is null
	//	//make new instance with constructor
	//	if (instance == nullptr)
	//	{
	//		instance = new CameraManager();
	//	}

	//	return *instance;
	//}



	friend class Viridian;

	 Camera* currCamera;
	 Camera* defaultCamera;
	 Camera* cam2D;


public:

	CameraManager();
	~CameraManager();
	CameraManager(const CameraManager&) = delete;
	CameraManager operator=(const CameraManager&) = delete;

	 Camera* Setup2DCamera();
	 void SetOrientAndPosition(const Vect& up, const Vect& lookAt, const Vect& pos);
	 void SetCurrentCamera(Camera* newCamera);
	 Camera* GetCurrentCamera();
	 Camera* Get2DCamera();
	 void DeleteCamera();
	 void UpdateCurrCamera();

};
#endif _CameraManager