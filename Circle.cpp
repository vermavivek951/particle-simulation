#pragma once
#include <SDL2/SDL.h>
#include <cmath>
#include "Color.h"

class Circle {
    public:
        int cent_x , cent_y;
        int radius;

        float ax , ay;
        float vx , vy;

        float lifespan;
        float age = 0.0f;
        
        Color color;

    Circle(int cent_x_init , int cent_y_init , int radius_init , Color color_init , float vx_init = 0.0f , float vy_init = 0.0f) 
    : cent_x(cent_x_init), cent_y(cent_y_init) , radius(radius_init) , color(color_init) ,vx(vx_init) , vy(vy_init), ax(0.0f) , ay(0.0f) , lifespan(5.0f) {} //5 seconds;


    void update(float dt) {
        vx = vx + ax * dt;
        vy = vy + ay * dt;

        cent_x = cent_x + static_cast<int>(vx * dt);
        cent_y = cent_y + static_cast<int>(vy * dt);

        age = age + dt;
        color.alpha = static_cast<Uint8>(255 * (1.0f - age / lifespan));

        ax = 0;
        ay = 0;
    }

    bool isDead() const {
        return age >= lifespan;
    }

    void applyForce(float fx , float fy) {
        ax = ax + fx;
        ay = ay + fy;
    }

    void handleCollision(int screenWidth , int screenHeight , float damping = 0.8f) {
        if(cent_x >= screenHeight) {
            cent_x = screenHeight;
            vx = -vx * damping;
        }
        else if(cent_x <= 0) {
            cent_x = 0;
            vx = -vx * damping;
        }

        if(cent_y >= screenHeight) {
            cent_y = screenHeight;
            vy = -vy * damping;
        }
        else if(cent_y <= 0) {
            cent_y = 0;
            vy = -vy * damping;
        }
    }
};


void DrawFilledCircle(SDL_Renderer *renderer , int cent_x , int cent_y , int radius) {
    for(int y = -radius; y <= radius ; y++) {
        int dx = static_cast<int>(sqrt(radius * radius - y * y));
        SDL_RenderDrawLine(renderer,
                        cent_x - dx , cent_y + y,
                    cent_x + dx , cent_y + y);
    }
}