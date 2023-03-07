#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
using namespace std;
#include "Engine.h"
#include "Input.h"
#include "Knight.h"
#include "TileLayer.hpp"
class Game
{           
public:     Game() {}
              static Game* _instance;
              SDL_Window* window;
              SDL_Renderer* renderer;
              bool _isRunning = true;
              static Game* GetInstance() {
                return _instance = (_instance != nullptr) ? _instance : new Game();
            }
      bool isRunning() { return _isRunning; }
      void init();
      void quit();
      void update();
      void render();
      void event();
      void cleanSDL();

};

