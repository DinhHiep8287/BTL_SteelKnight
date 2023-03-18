#pragma once
#include <iostream>
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
    
    inline Vector2D operator+(const Vector2D& v2)
    {
        Vector2D res;
        res.x = x + v2.x; 
        res.y = y + v2.y; 
        return res;
    }
    // trừ vector
    inline Vector2D operator-(const Vector2D& v2)
    {
        Vector2D res;
        res.x = x - v2.x;
        res.y = y - v2.y;
        return res;
    }
    // nhân vector
    inline Vector2D operator*(const float c)
    {
        Vector2D res;
        res.x = x * c;
        res.y = y * c;
        return res;
    }
    void print(string theObject)
    {
        cout << theObject << " ( " << x << " " << y << " )" << endl;
    }
};

