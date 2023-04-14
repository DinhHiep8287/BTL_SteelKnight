using namespace std;
#include "Game.h"
SDL_Event e;
time_t t;
TextureManage* TextureManage::_instance = nullptr;
Input* Input::_intance = nullptr;
Game* Game::_instance = nullptr;
Camera* Camera::instance = nullptr;
int main(int argc, char* argv[])
{
    srand((unsigned)time(&t));
    // KHỞI TẠO
    Game::GetInstance()->init();
    TextureManage::GetInstance()->load("MenuBack", "Art//backMenu1.png");
    Text start;
    start.setText("Start");
    start.setRectPos(400, 250);
    start.loadRenderText(Game::GetInstance()->MenuFont, Game::GetInstance()->renderer, { 0,0,0 });
    Text quit;
    quit.setText("Quit");
    quit.setRectPos(400, 350);
    quit.loadRenderText(Game::GetInstance()->MenuFont,  Game::GetInstance()->renderer, { 0,0,0 });
    //MENU

    int xm = 0; int ym = 0; // Mouse Position
    while (Game::GetInstance()->InMenu)
    {
        if (Mix_PlayingMusic() == 0)
        {
            //Play the music
            Mix_PlayMusic(Game::GetInstance()->music, -1);
        }
        while (SDL_PollEvent(&Input::getInstance()->e)) {

            switch (Input::getInstance()->e.type)
            {
            case SDL_QUIT:
                Game::GetInstance()->quit();
                break;
            case SDL_MOUSEMOTION :
                xm = Input::getInstance()->e.motion.x;
                ym = Input::getInstance()->e.motion.y;
                
                if (checkFocus(xm, ym, &start.rect))
                {
                    start.loadRenderText(Game::GetInstance()->MenuFont, Game::GetInstance()->renderer, { 255,0,0 });
                }
                else start.loadRenderText(Game::GetInstance()->MenuFont, Game::GetInstance()->renderer, { 224,224,224 });
                if (checkFocus(xm, ym, &quit.rect))
                {
                    quit.loadRenderText(Game::GetInstance()->MenuFont, Game::GetInstance()->renderer, { 255,0,0 });
                }
                else quit.loadRenderText(Game::GetInstance()->MenuFont, Game::GetInstance()->renderer, { 224,224,224 });
                break;

            case SDL_MOUSEBUTTONDOWN :
                quit.loadRenderText(Game::GetInstance()->MenuFont, Game::GetInstance()->renderer, { 224,224,224 });
                start.loadRenderText(Game::GetInstance()->MenuFont, Game::GetInstance()->renderer, { 224,224,224 });
                xm = Input::getInstance()->e.motion.x;
                ym = Input::getInstance()->e.motion.y;
                if (checkFocus(xm, ym, &start.rect))
                {
                    Game::GetInstance()->InMenu = false;
                }
                if (checkFocus(xm, ym, &quit.rect))
                {
                    Game::GetInstance()->quit();
                }
                break;
            case SDL_MOUSEBUTTONUP:
                quit.loadRenderText(Game::GetInstance()->MenuFont, Game::GetInstance()->renderer, { 224,224,224 });
                start.loadRenderText(Game::GetInstance()->MenuFont, Game::GetInstance()->renderer, { 224,224,224 });
                break;
            default:
                break;
            }

        SDL_RenderCopy(Game::GetInstance()->renderer, TextureManage::GetInstance()->_textureMap["MenuBack"], NULL, NULL);
        start.renderText(Game::GetInstance()->renderer);
        quit.renderText(Game::GetInstance()->renderer);
        start.Free();
        quit.Free();

        SDL_RenderPresent(Game::GetInstance()->renderer);
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
    }

    // GAMELOOP
    while (Game::GetInstance()->isRunning())
    {
        Game::GetInstance()->event();
        Game::GetInstance()->update();
        Game::GetInstance()->render();
    }
    // THOÁT //
    Game::GetInstance()->cleanSDL();

	return 0;
}