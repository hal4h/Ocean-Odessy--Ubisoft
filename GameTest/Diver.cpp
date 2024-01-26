#include "stdafx.h"
#include "app\app.h"

#include "Diver.h"

Diver::Diver(){
    diverSprite = new CSimpleSprite(".\\TestData\\main_diver.png", 4, 4); // create sprite

    // Set the initial position to the bottom of the page
    float initialX = APP_VIRTUAL_WIDTH / 2.0f;
    float initialY = APP_VIRTUAL_HEIGHT / 7.0f;
    
    diverSprite->SetPosition(initialX, initialY);

     // MAX_HEALTH = 3;
    health = MAX_HEALTH;     // initalize current health to max

    animSpeed = 1.0f / 6.0f; //let the default speed value (adjust as needed)
    swimSpeed = 1.2f;
    // Set the initial position to the top of the page

    // Set the initial scale during initialization (adjust the value as needed)
    diverSprite->SetScale(1.0f);

    // Create animations during initialization

    // Set the default animation (forwards)
    diverSprite->SetAnimation(ANIM_BACKWARDS);

    CreateAnimations(animSpeed);

    isPlaying = true;
    isDead = false;
    won = false;
    //vector of heartSprite, size of MAX_HEALTH
}

Diver::~Diver() {
    delete diverSprite;
    isPlaying = false;
    isDead = true;
}

void Diver::Update(float deltaTime, std::vector<CSimpleSprite*> obstacles, int speed, CSimpleSprite* chest) {
    diverSprite->Update(deltaTime); // update diver animation

    // Handle player input for movement and animation
    HandleInput(deltaTime); 
    CheckScreenCollision();
    IsColliding(obstacles);
    if (cooldown) {  
        cooldownDuration -= 1;
        if (cooldownDuration <= 0) {
            cooldown = false;
            cooldownDuration = 3 * 60;  // Reset cooldown duration
        }
    }
   // GameWon(chest);
    speeed = speed;
}

void Diver::Draw() {
     float x, y;
     diverSprite->GetPosition(x, y);
     diverSprite->SetPosition(x, y - speeed);
     if (cooldown) {
         // TODO: logic to flash 
     }
    diverSprite->Draw();
    DrawHearts();
}

void Diver::SetPosition(float x, float y) {
    diverSprite->SetPosition(x, y);
    diverX = x;
    diverY = y;
}

void Diver::SetColor(float r, float g, float b) {
    diverSprite->SetColor(r, g, b);
}

void Diver::GetPosition(float& x, float& y) {
    x = diverX;
    y = diverY;
}

void Diver::SetHealth(int h) {
    health = h;
}

int Diver::GetHealth() const {
    return health;
}

void Diver::TakeDamage() {
    health--;

    if (health == 0) {
        isDead = true;
    }
}

void Diver::CreateAnimations(float speed) {
    // Create animations for the diver sprite
    diverSprite->CreateAnimation(ANIM_BACKWARDS, speed, { 0, 1, 2, 3 });
    diverSprite->CreateAnimation(ANIM_LEFT, speed, { 4, 5, 6, 7 });
    diverSprite->CreateAnimation(ANIM_RIGHT, speed, { 8, 9, 10, 11 });
    diverSprite->CreateAnimation(ANIM_FORWARDS, speed, { 12, 13, 14, 15 });
}

void Diver::HandleInput(float deltaTime) {

    if (isPlaying == true) {

        // Handle player input for movement and animation
        if (App::GetController().GetLeftThumbStickX() > 0.5f) {
            diverSprite->SetAnimation(ANIM_RIGHT);
            float x, y;
            diverSprite->GetPosition(x, y);
            x += swimSpeed;
            diverSprite->SetPosition(x, y);
        }
         if (App::GetController().GetLeftThumbStickX() < -0.5f) {
            diverSprite->SetAnimation(ANIM_LEFT);
            float x, y;
            diverSprite->GetPosition(x, y);
            x -= swimSpeed;
            diverSprite->SetPosition(x, y);
        }
         if (App::GetController().GetLeftThumbStickY() > 0.5f) {
            diverSprite->SetAnimation(ANIM_FORWARDS);
            float x, y;
            diverSprite->GetPosition(x, y);
            y += swimSpeed;
            diverSprite->SetPosition(x, y);
        }
         if (App::GetController().GetLeftThumbStickY() < -0.5f) {
            diverSprite->SetAnimation(ANIM_BACKWARDS);
            float x, y;
            diverSprite->GetPosition(x, y);
            y -= swimSpeed;
            diverSprite->SetPosition(x, y);

        }
    }
}

void Diver::SetSpeed(float newSpeed) {
    swimSpeed= newSpeed;
}

float Diver::GetSpeed() const {
    return swimSpeed;
}

