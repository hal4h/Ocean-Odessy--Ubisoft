#include "stdafx.h"
#include "app\app.h"

#include "Diver.h"

Diver::Diver() {
    diverSprite = new CSimpleSprite(".\\TestData\\main_diver.png", 4, 4); // create sprite

    // Set the initial position to the bottom of the page
    float initialX = APP_VIRTUAL_WIDTH / 2.0f;
    float initialY = APP_VIRTUAL_HEIGHT / 7.0f;

   // MAX_HEALTH = 3;
    health = MAX_HEALTH;

    animSpeed = 1.0f / 6.0f; //let the default speed value (adjust as needed)
    swimSpeed = 0.85f;
    // Set the initial position to the top of the page
    diverSprite->SetPosition(initialX, initialY);

    // Set the initial scale during initialization (adjust the value as needed)
    diverSprite->SetScale(1.0f);

    // Create animations during initialization
    CreateAnimations(animSpeed);

    // Set the default animation (forwards)
    diverSprite->SetAnimation(ANIM_FORWARDS);

    isPlaying = true;
    isDead = false;



    // create heart sprite
    // heartSprite = new CSimpleSprite(".\\TestData\\heart.png", 1, 1);
    // noHeartSprite = new CSimpleSprite(".\\TestData\\noheart.png", 1, 1);

    //vector of heartSprite, size of MAX_HEALTH
    InitHealthVector();
}

Diver::~Diver() {
    delete diverSprite;
}

void Diver::Update(float deltaTime, std::vector<CSimpleSprite*> obstacles, CSimpleSprite* chest) {
    diverSprite->Update(deltaTime); // update diver animation

    // Handle player input for movement and animation
    HandleInput(deltaTime); 
    CheckScreenCollision();
    IsColliding(obstacles);
    GameWon(chest);

}

void Diver::Draw() {
    // float x, y;
    // diverSprite->GetPosition(x, y);
    // diverSprite->SetPosition(x, y);

    diverSprite->Draw();
    DrawHearts();
}

void Diver::SetPosition(float x, float y) {
    diverSprite->SetPosition(x, y);
    diverX = x;
    diverY = y;
}

void Diver::SetAngle(float a) {
    diverSprite->SetAngle(a);
}

