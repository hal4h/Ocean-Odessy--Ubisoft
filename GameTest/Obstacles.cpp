#include "stdafx.h"
#include "app\app.h"

#include "Obstacles.h"

Obstacles::Obstacles()
{
	rockY = generateY(ROCK_COUNT, 300, MAX);
	tireY = generateY(TIRE_COUNT, 1050, MAX);
	frogY = generateY(FROG_COUNT, 1800, MAX);
	fishY = generateY(FISH_COUNT, 2550, MAX);
	bottleY = generateY(BOTTLE_COUNT, 3300, MAX);
	cattailY = generateY(CATTAIL_COUNT, 4050, MAX);
	floatieY = generateY(FLOATIE_COUNT, 4800, MAX);
	// crabY = generateY(CRAB_COUNT, 1600, MAX);
	duckY = generateY(DUCK_COUNT, 3000, MAX);
	sharkY = generateY(SHARK, 6300, MAX);
	/// turtleY = generateY(TURTLE_COUNT, 1800, MAX);

	initializeSprites(); // create the sprites,
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
	
		delete crabSprites;

	for (CSimpleSprite* frogSprite : frogSprites)
	{
		delete frogSprite;
	}
	for (CSimpleSprite* floatie : floatieSprites)
	{
		delete floatie;
	}

	for (CSimpleSprite* turtleSprite : turtleSprites)
	{
		delete turtleSprite;
	}
	for (CSimpleSprite* duck : duckSprites)
	{
		delete duck;
	}

	for (CSimpleSprite* shark : sharkSprites)
	{
		delete shark;
	}

	// only one crab sprite
	delete crabSprites;
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

	for (CSimpleSprite* duck : duckSprites)
	{
		duck->Update(deltaTime);
	}

	for (CSimpleSprite* shark : sharkSprites)
	{
		shark->Update(deltaTime);
	}

	//crabSprites->Update(deltaTime);

}

void Obstacles::DrawObstacles(float speed, bool scrolling)
{
	// create vector of obj on screen-

	float currentX, currentY;

	/** draw and update all static objects*/
	// rock sprites
	for (CSimpleSprite* rockSprite : rockSprites)
	{
		moveObstacle(rockSprite, speed, rockY);
	}
	// tire sprites
	for (CSimpleSprite* tireSprite : tireSprites)
	{
		moveObstacle(tireSprite, speed, tireY);
	}
	// frog sprites
	for (CSimpleSprite* frog : frogSprites)
	{
		moveObstacle(frog, speed, frogY);
	}
	// bottle sprites
	for (CSimpleSprite* bottle : bottleSprites)
	{
		moveObstacle(bottle, speed, rockY);
	}
	// cattail sprites
	for (CSimpleSprite* cattailSprite : cattailSprites)
	{
		moveObstacle(cattailSprite, speed, rockY);
	}


	for (CSimpleSprite* floatie : floatieSprites)
	{
		moveObstacle(floatie, speed, rockY);
	}

	/** draw and update all dynamic objects*/

	//moveCrab(crabSprites, speed, MAX);

	int xSpeed = 0;
	if (scrolling) {
		xSpeed = 2; // is screen is scrolling let the objects move right and left 
	}
	for (CSimpleSprite* shark : sharkSprites)
	{
		dynamicShark(shark, speed, sharkY, xSpeed);
	}
	for (CSimpleSprite* duck : duckSprites)
	{
		dynamicShark(duck, speed, duckY, xSpeed);
	}
	// fish sprite
	for (CSimpleSprite* fishSprite : fishSprites)
	{
		dynamicShark(fishSprite, speed, rockY, xSpeed);
	}

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
	for (int i = 0; i < MAX_SPRITE; ++i)
	{
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

	for (int i = 0; i < MAX_SPRITE; ++i)
	{
		CSimpleSprite* fishSprite = initFish();
		initObstacle(fishSprite, fishY);
		fishSprites.push_back(fishSprite);
	}

	// // Initialize bottle sprites
	for (int i = 0; i < MAX_SPRITE; ++i)
	{
		CSimpleSprite* bottle = initBottle();
		initObstacle(bottle, bottleY);
		bottleSprites.push_back(bottle);
	}

	for (int i = 0; i < MAX_SPRITE; ++i)
	{
		CSimpleSprite* shark = initShark();
		initObstacle(shark, sharkY);
		sharkSprites.push_back(shark);
	}

	for (int i = 0; i < MAX_SPRITE; ++i)
	{
		CSimpleSprite* duck = initDuck();
		initObstacle(duck, duckY);
		duckSprites.push_back(duck);
	}
	for (int i = 0; i < MAX_SPRITE; ++i)
	{
		CSimpleSprite* floatie = initFloatie();
		initObstacle(floatie, floatieY);
		floatieSprites.push_back(floatie);
	}

	for (int i = 0; i < MAX_SPRITE; ++i)
	{
		CSimpleSprite* cattail = initCattail();
		initObstacle(cattail, cattailY);
		cattailSprites.push_back(cattail);
	}

	//only one crab sprite in game
	CSimpleSprite* crab = initCrab();

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
	sprite->CreateAnimation(0, 1.0f / 4.0f, { 0, 1, 2, 3 });
	sprite->SetAnimation(0);
	sprite->SetScale(1.8f);
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

CSimpleSprite* Obstacles::initShark()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\shark.png", 5, 2);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3, 4, 5, 6 });
	sprite->SetAnimation(0);
	sprite->SetScale(2.0);
	return sprite;
}

CSimpleSprite* Obstacles::initFrog()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\frog.png", 2, 5);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	sprite->SetAnimation(0);
	sprite->SetScale(1.5f);

	return sprite;
}

