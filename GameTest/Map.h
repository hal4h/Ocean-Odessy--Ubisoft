// Map.h
#pragma once

#ifndef MAP_H
#define MAP_H

#include "app/app.h"
#include "Obstacles.h"
constexpr  int ANIMATION_ID_WATER = 0;
enum TileType {
    WATER = 0,
    // Add more tile types as needed
};

class Map {
public:
    Map(int windowWidth, int windowHeight);
    ~Map();

    void Update(float deltaTime);
    void Draw();

    void ScrollUp(float deltatime);
    void ScrollDown(float deltaTime);

    Obstacles obstacles = Obstacles();

    float GetYPos();
    std::vector<Obstacle> Map::getVisibleObstacles();

    // get chest
    CSimpleSprite* getChest();

private:
  //  float delta;
    CSimpleSprite* wateranim;
    CSimpleSprite* waterSprite;
    CSimpleSprite* sandlayer;
    CSimpleSprite* chest;
    std::vector<std::vector<TileType>> tilemap;  // 2D vector to store tilemap data

   // float backgroundScale;

    // Matrix to represent the tilemap

    // Vertical scroll speed (adjust as needed)
    float scrollSpeed;

    // Y position of the map
    float mapYPosition;

    int rows; // Number of rows in the tilemap
    int cols; // Number of columns in the tilemap
    void DrawFirstLayer();  // Helper method to draw the first layer of the map
    void LoadTilemapFromFile(const char* filename);    

    // init chest
    // draw chest
    void drawChest();
    // draw meters
    void drawMeter();

};

#endif // MAP_H
