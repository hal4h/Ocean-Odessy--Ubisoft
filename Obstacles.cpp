#include "stdafx.h"
#include "app\app.h"

#include "Obstacles.h"

// create an array of each obstacle
//  create an array of coordinates for each obstacle

Obstacles::Obstacles()
{
    initializeSprites();
    initializeCoordinates();

}

Obstacles::~Obstacles()
{
    for (CSimpleSprite *rockSprite : rockSprites)
    {
        delete rockSprite;
    }
    for (CSimpleSprite *tireSprite : tireSprites)
    {
        delete tireSprite;
    }
}

void Obstacles::Update(float deltaTime)
{
    // Update the obstacles
    for (CSimpleSprite *rockSprite : rockSprites)
    {
        rockSprite->Update(deltaTime);
    } 
    for (CSimpleSprite *tireSprite : tireSprites)
    {
        tireSprite->Update(deltaTime);
     }
    // for (CSimpleSprite *branchSprite : branchSprites)
    // {
    //     branchSprite->Update(deltaTime);
    // }
    // for (CSimpleSprite *cattailSprite : cattailSprites)
    // {
    //     cattailSprite->Update(deltaTime);
    // }
}

void Obstacles::DrawObstacles()
{
    // Draw the obstacles
    for (CSimpleSprite *rockSprite : rockSprites)
    {
        rockSprite->Draw();
    }
    // for (CSimpleSprite *tireSprite : tireSprites)
    // {
    //     tireSprite->Draw();
    // }
    // for (CSimpleSprite *branchSprite : branchSprites)
    // {
    //     branchSprite->Draw();
    // }
    // for (CSimpleSprite *cattailSprite : cattailSprites)
    // {
    //     cattailSprite->Draw();
    // }
}

void Obstacles::initializeSprites()
{
    // Initialize rock sprites
    for (int i = 0; i < ROCK_COUNT; ++i)
    {
        CSimpleSprite *rockSprite = nullptr;
        initRock(rockSprite);
        rockSprites.push_back(rockSprite);
    }

    // Initialize tire sprites
    for (int i = 0; i < TIRE_COUNT; ++i)
    {
        CSimpleSprite *tireSprite = nullptr;
        initTire(tireSprite);
        tireSprites.push_back(tireSprite);
    }

    // // Initialize branch sprites
    // for (int i = 0; i < BRANCH_COUNT; ++i)
    // {
    //     CSimpleSprite *branchSprite = nullptr;
    //     initBranch(branchSprite);
    //     branchSprites.push_back(branchSprite);
    // }

    // // Initialize cattail sprites
    // for (int i = 0; i < CATTAIL_COUNT; ++i)
    // {
    //     CSimpleSprite *cattailSprite = nullptr;
    //     initCattail(cattailSprite);
    //     cattailSprites.push_back(cattailSprite);
    // }

    // // Initialize crab sprites
    // for (int i = 0; i < CRAB_COUNT; ++i)
    // {
    //     CSimpleSprite *crabSprite = nullptr;
    //     initCrab(crabSprite);
    //     crabSprites.push_back(crabSprite);
    // }

    // // Initialize frog sprites
    // for (int i = 0; i < FROG_COUNT; ++i)
    // {
    //     CSimpleSprite *frogSprite = nullptr;
    //     initFrog(frogSprite);
    //     frogSprites.push_back(frogSprite);
    // }

    // // Initialize pink jelly sprites
    // for (int i = 0; i < PINK_JELLY_COUNT; ++i)
    // {
    //     CSimpleSprite *pinkJellySprite = nullptr;
    //     initPinkJelly(pinkJellySprite);
    //     pinkJellySprites.push_back(pinkJellySprite);
    // }

    // // Initialize squid sprites
    // for (int i = 0; i < SQUID_COUNT; ++i)
    // {
    //     CSimpleSprite *squidSprite = nullptr;
    //     initSquid(squidSprite);
    //     squidSprites.push_back(squidSprite);
    // }

    // // Initialize tire sprites
    // for (int i = 0; i < TIRE_COUNT; ++i)
    // {
    //     CSimpleSprite *tireSprite = nullptr;
    //     initTire(tireSprite);
    //     tireSprites.push_back(tireSprite);
    // }

    // // Initialize turtle sprites
    // for (int i = 0; i < TURTLE_COUNT; ++i)
    // {
    //     CSimpleSprite *turtleSprite = nullptr;
    //     initTurtle(turtleSprite);
    //     turtleSprites.push_back(turtleSprite);
    // }

    // // Initialize watermelon sprites
    // for (int i = 0; i < WATERMELON_COUNT; ++i)
    // {
    //     CSimpleSprite *watermelonSprite = nullptr;
    //     initWatermelon(watermelonSprite);
    //     watermelonSprites.push_back(watermelonSprite);
    // }
}

