#pragma once
using namespace std;
#include "Character.h"
#include "Text.h"
#include "SDL_mixer.h"
class Game
{           
public:     
              static Game* _instance;
              SDL_Window* window;
              SDL_Renderer* renderer;
              TTF_Font* font;
              TTF_Font* MenuFont;
              Text playerHeath;
              Text Score;
              Text GameOver;
              Text GameOver1;
              bool InMenu = true;
              Mix_Music* music = NULL;
              bool _isRunning = true;
              static Game* GetInstance() {
                return _instance = (_instance != nullptr) ? _instance : new Game ;
            }
      bool isRunning() { return _isRunning; }
      bool inMenu() { return InMenu; }
      void init();
      void quit();
      void update();
      void render();
      void event();
      void cleanSDL();

};

