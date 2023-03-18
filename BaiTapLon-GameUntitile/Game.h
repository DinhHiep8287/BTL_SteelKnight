#pragma once
using namespace std;
#include "Character.h"
class Game
{           
public:     
              static Game* _instance;
              SDL_Window* window;
              SDL_Renderer* renderer;
              bool _isRunning = true;
              static Game* GetInstance() {
                return _instance = (_instance != nullptr) ? _instance : new Game ;
            }
      bool isRunning() { return _isRunning; }
      void init();
      void quit();
      void update();
      void render();
      void event();
      void cleanSDL();

};

