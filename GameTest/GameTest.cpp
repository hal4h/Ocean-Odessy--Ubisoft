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
#include "GameState.h"
#include "Diver.h"
#include "Map.h"
#include "Obstacles.h"

GameState* state;
Diver* diver;
Map* gameMap;

//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	state = new GameState();
	diver = new Diver() ;
	gameMap = new Map(APP_VIRTUAL_WIDTH, APP_VIRTUAL_HEIGHT);
	//------------------------------------------------------------------------
	
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	int speed = 2;
	bool paused = false;
	//------------------------------------------------------------------------
	state->Update(deltaTime);

	if (state->IsGameStarted() && !state->IsGameOver() && !state->IsGameWon())
	{
		if (state->IsGamePaused()) {
			paused = true;
			diver->IsPlaying(false);  // ensure user cant move sprite when game is paused
			deltaTime = 0;
			speed = 0;
			gameMap->Update(deltaTime, speed, paused);
			// get current obstacles
			std::vector<CSimpleSprite*> obstacles = gameMap->getVisibleObstacles();
			// get chest 
			CSimpleSprite* chest = gameMap->getChest();
			diver->Update(deltaTime, obstacles, speed, chest); // insert vector of obstacles here

			diver->IsPlaying(true);  // set back to true 

			if (diver->IsWon()) {
				state->SetGameWon(true);
			}
		}
		else {
			if (!gameMap->isScrolling()) {
				speed = 0;
			}
			// get current obstacles
			std::vector<CSimpleSprite*> obstacles = gameMap->getVisibleObstacles();
			// get chest 
			CSimpleSprite* chest = gameMap->getChest();
			gameMap->Update(deltaTime, speed, paused);

			diver->Update(deltaTime, obstacles, speed / 2.0f, chest); // insert vector of obstacles here
		}
	}
	else if (state->IsGameReset()) {
		// reset state
		//destroy
		//safeDelete();
		Init();
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
	if (state->IsGameStarted())
	{
		if (diver->IsDead()) {
			state->SetGameOver(true);
		}
		else if (diver->IsWon()) {
			state->SetGameWon(true);
		}
		else {
			gameMap->Draw();
			diver->Draw();
		}
	}
	state->Render();

}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{
	//------------------------------------------------------------------------
	delete diver;
	delete gameMap;
	delete state;
	//------------------------------------------------------------------------
}

