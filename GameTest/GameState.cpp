#include "stdafx.h"
#include "app\app.h"

#include "GameState.h" // Include the header file for GameState if not already included

GameState::GameState()
{
	gameStartSprite = new CSimpleSprite(".\\TestData\\game-menu.png", 1, 1);
	pausedSprite = new CSimpleSprite(".\\TestData\\paused.png", 1, 1);
	gameOverSprite = new CSimpleSprite(".\\TestData\\game-over.png", 1, 1);
	gameWonSprite = new CSimpleSprite(".\\TestData\\game-won.png", 1, 1);

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
	// check if game isnt started, space top start
	// p to pause game 
	// Implement game state updates here
	// For example, check if the game is over, display appropriate screens, etc.
	if (!gameStarted && App::GetController().CheckButton(XINPUT_GAMEPAD_START, true)) {
		gameStarted = true; // Start game if user hits space
	}
	
	//if game started and p is pressed, set game paused
	if (gameStarted && !gamePaused && !gameWon && !gameOver && App::GetController().CheckButton(XINPUT_GAMEPAD_A, true)) {
		gamePaused = true;

	}
	else if (gameStarted && gamePaused && !gameWon && !gameOver && App::GetController().CheckButton(XINPUT_GAMEPAD_A, true)) {
		gamePaused = false; 	// if game is started, paused, and p is pressed, set paused to false
	}

	// if user wants to restart game, 
	if ((gameOver || gameWon) && (App::IsKeyPressed('R'))) {
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

void GameState::DisplayGameMenu()
{
	// Implement logic to display the game menu
	// For example, draw the game menu sprite
	gameStartSprite->SetPosition(APP_VIRTUAL_WIDTH / 2.0f, APP_VIRTUAL_HEIGHT / 2.0f);
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
	pausedSprite->SetScale(0.6f);
	gameOverSprite->Draw();

}

void GameState::DisplayGameWon()
{
		gameWonSprite->SetPosition(APP_VIRTUAL_WIDTH / 2.0f, APP_VIRTUAL_HEIGHT / 2.0f);
		gameWonSprite->Draw();

}

