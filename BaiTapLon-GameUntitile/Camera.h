//#pragma once
//#include "Engine.h"
//#include "Vector2D.h"
//#include "SDL.h"
//int _SCREEN_WIDTH = 32 * 32;
//int _SCREEN_HEIGHT = 19 * 32;
//class Camera
//{
//public:
//    Camera() {
//        viewBox = { 0 , 0 , _SCREEN_WIDTH , _SCREEN_HEIGHT };
//    }
//    static Camera* instance;
//    static Camera* getInstance()
//    {
//        return instance = (instance != nullptr) ? instance : new Camera();
//    }
//    Vector2D* point;
//    Vector2D  pos;
//    SDL_Rect viewBox;
//
//    SDL_Rect getVIewBox()
//    {
//        return viewBox;
//    }
//
//    Vector2D* getPoint()
//    {
//        return point;
//    }
//
//    Vector2D getPos()
//    {
//        return pos;
//    }
//      
//    void setPoint(Vector2D* _point)
//    {
//        point = _point; 
//    }
//
//    void update(float dt)
//    {
//        viewBox.x = point->x - _SCREEN_WIDTH / 2;
//        viewBox.y = point->y - _SCREEN_HEIGHT / 2;
//        if (viewBox.x < 0)
//        {
//            viewBox.x = 0;
//        }
//        if (viewBox.y < 0)
//        {
//            viewBox.y = 0;
//        }
//        if (viewBox.x > (2 * _SCREEN_WIDTH - viewBox.w))
//        {
//            viewBox.x = 2 * _SCREEN_WIDTH - viewBox.w;
//        }
//        if (viewBox.y > (2 * _SCREEN_HEIGHT - viewBox.h))
//        {
//            viewBox.y = (2 * _SCREEN_HEIGHT - viewBox.h);
//        }
//
//        pos = Vector2D(viewBox.x, viewBox.y);
//    }
//
//};
//
