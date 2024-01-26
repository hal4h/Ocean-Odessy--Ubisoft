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

    state->Update(deltaTime);

    if (state->IsGameStarted() && !state->IsGameOver() && !state->IsGameWon())
    {
        if (state->IsGamePaused())
        {
            paused = true;
            diver->IsPlaying(false);  // Ensure the user can't move the sprite when the game is paused
            deltaTime = 0;
            speed = 0;
        }

        // Get current obstacles and chest
        std::vector<CSimpleSprite*> obstacles = gameMap->getVisibleObstacles();
        CSimpleSprite* chest = gameMap->getChest();

        // Update game map and diver
        gameMap->Update(deltaTime, speed, paused);
        diver->Update(deltaTime, obstacles, paused ? 0 : speed / 2.0f, chest);

        if (state->IsGameWon())
        {
            state->SetGameWon(true);
        }

        if (state->IsGamePaused())
        {
            diver->IsPlaying(true);  // Set back to true after updating
        }
    }
    else if (state->IsGameReset())
    {
        // Reset state
        // destroy
        // safeDelete();
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

