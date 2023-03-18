#include "Engine.h"
using namespace std;
const int SCREEN_WIDTH = 32 * SIZE;
const int SCREEN_HEIGHT = 18 * SIZE;
const string WINDOW_TITLE = "UntiledGame";
void logSDLError(std::ostream& os,
    const std::string& msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
void initSDL(SDL_Window*& window, SDL_Renderer*& renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP;
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
bool CollisionMap(SDL_Rect a)
{
    int tileSize = 32;
    const int X_Count = 128;
    const int Y_Count = 28;
    int mapWidth = tileSize * X_Count;
    int mapHeight = tileSize * Y_Count;
    ifstream map ("LayerData1.txt");
    int check[Y_Count+1][X_Count+1];
    for (int i = 0 ; i < Y_Count; i++)
    {
        for (int j = 0 ; j < X_Count; j++)
        { 
            
            map >> check[i][j];
            //cout << check[i][j] << " ";
        }
        //cout << endl;
    }
    int leftTile = a.x / tileSize;
    int rightTile = (a.x + a.w) / tileSize;
    int topTile = a.y / tileSize;
    int botTile = (a.y + a.h) / tileSize;
    if (leftTile < 0) leftTile = 0;
    if (rightTile < 0) rightTile = 0;
    if (topTile < 0) topTile = 0;
    if (botTile < 0) botTile = 0;

    if (a.x <= 0 || a.y <= 0 || a.x + a.w >= mapWidth || a.y + a.h >= mapHeight)
    {
        return true;
    }

    for (int i = leftTile ; i <= rightTile; i++)
    {
        for (int j = topTile ; j <= botTile; j++)
        {
            if (check[j][i] > 0)
            {   
                //cout << " i = " << i << "   j =   " << j << endl;
                //cout << "vacham " << leftTile << " " << rightTile <<" " << check[j][i] << " " << topTile << " " << botTile << " " << endl;
                return true;
            }
        }
    }

    return false;
}
bool CollisionUp(SDL_Rect a)
{
    int tileSize = 32;
    const int X_Count = 128;
    const int Y_Count = 28;
    int mapWidth = tileSize * X_Count;
    int mapHeight = tileSize * Y_Count;
    ifstream map("LayerData1.txt");
    int check[Y_Count + 1][X_Count + 1];
    for (int i = 0; i < Y_Count; i++)
    {
        for (int j = 0; j < X_Count; j++)
        {

            map >> check[i][j];
            //cout << check[i][j] << " ";
        }
        //cout << endl;
    }
    int leftTile = a.x / tileSize;
    int rightTile = (a.x + a.w) / tileSize;
    int topTile = a.y / tileSize;
    if (leftTile < 0) leftTile = 0;
    if (rightTile < 0) rightTile = 0;
    if (topTile < 0) topTile = 0;


    for (int i = leftTile; i <= rightTile; i++)
    {
        int j = topTile;
        if (check[j][i] > 0)
        {
            //cout << "vacham " << leftTile << " " << rightTile << " " << topTile << " " << botTile << " " << endl; 
            return true;
        }

    }

    return false;
}

bool CheckCollision(SDL_Rect a, SDL_Rect b)
{
    int LeftA = a.x; int RightA = a.x + a.w;
    int TopA = a.y; int BotA = a.y + a.h;

    int LeftB = b.x; int RightB = b.x + b.w;
    int TopB = b.y; int BotB = b.y + b.h;

    if (BotA <= TopB)
    {
        return false;
    }

    if (TopA >= BotB)
    {
        return false;
    }

    if (RightA <= LeftB)
    {
        return false;
    }

    if (LeftA >= RightB)
    {
        return false;
    }
    return true;
}

bool checkcollisionX(SDL_Rect a)

{
    int tileSize = 32;
    const int X_Count = 128;
    const int Y_Count = 28;
    int mapWidth = tileSize * X_Count;
    int mapHeight = tileSize * Y_Count;
    ifstream map("LayerData1.txt");
    int check[Y_Count + 1][X_Count + 1];
    for (int i = 0; i < Y_Count; i++)
    {
        for (int j = 0; j < X_Count; j++)
        {

            map >> check[i][j];
            //cout << check[i][j] << " ";
        }
        //cout << endl;
    }
    int leftTile = a.x / tileSize;
    int rightTile = (a.x + a.w) / tileSize;
    int botTile = (a.y + a.h) / tileSize;
    if (leftTile < 0) leftTile = 0;
    if (rightTile < 0) rightTile = 0;
    if (botTile < 0) botTile = 0;
    if (check[botTile - 1][leftTile - 1] > 0) return true;
    if (check[botTile - 1][rightTile + 1] > 0) return true;


    return false; 
}

// if char at the edge return true
bool checkEdge(SDL_Rect a)
{
    int tileSize = 32;
    const int X_Count = 128;
    const int Y_Count = 28;
    int mapWidth = tileSize * X_Count;
    int mapHeight = tileSize * Y_Count;
    ifstream map("LayerData1.txt");
    int check[Y_Count + 1][X_Count + 1];
    for (int i = 0; i < Y_Count; i++)
    {
        for (int j = 0; j < X_Count; j++)
        {

            map >> check[i][j];
            //cout << check[i][j] << " ";
        }
        //cout << endl;
    }
    int leftTile = a.x / tileSize;
    int rightTile = (a.x + a.w) / tileSize;
    int botTile = (a.y + a.h) / tileSize;
    if (leftTile < 0) leftTile = 0;
    if (rightTile < 0) rightTile = 0;
    if (botTile < 0) botTile = 0;
    if (check[botTile ][leftTile - 1] == 0) return true;
    if (check[botTile ][rightTile + 1] == 0) return true;

    return false;
}
