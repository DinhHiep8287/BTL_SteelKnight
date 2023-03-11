#pragma once
#include "Vector2D.h"
#define MASS 1
#define GRAVITY 9.8f 


class Body
{
public: float _mass, _gravity;
      Vector2D _force = Vector2D(0, 0), _friction = Vector2D(0, 0), _position = Vector2D(0, 0), _v, _a ;
    Body()
    {
        _mass = MASS;
        _gravity = GRAVITY;
    }
    // MASS + GRAVITY
    inline void setMass(float mass) { _mass = mass; } 
    inline void setGra(float gra) { _gravity = gra; }
    // FORCE
    inline void setForce(Vector2D F) { _force = F; }
    inline void setForceX(float Fx) { _force.x = Fx; }
    inline void setForceY(float Fy) { _force.y = Fy; }
    inline void unSetForce() { _force = Vector2D(0, 0); }
    // FRICTION
    inline void setFriction(Vector2D F) { _friction = F; }
    inline void UnSetFriction() { _friction = Vector2D(0, 0); }
    
    // Get

    float getMass() { return _mass; }
    Vector2D getPosition() { return _position; }
    Vector2D get_a() { return _a; }
    Vector2D get_v() { return _v; }

    // Update
    void Update(float dt)
    {
        _a.x = (_force.x + _friction.x) / _mass;
        _a.y = _gravity + _force.y / _mass;
        _v = _a * dt;
        _position = _v * dt;
    }


};

