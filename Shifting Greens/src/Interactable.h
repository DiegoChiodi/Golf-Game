#pragma once 

#include "Square.h"

class Interactable : public Square {
protected:
    float wInteract, hInteract; // Position of the interaction
public:
    Interactable(float x, float y, float width, float height, SDL_Color color,
         float wInteract, float hInteract);

    virtual void InteractAction() = 0;

    virtual float GetInteractW() const { return wInteract; }
    virtual float GetInteractH() const { return hInteract; }
    inline virtual point GetPositionColliser() const { 
        return { (position.x - (wInteract / 2) + (width / 2)), (position.y - (hInteract / 2) + (height / 2)) }; 
    }
    void RenderCollisor(SDL_Renderer* renderer, const SDL_Rect& camera);
};
