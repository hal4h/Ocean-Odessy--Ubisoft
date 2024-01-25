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

    mapYPosition = 2.0f; // Initial Y position of the map

    // Initialize the water sprite with an 8x2 animated sprite representing waves
    waterSprite = new CSimpleSprite(".\\TestData\\Ocean_SpriteSheet.png", 8, 2); // Adjust columns and rows

    sandlayer = new CSimpleSprite(".\\TestData\\newsand.png", 1, 1); // Adjust columns and rows
    sandlayer->SetPosition(sandlayer->GetWidth() / 2.0f, sandlayer->GetHeight() / 2.0f + mapYPosition);

    wateranim = new CSimpleSprite(".\\TestData\\waveanim.png", 17, 1); // Adjust columns and rows

    rows = 322;
    cols = 24;

    // Create animations for the water spr
    float animationSpeed = 1.0f / 6.0f; // Adjust as needed
    waterSprite->CreateAnimation(ANIMATION_ID_WATER, animationSpeed, { 0, 1, 2 });

    float waterSpeed = 1.0f / 6.0f; // Adjust as needed
    wateranim->CreateAnimation(ANIMATION_ID_WATER, animationSpeed, { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16 });
    scrollSpeed = 1.0f / 9.0f; // Adjust as needed

    // obstacles.initializeSprites();

    obstacle;
    // init chest
    chest = new CSimpleSprite(".\\TestData\\chest.png", 1, 1);

    max = rows * waterSprite->GetHeight();

}

Map::~Map()
{
    delete waterSprite;
}

void Map::Update(float deltaTime, int speed)
{
    // delta = deltaTime;
    // Update any animation or logic based on deltaTime
    waterSprite->Update(deltaTime);
    wateranim->Update(deltaTime);
    // waterSprite->SetColor(0.9 - depth /5, 0.9 -depth/5, 0.9 - depth / 5); // Light blue color
    obstacle.Update(deltaTime);

    ScrollDown(deltaTime);
    speeed = speed;
}

void Map::Draw()
{
    // Draw the tilemap

    float scaleX = static_cast<float>(APP_VIRTUAL_WIDTH) / (cols * waterSprite->GetWidth());

    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {

            // Calculate the position for each tile based on its row and column
            float xPos = col * waterSprite->GetWidth();
            float yPos = row * waterSprite->GetHeight() + mapYPosition;

            // Set the animation frame for the water sprite
            waterSprite->SetAnimation(ANIMATION_ID_WATER);

            // Draw the water sprite at the calculated position
            waterSprite->SetPosition(xPos + waterSprite->GetWidth() / 2.0f, yPos + waterSprite->GetHeight() / 2.0f);
            waterSprite->Draw();
        }
    }
    sandlayer->SetPosition(sandlayer->GetWidth() / 2.0f, rows * sandlayer->GetHeight() / 2.0f + mapYPosition);
    sandlayer->Draw();

    float start = wateranim->GetWidth() / 2.0f;
    float waterAnimWidth = wateranim->GetWidth();

    for (int i = 0; i < cols; i++)
    {
        float xPos = start + i * waterAnimWidth;
        wateranim->SetAnimation(ANIMATION_ID_WATER);
        wateranim->SetPosition(xPos,rows* sandlayer->GetHeight() + wateranim->GetHeight() / 2.0f + mapYPosition);
        wateranim->Draw();
    }
    obstacle.DrawObstacles(speeed);
 
    // Draw the chest
   
    drawMeter();

    drawChest();
}

void Map::ScrollUp(float deltatime)
{
    mapYPosition += scrollSpeed * deltatime;

    mapYPosition = min(mapYPosition, 0.0f);
}

void Map::ScrollDown(float deltatime)
{
    mapYPosition -= scrollSpeed * deltatime;

    // ensure it doesnt go past top of screen
    mapYPosition = max(mapYPosition, -static_cast<float>(rows * waterSprite->GetHeight()));
}

void Map::LoadTilemapFromFile(const char* filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        // Handle error: unable to open file
        return;
    }

    tilemap.clear(); // Clear existing tilemap data

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::vector<TileType> row;

        int tileType;
        while (iss >> tileType)
        {
            row.push_back(static_cast<TileType>(tileType));
        }

        tilemap.push_back(row);
    }

    file.close();
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

// draw chest 
void Map::drawChest()
{
    chest->SetPosition(APP_VIRTUAL_WIDTH / 2.0f, rows * waterSprite->GetHeight() / 2.0f + mapYPosition);
    chest->Draw();
}

CSimpleSprite *Map::getChest()
{
    return chest;
}

// display meters left until chest is reached
void Map::drawMeter()
{
    float meters = max + mapYPosition;

    // print meters left
    App::Print(10, 30, std::to_string(meters).c_str());
}