void Obstacles::initializeCoordinates(float sandWidth)
{
    // Initialize coordinates for rock sprites
    for (CSimpleSprite *rockSprite : rockSprites)
    {
        int randomX = generateRandomX(rockSprite);
        // Set Y value and other properties as needed
        rockSprite->SetPosition(randomX, 50++);
    }

    // Initialize coordinates for tire sprites
    for (CSimpleSprite *tireSprite : tireSprites)
    {
        int randomX = generateRandomX(tireSprite);
        // Set Y value and other properties as needed
        tireSprite->SetPosition(randomX, 40);
    }
}

void Obstacles::initRock(CSimpleSprite *sprite)
{
    sprite = new CSimpleSprite(".\\TestData\\obstacles\\rocks.png", 2, 3);
    sprite->CreateAnimation(0, 1.0f / 6.0f, {0, 1, 2, 3, 4, 5});
    sprite->SetAnimation(0);
}

void Obstacles::initTire(CSimpleSprite *sprite)
{
    sprite = new CSimpleSprite(".\\TestData\\obstacles\\tire.png", 2, 1);
    sprite->CreateAnimation(0, 1.0f / 6.0f, {0, 1});
    sprite->SetAnimation(0);

}
void Obstacles::initYellowJelly(CSimpleSprite *sprite)
{
    sprite = new CSimpleSprite(".\\TestData\\obstacles\\yellow-jelly.png", 4, 1);
    sprite->CreateAnimation(0, 1.0f / 6.0f, {0, 1, 2, 3});
}
void Obstacles::initFrog(CSimpleSprite *sprite)
{
    sprite = new CSimpleSprite(".\\TestData\\obstacles\\frog.png", 4, 4);
    sprite->CreateAnimation(0, 1.0f / 6.0f, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
}

void Obstacles::initPinkJelly(CSimpleSprite *sprite)
{
    sprite = new CSimpleSprite(".\\TestData\\obstacles\\pink-jelly.png", 4, 1);
    sprite->CreateAnimation(0, 1.0f / 6.0f, {0, 1, 2, 3});
}

void Obstacles::initSquid(CSimpleSprite *sprite)
{
    sprite = new CSimpleSprite(".\\TestData\\obstacles\\squid.png", 4, 1);
    sprite->CreateAnimation(0, 1.0f / 6.0f, {0, 1, 2, 3});
}

void Obstacles::initTurtle(CSimpleSprite *sprite)
{
    sprite = new CSimpleSprite(".\\TestData\\obstacles\\turtle.png", 4, 1);
    sprite->CreateAnimation(0, 1.0f / 6.0f, {0, 1, 2, 3});
}

void Obstacles::initWatermelon(CSimpleSprite *sprite)
{
    sprite = new CSimpleSprite(".\\TestData\\obstacles\\watermelon.png", 1, 1);
}

void Obstacles::initCattail(CSimpleSprite *sprite)
{
    sprite = new CSimpleSprite(".\\TestData\\obstacles\\cattail.png", 1, 1);
}

void Obstacles::initCrab(CSimpleSprite *sprite)
{
    sprite = new CSimpleSprite(".\\TestData\\obstacles\\crab.png", 4, 1);
    sprite->CreateAnimation(0, 1.0f / 6.0f, {0, 1, 2, 3});
}
void Obstacles::initBranch(CSimpleSprite *sprite)
{
    sprite = new CSimpleSprite(".\\TestData\\obstacles\\branch.png", 1, 1);
}

int Obstacles::generateRandomX(CSimpleSprite *sprite)
{
    // Assuming sprite is centered on its X-axis, you may need to adjust accordingly
    float spriteWidth = sprite->GetWidth();

    // Generate a random X-coordinate within the game screen
    // The +1 ensures that the entire sprite remains within the screen
    int minX = 0 + static_cast<int>(spriteWidth / 2.0f) + 1;
    int maxX = APP_VIRTUAL_WIDTH - static_cast<int>(spriteWidth / 2.0f) - 1;

    int randomX = rand() % (maxX - minX + 1) + minX;
    return randomX;
}
