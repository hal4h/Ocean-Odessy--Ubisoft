#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include "app\app.h"

class HomeScreen {
public:
    HomeScreen();
    ~HomeScreen();

    void Update(float deltaTime);
    void Render();
    bool IsGameStarted() const;

private:
    CSimpleSprite* homeScreenSprite;
    bool gameStarted;
};

#endif // HOMESCREEN_H
