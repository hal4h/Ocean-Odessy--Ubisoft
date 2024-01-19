#include "stdafx.h"
#include "app\app.h"

#include "Diver.h"

Diver::Diver() {
    diverSprite = new CSimpleSprite(".\\TestData\\main_diver.png", 4, 4);
    diverX = 400.0f;
    diverY = 400.0f;
    float initialX = APP_VIRTUAL_WIDTH / 2.0f;
    float initialY = APP_VIRTUAL_HEIGHT / 5.0f;

    health = 3;
    speed = 1.0f/6.0f; //et the default speed value (adjust as needed)
    //depth = 0.0f;
        
    // Set the initial position to the top of the page
    diverSprite->SetPosition(initialX, initialY);

    // Set the initial scale during initialization (adjust the value as needed)
    diverSprite->SetScale(1.0f);

    // Create animations during initialization
    CreateAnimations(speed);

    // Set the default animation (forwards)
   // diverSprite->SetAnimation(ANIM_FORWARDS);

    isPlaying = true;
    isDead = false;
}

Diver::~Diver() {
    delete diverSprite;
}

void Diver::Update(float deltaTime) {
   

    diverSprite->Update(deltaTime);

    
    //if (App::GetController().GetLeftThumbStickY() > 0.5f) {
      //  depth += 1.0f * deltaTime; // Increase depth when diving down
    //}
    //else if (App::GetController().GetLeftThumbStickY() < -0.5f && depth > 0.0f) {
    //   depth -= 1.0f * deltaTime; // Decrease depth when going up, but prevent going below 0
  //  }

    // Handle player input for movement and animation
    HandleInput(deltaTime);
    CheckScreenCollision();
}

void Diver::Draw(float deltaTime) {
    float x, y;
    diverSprite->GetPosition(x, y);
    diverSprite->SetPosition(x, y - 1.0f);

    diverSprite->Draw();
    // TODO: add health display logic here if needed
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

    if (health <= 0) {
        isDead = true;
    }
}

void Diver::CreateAnimations(float speed) {
    // Create animations for the diver sprite
    diverSprite->CreateAnimation(ANIM_BACKWARDS, speed, { 0, 1, 2, 3 });
    diverSprite->CreateAnimation(ANIM_LEFT, speed, { 4, 5, 6, 7 });
    diverSprite->CreateAnimation(ANIM_RIGHT, speed, { 8, 9, 10, 11 });
    diverSprite->CreateAnimation(ANIM_FORWARDS, speed, {12, 13, 14, 15 });
}

void Diver::HandleInput(float deltaTime) {
    if (App::GetController().GetLeftThumbStickX() > 0.5f) {
        diverSprite->SetAnimation(ANIM_RIGHT);
        float x, y;
        diverSprite->GetPosition(x, y);
        // x += speed * deltaTime; // Adjust for deltaTime
        x += 2.0f;
        diverSprite->SetPosition(x, y);
    }
    else if (App::GetController().GetLeftThumbStickX() < -0.5f) {
        diverSprite->SetAnimation(ANIM_LEFT);
        float x, y;
        diverSprite->GetPosition(x, y);
        // x -= speed * deltaTime; // Adjust for deltaTime
        x -= 2.0f;
        diverSprite->SetPosition(x, y);
    }
    else if (App::GetController().GetLeftThumbStickY() > 0.5f) {
        diverSprite->SetAnimation(ANIM_FORWARDS);
        float x, y;
        diverSprite->GetPosition(x, y);
        //y += speed * deltaTime; // Adjust for deltaTime
        y += 1.75f;
        diverSprite->SetPosition(x, y);
        //depth++;
    }
    else if (App::GetController().GetLeftThumbStickY() < -0.5f) {
        diverSprite->SetAnimation(ANIM_BACKWARDS);
        float x, y;
        diverSprite->GetPosition(x, y);
        // y -= speed * deltaTime; // Adjust for deltaTime
        y -= 1.75f;
        diverSprite->SetPosition(x, y);
        //depth--;

    }

}
  


void Diver::SetSpeed(float newSpeed) {
    speed = newSpeed;
}

float Diver::GetSpeed() const {
    return speed;
}



//void Diver::SetDepth(float d) {
  //  depth = d;
//}

float Diver::GetDepth() const {
    return depth;
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

    if (diverY <= 10) {
        RepositionOnScreenCollision();
    }
}



void Diver::RepositionOnScreenCollision() {
    // Subtract one life (add your life management logic here)
    TakeDamage();

    if (isDead == false) {

    }
    // Reposition the diver to the middle of the screen
    float middleX = (APP_VIRTUAL_WIDTH - diverSprite->GetWidth()) / 2.0f;
    float middleY = (APP_VIRTUAL_HEIGHT - diverSprite->GetHeight()) / 2.0f;
    diverSprite->SetPosition(middleX, middleY);
}


bool Diver::IsPlaying() const {
    return isPlaying;
}

bool Diver::IsDead() const {
    return isDead;
}
