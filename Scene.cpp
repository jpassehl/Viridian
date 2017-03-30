// Scene.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include "Scene.h"

#include "UpdateRegistration.h"
#include "UpdateDeregistration.h"

#include "DrawRegistration.h"
#include "DrawDeregistration.h"

#include "DrawRegistration2D.h"
#include "DrawDeregistration2D.h"

#include "AlarmRegistration.h"
#include "AlarmDeregistration.h"

#include "KeyRegistration.h"
#include "KeyDeregistration.h"


#include "SceneAddGameObjectCommand.h"
#include "SceneRemoveGameObjectCommand.h"

#include "Visualizer.h"

#include "TerrainManager.h"



void Scene::UpdateRegister(Updatable* up)
{
	commandRegistrationBroker.addCommand(new UpdateRegistration(&updatableManager, up));

}
void Scene::UpdateDeregister(Updatable* up)
{
	UpdateDeregistration* tempDeRregcommand = new UpdateDeregistration(&updatableManager,up);
	commandRegistrationBroker.addCommand(tempDeRregcommand);
}
void Scene::DrawRegister(Drawable* draw)
{
	commandRegistrationBroker.addCommand(new DrawRegistration(&drawableManager, draw));
}
void Scene::DrawDeregister(Drawable* draw)
{
	DrawDeregistration* tempDeRregcommand = new DrawDeregistration(&drawableManager,draw);
	commandRegistrationBroker.addCommand(tempDeRregcommand);
}
void Scene::DrawRegister2D(Drawable2D* draw)
{
	commandRegistrationBroker.addCommand(new DrawRegistration2D(&drawableManager2D, draw));
}
void Scene:: DrawDeregister2D(Drawable2D* draw)
{
	DrawDeregistration2D* tempDeRregcommand = new DrawDeregistration2D(&drawableManager2D, draw);
	commandRegistrationBroker.addCommand(tempDeRregcommand);
}
void Scene::AlarmRegister(AlarmMarker* alarm)
{
	commandRegistrationBroker.addCommand(new AlarmRegistration(&alarmManger, alarm));
}
void Scene::AlarmDeregister(AlarmMarker* alarm)
{
	AlarmDeregistration* tempDeRregcommand = new AlarmDeregistration(&alarmManger, alarm);
	commandRegistrationBroker.addCommand(tempDeRregcommand);
}
void Scene::KeyRegister(Inputable* input, AZUL_KEY key, Inputable::INPUT_EVENT_TYPE e)
{
	commandRegistrationBroker.addCommand(new KeyRegistration(&keyboardEventManager, input, key, e));
}
void Scene::KeyDeregister(Inputable* input, AZUL_KEY key, Inputable::INPUT_EVENT_TYPE e)
{
	KeyDeregistration* tempDeRregcommand = new KeyDeregistration(&keyboardEventManager, input, key,e);
	commandRegistrationBroker.addCommand(tempDeRregcommand);
}
Terrain* Scene::SetSceneTerrain(const std::string key)
{
	currTerrain=TerrainManager::GetTerrain(key);
	return currTerrain;
}
Terrain* Scene:: GetTerrain()
{
	return currTerrain;
}
//Sprint 4 Game Object LifeCycle
void Scene::AddToScene(GameObject* gameObj)
/**/
{
	//create the command and add it to command broker
	commandRegistrationBroker.addCommand(new SceneAddGameObjectCommand(gameObj));
}

void Scene::RemovefromScene(GameObject* gameObj)
{
	//create the command and add it to command broker
	SceneRemoveGameObjectCommand* tempDeRregcommand = new SceneRemoveGameObjectCommand(gameObj);
	commandRegistrationBroker.addCommand(tempDeRregcommand);
}

CameraManager* Scene::GetCameraManager()
{
	return &cameraManager;
}
SoundManager* Scene::GetSoundManager()
{
	return &soundManager;
}
void Scene::Update()
{

	//note: broker processes de/registration commands for ALL managers
	commandRegistrationBroker.executeCommand();
	keyboardEventManager.ProcessKeys();
	alarmManger.ProcessAlarms();
	updatableManager.ProcessElements();
	cameraManager.UpdateCurrCamera();
	collisionManager.ProcessCollisionTests();
	soundManager.SoundUpdate();

}

void Scene::Draw()
{	

	drawableManager.ProcessElements();
	Visualizer::ProcessRenders();
	drawableManager2D.ProcessElements();
}
