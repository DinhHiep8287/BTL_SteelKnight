#include "Game.h"

SDL_Rect rect = { 100,100,200,200 };
// Dữ liệu về quái 
vector<vector<string>> MonsterData;
vector<vector<int>> MonsterData1;
// Dữ liệu về map + respawnPoint
vector<vector<int>> LayerData1;
vector<vector<int>> LayerData2;
vector<vector<int>> LayerData3;
vector<Vector2D> spawnPoint;

//
level* _level = new level();
layer* layerCollision = new layer();
layer* layer3 = new layer();
layer* layer2 = new layer();
FullEnermy* fullEnermy = new FullEnermy();
Knight* player = new Knight(new All("" , 100 , 200 , 0 , 0));

Enermy* enermy1 = new Enermy(new All("" , 100, 500, 0, 0 ));
Enermy* enermy6 = new Enermy(new All("", 1250, 570, 0, 0));
Enermy* enermy7 = new Enermy(new All("", 2700, 550, 0, 0));
Enermy* enermy10 = new Enermy(new All("", 3600, 560, 0, 0));
Enermy* enermy11 = new Enermy(new All("", 3100, -130, 0, 0));
Enermy* enermy12 = new Enermy(new All("", 2300, -110, 0, 0));
Enermy* enermy13 = new Enermy(new All("", 2300, 300, 0, 0));
Enermy* enermy14 = new Enermy(new All("", 1850, 570, 0, 0));
Enermy* enermy16 = new Enermy(new All("", 1800, 0, 0, 0));
Enermy* enermy17 = new Enermy(new All("", 1300, 0, 0, 0));
Enermy* enermy18 = new Enermy(new All("", 3600, 100, 0, 0));

