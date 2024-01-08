#include "stdafx.h"
#include "app/app.h"

#include "HomeScreen.h"

HomeScreen::HomeScreen() {
    // Load home screen sprite or any other initialization
    homeScreenSprite = new CSimpleSprite(".\\TestData\\home-screen.png", 1, 1); 
    homeScreenSprite->SetPosition(APP_VIRTUAL_WIDTH / 2.0f, APP_VIRTUAL_HEIGHT / 2.0f);
    //(sandlayer->GetWidth() / 2.0f, sandlayer->GetHeight() / 2.0f
    gameStarted = false;
}

HomeScreen::~HomeScreen() {
    // Cleanup resources
    delete homeScreenSprite;
}

void HomeScreen::Update(float deltaTime) {
    // if user presses space
    if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true)) {
        gameStarted = true;
    }
}

void HomeScreen::Render() {
    // Render the home screen
    homeScreenSprite->Draw();
}

bool HomeScreen::IsGameStarted() const {
    return gameStarted;
}
