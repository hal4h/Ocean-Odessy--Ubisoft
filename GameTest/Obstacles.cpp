#include "stdafx.h"
#include "app\app.h"

#include "Obstacles.h"

Obstacles::Obstacles()
{
	rockY = generateY(ROCK_COUNT, 300, MAX);
	tireY = generateY(TIRE_COUNT, 400, MAX);
	frogY = generateY(FROG_COUNT, 600, MAX);
	

	initializeSprites(); // create the sprites,
	// initializeCoordinates(sandHeight, userDepth);
	//
	visibleSprites;
}

Obstacles::~Obstacles()
{
	for (CSimpleSprite* rockSprite : rockSprites)
	{
		delete rockSprite;
	}
	for (CSimpleSprite* tireSprite : tireSprites)
	{
		delete tireSprite;
	}
	for (CSimpleSprite* fishSprite : fishSprites)
	{
		delete fishSprite;
	}
	for (CSimpleSprite* bottleSprite : bottleSprites)
	{
		delete bottleSprite;
	}
	for (CSimpleSprite* cattailSprite : cattailSprites)
	{
		delete cattailSprite;
	}
	for (CSimpleSprite* crabSprite : crabSprites)
	{
		delete crabSprite;
	}
	for (CSimpleSprite* frogSprite : frogSprites)
	{
		delete frogSprite;
	}
	for (CSimpleSprite* pinkJellySprite : pinkJellySprites)
	{
		delete pinkJellySprite;
	}
	for (CSimpleSprite* squidSprite : squidSprites)
	{
		delete squidSprite;
	}
	for (CSimpleSprite* turtleSprite : turtleSprites)
	{
		delete turtleSprite;
	}
	for (CSimpleSprite* watermelonSprite : watermelonSprites)
	{
		delete watermelonSprite;
	}

	for (CSimpleSprite* yellowJellySprite : yellowJellySprites)
	{
		delete yellowJellySprite;
	}

	// add code to delete other sprites
}

void Obstacles::Update(float deltaTime)
{
	// Update the obstacles animation, only 
	for (CSimpleSprite* rockSprite : rockSprites)
	{
		rockSprite->Update(deltaTime);
	}
	for (CSimpleSprite* tireSprite : tireSprites)
	{
		tireSprite->Update(deltaTime);
	}
	for (CSimpleSprite* bottle : bottleSprites)
	{
		bottle->Update(deltaTime);
	}
	for (CSimpleSprite* frog : frogSprites)
	{
		frog->Update(deltaTime);
	}
	for (CSimpleSprite* fish : fishSprites)
	{
		fish->Update(deltaTime);
	}
	for (CSimpleSprite* cattail : cattailSprites)
	{
		cattail->Update(deltaTime);
	}
	for (CSimpleSprite* crab : crabSprites)
	{
		crab->Update(deltaTime);
	}
	for (CSimpleSprite* pinkJelly : pinkJellySprites)
	{
		pinkJelly->Update(deltaTime);
	}
}

void Obstacles::DrawObstacles(float speed)
{
	// create vector of obj on screen-

	float currentX, currentY;

	// Draw the obstacles
	for (CSimpleSprite* rockSprite : rockSprites)
	{
		moveObstacle(rockSprite, speed, rockY);
	}
	for (CSimpleSprite* tireSprite : tireSprites) {
		moveObstacle(tireSprite, speed, tireY);
	}
	for (CSimpleSprite* frog : frogSprites) {
		moveObstacle(frog, speed, frogY);
	}
	// for (CSimpleSprite* tireSprite : tireSprites)
	// {
	// tireSprite->GetPosition(currentX, currentY);
	// tireSprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position

	// //char buffer[50]; // Adjust the size according to your needs
	// //sprintf(buffer, " the current x %.2f and y %.2f coords", currentX, currentY - speed);
	// //App::Print(100 + i, 300+ i, buffer);
	// //i *500;
	// tireSprite->Draw();
	// }
	// for (CSimpleSprite* bottle : bottleSprites)
	// {
	// bottle->GetPosition(currentX, currentY);
	// bottle->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
	// bottle->Draw();
	// }

	// for (CSimpleSprite* cattailSprite : cattailSprites)
	// {
	// cattailSprite->GetPosition(currentX, currentY);
	// cattailSprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
	// // cattailSprite->Draw();
	// }
	// for (CSimpleSprite* crabSprite : crabSprites) {
	// crabSprite->GetPosition(currentX, currentY);
	// crabSprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
	// crabSprite->Draw();
	//}

	// for (CSimpleSprite* frogSprite : frogSprites)
	//{
	// frogSprite->GetPosition(currentX, currentY);
	// frogSprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
	// frogSprite->Draw();
	// }

	// for (CSimpleSprite* pinkJellySprite : pinkJellySprites)
	//{
	// pinkJellySprite->GetPosition(currentX, currentY);
	// pinkJellySprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
	// pinkJellySprite->Draw();
	// }

	// for (CSimpleSprite* squidSprite : squidSprites)
	//{
	// squidSprite->GetPosition(currentX, currentY);
	// squidSprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
	// squidSprite->Draw();
	// }

	// for (CSimpleSprite* fishSprite : fishSprites)
	//{
	// fishSprite->GetPosition(currentX, currentY);
	// fishSprite->SetPosition(currentX, currentY - speed); // Add yPos to the current Y position, Set the updated position
	// fishSprite->Draw();
	//}
}

