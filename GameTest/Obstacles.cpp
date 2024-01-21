#include "stdafx.h"
#include "app\app.h"

#include "Obstacles.h"

// create an array of each obstacle
//  create an array of coordinates for each obstacle

Obstacles::Obstacles()
{
    initializeSprites();
    // initializeCoordinates(sandHeight, userDepth);
    //
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

// updates the animation of all sprites, only needed for sprites with more than one frame
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

    for (CSimpleSprite* fish : fishSprites)
    {
        fish->Update(deltaTime);
    }

     for (CSimpleSprite *pinkJelly : pinkJellySprites)
     {
         pinkJelly->Update(deltaTime);
     }

     for (CSimpleSprite* frogs : frogSprites)
     {
         frogs->Update(deltaTime);
     }

}

void Obstacles::DrawObstacles(const float speed)
{
    float currentX, currentY;

    // Draw the obstacles
    for (CSimpleSprite *rockSprite : rockSprites)
    {
        rockSprite->GetPosition(currentX, currentY);
       rockSprite->SetPosition(currentX, currentY- speed ); // Add yPos to the current Y position, Set the updated position
      rockSprite->Draw();
    }
    for (CSimpleSprite* tireSprite : tireSprites)
    {
        tireSprite->GetPosition(currentX, currentY);
        tireSprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
        tireSprite->Draw();
    }
    for (CSimpleSprite* branchSprite : branchSprites)
    {
        branchSprite->GetPosition(currentX, currentY);
        branchSprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
        branchSprite->Draw();
    }
    for (CSimpleSprite* cattailSprite : cattailSprites)
    {
        cattailSprite->GetPosition(currentX, currentY);
        cattailSprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
        cattailSprite->Draw();
    }

  //  for (CSimpleSprite* crabSprite : crabSprites) {
     //   crabSprite->GetPosition(currentX, currentY);
      //  crabSprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
      //  crabSprite->Draw();
   // }

    for (CSimpleSprite* frogSprite : frogSprites)
    {
        frogSprite->GetPosition(currentX, currentY);
        frogSprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
        frogSprite->Draw();
    }

    for (CSimpleSprite* pinkJellySprite : pinkJellySprites)  
    {
        pinkJellySprite->GetPosition(currentX, currentY);
        pinkJellySprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
        pinkJellySprite->Draw();
    }

    for (CSimpleSprite* squidSprite : squidSprites)
    {
        squidSprite->GetPosition(currentX, currentY);
        squidSprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
        squidSprite->Draw();
    }

    for (CSimpleSprite* fishSprite : fishSprites)
    {
        fishSprite->GetPosition(currentX, currentY);
        fishSprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
        fishSprite->Draw();
    }
}

void Obstacles::initializeSprites()
{
    // Initialize rock sprites
    for (int i = 0; i < ROCK_COUNT; ++i)
    {
        CSimpleSprite *rockSprite = initRock();
        rockSprites.push_back(rockSprite);
    }

    //Initialize tire sprites
    for (int i = 0; i < TIRE_COUNT; ++i)
    {
        CSimpleSprite* tireSprite = initTire();
        tireSprites.push_back(tireSprite);
    }

    for (int i = 0; i < FISH_COUNT; i++)
    {
        CSimpleSprite* fishSprite = initFish();
        fishSprites.push_back(fishSprite);
    }


    // Initialize branch sprites
    for (int i = 0; i < BRANCH_COUNT; ++i)
    {
        CSimpleSprite* branchSprite = initBranch();
        branchSprites.push_back(branchSprite);
    }

    // Initialize cattail sprites
    for (int i = 0; i < CATTAIL_COUNT; ++i)
    {
        CSimpleSprite* cattailSprite = initCattail();
        cattailSprites.push_back(cattailSprite);
    }

    // Initialize crab sprites
    for (int i = 0; i < CRAB_COUNT; ++i)
    {
        CSimpleSprite* crabSprite = initCrab();
        crabSprites.push_back(crabSprite);
    }

    // Initialize frog sprites
    for (int i = 0; i < FROG_COUNT; ++i)
    {
        CSimpleSprite* frogSprite = initFrog();
        frogSprites.push_back(frogSprite);
    }

    // Initialize pink jelly sprites
    for (int i = 0; i < PINK_JELLY_COUNT; ++i)
    {
        CSimpleSprite* pinkJellySprite = initPinkJelly();
        pinkJellySprites.push_back(pinkJellySprite);
    }

    // Initialize squid sprites
    for (int i = 0; i < SQUID_COUNT; ++i)
    {
        CSimpleSprite* squidSprite = initSquid();
        squidSprites.push_back(squidSprite);
    }

    // Initialize tire sprites
    for (int i = 0; i < YELLOW_JELLY_COUNT; ++i)
    {
        CSimpleSprite* yellowJellySprite = initYellowJelly();
        yellowJellySprites.push_back(yellowJellySprite);
    }

    // Initialize turtle sprites
    for (int i = 0; i < TURTLE_COUNT; ++i)
    {
        CSimpleSprite* turtleSprite = initTurtle();
        turtleSprites.push_back(turtleSprite);
    }

    // Initialize watermelon sprites
    for (int i = 0; i < WATERMELON_COUNT; ++i)
    {
        CSimpleSprite* watermelonSprite = initWatermelon();
        watermelonSprites.push_back(watermelonSprite);
    }

    // Initialize yellow jelly sprites
    for (int i = 0; i < YELLOW_JELLY_COUNT; ++i)
    {
        CSimpleSprite* yellowJellySprite = initYellowJelly();
        yellowJellySprites.push_back(yellowJellySprite);
    }

    // initialize coordinates at the end
    // initializeCoordinates(sandHeight, userDepth);
}

