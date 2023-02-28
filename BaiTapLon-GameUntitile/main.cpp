using namespace std;
#include "Game.h"
const int S = 25;
const int SCREEN_WIDTH = 64 * S;
const int SCREEN_HEIGHT = 32 * S;
SDL_Event e;
time_t t;


int main(int argc, char* argv[])
{
    // KHỞI TẠO
    Game::GetInstance()->init();
    // GAMELOOP
    while (Game::GetInstance()->isRunning())
    {
        Game::GetInstance()->event();
        Game::GetInstance()->update();
        Game::GetInstance()->render();
    }
    
    Game::GetInstance()->cleanSDL();

	return 0;
}