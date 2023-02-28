#include "Input.h"
Input* Input::_intance = nullptr;
Input::Input()
{
    _keyStates = SDL_GetKeyboardState(nullptr);
}

void Input::listen()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_QUIT: 
            Game::GetInstance()->quit();
            break;
        case SDL_KEYDOWN: keyDown();
            break;
        case SDL_KEYUP: keyUp();
        default:
            break;
        }
    }
}

bool Input::getKeyDown(SDL_Scancode key)
{
    return (_keyStates[key] == 1);
}

void Input::keyUp()
{
    _keyStates = SDL_GetKeyboardState(nullptr);
}

void Input::keyDown()
{
    _keyStates = SDL_GetKeyboardState(nullptr);
}
