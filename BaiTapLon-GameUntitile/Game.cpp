#include "Game.h"
level* _level = new level();
layer* layerCollision = new layer();
layer* layer2 = new layer();
Knight* player = new Knight(new All("KnightIdle", 200, 100, TextureManage::GetInstance()->textureWidth("KnightIdle") / 11, TextureManage::GetInstance()->textureHeight("KnightIdle")));
void Game::init()
{
    // Khởi tạo Window + Renderer
    initSDL(window, renderer);
    // Load Layer + level
    layerCollision->load("LayerData1.txt", TextureManage::GetInstance()->load_texture("Art//Tileset.png") , 10 , 6 , 1 );
    layer2->load("LayerData2.txt", TextureManage::GetInstance()->load_texture("Art//Ob.png"), 12, 11 , 61 );
    _level->loadLayerToLevel(layerCollision);
    _level->loadLayerToLevel(layer2);

    // Load đồ họa

    //background
    TextureManage::GetInstance()->load("SimpleBackground", "Art//Background_0.png");
    TextureManage::GetInstance()->load("background_1", "Art//Layers//1_1.png");
    TextureManage::GetInstance()->load("background_2", "Art//Layers//2_2.png");
    TextureManage::GetInstance()->load("background_3", "Art//Layers//3_3.png");
    TextureManage::GetInstance()->load("background_4", "Art//Layers//4_4.png");
    TextureManage::GetInstance()->load("background_5", "Art//Layers//5_5.png");
    //

    TextureManage::GetInstance()->load("KnightIdle", "Art//Knight//idle.png");
    TextureManage::GetInstance()->load("KnightRun", "Art//Knight//Run.png");
    TextureManage::GetInstance()->load("KnightAttack", "Art//Knight//Attack.png");
    TextureManage::GetInstance()->load("KnightJump", "Art//Knight//Jump.png");
    TextureManage::GetInstance()->load("KnightFall", "Art//Knight//Fall.png");
    
    // Set Camera vào nhân vật
    Camera::getInstance()->setPoint(player->point);
}

void Game::quit()
{
    _isRunning = false;
}

void Game::update()
{
    float dt =  1;  
    player->updateObject(dt);
   // player->O_tranform->vector.print(" player : ");

    Camera::getInstance()->update(dt);
}
void Game::render()
{
    // Render Background

    TextureManage::GetInstance()->draw("background_1", 0, 0, 4028, 800, SDL_FLIP_NONE, 0.5);
    TextureManage::GetInstance()->draw("background_2", 0, 0, 4028, 800, SDL_FLIP_NONE, 0.6);
    TextureManage::GetInstance()->draw("background_3", 0, 0, 4028, 800, SDL_FLIP_NONE, 0.7);
    TextureManage::GetInstance()->draw("background_4", 0, 50, 4028, 800, SDL_FLIP_NONE, 0.8);
    TextureManage::GetInstance()->draw("background_5", 200, 0, 4028, 800, SDL_FLIP_NONE, 0.9);
    

    // Render level 
    _level->renderLevel(renderer);

    // Render Player
    player->drawObject( player->animation );


    SDL_RenderPresent(renderer);
    
}
void Game::event()
{
    Input::getInstance()->listen();
}
void Game::cleanSDL()
{
    //SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}