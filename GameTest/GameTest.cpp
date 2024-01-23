//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h>
#include <math.h>
//------------------------------------------------------------------------
#include "app\app.h"
#include "app\AppSettings.h"

// #include <algorithm>
#include "Diver.h"
#include "Map.h"
#include "Homescreen.h"
#include "Obstacles.h"

HomeScreen* homescreen;
Diver* diver;
Map* gameMap;

// int WINDOW_WIDT = APP_INIT_WINDOW_WIDTH;
// int WINDOW_HEIGH = APP_INIT_WINDOW_HEIGHT;
float depth;

enum
{
	ANIM_FORWARDS,
	ANIM_BACKWARDS,
	ANIM_LEFT,
	ANIM_RIGHT,
};
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	homescreen = new HomeScreen();
	diver = new Diver();
	gameMap = new Map(APP_VIRTUAL_WIDTH, APP_VIRTUAL_HEIGHT);
	//------------------------------------------------------------------------
	
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{

	//------------------------------------------------------------------------
	// Example Sprite Code...
	// float depth = diver->GetDepth();
	if (homescreen->IsGameStarted())
	{
		gameMap->Update(deltaTime);
		// get current obstacles
		std::vector<CSimpleSprite*> obstacles = gameMap->getVisibleObstacles();
		// get chest 
		CSimpleSprite* chest = gameMap->getChest();
		diver->Update(deltaTime, obstacles, chest); // insert vector of obstacles here
		
		

	}
	else
	{
		homescreen->Update(deltaTime);
	}
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.)
// See App.h
//------------------------------------------------------------------------
void Render()
{
	//------------------------------------------------------------------------
	// Example Sprite Code....

	if (homescreen->IsGameStarted())
	{
		if (!diver->IsDead()) {

			gameMap->Draw();
			diver->Draw();

		}
		else {
			App::Print(400, 400, "Player is dead, game over");

		}
			 
	// Add other game elements render logic as needed
	}
	else
	{
		homescreen->Render();
	}
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{
	//------------------------------------------------------------------------
	// Example Sprite Code....
	delete diver;
	delete gameMap;
	delete homescreen;
	// delete chest;
	// delete background;
	//------------------------------------------------------------------------
}
