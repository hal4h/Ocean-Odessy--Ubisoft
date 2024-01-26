#pragma once

#ifndef _OBSTACLES_H_
#define _OBSTACLES_H_

#include <cstdlib>
#include <vector>

#include "app/app.h"
#include "app/AppSettings.h"

class Obstacles {
public:
	Obstacles();
	~Obstacles();

	void initializeSprites();
	//void initializeCoordinates(float userDepth);

	//std::vector<CSimpleSprite*> getVisibleObjects();

	std::vector<CSimpleSprite*> visibleSprites;


	const int ROCK_COUNT = 20;
	const int TIRE_COUNT = 20;
	const int FISH_COUNT = 25;
	const int BOTTLE_COUNT = 25;
	const int CATTAIL_COUNT = 20;
	const int FROG_COUNT = 30;
	const int FLOATIE_COUNT = 20;

	const int CRAB_COUNT = 1;
	const int DUCK_COUNT = 30;
	const int SHARK = 10;

	const int TURTLE_COUNT = 1;
	const int WATERMELON_COUNT = 1;

	void DrawObstacles(float speed, bool scrolling);
	void Update(float deltaTime);

	const int MAX = 10304- 2000;
	const int MAX_SPRITE = 7;
	void moveObstacle(CSimpleSprite* sprite, float speed, std::vector<float> yValuesects);

private:
	std::vector<float> generateY(int count, float yStart, float yEnd);


	std::vector<float> rockY;
	std::vector<float> tireY;
	std::vector<float> fishY;
	std::vector<float> bottleY;
	std::vector<float> cattailY;
	//std::vector<float> crabY;
	std::vector<float> frogY;
	std::vector<float> floatieY;

	std::vector<float> duckY;
	//std::vector<float> turtleY;
	//std::vector<float> watermelonY;
	std::vector<float> sharkY;

	std::vector<CSimpleSprite*> rockSprites;
	std::vector<CSimpleSprite*> tireSprites;
	std::vector<CSimpleSprite*> bottleSprites;
	std::vector<CSimpleSprite*> cattailSprites;
	std::vector<CSimpleSprite*> frogSprites;
	std::vector<CSimpleSprite*> floatieSprites;
	std::vector<CSimpleSprite*> duckSprites;
	std::vector<CSimpleSprite*> turtleSprites;
	std::vector<CSimpleSprite*> watermelonSprites;
	std::vector<CSimpleSprite*> sharkSprites;
	std::vector<CSimpleSprite*> fishSprites;

	CSimpleSprite* crabSprites;

	float generateRandomX(CSimpleSprite* sprite);

	CSimpleSprite* initRock();
	CSimpleSprite* initTire();
	CSimpleSprite* initFish();
	CSimpleSprite* initFrog();
	CSimpleSprite* initShark();
	CSimpleSprite* initDuck();
	CSimpleSprite* initFloatie();
	//CSimpleSprite* initTurtle();
	//CSimpleSprite* initWatermelon();
	CSimpleSprite* initCattail();
	CSimpleSprite* initCrab();
	CSimpleSprite* initBottle();


	void initObstacle(CSimpleSprite* sprite, std::vector<float>& yValues);

	void moveCrab(CSimpleSprite* sprite, float speed, float xSpeed);
	void dynamicShark(CSimpleSprite* sprite, float speed, std::vector<float> yValues, float xSpeed);
	void dynamicDuck(CSimpleSprite* sprite, float speed, std::vector<float> yValues, float xSpeed);


};

#endif