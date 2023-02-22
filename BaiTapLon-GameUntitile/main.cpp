#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include <string.h>
#include <ctime> 
#include <cstdlib> 
#include <random>
using namespace std;
#include "Engine.h"

const int S = 25;
const int SCREEN_WIDTH = 32 * S;
const int SCREEN_HEIGHT = 16 * S;
const string WINDOW_TITLE = "UntiledGame";
SDL_Event e;
time_t t;



struct Wall
{
	int x, y;

	Wall()
	{
		x = 0;
		y = 0;
	}

	Wall(int _x , int _y)
	{
		x = _x;
		y = _y;
	}
	
	void render( SDL_Renderer* renderer)
	{
		SDL_Rect fill_box;
		fill_box.x = x;
		fill_box.y = y;
		fill_box.w = S;
		fill_box.h = S;
		SDL_RenderFillRect(renderer, &fill_box);
	}
};


int main(int argc, char* argv[])
{
	SDL_Renderer* renderer;
	SDL_Window* window;
	initSDL(window, renderer);
	Wall wall(2 * S, 2 * S);

	SDL_Texture* background = loadTexture("background.png", renderer);
	SDL_Texture* KnightStand = loadTexture("knightStand.png", renderer);

	bool quit = 0;
	while (quit == 0)
	{	

		//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		//SDL_RenderClear(renderer);
		//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		//wall.render(renderer);
		//SDL_RenderPresent(renderer);



		while (SDL_PollEvent(&e) != 0)
		{
			SDL_RenderCopy(renderer, background, NULL, NULL);
            draw(KnightStand, renderer, 200, 200 , textureWidth(KnightStand) , textureHeight(KnightStand) );
            SDL_RenderPresent(renderer);
			if (e.type == SDL_QUIT)
			{
				quit = 1;
				break;

			}
			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE: quit = 1;
					break;




				default:
					break;
				}
			}
		}
	}




	quitSDL(window, renderer);
	return 0;
}