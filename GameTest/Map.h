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

	void Update(float deltaTime, int speed, bool paused);
	void Draw();

	Obstacles obstacle;
	float GetYPos();
	std::vector<CSimpleSprite*> getVisibleObstacles();

	// get chest
	CSimpleSprite* getChest();
	float max;
	bool isScrolling() const;

	bool scrolling;
private:
	bool paused;
	//  float delta;
	CSimpleSprite* wateranim;
	CSimpleSprite* waterSprite;
	CSimpleSprite* sandlayer;
	CSimpleSprite* chest;
	std::vector<std::vector<TileType>> tilemap;  // 2D vector to store tilemap data


	// Vertical scroll speed (adjust as needed)
	float scrollSpeed;

	// Y position of the map
	float mapYPosition;

	int rows; // Number of rows in the tilemap
	int cols; // Number of columns in the tilemap
	//void LoadTilemapFromFile(const char* filename);

	void ScrollDown(float deltaTime);
	void drawSand();
	void drawChest();
	void drawMeter();

	float speeed; 

};

#endif // MAP_H