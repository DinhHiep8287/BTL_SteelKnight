#include "Time.h"
#include "SDL.h"
Time* Time::_intance = nullptr;
void Time::Tick()
{
    _dt = (SDL_GetTicks() - _lastTime) * (FPS / 1000.0f);
    if (_dt > DELTATIME)
    {
        _dt = DELTATIME;
        _lastTime = SDL_GetTicks();
    }

}
