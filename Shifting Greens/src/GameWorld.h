#pragma once

#include <iostream>

#include "Ball.h"
#include "Player.h"
#include <memory>
#include <list>
#include "TextureManager.h"

class GameWorld {
private:
    SDL_Renderer* renderer;
    Player* player;
    std::list<std::unique_ptr<GameObject>> objects;
    const float interactDelay = 0.75f; // Tempo de espera para interação
    float interactTimer = 0.0f; // Temporizador de interação
    TextureManager* textureManager;

public:
    GameWorld(SDL_Renderer* renderer, TextureManager* textureManager);
    ~GameWorld();

    void Run(const float& dt, const Uint8* stat);
    bool InteractAction(const Uint8* stat);
};