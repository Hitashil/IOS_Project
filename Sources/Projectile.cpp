//
//  Projectile.cpp
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-04-02.
//
//

#include "Projectile.h"

Projectile::Projectile() : Entity()
{
    go = false;
    originalRect = rect;
}

Projectile::Projectile(const char *name, int x, int y,  SDL_Renderer *renderer) : Entity(name, x, y, renderer)
{
    go = false;
    originalRect = rect;
}

Projectile::Projectile(const char *name, SDL_Rect rect,  SDL_Renderer *renderer) : Entity(name ,rect, renderer)
{
    go = false;
    originalRect = rect;
}

void Projectile::collision(int x, int y)
{
    if (go && (rect.y + rect.h) <= 0)
    {
        go = false;
        rect.x = originalRect.x;
        rect.y = originalRect.y;
    }
}

void Projectile::moveProjec()
{
    if (go)
    {
        rect.y -= 5;
    }
}