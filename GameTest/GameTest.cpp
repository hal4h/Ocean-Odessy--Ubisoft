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

//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Eample data....
//------------------------------------------------------------------------
//CSimpleSprite *testSprite;

//CSimpleSprite* cow;
//CSimpleSprite* background;
//CSimpleSprite* chest;

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
	//------------------------------------------------------------------------
	// Example Sprite Code....
	//background = App::CreateSprite(".\\TestData\\output-onlinegiftools.png", 48, 1);

	//float centerX = WINDOW_WIDT / 2.0f;
	//float centerY = WINDOW_HEIGH / 2.0f;
	//depth = centerY; // initialize depth to  
	//background->SetPosition(centerX, centerY);
	// Set scale to cover the entire screen
	//float scaleX = WINDOW_WIDT / background->GetWidth();
	//float scaleY = WINDOW_HEIGH / background->GetHeight();
	//float scale = std::min(WINDOW_WIDTH / background->GetWidth(), WINDOW_HEIGHT / background->GetHeight());

	//background->SetScale(scaleX);

	diver = new Diver();
	//diver->SetSpeed(1.0f/15.0f);

	gameMap = new Map(WINDOW_WIDT, WINDOW_HEIGH);

	//cow = App::CreateSprite(".\\TestData\\cow.png", 3, 2);
	//cow->SetPosition(600.0f, 400.0f);
	//background->SetPosition(500.f, 500.0f);



	//chest = App::CreateSprite(".\\TestData\\output-chest.png", 5, 2);

	//testSprite->SetPosition(centerX, WINDOW_HEIGH + 20.f);
	//chest->SetPosition(500.0f, 100.f);

	//float speed = 1.0f / 15.0f;
	//testSprite->CreateAnimation(ANIM_BACKWARDS, speed, { 0,1,2,3,4});
	//testSprite->CreateAnimation(ANIM_LEFT, speed, { 5,6,7,8 });
	//testSprite->CreateAnimation(ANIM_RIGHT, speed, { 9,10,11,12 });
	//testSprite->CreateAnimation(ANIM_FORWARDS, speed, { 13,14,15,16 });

	//chest->CreateAnimation(0, speed, { 1,2,3,4,5,6,7,8 });

	//background->CreateAnimation(0, speed, { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 });
	//testSprite->SetScale(2.0f);
	//cow->SetScale(2.0f);
	//ckground->SetScale(30.0f);

	//App::PlaySound(".\\TestData\\mletoff.wav");

	//------------------------------------------------------------------------
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	//------------------------------------------------------------------------
	// Example Sprite Code....
	gameMap->Update(deltaTime);
	diver->Update(deltaTime);

	//background->Update(deltaTime);  // Add this line to update the background animation
	//chest->Update(deltaTime);

	//if (App::GetController().GetLeftThumbStickX() > 0.5f)
	//{
	//	testSprite->SetAnimation(ANIM_RIGHT);
	//	float x, y;
	//	testSprite->GetPosition(x, y);
	//	x += 1.0f;
	//	testSprite->SetPosition(x, y);
	//}
	//if (App::GetController().GetLeftThumbStickX() < -0.5f)
	//{
	//	testSprite->SetAnimation(ANIM_LEFT);
	//	float x, y;
	//	testSprite->GetPosition(x, y);
	//	x -= 1.0f;
	//	testSprite->SetPosition(x, y);
	//}
 //   if (App::GetController().GetLeftThumbStickY() > 0.5f)
 //   {
 //       testSprite->SetAnimation(ANIM_FORWARDS);
 //       float x, y;
 //       testSprite->GetPosition(x, y);
 //       y += 1.0f;
 //       testSprite->SetPosition(x, y);
 //   }
	//if (App::GetController().GetLeftThumbStickY() < -0.5f)
	//{
	//	testSprite->SetAnimation(ANIM_BACKWARDS);
	//	float x, y;
	//	testSprite->GetPosition(x, y);
	//	y -= 1.0f;
	//	testSprite->SetPosition(x, y);
	//}


	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, false))
	//{
	//	testSprite->SetScale(testSprite->GetScale() + 0.1f);
	//}
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, false))
	//{
	//	testSprite->SetScale(testSprite->GetScale() - 0.1f);
	//}
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false))
	//{
	//	testSprite->SetAngle(testSprite->GetAngle() + 0.1f);
	//}
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false))
	//{
	//	testSprite->SetAngle(testSprite->GetAngle() - 0.1f);
	//}
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	//{
	//	testSprite->SetAnimation(-1);
	//}
	//------------------------------------------------------------------------
	// Sample Sound.
	//------------------------------------------------------------------------
	//ifApp::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
	//
	//pp::PlaySound(".\\TestData\\mletoff.wav");
	//

	App::PlaySound(".\\TestData\\mletoff.wav");

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

	gameMap->Draw();

	diver->Draw();

	App::Print(10, 10, "Depth: %.2f meters", diver->GetDepth()); // Adjust position and format as needed


	//cow->Draw();
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// Example Text.
	//------------------------------------------------------------------------
	//App::Print(100, 100, "Sample Text");

	//------------------------------------------------------------------------
	// Example Line Drawing.
	//------------------------------------------------------------------------
	static float a = 0.0f;
	float r = 1.0f;
	float g = 1.0f;
	float b = 1.0f;
	a += 0.1f;
	for (int i = 0; i < 20; i++)
	{

		float sx = 200 + sinf(a + i * 0.1f)*60.0f;
		float sy = 200 + cosf(a + i * 0.1f)*60.0f;
		float ex = 700 - sinf(a + i * 0.1f)*60.0f;
		float ey = 700 - cosf(a + i * 0.1f)*60.0f;
		g = (float)i / 20.0f;
		b = (float)i / 20.0f;
		//App::DrawLine(sx, sy, ex, ey,r,g,b);
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