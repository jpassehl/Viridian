#ifndef GAME_H
#define GAME_H

#include "AzulCore.h"

class Game: public Engine
{
public:
	//Game(){};//- moved to private for singleton, constructor cant be public

	// Methods Users need to overload in their game
    virtual void Initialize();
    virtual void LoadContent();
	virtual void Update();
    virtual void Draw();
    virtual void UnLoadContent();

	//To be defined by user since each game has different needs
	void GameInitalize();
	void LoadResources();

private:	

	//------Singleton Format------//

	static Game* instance; //instance pointer

	//Default Constructors
	Game(){};
	~Game(){};
	Game(const Game&) = delete; //deletes are here because
	Game& operator=(const Game&) = delete;

	//
	static Game& getInstance()	// Access reference (all public methods will be static)
	{
		if (!instance)
		{
			instance = new Game;
			
		}
		return *instance;
	};



public:
	static void Run();
	static float GetTime();
	static int GetWidth();
	static int GetHeight();
	static void SetWindowName(const char* name);
	static void SetWidthHeight(int width, int height);
	static void SetClear(float r, float g, float b, float a);

};

#endif