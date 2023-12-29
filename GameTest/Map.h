// Map.h
#pragma once

#ifndef MAP_H
#define MAP_H

#include "app/app.h"
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


private:
    CSimpleSprite* waterSprite;
   // float backgroundScale;

    // Matrix to represent the tilemap
    std::vector<std::vector<TileType>> tilemap;

    // Vertical scroll speed (adjust as needed)
    float scrollSpeed;

    // Y position of the map
    float mapYPosition;
};

#endif // MAP_H
