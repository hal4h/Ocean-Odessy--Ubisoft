#include "stdafx.h"
#include "app\app.h"

#include "GameState.h" // Include the header file for GameState

GameState::GameState()
{
	gameStartSprite = new CSimpleSprite(".\\Assests\\game-menu.png", 9, 1);
	gameStartSprite->CreateAnimation(0, 1.0f / 6.0f, { 0,1,2,3,4,5,6,7,8 });

	pausedSprite = new CSimpleSprite(".\\Assests\\paused.png", 1, 1);
	gameOverSprite = new CSimpleSprite(".\\Assests\\game-over.png", 1, 1);
	gameWonSprite = new CSimpleSprite(".\\Assests\\game-won.png", 1, 1);

	// Initialize other member variables
	gameStarted = false;
	gameOver = false;
	gameWon = false;
	gamePaused = false;
	gameReset = false;
}

GameState::~GameState()
{
	// Release resources in the destructor
	delete gameStartSprite;
	delete pausedSprite;
	delete gameOverSprite;
	delete gameWonSprite;
}

void GameState::Update(float deltaTime)
{
	gameStartSprite->Update(deltaTime);
	// check if game isnt started, space to start
	if (!gameStarted && App::GetController().CheckButton(XINPUT_GAMEPAD_START, true)) {
		gameStarted = true; // Start game if user hits space
		gameReset = false;
	}

	//if game started and sapce is pressed, set game paused
	if (gameStarted && !gamePaused && !gameWon && !gameOver && App::GetController().CheckButton(XINPUT_GAMEPAD_A, true)) {
		gamePaused = true;

	}
	else if (gameStarted && gamePaused && !gameWon && !gameOver && App::GetController().CheckButton(XINPUT_GAMEPAD_A, true)) {
		gamePaused = false; 	// if game is started, paused, and pause is pressed, set paused to false
	}

	// if user wants to restart game, 
	if ((App::IsKeyPressed('R'))) {
		gameReset = true;
		gameStarted = false;
		gameOver = false;
		gameWon = false;
		gamePaused = false;
	}
}

void GameState::Render()
{
	// Implement rendering logic here
	if (gameStarted) {
		if (gameOver) {
			DisplayGameOver();
			//draw text on the screen, press to restart
		}
		else if (gamePaused) {
			DisplayPaused();
			//draw text on the screen, press space to resume 
		}
		else if (gameWon) {
			DisplayGameWon();
		}

		// game continues as usual
	}
	else {
		// Render game menu or other screens
		DisplayGameMenu();
	}
}

void GameState::SetGameStarted(bool gameStarted)
{
	this->gameStarted = gameStarted;
}

bool GameState::IsGameStarted() const
{
	return gameStarted;
}

void GameState::SetGameOver(bool gameOver)
{
	this->gameOver = gameOver;
}

bool GameState::IsGameOver() const
{
	return gameOver;
}

void GameState::SetGameWon(bool gameWon)
{
	this->gameWon = gameWon;
}

bool GameState::IsGameWon() const
{
	return gameWon;
}

void GameState::SetGamePaused(bool gamePaused)
{
	this->gamePaused = gamePaused;
}

bool GameState::IsGamePaused() const
{
	return gamePaused;
}

bool GameState::IsGameReset() const {
	return gameReset;
}

void GameState::DisplayGameMenu()
{
	// Implement logic to display the game menu
	// For example, draw the game menu sprite
	gameStartSprite->SetPosition(APP_VIRTUAL_WIDTH / 2.0f, APP_VIRTUAL_HEIGHT / 2.0f);
	gameStartSprite->SetAnimation(0);
	gameStartSprite->SetScale(0.8);
	gameStartSprite->Draw();
}

void GameState::DisplayPaused()
{
	pausedSprite->SetPosition(APP_VIRTUAL_WIDTH / 2.0f, APP_VIRTUAL_HEIGHT / 2.0f);
	pausedSprite->SetScale(0.2f);
	pausedSprite->Draw();

}

void GameState::DisplayGameOver()
{
	// Implement logic to display the game over screen
	gameOverSprite->SetPosition(APP_VIRTUAL_WIDTH / 2.0f, APP_VIRTUAL_HEIGHT / 2.0f);
	gameOverSprite->SetScale(0.6f);
	gameOverSprite->Draw();

}

void GameState::DisplayGameWon()
{
	gameWonSprite->SetPosition(APP_VIRTUAL_WIDTH / 2.0f, APP_VIRTUAL_HEIGHT / 2.0f);
	gameWonSprite->SetScale(1.0f);
	gameWonSprite->Draw();

}

