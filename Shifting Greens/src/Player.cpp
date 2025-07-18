#include "Player.h"
#include <iostream>

Player::Player(float x, float y, float width, float height, SDL_Color color, vector speed, SDL_Texture* textureUpright, SDL_Texture* textureSprinting)
    : Movel(x, y, width, height, color, speed), textureUpright(textureUpright), textureSprinting(textureSprinting), delayAnimate(0.0f) {
        actualTexture = textureUpright;
        currentDirection = Direction::RIGHT;
        movingState = MovingState::IDLE_CENTRAL;    
    }

void Player::Run(const float& dt, const Uint8* stat, SDL_Renderer* renderer, const SDL_Rect& camera) {
    Movel::Run(dt, stat, renderer, camera);
    Animated(dt);
} 

void Player::Animated(const float& dt) {
    if (this->movingState == MovingState::SPRINTING) {

        if (animate)
        {
            actualTexture = this->textureSprinting;
        } else {
            actualTexture = this->textureUpright;
        }

        if (delayAnimate > 0.5f)
        {
            delayAnimate = 0.0f;
            animate = !animate;
        }
        delayAnimate += 0.05f;
    } else {
        this->actualTexture = this->textureUpright;
        delayAnimate = 0.0f;
    }
}

void Player::Render(SDL_Renderer* renderer, const SDL_Rect& camera) {
    
    SDL_Rect renderRect;
    renderRect.x = this->rect.x - camera.x;
    renderRect.y = this->rect.y - camera.y;
    renderRect.w = this->rect.w;
    renderRect.h = this->rect.h;

    if (this->currentDirection == Direction::LEFT && movingState == MovingState::SPRINTING) {
        this->flip = SDL_FLIP_HORIZONTAL;
    } else if (this->currentDirection == Direction::RIGHT && movingState == MovingState::SPRINTING) {
        this->flip = SDL_FLIP_NONE;
    }
    
    SDL_RenderCopyEx(renderer, actualTexture, nullptr, &renderRect, 0.0, nullptr, flip);
}