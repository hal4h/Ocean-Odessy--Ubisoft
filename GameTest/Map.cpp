#include "stdafx.h"
#include "app\app.h"


// Map.cpp
#include "Map.h"
#include <algorithm>


const std::vector<std::vector<int>> initialTileset = {
    {0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};


Map::Map(int windowWidth, int windowHeight) {
    // Initialize the water sprite with an 8x2 animated sprite representing waves
    waterSprite = new CSimpleSprite(".\\TestData\\Ocean_SpriteSheet.png", 8, 2); // Adjust columns and rows

    // Calculate scale to cover the entire screen
   // float scale = windowHeight / waterSprite->GetHeight();
    //waterSprite->SetScale(scale);



    // Initialize the tilemap
    // initialize it as a 2D matrix with all tiles set to WATER

    //TODO: change values to work with screen dimentions
    int numRows = 90; // Adjust as needed
    int numColumns = 40; // Adjust as needed
    tilemap.resize(numRows, std::vector<TileType>(numColumns, WATER));




    // Create animations for the water sprite
    float animationSpeed = 1.0f/7.0f; // Adjust as needed
    waterSprite->CreateAnimation(ANIMATION_ID_WATER, animationSpeed, { 0, 1, 2, 3, 4, 5, 6, 7 });

    // Set other properties or load additional tilesets as needed
}



Map::~Map() {
    delete waterSprite;
}

void Map::Update(float deltaTime) {
    // Update any animation or logic based on deltaTime
    waterSprite->Update(deltaTime);

    // Additional update logic as needed
}

void Map::Draw() {
    // Draw the tilemap
    for (int i = 0; i < tilemap.size(); ++i) {
        for (int j = 0; j < tilemap[i].size(); ++j) {
            // Determine the position for each tile based on its row and column
            float tileX = j * waterSprite->GetWidth();
            float tileY = i * waterSprite->GetHeight();

            // Set the animation frame for the water sprite
            waterSprite->SetAnimation(ANIMATION_ID_WATER);

            // Draw the water sprite at the calculated position
            waterSprite->SetPosition(tileX, tileY);
            waterSprite->Draw();
        }
    }

}