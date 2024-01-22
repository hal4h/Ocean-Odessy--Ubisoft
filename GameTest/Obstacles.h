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
    void initializeCoordinates(float userDepth);

    std::vector<CSimpleSprite*> getVisibleObjects();

    std::vector<CSimpleSprite*> rockSprites;
    std::vector<CSimpleSprite*> tireSprites;
    std::vector<CSimpleSprite*> bottleSprites;
    std::vector<CSimpleSprite*> cattailSprites;
    std::vector<CSimpleSprite*> crabSprites;
    std::vector<CSimpleSprite*> frogSprites;
    std::vector<CSimpleSprite*> pinkJellySprites;
    std::vector<CSimpleSprite*> squidSprites;
    std::vector<CSimpleSprite*> turtleSprites;
    std::vector<CSimpleSprite*> watermelonSprites;
    std::vector<CSimpleSprite*> yellowJellySprites;
    std::vector<CSimpleSprite*> fishSprites;



    const int ROCK_COUNT = 50;
    const int TIRE_COUNT = 40;
    const int FISH_COUNT = 30;
    const int BOTTLE_COUNT = 30;
    const int CATTAIL_COUNT = 20;
    const int CRAB_COUNT = 2;
    const int FROG_COUNT = 1;
    const int PINK_JELLY_COUNT = 1;
    const int SQUID_COUNT = 1;
    const int TURTLE_COUNT = 1;
    const int WATERMELON_COUNT = 1;
    const int YELLOW_JELLY_COUNT = 1;

    void DrawObstacles(float yPos);
    void Update(float deltaTime);

    const int MAX = 10304;
private:

    float generateRandomX(CSimpleSprite* sprite);

    CSimpleSprite* initRock();
    CSimpleSprite* initTire();
    CSimpleSprite* initFish();
    CSimpleSprite* initYellowJelly();
    CSimpleSprite* initFrog();
    CSimpleSprite* initPinkJelly();
    CSimpleSprite* initSquid();
    CSimpleSprite* initTurtle();
    CSimpleSprite* initWatermelon();
    CSimpleSprite* initCattail();
    CSimpleSprite* initCrab();
    CSimpleSprite* initBottle();
};

#endif