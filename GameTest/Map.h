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

    void Update(float deltaTime, int speed);
    void Draw();

	Obstacles obstacle;
    float GetYPos();
    std::vector<CSimpleSprite*> getVisibleObstacles();

    // get chest
    CSimpleSprite* getChest();
     float max;
     bool isScrolling() const;

     bool scrolling;
     float top = max;
private:
    //  float delta;
    CSimpleSprite* wateranim;
    CSimpleSprite* waterSprite;
    CSimpleSprite* sandlayer;
    CSimpleSprite* chest;
    std::vector<std::vector<TileType>> tilemap;  // 2D vector to store tilemap data

    // float backgroundScale;
  // void ScrollUp(float deltatime);
    void ScrollDown(float deltaTime);

     // Matrix to represent the tilemap

     // Vertical scroll speed (adjust as needed)
    float scrollSpeed;

    // Y position of the map
    float mapYPosition;

    int rows; // Number of rows in the tilemap
    int cols; // Number of columns in the tilemap
    //void LoadTilemapFromFile(const char* filename);

    // init chest
    // draw chest
    void drawSand();
    void drawChest();
    // draw meters
    void drawMeter();

	float speeed; //

};

#endif // MAP_H