void Diver::SetScale(float s) {
    diverSprite->SetScale(s);
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

    // Call LoseHeart to update the visuals
    LoseHeart();

    if (health <= 0) {
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
    // Handle player input for movement and animation
    if (App::GetController().GetLeftThumbStickX() > 0.5f) {
        diverSprite->SetAnimation(ANIM_RIGHT);
        float x, y;
        diverSprite->GetPosition(x, y);
        x += swimSpeed;
        diverSprite->SetPosition(x, y);
    }
    else if (App::GetController().GetLeftThumbStickX() < -0.5f) {
        diverSprite->SetAnimation(ANIM_LEFT);
        float x, y;
        diverSprite->GetPosition(x, y);
        x -= swimSpeed;
        diverSprite->SetPosition(x, y);
    }
    else if (App::GetController().GetLeftThumbStickY() > 0.5f) {
        diverSprite->SetAnimation(ANIM_FORWARDS);
        float x, y;
        diverSprite->GetPosition(x, y);
        y += swimSpeed;
        diverSprite->SetPosition(x, y);
    }
    else if (App::GetController().GetLeftThumbStickY() < -0.5f) {
        diverSprite->SetAnimation(ANIM_BACKWARDS);
        float x, y;
        diverSprite->GetPosition(x, y);
        y -= swimSpeed;
        diverSprite->SetPosition(x, y);

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
    if (diverY + diverWidth / 2.0f <= 0) {
        RepositionOnScreenCollision();
    }
}



void Diver::RepositionOnScreenCollision() {
    // Subtract one life (add your life management logic here)
    TakeDamage();

    if (isDead == false) {
        //gameOver = true;
    }
    else {
        float middleX = (APP_VIRTUAL_WIDTH - diverSprite->GetWidth()) / 2.0f;
        float middleY = (APP_VIRTUAL_HEIGHT - diverSprite->GetHeight()) / 2.0f;
        diverSprite->SetPosition(middleX, middleY);
    }
    // Reposition the diver to the middle of the screen

}


bool Diver::IsPlaying() const {
    return isPlaying;
}

bool Diver::IsDead() const {
    return isDead;
}


// method to check if the diver intersects with an obstacle, returns true if it does
// remember position of object is in the middle of the object, so you need to adjust the position of the diver to the left and right by half the width of the object
bool Diver::Intersects(CSimpleSprite* obstacle){
    float x,y;
    diverSprite->GetPosition(x,y);
    float diverWidth = diverSprite->GetWidth();
    float diverHeight = diverSprite->GetHeight();

    float obsX, obsY;
    obstacle.GetPosition(obsX, obsY);
    float obstacleWidth = obstacle.GetWidth();
    float obstacleHeight = obstacle.GetHeight();

    // check if diver hits any side of obstacle
    if(x+diverWidth/2 > obsX && x-diverWidth/2 < obsX+obstacleWidth){
        if(y+diverHeight/2 > obsY && y-diverHeight/2 < obsY+obstacleHeight){
            return true;
        }
    }

}


// method to check if the diver intersects with an obstacle, returns true if it does
// remember position of object is in the middle of the object, so you need to adjust the position of the diver to the left and right by half the width of the object
bool Diver::Intersects(CSimpleSprite* obstacle) {
    float x, y;
    diverSprite->GetPosition(x, y);
    float diverWidth = diverSprite->GetWidth();
    float diverHeight = diverSprite->GetHeight();

    float obsX, obsY;
    obstacle->GetPosition(obsX, obsY);
    float obstacleWidth = obstacle->GetWidth();
    float obstacleHeight = obstacle->GetHeight();

    // check if diver hits any side of obstacle
    if (x + diverWidth / 2 > obsX && x - diverWidth / 2 < obsX + obstacleWidth) {
        if (y + diverHeight / 2 > obsY && y - diverHeight / 2 < obsY + obstacleHeight) {
            return true;
        }
    }

}


// take vector as a parameter, and return true if the diver intersects with any of the obstacles in the vector
// if intersects, break for loop, call take damage method, delete obstacle from vector, and return true
bool Diver::IsColliding(std::vector<CSimpleSprite*> obstacles) {

    for (int i = 0; i < obstacles.size(); i++) {
        if (Intersects(obstacles[i])) {
            //TODO: if health gainer. not enemy
            RepositionOnScreenCollision();
            obstacles.erase(obstacles.begin() + i);
            return true;
        }
    }
    return false;
}

// method to check if diver collides with the chest object, if it does game won
bool Diver::GameWon(CSimpleSprite* chest) {

    if (Intersects(chest)) {
        return true;
    }
    return false;
}



// Initialize health vector
void Diver::InitHealthVector() {
    // Create a vector of size MAX_HEALTH
    // TODO: create a vector of hearts, and set the position of the hearts using a for loop
    for (int i = 0; i < MAX_HEALTH; i++) {
        CSimpleSprite* heartSprite = new CSimpleSprite(".\\TestData\\heart.png", 1, 1);
        heartSprite->SetPosition(i * heartSprite->GetWidth() + 5, 20);
        hearts.push_back(heartSprite);
    }
}

void Diver::LoseHeart() {
    // Takes the array and changes the last heart sprite
    if (!hearts.empty()) {
        // Remove the last heart sprite
        CSimpleSprite* lastHeart = hearts.back();
        hearts.pop_back();
        delete lastHeart; // Don't forget to free the memory
    }
}

void Diver::DrawHearts() {
    // Draw the hearts
    for (CSimpleSprite* heartSprite : hearts) {
        heartSprite->Draw();
    }
}