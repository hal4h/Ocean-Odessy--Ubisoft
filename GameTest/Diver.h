#pragma once

#ifndef DIVER_H
#define DIVER_H

#include "app/app.h"

class Diver {
public:
    Diver();
    ~Diver();

    void Update(float deltaTime);
    void Draw();
    void SetPosition(float x, float y);
    void SetAngle(float a);
    void SetScale(float s);
    void SetColor(float r, float g, float b);
    void GetPosition(float& x, float& y);

    // Health-related methods
    void SetHealth(int health);
    int GetHealth() const;
    void TakeDamage(int damage);

    // Animation-related methods
    void CreateAnimations(float speed);
    void HandleInput(float deltaTime);

    // Speed-related methods
    void SetSpeed(float speed);
    float GetSpeed() const;

private:
    CSimpleSprite* diverSprite;
    float diverX, diverY;
    int health;
    float speed; // Speed variable
};

#endif // DIVER_H