void Obstacles::initializeSprites()

{
	// Initialize rock sprites
	for (int i = 0; i < MAX_SPRITE; ++i)
	{
		CSimpleSprite* rockSprite = initRock();
		initObstacle(rockSprite, rockY);
		rockSprites.push_back(rockSprite);
	}

	// init tire
	for (int i = 0; i < MAX_SPRITE; ++i) {
		CSimpleSprite* tireSprite = initTire();
		initObstacle(tireSprite, tireY);
		tireSprites.push_back(tireSprite);
	}

	// Initialize frog sprites
	for (int i = 0; i < MAX_SPRITE; ++i)
	{
		CSimpleSprite* frogSprite = initFrog();
		initObstacle(frogSprite, frogY);
		frogSprites.push_back(frogSprite);
	}
	// //Initialize tire spritesw
	// for (int i = 0; i < TIRE_COUNT; ++i)
	// {
	// CSimpleSprite* tireSprite = initTire();
	// tireSprites.push_back(tireSprite);
	// }

	// for (int i = 0; i < FISH_COUNT; i++)
	// {
	// CSimpleSprite* fishSprite = initFish();
	// fishSprites.push_back(fishSprite);
	// }

	// // Initialize bottle sprites
	// for (int i = 0; i < BOTTLE_COUNT; ++i)
	// {
	// CSimpleSprite* branchSprite = initBottle();
	// bottleSprites.push_back(branchSprite);
	// }

	// // Initialize cattail sprites
	// for (int i = 0; i < CATTAIL_COUNT; ++i)
	// {
	// CSimpleSprite* cattailSprite = initCattail();
	// cattailSprites.push_back(cattailSprite);
	// }

	// // Initialize crab sprites
	// for (int i = 0; i < CRAB_COUNT; ++i)
	// {
	// CSimpleSprite* crabSprite = initCrab();
	// crabSprites.push_back(crabSprite);
	// }

	// // Initialize frog sprites
	// for (int i = 0; i < FROG_COUNT; ++i)
	// {
	// CSimpleSprite* frogSprite = initFrog();
	// frogSprites.push_back(frogSprite);
	// }

	// // Initialize pink jelly sprites
	// for (int i = 0; i < PINK_JELLY_COUNT; ++i)
	// {
	// CSimpleSprite* pinkJellySprite = initPinkJelly();
	// pinkJellySprites.push_back(pinkJellySprite);
	// }

	// // Initialize squid sprites
	// for (int i = 0; i < SQUID_COUNT; ++i)
	// {
	// CSimpleSprite* squidSprite = initSquid();
	// squidSprites.push_back(squidSprite);
	// }

	// // Initialize tire sprites
	// for (int i = 0; i < YELLOW_JELLY_COUNT; ++i)
	// {
	// CSimpleSprite* yellowJellySprite = initYellowJelly();
	// yellowJellySprites.push_back(yellowJellySprite);
	// }

	// // Initialize turtle sprites
	// for (int i = 0; i < TURTLE_COUNT; ++i)
	// {
	// CSimpleSprite* turtleSprite = initTurtle();
	// turtleSprites.push_back(turtleSprite);
	// }

	// // Initialize watermelon sprites
	// for (int i = 0; i < WATERMELON_COUNT; ++i)
	// {
	// CSimpleSprite* watermelonSprite = initWatermelon();
	// watermelonSprites.push_back(watermelonSprite);
	// }

	// // Initialize yellow jelly sprites
	// for (int i = 0; i < BOTTLE_COUNT; ++i)
	// {
	// CSimpleSprite* bottle = initBottle();
	// bottleSprites.push_back(bottle);
	// }

	// initialize coordinates at the end
	// initializeCoordinates(sandHeight, userDepth);
}

