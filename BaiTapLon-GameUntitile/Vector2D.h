#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include <string.h>
#include <ctime> 
#include <cstdlib> 
#include <random>
using namespace std;
// class chứa tọa độ của 1 object
class Vector2D
{
public: float x; float y; 
    Vector2D()
    {
        x = 0; y = 0; 
    }
    Vector2D(float _x, float _y)
    {
        x = _x;
        y = _y;
    }
    // cộng vector 
    
    Vector2D operator+(const Vector2D& v2)
    {
        Vector2D res;
        res.x = x + v2.x; 
        res.y = y + v2.y; 
        return res;
    }
    // trừ vector
    Vector2D operator-(const Vector2D& v2)
    {
        Vector2D res;
        res.x = x - v2.x;
        res.y = y - v2.y;
        return res;
    }
    // nhân vector
    Vector2D operator*(const Vector2D& v2)
    {
        Vector2D res;
        res.x = x * v2.x;
        res.y = y * v2.y;
        return res;
    }
    void print(string theObject)
    {
        cout << theObject << " ( " << x << " " << y << " )" << endl;
    }
};

