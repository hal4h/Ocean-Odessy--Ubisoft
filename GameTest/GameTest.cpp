//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//#include <algorithm>
#include "Diver.h"
#include "Map.h"
#include "Homescreen.h"


HomeScreen* homescreen;
Diver* diver;
Map* gameMap;

int WINDOW_WIDT = APP_INIT_WINDOW_WIDTH;
int WINDOW_HEIGH = APP_INIT_WINDOW_HEIGHT;
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
	gameMap = new Map(WINDOW_WIDT, WINDOW_HEIGH);


	//------------------------------------------------------------------------
	//const char* sound = ".\\TestData\\mletoff.wav";
	//App::PlaySound(sound);
	//App::StopSound(sound);

	//App::PlaySound(sound);
	
	//if (App::IsSoundPlaying(sound)) {
	//	App::Print(10,10, "The sound is playing");
//	}
	//else {
	//	App::Print(300, 10, "No sound is playing");
	//}
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{

	//------------------------------------------------------------------------
	// Example Sprite Code...
	//float depth = diver->GetDepth();
	if (homescreen->IsGameStarted()) {
		diver->Update(deltaTime);
		gameMap->Update(deltaTime, diver->GetDepth());

		// Add other game elements update logic as needed
	}
	else {
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
	//background->Draw();
	//chest->Draw();

		if (homescreen->IsGameStarted()) {
			gameMap->Draw();
			diver->Draw(1);

			// Add other game elements render logic as needed
		}
		else {
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
	//delete cow;
	delete diver;
	delete gameMap;

	//delete chest;
	//delete background;
	//------------------------------------------------------------------------
}