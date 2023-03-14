#pragma once

#include "Vector2D.h"
#include "SDL.h"
const int screenWidth = 32 * 32;
const int screenHeight = 19 * 32;
class Camera
{
public:
    Camera() {
        viewBox = { 0 , 0 , screenWidth , screenHeight };
    }
    static Camera* instance;
    static Camera* getInstance()
    {
        return instance = (instance != nullptr) ? instance : new Camera();
    }
    Vector2D* point;
    Vector2D  pos;
    SDL_Rect viewBox;

    SDL_Rect getVIewBox()
    {
        return viewBox;
    }

    Vector2D* getPoint()
    {
        return point;
    }

    Vector2D getPos()
    {
        return pos;
    }
      
    void setPoint(Vector2D* _point)
    {
        point = _point; 
    }

    void update(float dt)
    {
        // đặt tọa độ của "box" điểm nhìn 
        viewBox.x = point->x - screenWidth / 2; // từ trung tâm trừ đi độ dài màn hình / 2
        viewBox.y = point->y - screenHeight / 2; //  từ trung tâm trừ đi độ cao màn hình / 2
        // Nếu nhỏ hơn 0 chứng tỏ đã đến giới hạn của map, không cuộn camera nữa
        if (viewBox.x < 0)
        {
            viewBox.x = 0;
        }
        if (viewBox.y < 0)
        {
            viewBox.y = 0;
        }
        // Tương tự, đã đến giới hạn map thì không cuộn camera nữa
        if (viewBox.x > ( 32*128 - viewBox.w))
        {
            viewBox.x = 32 * 128  - viewBox.w;
        }
        if (viewBox.y > (2 * screenHeight - viewBox.h))
        {
            viewBox.y = (2 * screenHeight - viewBox.h);
        }

        // Đặt tọa độ pos điểm nhìn
        pos = Vector2D(viewBox.x, viewBox.y);
    }

};

