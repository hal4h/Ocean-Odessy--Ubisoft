#pragma once

#ifndef _OBSTACLES_H_
#define _OBSTACLES_H_

#include <cstdlib>
#include <vector>

#include "app/app.h"
#include "app/AppSettings.h"

class Obstacles {
public:
    Obstacles(float sandHeight, float userDepth);
        ~Obstacles();

        void initializeSprites();
        void initializeCoordinates(float sandHeight, float userDepth);

    std::vector<CSimpleSprite*> rockSprites;
    std::vector<CSimpleSprite*> tireSprites;
    std::vector<CSimpleSprite*> branchSprites;
    std::vector<CSimpleSprite*> cattailSprites;
    std::vector<CSimpleSprite*> crabSprites;
    std::vector<CSimpleSprite*> frogSprites;
    std::vector<CSimpleSprite*> pinkJellySprites;
    std::vector<CSimpleSprite*> squidSprites;
    std::vector<CSimpleSprite*> turtleSprites;
    std::vector<CSimpleSprite*> watermelonSprites;

    const int ROCK_COUNT = 50;
    const int TIRE_COUNT = 40;
    const int BRANCH_COUNT = 30;
    const int CATTAIL_COUNT = 20;
    const int CRAB_COUNT = 2;
    const int FROG_COUNT = 1;
    const int PINKJELLY_COUNT = 1;
    const int SQUID_COUNT = 1;
    const int TURTLE_COUNT = 1;
    const int WATERMELON_COUNT = 1;

    void DrawObstacles(float yPosition);
    void Update(float deltaTime);

private:

    int generateRandomX(CSimpleSprite* sprite);

    void initRock(CSimpleSprite* sprite);
    void initTire(CSimpleSprite* sprite);

    void initYellowJelly(CSimpleSprite* sprite);
    void initFrog(CSimpleSprite* sprite);
    void initPinkJelly(CSimpleSprite* sprite);
    void initSquid(CSimpleSprite* sprite);
    void initTurtle(CSimpleSprite* sprite);
    void initWatermelon(CSimpleSprite* sprite);
    void initCattail(CSimpleSprite* sprite);
    void initCrab(CSimpleSprite* sprite);
    void initBranch(CSimpleSprite* sprite);
};

#endif
