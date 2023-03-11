#pragma once
#include "SDL.h"
#include "Engine.h"
#include "Game.h"
class Input 
{
public: Input();
       static Input* _intance;
       const Uint8* _keyStates;
       SDL_Event e;
       static Input* getInstance()
       {
           return _intance = (_intance != nullptr) ? _intance : new Input();
       }
       void listen();
       bool getKeyDown(SDL_Scancode key);
       void keyUp();
       void keyDown();

};