void Game::init()
{
    // Khởi tạo SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
    music = Mix_LoadMUS("dungeon_theme_2.wav");
    if (music == NULL)
    {
        printf("Failed to load %s\n", Mix_GetError());
    }

    // Khởi tạo Font 
    TTF_Init();
    Game::GetInstance()->font = TTF_OpenFont("fontGame.ttf", 40);
    if (font == NULL) cout << "loi font ";
    Game::GetInstance()->MenuFont = TTF_OpenFont("fontGame.ttf", 60);
    if (MenuFont == NULL) cout << "loi font ";

    // Khởi tạo Window + Renderer + Text 
    initSDL(window, renderer);

    // Khởi tạo quái
    MonsterData.resize(10); MonsterData1.resize(10);
    for (int i = 0; i < 10; i++) MonsterData[i].resize(10);
    for (int i = 0; i < 10; i++) MonsterData1[i].resize(10);
    MonsterData[0][0] = "skeWalk";
    MonsterData[0][1] = "skeAttack" ;
    MonsterData[0][2] = "skeTakeHit";
    MonsterData[0][3] = "skeDie";
    MonsterData[0][4] = "skeDead";

    MonsterData[1][0] = "goblinRun";
    MonsterData[1][1] = "goblinAttack";
    MonsterData[1][2] = "goblinTakeHit";
    MonsterData[1][3] = "goblinDie";
    MonsterData[1][4] = "goblinDead";

    MonsterData[2][0] = "MushroomnRun";
    MonsterData[2][1] = "MushroomAttack";
    MonsterData[2][2] = "MushroomTakeHit";
    MonsterData[2][3] = "MushroomDie";
    MonsterData[2][4] = "MushroomDead";

    MonsterData[3][0] = "eyeFlight";
    MonsterData[3][1] = "eyeAttack";
    MonsterData[3][2] = "eyeTakeHit";
    MonsterData[3][3] = "eyeDie";
    MonsterData[3][4] = "eyeDead";

    MonsterData1[0][0] = 4; 
    MonsterData1[0][1] = 8; 
    MonsterData1[0][2] = 4;

    MonsterData1[1][0] = 8 ;
    MonsterData1[1][1] = 8 ;
    MonsterData1[1][2] = 4 ;

    MonsterData1[2][0] = 8;
    MonsterData1[2][1] = 8;
    MonsterData1[2][2] = 4;

    MonsterData1[3][0] = 8;
    MonsterData1[3][1] = 8;
    MonsterData1[3][2] = 4;

    fullEnermy->loadEnermy(enermy1);
    fullEnermy->loadEnermy(enermy6);
    fullEnermy->loadEnermy(enermy7);
    fullEnermy->loadEnermy(enermy10);
    fullEnermy->loadEnermy(enermy11);
    fullEnermy->loadEnermy(enermy12);
    fullEnermy->loadEnermy(enermy13);
    fullEnermy->loadEnermy(enermy14);
    fullEnermy->loadEnermy(enermy16);
    fullEnermy->loadEnermy(enermy17);
    fullEnermy->loadEnermy(enermy18);

    // Nạp dự liệu về map + spawnPoint
    const int tileSize = 32;
    const int X_Count = 128;
    const int Y_Count = 28;
    int mapWidth = tileSize * X_Count;
    int mapHeight = tileSize * Y_Count;
    ifstream map1("LayerData1.txt");
    ifstream map2("LayerData2.txt");
    ifstream map3("LayerData3.txt");

    LayerData1.resize(Y_Count);
    for (int i = 0; i < Y_Count; i++)
    {
        LayerData1[i].resize(X_Count);
    }
    LayerData2.resize(Y_Count);
    for (int i = 0; i < Y_Count; i++)
    {
        LayerData2[i].resize(X_Count);
    }
    LayerData3.resize(Y_Count);
    for (int i = 0; i < Y_Count; i++)
    {
        LayerData3[i].resize(X_Count);
    }
    for (int i = 0; i < Y_Count; i++)
    {
        for (int j = 0; j < X_Count; j++)
        {

            map1 >> LayerData1[i][j];
        }
    }
    for (int i = 0; i < Y_Count; i++)
    {
        for (int j = 0; j < X_Count; j++)
        {

            map2 >> LayerData2[i][j];
        }
    }
    for (int i = 0; i < Y_Count; i++)
    {
        for (int j = 0; j < X_Count; j++)
        {

            map3 >> LayerData3[i][j];
        }
    }
    
    spawnPoint.push_back(Vector2D(100, 500));
    spawnPoint.push_back(Vector2D(1250, 570));
    spawnPoint.push_back(Vector2D(2700, 550));
    spawnPoint.push_back(Vector2D(3600, 560));
    spawnPoint.push_back(Vector2D(3100, -130));
    spawnPoint.push_back(Vector2D(3600, 560));
    spawnPoint.push_back(Vector2D(2300, -110));
    spawnPoint.push_back(Vector2D(2300, 300));
    spawnPoint.push_back(Vector2D(1850, 570));
    spawnPoint.push_back(Vector2D(1800, 0));
    spawnPoint.push_back(Vector2D(1300, 0));
    spawnPoint.push_back(Vector2D(3600, 100));


    // Load Layer + level

    layerCollision->load("LayerData1.txt", TextureManage::GetInstance()->load_texture("Art//Tileset.png") , 10 , 6 , 1 );
    layer3->load("LayerData2.txt", TextureManage::GetInstance()->load_texture("Art//Ob.png"), 12, 11 , 61 );
    layer2->load("LayerData3.txt", TextureManage::GetInstance()->load_texture("Art//Ob1.png"), 40, 30, 193);
    _level->loadLayerToLevel(layerCollision);
    _level->loadLayerToLevel(layer2);
    _level->loadLayerToLevel(layer3);
    // Load đồ họa
    
    // heart
    TextureManage::GetInstance()->load("heart", "Art//heart.png");

    
    
    //background
    TextureManage::GetInstance()->load("background_1", "Art//Layers//1_1.png");
    TextureManage::GetInstance()->load("background_2", "Art//Layers//2_2.png");
    TextureManage::GetInstance()->load("background_3", "Art//Layers//3_3.png");
    TextureManage::GetInstance()->load("background_4", "Art//Layers//4_4.png");
    TextureManage::GetInstance()->load("background_5", "Art//Layers//5_5.png");
    //Char

    TextureManage::GetInstance()->load("KnightIdle", "Art//Knight//idle.png");
    TextureManage::GetInstance()->load("KnightRun", "Art//Knight//Run.png");
    TextureManage::GetInstance()->load("KnightAttack", "Art//Knight//Attack.png");
    TextureManage::GetInstance()->load("KnightJump", "Art//Knight//Jump.png");
    TextureManage::GetInstance()->load("KnightFall", "Art//Knight//Fall.png");
    TextureManage::GetInstance()->load("KnightTakeHit", "Art//Knight//Take Hit.png");
    TextureManage::GetInstance()->load("KnightDie", "Art//Knight//Death.png");
    TextureManage::GetInstance()->load("KnightDead", "Art//Knight//Dead.png");


    TextureManage::GetInstance()->load("skeWalk", "Art/Monster/Skeleton/Walk.png");
    TextureManage::GetInstance()->load("skeAttack", "Art/Monster/Skeleton/Attack.png");
    TextureManage::GetInstance()->load("skeTakeHit", "Art/Monster/Skeleton/Take Hit.png");
    TextureManage::GetInstance()->load("skeDie", "Art/Monster/Skeleton/Death.png");
    TextureManage::GetInstance()->load("skeDead", "Art/Monster/Skeleton/Dead.png");


    TextureManage::GetInstance()->load("goblinRun", "Art/Monster/Goblin/Run.png");
    TextureManage::GetInstance()->load("goblinAttack", "Art/Monster/Goblin/Attack.png");
    TextureManage::GetInstance()->load("goblinTakeHit", "Art/Monster/Goblin/Take Hit.png");
    TextureManage::GetInstance()->load("goblinDie", "Art/Monster/Goblin/Death.png");
    TextureManage::GetInstance()->load("goblinDead", "Art/Monster/Goblin/Dead.png");

    TextureManage::GetInstance()->load("MushroomnRun", "Art/Monster/Mushroom/Run.png");
    TextureManage::GetInstance()->load("MushroomAttack", "Art/Monster/Mushroom/Attack.png");
    TextureManage::GetInstance()->load("MushroomTakeHit", "Art/Monster/Mushroom/Take Hit.png");
    TextureManage::GetInstance()->load("MushroomDie", "Art/Monster/Mushroom/Death.png");
    TextureManage::GetInstance()->load("MushroomDead", "Art/Monster/Mushroom/Dead.png");

    TextureManage::GetInstance()->load("eyeFlight", "Art/Monster/Flying eye/Flight.png");
    TextureManage::GetInstance()->load("eyeAttack", "Art/Monster/Flying eye/Attack.png");
    TextureManage::GetInstance()->load("eyeTakeHit", "Art/Monster/Flying eye/Take Hit.png");
    TextureManage::GetInstance()->load("eyeDie", "Art/Monster/Flying eye/Death.png");
    TextureManage::GetInstance()->load("eyeDead", "Art/Monster/Flying eye/Dead.png");


    // Set Camera vào nhân vật
    Camera::getInstance()->setPoint(player->point);
}

