#include "AzulCore.h"
#include "Game.h"

#include "ShaderManager.h"
#include "TextureManager.h"
#include "ModelManager.h"
#include "CameraManager.h"
#include "SceneManager.h"

#include "../../src/User Code/SceneObject.h"

//#include "../../src/User Code/SpaceShipWireFrame.h"
//#include "../../src/User Code/SpaceShipTexture.h"
//#include "../../src/User Code/Cottage.h"
//#include "../../src/User Code/BoundingSphere.h"
//#include "../../src/User Code/WireframeBox.h"


Game* Game::instance = nullptr;

	
SceneObject* currScene;


//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void Game::Initialize()
{
	DebugMsg::out("Game() started\n");
	this->GameInitalize(); //also sets start scene
}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Game::LoadContent()
{	
	this->LoadResources();

	SceneManager::InitStartScene();

	//currScene = new SceneObject();
	//currScene->Initalize();
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void Game::Update()
{
	SceneManager:: Update();
	//currScene->Update();
}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Draw()
{
	SceneManager::Draw();
	//currScene->Draw();

}



//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Game::UnLoadContent()
{

	SceneManager::Delete();

	// Problem: how to delete the shaders? Models? Textures?
	ShaderManager::DeleteShaders();
	TextureManager::DeleteTextures();
	ModelManager::DeleteModels();

	CameraManager::DeleteCamera();

	DebugMsg::out("Game() ended\n");

}

	//---------------------------------------------------------------------------------------------------------
	// Accessors
	//---------------------------------------------------------------------------------------------------------
	
void Game::Run()
{
	getInstance().run();
}
float Game::GetTime()
{
	return getInstance().GetTimeInSeconds();
}
int Game::GetWidth()
{
	return getInstance().getWidth();
}
int Game::GetHeight()
{
	return getInstance().getHeight();
}
void Game::SetWindowName(const char* name)
{
	getInstance().setWindowName(name);
}
void Game::SetWidthHeight(int width, int height)
{
	getInstance().setWidthHeight(width,height);
}
void Game::SetClear(float r, float g, float b, float a)
{
	getInstance().SetClearColor(r,g,b,a);
}