// TODO: add class to handle the different types of obstacles
CSimpleSprite* Obstacles::initRock()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\rocks.png", 2, 3);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3, 4, 5 });
	sprite->SetAnimation(0);
	return sprite;
}
CSimpleSprite* Obstacles::initFish()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\fish.png", 4, 1);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3 });
	sprite->SetAnimation(0);
	return sprite;
}
CSimpleSprite* Obstacles::initTire()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\tire.png", 2, 1);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1 });
	sprite->SetAnimation(0);
	sprite->SetScale(1.8);
	return sprite;
}

CSimpleSprite* Obstacles::initYellowJelly()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\yellow-jelly.png", 4, 1);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3 });
	sprite->SetAnimation(0);

	return sprite;
}

CSimpleSprite* Obstacles::initFrog()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\frog.png", 4, 4);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, -13, 14, 15 });
	sprite->SetAnimation(0);
	sprite->SetScale(3.0f);

	return sprite;
}

CSimpleSprite* Obstacles::initPinkJelly()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\pink-jelly.png", 2, 1);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1 });
	return sprite;
}

CSimpleSprite* Obstacles::initSquid()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\squid.png", 5, 1);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3, 4 });
	return sprite;
}

CSimpleSprite* Obstacles::initTurtle()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\turtle.png", 4, 1);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3 });
	return sprite;
}

CSimpleSprite* Obstacles::initWatermelon()
{
	return new CSimpleSprite(".\\TestData\\\watermelon.png", 1, 1);
}

CSimpleSprite* Obstacles::initCattail()
{
	return new CSimpleSprite(".\\TestData\\cattail.png", 1, 1);
}

CSimpleSprite* Obstacles::initCrab()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\crab.png", 6, 1);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3, 4, 5 });
	return sprite;
}

CSimpleSprite* Obstacles::initBottle()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\bottle.png", 4, 1);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3 });
	return sprite;
}