CSimpleSprite* Obstacles::initFloatie()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\float.png", 1, 1);
	sprite->SetScale(2.5f);
	return sprite;
}

CSimpleSprite* Obstacles::initDuck()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\ducks.png", 3, 2);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2 });
	sprite->CreateAnimation(1, 1.0f / 6.0f, { 3, 4, 5 });
	sprite->SetScale(1.5f);
	sprite->SetAnimation(1);
	return sprite;
}

//CSimpleSprite* Obstacles::initTurtle()
//{
//	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\turtle.png", 4, 1);
//	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3 });
//	return sprite;
//}

//CSimpleSprite* Obstacles::initWatermelon()
//{
//	return new CSimpleSprite(".\\TestData\\watermelon.png", 1, 1);
//}

CSimpleSprite* Obstacles::initCattail()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\cattail.png", 1, 1);
	sprite->SetScale(1.6f);
	return sprite;
}

CSimpleSprite* Obstacles::initCrab()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\crab.png", 1, 2);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1 });
	sprite->SetPosition(0, MAX);
	return sprite;
}

CSimpleSprite* Obstacles::initBottle()
{
	CSimpleSprite* sprite = new CSimpleSprite(".\\TestData\\bottle.png", 4, 1);
	sprite->CreateAnimation(0, 1.0f / 6.0f, { 0, 1, 2, 3 });
	return sprite;
}

/*

*/
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

