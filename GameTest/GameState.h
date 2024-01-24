
// Map.h
#pragma once

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "app/AppSettings.h"
#include "app/app.h"

class GameState {
public:
	GameState();
	~GameState();

	void Update(float deltaTime);
	void Render();

	void SetGameStarted(bool gameStarted);
	bool IsGameStarted() const;
	void SetGameOver(bool gameOver);
	bool IsGameOver() const;
	void SetGameWon(bool gameWon);
	bool IsGameWon() const;
	void SetGamePaused(bool gamePaused);
	bool IsGamePaused() const;

	bool IsGameReset() const;
private:
	CSimpleSprite* gameStartSprite;
	CSimpleSprite* pausedSprite;
	CSimpleSprite* gameOverSprite;
	CSimpleSprite* gameWonSprite;

	bool gameStarted;
	bool gameOver;
	bool gameWon;
	bool gamePaused;
	bool gameReset;

	void DisplayGameMenu();
	void DisplayPaused();
	void DisplayGameOver();
	void DisplayGameWon();
};



#endif