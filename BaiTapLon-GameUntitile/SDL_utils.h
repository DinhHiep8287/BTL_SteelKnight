#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include <string.h>
using namespace std;

void logSDLError(std::ostream& os,
    const std::string& msg, bool fatal = false);

void initSDL(SDL_Window*& window, SDL_Renderer*& renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();
