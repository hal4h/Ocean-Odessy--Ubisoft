#include "stdafx.h"
#include "app\app.h"

// Map.cpp
#include "Map.h"
#include <fstream>
#include <sstream>
#include <iostream> // Include this for error handling

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

Map::Map(int windowWidth, int windowHeight)
{

	mapYPosition = 0.0f; // Initial Y position of the map

	// Initialize the water sprite with an 8x2 animated sprite representing waves
	waterSprite = new CSimpleSprite(".\\Assests\\Ocean_SpriteSheet.png", 8, 2); // Adjust columns and rows
	float animationSpeed = 1.0f / 6.0f; // Adjust as needed
	waterSprite->CreateAnimation(ANIMATION_ID_WATER, animationSpeed, { 0, 1, 2 });

	// Initialize the sand layer sprite
	sandlayer = new CSimpleSprite(".\\Assests\\new-sand.png", 1, 1); // Adjust columns and rows
	sandlayer->SetPosition(APP_VIRTUAL_WIDTH / 2.0f, max - APP_VIRTUAL_HEIGHT - (sandlayer->GetHeight() / 2.0f) + mapYPosition);

	// Initialize the water animation sprite
	wateranim = new CSimpleSprite(".\\Assests\\waveanim.png", 17, 1); // Adjust columns and rows
	wateranim->CreateAnimation(ANIMATION_ID_WATER, animationSpeed, { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16 });
	wateranim->SetPosition(APP_VIRTUAL_WIDTH / 2.0f, max - APP_VIRTUAL_HEIGHT - sandlayer->GetHeight() + mapYPosition);

	// Set the number of rows and columns for the map
	rows = 322;
	cols = 24;

	// Create animations for the water sprite
	float waterSpeed = 1.0f / 6.0f; // Adjust as needed
	scrollSpeed = 1.0f / 9.0f; // Adjust as needed

	// Initialize obstacle
	obstacle; // Note: This line appears incomplete or may need correction

	// Initialize the chest sprite
	chest = new CSimpleSprite(".\\Assests\\chest.png", 1, 1);
	chest->SetScale(1.9f);

	// Calculate the maximum Y position based on the rows and water sprite height
	max = rows * waterSprite->GetHeight();

	// Set the scrolling state to true
	scrolling = true;
}

Map::~Map()
{
	delete waterSprite;
}

void Map::Update(float deltaTime, int speed, bool paused)
{
	// Update  animation 
	waterSprite->Update(deltaTime);
	wateranim->Update(deltaTime);
	obstacle.Update(deltaTime);

	ScrollDown(deltaTime);
	speeed = speed;
	this->paused = paused;
}

void Map::Draw()
{
	// Draw the tilemap
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{

			// Calculate the position for each tile based on its row and column
			float xPos = col * waterSprite->GetWidth();
			float yPos = row * waterSprite->GetHeight() + mapYPosition;
			waterSprite->SetPosition(xPos + waterSprite->GetWidth() / 2.0f, yPos + waterSprite->GetHeight() / 2.0f);

			// Set the animation frame for the water sprite
			waterSprite->SetAnimation(ANIMATION_ID_WATER);

			// Draw the water sprite at the calculated position
			waterSprite->Draw();
		}
	}
	if (!scrolling) {
		speeed = 0;
	}
	obstacle.DrawObstacles(speeed, scrolling, paused);
	drawSand();
	drawMeter();
	drawChest();
}

// draw chest 
void Map::drawChest()
{
	chest->SetPosition(APP_VIRTUAL_WIDTH / 2.0f, 10328 - (sandlayer->GetHeight() / 2.0f) + mapYPosition);
	chest->Draw();
}

void Map::drawSand() {
	float start = wateranim->GetWidth() / 2.0f;
	float waterAnimWidth = wateranim->GetWidth();

	for (int i = 0; i < cols; i++)
	{
		float xPos = start + i * waterAnimWidth;
		wateranim->SetAnimation(ANIMATION_ID_WATER);
		wateranim->SetPosition(xPos, 10328 - (sandlayer->GetHeight()) + mapYPosition - wateranim->GetHeight() / 2.0f);
		wateranim->Draw();
	}
	sandlayer->SetPosition(APP_VIRTUAL_WIDTH / 2.0f, 10328 - (sandlayer->GetHeight() / 2.0f) + mapYPosition);
	sandlayer->Draw();
}


void Map::ScrollDown(float deltatime)
{
	// ensure it doesnt go past top of screen
	if (mapYPosition <= -max + APP_VIRTUAL_HEIGHT) {
		scrolling = false;
		return;
	}

	mapYPosition -= scrollSpeed * deltatime;

}
bool Map::isScrolling() const {
	return scrolling;
}


// method to return mapY location
float Map::GetYPos()
{
	return mapYPosition;
}

// returns vectors of all visibile objects from calling objects method
std::vector<CSimpleSprite*> Map::getVisibleObstacles()
{
	return obstacle.visibleSprites;
}



CSimpleSprite* Map::getChest()
{
	return chest;
}

// display meters left until chest is reached
void Map::drawMeter()
{
	float meters = 10319 - (sandlayer->GetHeight()) + mapYPosition;
	char* msg = "Meters left until chest is reached:";
	App::Print(10, 70, msg);
	App::Print(10, 50, std::to_string(meters).c_str());
}

