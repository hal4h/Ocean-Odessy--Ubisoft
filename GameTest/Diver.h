#pragma once

#ifndef DIVER_H
#define DIVER_H

#include "app/AppSettings.h";
#include "app/app.h"

class Diver {
public:


    enum
    {
        ANIM_FORWARDS,
        ANIM_BACKWARDS,
        ANIM_LEFT,
        ANIM_RIGHT,
    };

    Diver();
    ~Diver();

    void Update(float deltaTime);
    void Draw();
    void SetPosition(float x, float y);
    void SetDepth(float d); // Added method to set depth
    float GetDepth() const;  // Added method to get depth
    void SetAngle(float a);
    void SetScale(float s);
    void SetColor(float r, float g, float b);
    void GetPosition(float& x, float& y);
    void CheckScreenCollision();


    // Health-related methods
    void SetHealth(int health);
    int GetHealth() const;
    void TakeDamage();

    // Animation-related methods
    void CreateAnimations(float speed);
    void HandleInput(float deltaTime);

    // Speed-related methods
    void SetSpeed(float speed);
    float GetSpeed() const;

    bool IsPlaying() const; // New method
    bool IsDead() const;    // New method

   
private:
    CSimpleSprite* diverSprite;
    float diverX, diverY;
    float depth; // Added depth variable
    int health;
    float speed; // Speed variable

    void RepositionOnScreenCollision();

    bool isPlaying;
    bool isDead;

};

#endif // DIVER_H
