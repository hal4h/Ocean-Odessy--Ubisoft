#pragma once

#ifndef DIVER_H
#define DIVER_H

#include "app/AppSettings.h"
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

    void Update(float deltaTime, std::vector<CSimpleSprite*> obstacles, CSimpleSprite* chest);
    void Draw(); // Added method to set depth
    void SetAngle(float a);
    void SetScale(float s);
    void SetColor(float r, float g, float b);
    void GetPosition(float& x, float& y);
    void CheckScreenCollision();

    //  void Diver::SetDepth(float d) {

    void SetPosition(float x, float y);


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
    const int MAX_HEALTH = 3;
    int health;
    float animSpeed; // Speed variable
    float swimSpeed;
    void RepositionOnScreenCollision();

    bool isPlaying;
    bool isDead;

    bool Intersects(CSimpleSprite* obstacle);
    bool IsColliding(std::vector<CSimpleSprite*> obstacles);

    // vector of 3 hearts
    void DrawHearts();
    bool GameWon(CSimpleSprite* chest);

    void deleteObjects(std::vector<CSimpleSprite*> visibleObjects);

};

#endif // DIVER_H