float Obstacles::generateRandomX(CSimpleSprite* sprite)
{
	float spriteWidth = sprite->GetWidth();

	// Generate a random X-coordinate within the game screen, +1 ensures that the entire sprite remains within the screen
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
//*/
//std::vector<CSimpleSprite*> Obstacles::getVisibleObjects()
//{
//	for (CSimpleSprite* rockSprite : rockSprites)
//	{
//		float y, x;
//		rockSprite->GetPosition(x, y);
//		if (y > 0 && y < APP_VIRTUAL_HEIGHT)
//		{
//			visibleObjects.push_back(rockSprite);
//		}
//	}
//
//	// for bottle sprite
//	for (CSimpleSprite* bottleSprite : bottleSprites)
//	{
//		float y, x;
//		bottleSprite->GetPosition(x, y);
//		if (y > 0 && y < APP_VIRTUAL_HEIGHT)
//		{
//			visibleObjects.push_back(bottleSprite);
//		}
//	}
//
//	for (CSimpleSprite* tireSprite : tireSprites)
//	{
//
//		float y, x;
//		tireSprite->GetPosition(x, y);
//		if (y > 0 && y < APP_VIRTUAL_HEIGHT)
//		{
//			visibleObjects.push_back(tireSprite);
//		}
//	}
//
//	for (CSimpleSprite* fishSprite : fishSprites)
//	{
//		float y, x;
//		fishSprite->GetPosition(x, y);
//		if (y > 0 && y < APP_VIRTUAL_HEIGHT)
//		{
//			visibleObjects.push_back(fishSprite);
//		}
//	}
//
//	for (CSimpleSprite* yellowJellySprite : yellowJellySprites)
//	{
//		float y, x;
//		yellowJellySprite->GetPosition(x, y);
//		if (y > 0 && y < APP_VIRTUAL_HEIGHT)
//		{
//			visibleObjects.push_back(yellowJellySprite);
//		}
//	}
//
//	for (CSimpleSprite* frogSprite : frogSprites)
//	{
//
//		float y, x;
//		frogSprite->GetPosition(x, y);
//		if (y > 0 && y < APP_VIRTUAL_HEIGHT)
//		{
//			visibleObjects.push_back(frogSprite);
//		}
//	}
//
//	for (CSimpleSprite* pinkJellySprite : pinkJellySprites)
//	{
//		float y, x;
//		pinkJellySprite->GetPosition(x, y);
//		if (y > 0 && y < APP_VIRTUAL_HEIGHT)
//		{
//			visibleObjects.push_back(pinkJellySprite);
//		}
//	}
//
//	for (CSimpleSprite* squidSprite : squidSprites)
//	{
//		float y, x;
//		squidSprite->GetPosition(x, y);
//		if (y > 0 && y < APP_VIRTUAL_HEIGHT)
//		{
//			visibleObjects.push_back(squidSprite);
//		}
//	}
//
//	for (CSimpleSprite* turtleSprite : turtleSprites)
//	{
//		float y, x;
//		turtleSprite->GetPosition(x, y);
//		if (y > 0 && y < APP_VIRTUAL_HEIGHT)
//		{
//			visibleObjects.push_back(turtleSprite);
//		}
//	}
//
//	for (CSimpleSprite* watermelonSprite : watermelonSprites)
//	{
//		float y, x;
//		watermelonSprite->GetPosition(x, y);
//		if (y > 0 && y < APP_VIRTUAL_HEIGHT)
//		{
//			visibleObjects.push_back(watermelonSprite);
//		}
//	}
//
//	for (CSimpleSprite* cattailSprite : cattailSprites)
//	{
//		float y, x;
//		cattailSprite->GetPosition(x, y);
//		if (y > 0 && y < APP_VIRTUAL_HEIGHT)
//		{
//			visibleObjects.push_back(cattailSprite);
//		}
//	}
//
//	for (CSimpleSprite* crabSprite : crabSprites)
//	{
//		float y, x;
//		crabSprite->GetPosition(x, y);
//		if (y > 0 && y < APP_VIRTUAL_HEIGHT)
//		{
//			visibleObjects.push_back(crabSprite);
//		}
//	}
//
//	return visibleObjects;
//}

std::vector<float> Obstacles::generateY(int count, float yStart, float yEnd)
{
	std::vector<float> yValues;
	// Ensure count is at least 1 to avoid division by zero
	if (count < 1) {
		return yValues;
	}

	float step = (yEnd - yStart) / static_cast<float>(count - 1);
	float y = yStart;

	for (int i = 0; i < count; i++)
	{
		yValues.push_back(y);
		y += step;
	}

	return yValues;
}

// takes pointer to a sprite, and yVector. changes its pos to head of vector of float Y values, delete Y position from front, and calls randomX
// returns modified sprite pointer
void Obstacles::initObstacle(CSimpleSprite* sprite, std::vector<float>& yValues)
{
	if (!yValues.empty())
	{
		sprite->SetPosition(generateRandomX(sprite), yValues[0]);
		yValues.erase(yValues.begin());
	}
	// handle the case where yValues is empty
}


// takes pointer to a sprite, and speed, udpates its position, by adding speed to its current Y
// if its Y is in page, call Draw(), and add to visible obsticles,
// if Y is less than 0 and Y values is not empty, replace that
void Obstacles::moveObstacle(CSimpleSprite* sprite, float speed, std::vector<float> yValues)
{
	float y, x;
	sprite->GetPosition(x, y);
	sprite->SetPosition(x, y - speed);


	if (y < 0) //below scrren
	{
		if (yValues.size() > 0)
		{
			//
			initObstacle(sprite, yValues);
		}
		// else
		// {
		// delete sprite; // no sprites left and it is out of bounds
		// }
	}
	else if (y > 0 && y < APP_VIRTUAL_HEIGHT){
			visibleSprites.push_back(sprite);
		sprite->Draw();
	}
}