void Obstacles::initializeCoordinates(float userDepth)
{
    float start = 500;

    // Calculate the vertical spacing between rock sprites
    float verticalSpacingRock = (MAX - start) / (ROCK_COUNT - 1);

    // Initialize coordinates for rock sprites
    for (CSimpleSprite* rockSprite : rockSprites)
    {
        float randomX = generateRandomX(rockSprite);

        // Set Y value and other properties as needed
        rockSprite->SetPosition(randomX, start);
        start += verticalSpacingRock;
    }

    start = 700;
    float verticalSpacingTire = (MAX - start) / (TIRE_COUNT - 1);

    // Initialize coordinates for tire sprites
    for (CSimpleSprite* tireSprite : tireSprites)
    {
        float randomX = generateRandomX(tireSprite);

        // Set Y value and other properties as needed
        tireSprite->SetPosition(randomX, start);
        start += verticalSpacingTire;
    }

    // Now, let's add a similar loop for the branch sprite
    start = 600;  // Adjust the starting Y position for the branch sprite
    float verticalSpacingBranch = (MAX - start) / (BRANCH_COUNT - 1);

    // Initialize coordinates for branch sprites
    for (CSimpleSprite* branchSprite : branchSprites)
    {
        float randomX = generateRandomX(branchSprite);

        // Set Y value and other properties as needed
        branchSprite->SetPosition(randomX, start);
        start += verticalSpacingBranch;
    }
}


CSimpleSprite *Obstacles::initRock()
{
    CSimpleSprite *sprite = new CSimpleSprite(".\\TestData\\rocks.png", 2, 3);
    sprite->CreateAnimation(0, 1.0f / 6.0f, {0, 1, 2, 3, 4, 5});
    sprite->SetAnimation(0);
    return sprite;
}

CSimpleSprite* Obstacles::initFish()
{
    CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\obstacles\\fish.png", 4, 1);
    sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3 });
    sprite->SetAnimation(0);
    return sprite;
} 
CSimpleSprite* Obstacles::initTire()
{
    CSimpleSprite * sprite = new CSimpleSprite(".\\TestData\\obstacles\\tire.png", 2, 1);
    sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1 });
    sprite->SetAnimation(0);
    return sprite;
}

//CSimpleSprite* Obstacles::initFish()
//{
  //  CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\obstacles\\fish.png", 4, 1);
   // sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3 });
   // sprite->SetAnimation(0);

    //return sprite;
//}

CSimpleSprite* Obstacles::initYellowJelly()
{
    CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\obstacles\\yellow-jelly.png", 4, 1);
    sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3 });
    sprite->SetAnimation(0);

    return sprite;
}

CSimpleSprite* Obstacles::initFrog()
{
    CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\obstacles\\frog.png", 4, 4);
    sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
    sprite->SetAnimation(0);

    return sprite;
}

CSimpleSprite* Obstacles::initPinkJelly()
{
    CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\obstacles\\pink-jelly.png", 2, 1);
    sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1 });
    return sprite;
}

CSimpleSprite* Obstacles::initSquid()
{
    CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\obstacles\\squid.png", 5, 1);
    sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3,4 });
    return sprite;
}

CSimpleSprite* Obstacles::initTurtle()
{
    CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\obstacles\\turtle.png", 4, 1);
    sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3 });
    return sprite;
}

CSimpleSprite* Obstacles::initWatermelon()
{
    return new CSimpleSprite(".\\TestData\\obstacles\\watermelon.png", 1, 1);
}

CSimpleSprite* Obstacles::initCattail()
{
    return new CSimpleSprite(".\\TestData\\obstacles\\cattail.png", 1, 1);
}

CSimpleSprite* Obstacles::initCrab()
{
    CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\obstacles\\crab.png", 6, 1);
    sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3,4,5 });
    return sprite;
}