void Diver::CheckScreenCollision() {
    float diverX, diverY;
    diverSprite->GetPosition(diverX, diverY);

    // Get the width of the diver sprite
    float diverWidth = diverSprite->GetWidth();

    // Check for collision with the left side of the screen
    if (diverX < diverWidth / 2.0f) {
        // Adjust the diver's position to stay within the left edge
        diverSprite->SetPosition(diverWidth / 2.0f, diverY);
    }

    // Check for collision with the right side of the screen
    if (diverX + diverWidth / 2.0f > APP_VIRTUAL_WIDTH) {
        // Adjust the diver's position to stay within the right edge
        diverSprite->SetPosition(APP_VIRTUAL_WIDTH - diverWidth / 2.0f, diverY);
    }

    // Check for collision with the top of the screen
    if (diverY + diverWidth / 2.0f > APP_VIRTUAL_HEIGHT) {
        // Adjust the diver's position to stay within the top edge
        diverSprite->SetPosition(diverX, APP_VIRTUAL_HEIGHT - diverWidth / 2.0f);
    }
    // Check for collision with the bottom of the screen, loses a life
    if (diverY - diverWidth / 2.0f <= 0) {
        RepositionOnScreenCollision();
    }
}

void Diver::RepositionOnScreenCollision() {
    // Subtract one life (add your life management logic here)
    //TakeDamage();
        float middleX = APP_VIRTUAL_WIDTH/ 2.0f;
        float middleY = APP_VIRTUAL_HEIGHT / 8.0f;
        diverSprite->SetPosition(middleX, middleY);

        health--;

    // Reposition the diver to the middle of the screen

}


void Diver::IsPlaying(bool value)  {
    isPlaying = value;
}

bool Diver::IsDead() const {
    if (health > 0) {
        return false;
    }
    return true;
}

void Diver::setGameWon(bool value) {
	won = value;
}

// method to check if the diver intersects with an obstacle returns true if it does
// remember position of the object is in the middle of the object, so you need to adjust the position of the diver to the left and right by half the width of the object
bool Diver::Intersects(CSimpleSprite* obstacle){
    float x,y;
    diverSprite->GetPosition(x,y);
    float diverWidth = diverSprite->GetWidth();
    float diverHeight = diverSprite->GetHeight();

    float obsX, obsY;
    obstacle->GetPosition(obsX, obsY);
    float obstacleWidth = obstacle->GetWidth();
    float obstacleHeight = obstacle->GetHeight();

    // Check if diver hits any side of obstacle with a 5-pixel leeway
    if (x + diverWidth / 2  > obsX && x - diverWidth / 2 < obsX + obstacleWidth)
    {
        if (y + diverHeight / 2 > obsY && y - diverHeight / 2 < obsY + obstacleHeight)
        {
            return true;
        }
    }

    return false;
}

// method to give immunity to sprite, flashes red

// take vector as a parameter, and return true if the diver intersects with any of the obstacles in the vector
// if intersects, break for loop, call take damage method, delete obstacle from vector, and return true
bool Diver::IsColliding(std::vector<CSimpleSprite*> obstacles) {

    for (int i = 0; i < obstacles.size(); i++) {
        if (Intersects(obstacles[i]) && !cooldown) {
            //TODO: if health booster. not enemy
            hitObject(obstacles[i]);
            cooldown = true;  // Activate cooldown
            obstacles.erase(obstacles.begin() + i);
            return true;
        }
    }
    return false;
}

void Diver::hitObject(CSimpleSprite* obstacle) {
    TakeDamage();

    // logic for turning red/ flashing
} 

// method to check if diver collides with the chest object, if it does game won
bool Diver::GameWon(CSimpleSprite* chest) {
    if (Intersects(chest)) {
        return true;
    }
	return false;
}

bool Diver::IsWon() const {
    return won;
}

void Diver::DrawHearts() {
    // Draw the hearts
    for (int i = 0; i < health; i++) {
            CSimpleSprite* heartSprite = new CSimpleSprite(".\\TestData\\heart.png", 1, 1);
            heartSprite->SetPosition(i * heartSprite->GetWidth() + 30, 20);
            heartSprite->Draw();
    
    }
}

// NO LONGER NEEDED, ADDED OBJECT POOLING
// once we have the vector of visible objects, we can iterate over it and delete the objects that are not on the screen anymore, or that reach the bottom of the screen, y value of 0.
// we can also delete the objects that are in the vector, since we are not going to draw them anymore, and we want to save memory
//void Diver::deleteObjects(std::vector<CSimpleSprite*> visibleObjects) {
//    for (CSimpleSprite* visibleObject : visibleObjects) {
//        float x, y;
//        visibleObject->GetPosition(x, y);
//        if (y <= 0) {
//            delete visibleObject;
//        }
//    }
//}