void Game::quit()
{
    InMenu = false;
    _isRunning = false;
}
void Game::update()
{
    if (Mix_PlayingMusic() == 0)
    {
        //Play the music
        Mix_PlayMusic(music, -1);
    }
    float dt = 1; 
    player->updateObject(dt, fullEnermy ,LayerData1 );
    fullEnermy->updateFullEnermy(dt, player , MonsterData , MonsterData1 , LayerData1 , spawnPoint);
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

    fullEnermy->drawFullEnermy(renderer , player );
    player->drawObject(player->animation );

    // Heath Text + Heart Icon
    string heathStr = to_string(player->health);
    playerHeath.setText(heathStr);
    playerHeath.loadRenderText(font, renderer , {255,51,51});
    playerHeath.setRectPos(200, 20);
    playerHeath.renderText(renderer);
    SDL_Rect heartIconRect = { 120,20,60,60 };
    SDL_RenderCopy(renderer, TextureManage::GetInstance()->_textureMap["heart"], NULL, &heartIconRect);
    // Score Text
    string scoreStr = to_string(player->score);
    scoreStr = "Score : " + scoreStr;
    Score.setText(scoreStr);
    Score.loadRenderText(font, renderer , {224,224,224});
    Score.setRectPos(600, 20);
    Score.renderText(renderer);


    SDL_RenderPresent(renderer );

    playerHeath.Free();
    Score.Free();
    
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