CSimpleSprite* Obstacles::initBranch()
{
    return new CSimpleSprite(".\\TestData\\obstacles\\branch.png", 1, 1);
}

float Obstacles::generateRandomX(CSimpleSprite *sprite)
{
    // Assuming sprite is centered on its X-axis, you may need to adjust accordingly
    float spriteWidth = sprite->GetWidth();

    // Generate a random X-coordinate within the game screen
    // The +1 ensures that the entire sprite remains within the screen
    float minX = 0 + (spriteWidth / 2.0f) + 1;
    float maxX = APP_VIRTUAL_WIDTH - (spriteWidth / 2.0f) - 1;

    // Generate a random number between those two values
    float randomX = minX + static_cast<float>(rand()) / RAND_MAX * (maxX - minX);

    return randomX;
}


/*
create a method that returns a vectors of all the objects whos coordinates are visible in the game screen,
meaning coordinates are between GAME_WIDTH and GAME_HEIGHT
iterate over the vectors of all objects in the .h file, get the y value, if between 0 and GAME_HEIGHT, add it to the vectors of visible objects
return the vector
*/

/**
 * method that returns a vector of all the objects whos coordinates are visible in the game screen,
 * everyframe, we are still updating the obstacle's coordinates, only draw the ones on the screen tho
*//**
 * method that returns a vector of all the objects whose coordinates are visible in the game screen,
 * every frame, we are still updating the obstacle's coordinates, only draw the ones on the screen though
*/
std::vector<CSimpleSprite*> Obstacles::getVisibleObjects() {
    std::vector<CSimpleSprite*> visibleObjects;

    for (CSimpleSprite* rockSprite : rockSprites)
    {
        float x, y;
        rockSprite->GetPosition(x, y);
        if (y > 0 && y < APP_VIRTUAL_HEIGHT)
        {
            visibleObjects.push_back(rockSprite);
        }
    }

 /*   for (CSimpleSprite* tireSprite : tireSprites) {
        float x, y;
        tireSprite->GetPosition(x, y);
        if (y > 0 && y < APP_VIRTUAL_HEIGHT)
        {
            visibleObjects.push_back(tireSprite);
        }
    }

    for (CSimpleSprite* fishSprite : fishSprites) {
        float x, y;
        fishSprite->GetPosition(x, y);
        if (y > 0 && y < APP_VIRTUAL_HEIGHT)
        {
            visibleObjects.push_back(fishSprite);
        }
    }

    for (CSimpleSprite* yellowJellySprite : yellowJellySprites) {
        float x, y;
        yellowJellySprite->GetPosition(x, y);
        if (y > 0 && y < APP_VIRTUAL_HEIGHT)
        {
            visibleObjects.push_back(yellowJellySprite);
        }
    }

    for (CSimpleSprite* frogSprite : frogSprites) {
        float x, y;
        frogSprite->GetPosition(x, y);
        if (y > 0 && y < APP_VIRTUAL_HEIGHT)
        {
            visibleObjects.push_back(frogSprite);
        }
    }

    for (CSimpleSprite* pinkJellySprite : pinkJellySprites) {
        float x, y;
        pinkJellySprite->GetPosition(x, y);
        if (y > 0 && y < APP_VIRTUAL_HEIGHT)
        {
            visibleObjects.push_back(pinkJellySprite);
        }
    }

    for (CSimpleSprite* squidSprite : squidSprites) {
        float x, y;
        squidSprite->GetPosition(x, y);
        if (y > 0 && y < APP_VIRTUAL_HEIGHT)
        {
            visibleObjects.push_back(squidSprite);
        }
    }

    for (CSimpleSprite* turtleSprite : turtleSprites) {
        float x, y;
        turtleSprite->GetPosition(x, y);
        if (y > 0 && y < APP_VIRTUAL_HEIGHT)
        {
            visibleObjects.push_back(turtleSprite);
        }
    }

    for (CSimpleSprite* watermelonSprite : watermelonSprites) {
        float x, y;
        watermelonSprite->GetPosition(x, y);
        if (y > 0 && y < APP_VIRTUAL_HEIGHT)
        {
            visibleObjects.push_back(watermelonSprite);
        }
    }

    for (CSimpleSprite* cattailSprite : cattailSprites) {
        float x, y;
        cattailSprite->GetPosition(x, y);
        if (y > 0 && y < APP_VIRTUAL_HEIGHT)
        {
            visibleObjects.push_back(cattailSprite);
        }
    }

    for (CSimpleSprite* crabSprite : crabSprites) {
        float x, y;
        crabSprite->GetPosition(x, y);
        if (y > 0 && y < APP_VIRTUAL_HEIGHT)
        {
            visibleObjects.push_back(crabSprite);
        }
    }*/

    return visibleObjects;
}

/*
method that deletes objects as soon as the leave the screen, since we cant go back

*/