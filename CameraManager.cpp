//CameraManager.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include <string>
#include <map>
#include "Camera.h"
#include "CameraManager.h"
#include "AzulCore.h"
#include "Viridian.h"

//CameraManager* CameraManager::instance = nullptr;

CameraManager::CameraManager()
{
	Camera* newCamera;

	//1.)Create a default camera
	newCamera = new Camera(Camera::Type::PERSPECTIVE_3D);
	newCamera->setViewport(0, 0, Viridian::GetWidth(), Viridian::GetHeight());
	newCamera->setPerspective(35.0f, float(Viridian::GetWidth()) / float(Viridian::GetHeight()), 1.0f, 5000.0f);

	// Orient Camera
	Vect up3DCam(0.0f, 1.0f, 0.0f);
	Vect pos3DCam(50.0f, 50.0f, 150.0f);
	Vect lookAt3DCam(0.0f, 0.0f, 0.0f);
	newCamera->setOrientAndPosition(up3DCam, lookAt3DCam, pos3DCam);
	newCamera->updateCamera();

	
	defaultCamera = newCamera;
	currCamera = defaultCamera;
	DebugMsg::out("Default Camera Created\n");
}
void CameraManager::SetCurrentCamera(Camera* newCamera)
{
	currCamera = newCamera;
}
Camera* CameraManager::GetCurrentCamera()
{
	//SetCurrentCamera(defaultCamera);
	return currCamera;
}
Camera* CameraManager:: Setup2DCamera()
{
	Camera* pCam2D;

	pCam2D = new Camera(Camera::Type::ORTHOGRAPHIC_2D);
	//assert(pCam2D);

	pCam2D->setViewport(0, 0, Viridian::GetWidth(), Viridian::GetHeight());
	pCam2D->setOrthographic(-0.5f*Viridian::GetWidth(), 0.5f*Viridian::GetWidth(), -0.5f*Viridian::GetHeight(), 0.5f*Viridian::GetHeight(), 1.0f, 1000.0f);

	// Orient Camera
	Vect up2DCam(0.0f, 1.0f, 0.0f);
	Vect pos2DCam(0.0f, 0.0f, 0.0f);
	Vect lookAt2DCam(0.0f, 0.0f, -1.0f);
	pCam2D->setOrientAndPosition(up2DCam, lookAt2DCam, pos2DCam);
	pCam2D->updateCamera();
	
	cam2D = pCam2D;
	return cam2D;
}
Camera* CameraManager::Get2DCamera()
{
	return cam2D;
}
void CameraManager::DeleteCamera()
{
	//Problem- cant do delete currCamera if this method isn't static...
	//BUT you need for it to be staticto call it in Viridain.cpp
	DebugMsg::out("Camera Manager Delete Called");

	//just deletes pointer instance
	delete currCamera;
}

CameraManager::~CameraManager()
{	
	delete currCamera;
	delete defaultCamera;
}
void CameraManager::UpdateCurrCamera()
{
	currCamera->updateCamera();
}
void CameraManager::SetOrientAndPosition(const Vect& up, const Vect& lookAt, const Vect& pos)
{
	currCamera->setOrientAndPosition(up, lookAt, pos);
}