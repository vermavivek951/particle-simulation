#pragma once
#include <SDL2/SDL.h>
#include "Color.h"

class Particle  {
    public:
        float x , y;
        float vx , vy;
        float ax , ay;
        float lifespan;
        float age = 0.0f;

        Color color;

        Particle(float x_init , float y_init , Color color_init, float vx_init = 0.0f , float vy_init = 0.0f )
                : x(x_init) , y(y_init) , color(color_init) , vx(vx_init) , vy(vy_init) , ax(0) , ay(0), lifespan(5.0f){} //5 seconds

        void update(float dt) {
            vx = vx + ax * dt;
            vy = vy + ay * dt;

            x = x + vx * dt;
            y = y + vy * dt;
            
            age = age + dt;
            color.alpha = static_cast<Uint8>(255 * (1.0f - age / lifespan)); //TODO

            //reset acceleration after update(forces need to be applied each frame)
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
            if(x >= screenWidth) {
                x = screenWidth;
                vx = -vx * damping;
            }
            else if(x <= 0) {
                x = 0;
                vx = -vx * damping;
            }

            if(y >= screenHeight) {
                y = screenHeight;
                vy = -vy * damping;
            }

            else if( y <= 0) {
                y = 0;
                vy = -vy * damping;
            }
        }
};