// generates a vector of floats, with count number of values, starting at yStart and ending at yEnd
std::vector<float> Obstacles::generateY(int count, float yStart, float yEnd)
{
	std::vector<float> yValues;
	// Ensure count is at least 1 to avoid division by zero
	if (count < 1)
	{
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
	//
	sprite->SetPosition(x, y - speed);

	if (y < 0) // below scrren
	{
		if (yValues.size() > 0)
		{
				initObstacle(sprite, yValues);
		}
		// else
		// {
		// delete sprite; // no sprites left and it is out of bounds
		// }
	}
	else if (y > 0 && y < APP_VIRTUAL_HEIGHT)
	{
		visibleSprites.push_back(sprite);
		sprite->Draw();
	}
}

// crab, duck shark all dynamic
// void Obstacles::moveCrab(CSimpleSprite *sprite, float speed, std::vector<float> yValues, float xSpeed)
// {
// floatx, y;
// sprite->GetPosition(x, y);
// // dynamic obstacle, crab moves back and forth on the screen, one it hits left side of the screen, slip angle to other side
// // everyframe object will move at a speed of xSpeed
// // if hits x of 0 or screen width, reverse direction and reverse angle
// if (x < 0 || x > APP_VIRTUAL_WIDTH)
// {
// sprite->SetAngle(180);
// xSpeed = -xSpeed;
// }
// else
// {
// sprite->SetAngle(0);
// }
// sprite->SetPosition(x + xSpeed, y - speed);
// if (y < 0) // below scrren
// {
// if (yValues.size() > 0)
// {
// initObstacle(sprite, yValues);
// }
// }
// else if (y > 0 && y < APP_VIRTUAL_HEIGHT)
// {
// visibleSprites.push_back(sprite);
// sprite->Draw();
// }
// }


// method that has crab moves back and forth on the screen, one it hits left side of the screen it moves other side
//y is updated by subtracting speed, x is updated by adding xSpeed
void Obstacles::moveCrab(CSimpleSprite* sprite, float speed, float xSpeed) {
	float x, y;
	sprite->GetPosition(x, y);
	// dynamic obstacle, crab moves back and forth on the screen, one it hits left side of the screen, slip angle to other side
	// everyframe object will move at a speed of xSpeed
	//if (x <= 0 || x >=  APP_VIRTUAL_WIDTH)
	//{
	//	xSpeed = -xSpeed;
	//}
	//// set y position to the maximium of 500 and y - speed
	//y = max(500, y - speed);
	//sprite->SetPosition(x + xSpeed, y - speed);
	//if (y > 0 && y < APP_VIRTUAL_HEIGHT)
	//{
	//	sprite->Draw();
	//}
}

void Obstacles::dynamicShark(CSimpleSprite* sprite, float speed, std::vector<float> yValues, float xSpeed)
{
	float x, y;
	sprite->GetPosition(x, y);

	// Dynamic obstacle, shark moves back and forth on the screen.
	// Once it hits the right side of the screen, it respawns at the left (x of 0).
	// Every frame, the object will move at a speed of xSpeed.

	if (x <= 0 - sprite->GetWidth() / 2.0f || x >= APP_VIRTUAL_WIDTH)
	{
		x = (x <= 0 - sprite->GetWidth() / 2.0f) ? APP_VIRTUAL_WIDTH : 0 - sprite->GetWidth() / 2.0f;
	}

	sprite->SetPosition(x + xSpeed, y - speed);

	if (y < 0) // below scrren
	{
		if (yValues.size() > 0)
		{
			initObstacle(sprite, yValues);
		}
	}
	else if (y > 0 && y < APP_VIRTUAL_HEIGHT)
	{
		visibleSprites.push_back(sprite);
		sprite->Draw();
	}
}


// dynamic obstacle, duck moves back and forth on the screen
// start by moving by increasing X value until it hits wdith of screen, set animation to 0
// when it hits the screen flip the other way so it subtracts X speed while setting animation to 1
// if it hits the screen again, flip it back to 0,
// everycall change Y value by -speed 
//void Obstacles::dynamicDuck(CSimpleSprite* sprite, float speed, std::vector<float> yValues, float xSpeed)
//{
//	float x, y;
//	sprite->GetPosition(x, y);
//
//	if (x - (sprite->GetWidth() /2.0f)  == 0){
//		sprite->SetAnimation(1);
//	}
//	else if (x + (sprite->GetWidth() / 2.0f) == APP_VIRTUAL_WIDTH)
//	{
//		sprite->SetAnimation(0);
//		xSpeed = -xSpeed;
//
//	}
//
//	sprite->SetPosition(x + xSpeed, y - speed);
//	//float x, y;
//
//	if (y < 0) // below scrren
//	{
//		if (yValues.size() > 0)
//		{
//			initObstacle(sprite, yValues);
//		}
//	}
//	else if (y > 0 && y < APP_VIRTUAL_HEIGHT)
//	{
//		visibleSprites.push_back(sprite);
//		sprite->Draw();
//	}
//}
