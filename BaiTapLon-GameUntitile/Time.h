#pragma once
const float FPS = 60;
const float DELTATIME = 1.0f;
class Time
{
public: static Time* _intance;
       float _dt;
       float _lastTime;

       inline static Time* getIntance()
       {
           return _intance = (_intance != nullptr) ? _intance : new Time();
       }

       void Tick();

       float getDeltaTime() { return _dt; }

};

