#include "stdafx.h"
#include "app\app.h"

#include "Diver.h"



#include "Diver.h"

Diver::Diver() {
    diverSprite = new CSimpleSprite(".\\TestData\\main_diver.png", 4, 4);
    diverX = 400.0f;
    diverY = 400.0f;
    health = 3;
    speed = 1.0f/15.0f; // Set the default speed value (adjust as needed)
    depth = 0.0f;

    // Set the initial position to the top of the page
    diverSprite->SetPosition(diverX, diverY);

    // Set the initial scale during initialization (adjust the value as needed)
    diverSprite->SetScale(1.0f);

    // Create animations during initialization
    CreateAnimations(speed);

    // Set the default animation (forwards)
   // diverSprite->SetAnimation(ANIM_FORWARDS);
}

Diver::~Diver() {
    delete diverSprite;
}

void Diver::Update(float deltaTime) {
    diverSprite->Update(deltaTime);

    if (App::GetController().GetLeftThumbStickY() > 0.5f) {
        depth += 1.0f * deltaTime; // Increase depth when diving down
    }
    else if (App::GetController().GetLeftThumbStickY() < -0.5f && depth > 0.0f) {
        depth -= 1.0f * deltaTime; // Decrease depth when going up, but prevent going below 0
    }
    // Add any specific update logic for the diver here if needed

    // Handle player input for movement and animation
    HandleInput(deltaTime);
}

void Diver::Draw() {
    diverSprite->Draw();
    // You can add health display logic here if needed
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

void Diver::TakeDamage(int damage) {
    health -= damage;
    // Add logic here for what happens when the player takes damage
    // For example, you can check if the player's health reaches zero and handle it accordingly
}

void Diver::CreateAnimations(float speed) {
    // Create animations for the diver sprite
    diverSprite->CreateAnimation(ANIM_FORWARDS, speed, { 0, 1, 2, 3, 4 });
    diverSprite->CreateAnimation(ANIM_BACKWARDS, speed, { 5, 6, 7, 8 });
    diverSprite->CreateAnimation(ANIM_LEFT, speed, { 9, 10, 11, 12 });
    diverSprite->CreateAnimation(ANIM_RIGHT, speed, { 13, 14, 15, 16 });
    // Add more animations as needed
}

void Diver::HandleInput(float deltaTime) {
    if (App::GetController().GetLeftThumbStickX() > 0.5f) {
        diverSprite->SetAnimation(ANIM_RIGHT);
        float x, y;
        diverSprite->GetPosition(x, y);
       // x += speed * deltaTime; // Adjust for deltaTime
        x += 1.0f;
        diverSprite->SetPosition(x, y);
    }
    else if (App::GetController().GetLeftThumbStickX() < -0.5f) {
        diverSprite->SetAnimation(ANIM_LEFT);
        float x, y;
        diverSprite->GetPosition(x, y);
       // x -= speed * deltaTime; // Adjust for deltaTime
        x -= 1.0f;
        diverSprite->SetPosition(x, y);
    }
    else if (App::GetController().GetLeftThumbStickY() > 0.5f) {
        diverSprite->SetAnimation(ANIM_FORWARDS);
        float x, y;
        diverSprite->GetPosition(x, y);
        //y += speed * deltaTime; // Adjust for deltaTime
        y += 1.0f;
        diverSprite->SetPosition(x, y);
    }
    else if (App::GetController().GetLeftThumbStickY() < -0.5f) {
        diverSprite->SetAnimation(ANIM_BACKWARDS);
        float x, y;
        diverSprite->GetPosition(x, y);
       // y -= speed * deltaTime; // Adjust for deltaTime
        y -= 1.0f;
        diverSprite->SetPosition(x, y);
    }
}

void Diver::SetSpeed(float newSpeed) {
    speed = newSpeed;
}

float Diver::GetSpeed() const {
    return speed;
}



void Diver::SetDepth(float d) {
    depth = d;
}

float Diver::GetDepth() const {
    return depth;
}