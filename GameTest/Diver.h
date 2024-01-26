#pragma once

#ifndef DIVER_H
#define DIVER_H

#include "app/AppSettings.h"
#include "Map.h"
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

	void Update(float deltaTime, std::vector<CSimpleSprite*> obstacles, int speed, CSimpleSprite* chest);
	void Draw(); // Added method to set depth
	void SetColor(float r, float g, float b);
	void GetPosition(float& x, float& y);

	//  void Diver::SetDepth(float d) {

	void SetPosition(float x, float y);



	// Speed-related methods
	void SetSpeed(float speed);
	float GetSpeed() const;

	bool IsDead() const;
	void IsPlaying(bool value);

	bool IsWon() const;

	void setGameWon(bool value);

	bool GameWon(CSimpleSprite* chest);

private:
	CSimpleSprite* chest;
	CSimpleSprite* diverSprite;
	float diverX, diverY;
	float depth; // Added depth variable
	const int MAX_HEALTH = 3;
	int health;
	float animSpeed; // Speed variable
	float swimSpeed;
	void RepositionOnScreenCollision();

	bool isDead;
	bool isPlaying;
	bool won;
	bool Intersects(CSimpleSprite* obstacle);
	bool IsColliding(std::vector<CSimpleSprite*> obstacles);
	void CheckScreenCollision();


	// Health-related methods
	void SetHealth(int health);
	int GetHealth() const;
	void TakeDamage();

	// Animation-related methods
	void CreateAnimations(float speed);
	void HandleInput(float deltaTime);
	// vector of 3 hearts
	void DrawHearts();


	int speeed;

	bool cooldown = false;  // Add a cooldown flag
	int cooldownDuration = 3 * 60;  // 3 seconds cooldown (assuming 60 frames per second)
};

#endif // DIVER_H
