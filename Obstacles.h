// Map.h
#pragma once

#ifndef _OBSTACLES_H_
#define _OBSTACLES_H_

#include <cstdlib> // Include this header for rand() function

#include "app/app.h"
#include "app/AppSettings.h"

enum fileNames
{

}

enum objectType
{

}

class Obstacles
{
public:
    Obstacles();
    ~Obstacles();

    std::vector<CSimpleSprite *> rockSprites;
    std::vector<CSimpleSprite *> tireSprites;
    std::vector<CSimpleSprite *> branchSprites;
    std::vector<CSimpleSprite *> cattailSprites;
    std::vector<CSimpleSprite *> crabSprites;
    std::vector<CSimpleSprite *> frogSprites;
    std::vector<CSimpleSprite *> pinkJellySprites;
    std::vector<CSimpleSprite *> squidSprites;
    std::vector<CSimpleSprite *> turtleSprites;
    std::vector<CSimpleSprite *> watermelonSprites;

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


    void DrawObstacles(); // You can add this method to draw obstacles in other parts of your program

    // struct object{
    //     CSimpleSprite *sprite;
    //     int quantity;
    //     float startingY;
    // };

    //  vector<object> rocks;

private:
    // CSimpleSprite* rocks;
    // CSimpleSprite* tire;
    // CSimpleSprite* branch;
    // CSimpleSprite* cattail;
    // CSimpleSprite* crab;
    // CSimpleSprite* frog;
    // CSimpleSprite* pinkJelly;
    // CSimpleSprite* squid;
    // CSimpleSprite* tire;
    // CSimpleSprite* turtle;
    // CSimpleSprite* watermelon; // when collected delete sprite

    // create a struct for all the objects, initialize

    // object branch;
    // object cattail;
    // object crab;
    // object frog;
    // object pinkJelly;
    // object squid;
    // object turtle;
    // object watermelon;
};

#endif

/*



method that randomoizes x values
enum for file name


*/